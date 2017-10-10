#include <iostream>
#include <string>

#include "DataUnit.h"
#include "VectorBuffer.h"
#include "TransportRelay.h"
#include "Socket.h"
#include "TCPClientSocket.h"
#include "TCPServerSocket.h"
#include "BufferStreamReader.h"
#include "String_.h"
#include "DataUnitCursor.h"
#include "DataUnitOperator.h"
#include "../../../tls-definitions.h"

using namespace std;


class MyRelay : public TransportRelay {

private:

	std::ofstream* ofs;

	bool sawClientHello_;


public:

	TVector_MainType streamToServer;
	TVector_MainType streamToClient;


	MyRelay(int inPort, const string& destAddr, int destPort)
		: TransportRelay(inPort, destAddr, destPort) {

		ofs = 0;
		sawClientHello_ = false;
	}

	virtual bool interceptToServer(vector<uint8_t>& data) {

		VectorBuffer buf;
		buf.appendBytes(&(data.at(0)), data.size());

		BC from = streamToServer.getLength();

		if (!sawClientHello_) {

			BufferStreamReader reader(buf);
			streamToServer.dissector().dissect(reader);

			VectorBuffer extBuf;
			extBuf.appendFromHexString("0001000101");

			TStruct_Extension* ext = new TStruct_Extension();
			ext->dissector().dissectFromBuffer(extBuf);

			DataUnitCursor cursor(*streamToServer.getChildTail());
			if (!cursor.seekByPath("msg/_M0/extensions/_V/~4")) {
				cout << "failed to seek" << endl;
			}
			if (!cursor.getCurrent().appendNext(ext)) {
				cout << "failed to append" << endl;
			}

			RepairingOperator repOp;

			cursor.seekByIndex(0);
			repOp.apply(cursor);

			cursor.getCurrent().print();

			data.clear();
			BC len = cursor.getCurrent().getLength();
			for (BC i = 0; i < len; i++) {
				data.push_back(cursor.getCurrent().getByte(i));
			}

			sawClientHello_ = true;
		}


        //cout << String::format("[Client] ---> (%d bytes) ---> [Server]", data.size()) << endl;
		//DataUnit::PrintOptions po;
		//po.from = from;
		//streamToServer.print(po);

		return true;
	}

	virtual bool interceptToClient(vector<uint8_t>& data) {

		bool keepConnection = true;

		VectorBuffer buf;
		buf.appendBytes(&(data.at(0)), data.size());

		BC from = streamToClient.getLength();

		BufferStreamReader reader(buf);
		streamToClient.dissector().dissect(reader);

		/* check if server sent application data */
		if (streamToClient.getChildTail()->getChildByName("type")->propGet<int>(".value") == 3) {
			keepConnection = false;
		}

        //cout << String::format("[Client] <--- (%d bytes) <--- [Server]", data.size()) << endl;
		//DataUnit::PrintOptions po;
		//po.from = from;
		//streamToClient.print(po);

		return keepConnection;
	}

};



int main(int argc , char *argv[]) {

    size_t inPort = 5001;
    size_t destPort = 4440;
    string destAddr = "localhost";

	MyRelay relay(inPort, destAddr, destPort);

	while (relay.process());

	return EXIT_SUCCESS;

}
