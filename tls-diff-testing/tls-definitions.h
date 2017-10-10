/*
 *  Copyright (C) 2017
 *  Andreas Walz [andreas.walz@hs-offenburg.de]
 *  Offenburg University of Applied Sciences
 *  Institute of Reliable Embedded Systems and Communications Electronics (ivESK)
 *  [https://ivesk.hs-offenburg.de/]
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its contributors
 *     may be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 * Auto-generated using etpl-tool [https://github.com/phantax/etpl-tool].
 * See also: A. Walz and A. Sikora, “eTPL: An Enhanced Version of the TLS
 * Presentation Language Suitable for Automated Parser Generation,” 
 * in 9th IEEE International Conference on Intelligent Data Acquisition 
 * and Advanced Computing Systems: Technology and Applications (IDAACS), 2017.
 */

#include "CompositeDataUnit.h"
#include "EnumerationField.h"
#include "DataUnit.h"
#include "OpaqueField.h"
#include "StreamVectorDataUnit.h"


/* ========================================================================= */

/* Definition of class "TEnum_AlertLevel" corresponding to Enum "AlertLevel" */
class TEnum_AlertLevel : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_AlertLevel" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 231, "AlertLevel");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_AlertLevel" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_AlertLevel" */
    TEnum_AlertLevel() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("AlertLevel");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("warning", 1);
            staticList_.addItem("fatal"  , 2);
            staticList_.addFallbackItem("unknown");
        }
    }


    /* Function to create another instance of class "TEnum_AlertLevel" */
    TEnum_AlertLevel* newInstance_() const {

        TEnum_AlertLevel* du = new TEnum_AlertLevel();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_AlertLevel" */
EnumerationItemList TEnum_AlertLevel::staticList_;


/* ========================================================================= */

/* Definition of class "TEnum_AlertDescription" corresponding to Enum "AlertDescription" */
class TEnum_AlertDescription : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_AlertDescription" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 232, "AlertDescription");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_AlertDescription" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_AlertDescription" */
    TEnum_AlertDescription() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("AlertDescription");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("close_notify"               , 0);
            staticList_.addItem("unexpected_message"         , 10);
            staticList_.addItem("bad_record_mac"             , 20);
            staticList_.addItem("decryption_failed_RESERVED" , 21);
            staticList_.addItem("record_overflow"            , 22);
            staticList_.addItem("decompression_failure"      , 30);
            staticList_.addItem("handshake_failure"          , 40);
            staticList_.addItem("no_certificate_RESERVED"    , 41);
            staticList_.addItem("bad_certificate"            , 42);
            staticList_.addItem("unsupported_certificate"    , 43);
            staticList_.addItem("certificate_revoked"        , 44);
            staticList_.addItem("certificate_expired"        , 45);
            staticList_.addItem("certificate_unknown"        , 46);
            staticList_.addItem("illegal_parameter"          , 47);
            staticList_.addItem("unknown_ca"                 , 48);
            staticList_.addItem("access_denied"              , 49);
            staticList_.addItem("decode_error"               , 50);
            staticList_.addItem("decrypt_error"              , 51);
            staticList_.addItem("export_restriction_RESERVED", 60);
            staticList_.addItem("protocol_version"           , 70);
            staticList_.addItem("insufficient_security"      , 71);
            staticList_.addItem("internal_error"             , 80);
            staticList_.addItem("user_canceled"              , 90);
            staticList_.addItem("no_renegotiation"           , 100);
            staticList_.addItem("unsupported_extension"      , 110);
            staticList_.addFallbackItem("unknown");
        }
    }


    /* Function to create another instance of class "TEnum_AlertDescription" */
    TEnum_AlertDescription* newInstance_() const {

        TEnum_AlertDescription* du = new TEnum_AlertDescription();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_AlertDescription" */
EnumerationItemList TEnum_AlertDescription::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_Alert" corresponding to Struct "Alert" */
class TStruct_Alert : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Alert" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 233, "Alert");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Alert" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Alert" */
    TStruct_Alert() : CompositeDataUnit() {

        this->setName("Alert");
    }


    /* Function to create another instance of class "TStruct_Alert" */
    TStruct_Alert* newInstance_() const {

        TStruct_Alert* du = new TStruct_Alert();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "level" ===== */
            TEnum_AlertLevel* _M0 = new TEnum_AlertLevel();
            this->appendChildRenamed(_M0, "level");
            /* ===== Struct member "description" ===== */
            TEnum_AlertDescription* _M1 = new TEnum_AlertDescription();
            this->appendChildRenamed(_M1, "description");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_Type" corresponding to Enum "Type" */
class TEnum_Type : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_Type" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 234, "Type");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_Type" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_Type" */
    TEnum_Type() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("Type");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("change_cipher_spec", 20);
            staticList_.addItem("alert"             , 21);
            staticList_.addItem("handshake"         , 22);
            staticList_.addItem("application_data"  , 23);
            staticList_.addFallbackItem("unknown");
        }
    }


    /* Function to create another instance of class "TEnum_Type" */
    TEnum_Type* newInstance_() const {

        TEnum_Type* du = new TEnum_Type();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_Type" */
EnumerationItemList TEnum_Type::staticList_;


/* ========================================================================= */

/* Definition of class "TEnum_Version" corresponding to Enum "Version" */
class TEnum_Version : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_Version" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 235, "Version");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_Version" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_Version" */
    TEnum_Version() : EnumerationField(BC(0, 16), staticList_) {

        this->setName("Version");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("SSLv3"   , 768);
            staticList_.addItem("TLSv1"   , 769);
            staticList_.addItem("TLSv1_1" , 770);
            staticList_.addItem("TLSv1_2" , 771);
            staticList_.addItem("DTLSv1_2", 65277);
            staticList_.addFallbackItem("unknown");
        }
    }


    /* Function to create another instance of class "TEnum_Version" */
    TEnum_Version* newInstance_() const {

        TEnum_Version* du = new TEnum_Version();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_Version" */
EnumerationItemList TEnum_Version::staticList_;


/* ========================================================================= */

/* Definition of class "TEnum_HandshakeType" corresponding to Enum "HandshakeType" */
class TEnum_HandshakeType : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_HandshakeType" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 236, "HandshakeType");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_HandshakeType" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_HandshakeType" */
    TEnum_HandshakeType() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("HandshakeType");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("hello_request"      , 0);
            staticList_.addItem("client_hello"       , 1);
            staticList_.addItem("server_hello"       , 2);
            staticList_.addItem("new_session_ticket" , 4);
            staticList_.addItem("certificate"        , 11);
            staticList_.addItem("server_key_exchange", 12);
            staticList_.addItem("certificate_request", 13);
            staticList_.addItem("server_hello_done"  , 14);
            staticList_.addItem("certificate_verify" , 15);
            staticList_.addItem("client_key_exchange", 16);
            staticList_.addItem("finished"           , 20);
            staticList_.addFallbackItem("unknown");
        }
    }


    /* Function to create another instance of class "TEnum_HandshakeType" */
    TEnum_HandshakeType* newInstance_() const {

        TEnum_HandshakeType* du = new TEnum_HandshakeType();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_HandshakeType" */
EnumerationItemList TEnum_HandshakeType::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_DTLSClientHello_cookie" corresponding to Struct "DTLSClientHello_cookie" */
class TStruct_DTLSClientHello_cookie : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_DTLSClientHello_cookie" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 237, "DTLSClientHello_cookie");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_DTLSClientHello_cookie" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_DTLSClientHello_cookie" */
    TStruct_DTLSClientHello_cookie() : CompositeDataUnit() {

        this->setName("DTLSClientHello_cookie");
    }


    /* Function to create another instance of class "TStruct_DTLSClientHello_cookie" */
    TStruct_DTLSClientHello_cookie* newInstance_() const {

        TStruct_DTLSClientHello_cookie* du = new TStruct_DTLSClientHello_cookie();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ASN1Cert" corresponding to Struct "ASN1Cert" */
class TStruct_ASN1Cert : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ASN1Cert" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 238, "ASN1Cert");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ASN1Cert" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ASN1Cert" */
    TStruct_ASN1Cert() : CompositeDataUnit() {

        this->setName("ASN1Cert");
    }


    /* Function to create another instance of class "TStruct_ASN1Cert" */
    TStruct_ASN1Cert* newInstance_() const {

        TStruct_ASN1Cert* du = new TStruct_ASN1Cert();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 24), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_HandshakeMessage_msg__C2_certificates" corresponding to Struct "HandshakeMessage_msg__C2_certificates" */
class TStruct_HandshakeMessage_msg__C2_certificates : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_HandshakeMessage_msg__C2_certificates" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 239, "HandshakeMessage_msg__C2_certificates");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_HandshakeMessage_msg__C2_certificates" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_HandshakeMessage_msg__C2_certificates" */
    TStruct_HandshakeMessage_msg__C2_certificates() : CompositeDataUnit() {

        this->setName("HandshakeMessage_msg__C2_certificates");
    }


    /* Function to create another instance of class "TStruct_HandshakeMessage_msg__C2_certificates" */
    TStruct_HandshakeMessage_msg__C2_certificates* newInstance_() const {

        TStruct_HandshakeMessage_msg__C2_certificates* du = new TStruct_HandshakeMessage_msg__C2_certificates();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 24), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TStruct_ASN1Cert* _M1_V = new TStruct_ASN1Cert();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_ExtensionType" corresponding to Enum "ExtensionType" */
class TEnum_ExtensionType : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_ExtensionType" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 240, "ExtensionType");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_ExtensionType" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_ExtensionType" */
    TEnum_ExtensionType() : EnumerationField(BC(0, 16), staticList_) {

        this->setName("ExtensionType");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("server_name"                           , 0);
            staticList_.addItem("max_fragment_length"                   , 1);
            staticList_.addItem("client_certificate_url"                , 2);
            staticList_.addItem("trusted_ca_keys"                       , 3);
            staticList_.addItem("truncated_hmac"                        , 4);
            staticList_.addItem("status_request"                        , 5);
            staticList_.addItem("user_mapping"                          , 6);
            staticList_.addItem("client_authz"                          , 7);
            staticList_.addItem("server_authz"                          , 8);
            staticList_.addItem("cert_type"                             , 9);
            staticList_.addItem("supported_groups"                      , 10);
            staticList_.addItem("ec_point_formats"                      , 11);
            staticList_.addItem("srp"                                   , 12);
            staticList_.addItem("signature_algorithms"                  , 13);
            staticList_.addItem("use_srtp"                              , 14);
            staticList_.addItem("heartbeat"                             , 15);
            staticList_.addItem("application_layer_protocol_negotiation", 16);
            staticList_.addItem("status_request_v2"                     , 17);
            staticList_.addItem("signed_certificate_timestamp"          , 18);
            staticList_.addItem("client_certificate_type"               , 19);
            staticList_.addItem("server_certificate_type"               , 20);
            staticList_.addItem("padding"                               , 21);
            staticList_.addItem("encrypt_then_mac"                      , 22);
            staticList_.addItem("extended_master_secret"                , 23);
            staticList_.addItem("cached_info"                           , 25);
            staticList_.addItem("SessionTicket_TLS"                     , 35);
            staticList_.addItem("renegotiation_info"                    , 65281);
            staticList_.addFallbackItem("unknown");
        }
    }


    /* Function to create another instance of class "TEnum_ExtensionType" */
    TEnum_ExtensionType* newInstance_() const {

        TEnum_ExtensionType* du = new TEnum_ExtensionType();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_ExtensionType" */
EnumerationItemList TEnum_ExtensionType::staticList_;


/* ========================================================================= */

/* Definition of class "TEnum_CompressionMethod" corresponding to Enum "CompressionMethod" */
class TEnum_CompressionMethod : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_CompressionMethod" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 241, "CompressionMethod");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_CompressionMethod" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_CompressionMethod" */
    TEnum_CompressionMethod() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("CompressionMethod");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("no_compression", 0);
            staticList_.addFallbackItem("unknown");
        }
    }


    /* Function to create another instance of class "TEnum_CompressionMethod" */
    TEnum_CompressionMethod* newInstance_() const {

        TEnum_CompressionMethod* du = new TEnum_CompressionMethod();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_CompressionMethod" */
EnumerationItemList TEnum_CompressionMethod::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_ClientHello_compression_methods" corresponding to Struct "ClientHello_compression_methods" */
class TStruct_ClientHello_compression_methods : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ClientHello_compression_methods" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 242, "ClientHello_compression_methods");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ClientHello_compression_methods" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ClientHello_compression_methods" */
    TStruct_ClientHello_compression_methods() : CompositeDataUnit() {

        this->setName("ClientHello_compression_methods");
    }


    /* Function to create another instance of class "TStruct_ClientHello_compression_methods" */
    TStruct_ClientHello_compression_methods* newInstance_() const {

        TStruct_ClientHello_compression_methods* du = new TStruct_ClientHello_compression_methods();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TEnum_CompressionMethod* _M1_V = new TEnum_CompressionMethod();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_DTLSClientHello_compression_methods" corresponding to Struct "DTLSClientHello_compression_methods" */
class TStruct_DTLSClientHello_compression_methods : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_DTLSClientHello_compression_methods" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 243, "DTLSClientHello_compression_methods");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_DTLSClientHello_compression_methods" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_DTLSClientHello_compression_methods" */
    TStruct_DTLSClientHello_compression_methods() : CompositeDataUnit() {

        this->setName("DTLSClientHello_compression_methods");
    }


    /* Function to create another instance of class "TStruct_DTLSClientHello_compression_methods" */
    TStruct_DTLSClientHello_compression_methods* newInstance_() const {

        TStruct_DTLSClientHello_compression_methods* du = new TStruct_DTLSClientHello_compression_methods();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TEnum_CompressionMethod* _M1_V = new TEnum_CompressionMethod();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_CipherSuite" corresponding to Enum "CipherSuite" */
class TEnum_CipherSuite : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_CipherSuite" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 244, "CipherSuite");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_CipherSuite" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_CipherSuite" */
    TEnum_CipherSuite() : EnumerationField(BC(0, 16), staticList_) {

        this->setName("CipherSuite");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("TLS_NULL_WITH_NULL_NULL"                     , 0);
            staticList_.addItem("TLS_RSA_WITH_NULL_MD5"                       , 1);
            staticList_.addItem("TLS_RSA_WITH_NULL_SHA"                       , 2);
            staticList_.addItem("TLS_RSA_EXPORT_WITH_RC4_40_MD5"              , 3);
            staticList_.addItem("TLS_RSA_WITH_RC4_128_MD5"                    , 4);
            staticList_.addItem("TLS_RSA_WITH_RC4_128_SHA"                    , 5);
            staticList_.addItem("TLS_RSA_EXPORT_WITH_RC2_CBC_40_MD5"          , 6);
            staticList_.addItem("TLS_RSA_WITH_IDEA_CBC_SHA"                   , 7);
            staticList_.addItem("TLS_RSA_EXPORT_WITH_DES40_CBC_SHA"           , 8);
            staticList_.addItem("TLS_RSA_WITH_DES_CBC_SHA"                    , 9);
            staticList_.addItem("TLS_RSA_WITH_3DES_EDE_CBC_SHA"               , 10);
            staticList_.addItem("TLS_DH_DSS_EXPORT_WITH_DES40_CBC_SHA"        , 11);
            staticList_.addItem("TLS_DH_DSS_WITH_DES_CBC_SHA"                 , 12);
            staticList_.addItem("TLS_DH_DSS_WITH_3DES_EDE_CBC_SHA"            , 13);
            staticList_.addItem("TLS_DH_RSA_EXPORT_WITH_DES40_CBC_SHA"        , 14);
            staticList_.addItem("TLS_DH_RSA_WITH_DES_CBC_SHA"                 , 15);
            staticList_.addItem("TLS_DH_RSA_WITH_3DES_EDE_CBC_SHA"            , 16);
            staticList_.addItem("TLS_DHE_DSS_EXPORT_WITH_DES40_CBC_SHA"       , 17);
            staticList_.addItem("TLS_DHE_DSS_WITH_DES_CBC_SHA"                , 18);
            staticList_.addItem("TLS_DHE_DSS_WITH_3DES_EDE_CBC_SHA"           , 19);
            staticList_.addItem("TLS_DHE_RSA_EXPORT_WITH_DES40_CBC_SHA"       , 20);
            staticList_.addItem("TLS_DHE_RSA_WITH_DES_CBC_SHA"                , 21);
            staticList_.addItem("TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA"           , 22);
            staticList_.addItem("TLS_DH_anon_EXPORT_WITH_RC4_40_MD5"          , 23);
            staticList_.addItem("TLS_DH_anon_WITH_RC4_128_MD5"                , 24);
            staticList_.addItem("TLS_DH_anon_EXPORT_WITH_DES40_CBC_SHA"       , 25);
            staticList_.addItem("TLS_DH_anon_WITH_DES_CBC_SHA"                , 26);
            staticList_.addItem("TLS_DH_anon_WITH_3DES_EDE_CBC_SHA"           , 27);
            staticList_.addItem("TLS_KRB5_WITH_DES_CBC_SHA"                   , 30);
            staticList_.addItem("TLS_KRB5_WITH_3DES_EDE_CBC_SHA"              , 31);
            staticList_.addItem("TLS_KRB5_WITH_RC4_128_SHA"                   , 32);
            staticList_.addItem("TLS_KRB5_WITH_IDEA_CBC_SHA"                  , 33);
            staticList_.addItem("TLS_KRB5_WITH_DES_CBC_MD5"                   , 34);
            staticList_.addItem("TLS_KRB5_WITH_3DES_EDE_CBC_MD5"              , 35);
            staticList_.addItem("TLS_KRB5_WITH_RC4_128_MD5"                   , 36);
            staticList_.addItem("TLS_KRB5_WITH_IDEA_CBC_MD5"                  , 37);
            staticList_.addItem("TLS_KRB5_EXPORT_WITH_DES_CBC_40_SHA"         , 38);
            staticList_.addItem("TLS_KRB5_EXPORT_WITH_RC2_CBC_40_SHA"         , 39);
            staticList_.addItem("TLS_KRB5_EXPORT_WITH_RC4_40_SHA"             , 40);
            staticList_.addItem("TLS_KRB5_EXPORT_WITH_DES_CBC_40_MD5"         , 41);
            staticList_.addItem("TLS_KRB5_EXPORT_WITH_RC2_CBC_40_MD5"         , 42);
            staticList_.addItem("TLS_KRB5_EXPORT_WITH_RC4_40_MD5"             , 43);
            staticList_.addItem("TLS_PSK_WITH_NULL_SHA"                       , 44);
            staticList_.addItem("TLS_DHE_PSK_WITH_NULL_SHA"                   , 45);
            staticList_.addItem("TLS_RSA_PSK_WITH_NULL_SHA"                   , 46);
            staticList_.addItem("TLS_RSA_WITH_AES_128_CBC_SHA"                , 47);
            staticList_.addItem("TLS_DH_DSS_WITH_AES_128_CBC_SHA"             , 48);
            staticList_.addItem("TLS_DH_RSA_WITH_AES_128_CBC_SHA"             , 49);
            staticList_.addItem("TLS_DHE_DSS_WITH_AES_128_CBC_SHA"            , 50);
            staticList_.addItem("TLS_DHE_RSA_WITH_AES_128_CBC_SHA"            , 51);
            staticList_.addItem("TLS_DH_anon_WITH_AES_128_CBC_SHA"            , 52);
            staticList_.addItem("TLS_RSA_WITH_AES_256_CBC_SHA"                , 53);
            staticList_.addItem("TLS_DH_DSS_WITH_AES_256_CBC_SHA"             , 54);
            staticList_.addItem("TLS_DH_RSA_WITH_AES_256_CBC_SHA"             , 55);
            staticList_.addItem("TLS_DHE_DSS_WITH_AES_256_CBC_SHA"            , 56);
            staticList_.addItem("TLS_DHE_RSA_WITH_AES_256_CBC_SHA"            , 57);
            staticList_.addItem("TLS_DH_anon_WITH_AES_256_CBC_SHA"            , 58);
            staticList_.addItem("TLS_RSA_WITH_NULL_SHA256"                    , 59);
            staticList_.addItem("TLS_RSA_WITH_AES_128_CBC_SHA256"             , 60);
            staticList_.addItem("TLS_RSA_WITH_AES_256_CBC_SHA256"             , 61);
            staticList_.addItem("TLS_DH_DSS_WITH_AES_128_CBC_SHA256"          , 62);
            staticList_.addItem("TLS_DH_RSA_WITH_AES_128_CBC_SHA256"          , 63);
            staticList_.addItem("TLS_DHE_DSS_WITH_AES_128_CBC_SHA256"         , 64);
            staticList_.addItem("TLS_RSA_WITH_CAMELLIA_128_CBC_SHA"           , 65);
            staticList_.addItem("TLS_DH_DSS_WITH_CAMELLIA_128_CBC_SHA"        , 66);
            staticList_.addItem("TLS_DH_RSA_WITH_CAMELLIA_128_CBC_SHA"        , 67);
            staticList_.addItem("TLS_DHE_DSS_WITH_CAMELLIA_128_CBC_SHA"       , 68);
            staticList_.addItem("TLS_DHE_RSA_WITH_CAMELLIA_128_CBC_SHA"       , 69);
            staticList_.addItem("TLS_DH_anon_WITH_CAMELLIA_128_CBC_SHA"       , 70);
            staticList_.addItem("TLS_DHE_RSA_WITH_AES_128_CBC_SHA256"         , 103);
            staticList_.addItem("TLS_DH_DSS_WITH_AES_256_CBC_SHA256"          , 104);
            staticList_.addItem("TLS_DH_RSA_WITH_AES_256_CBC_SHA256"          , 105);
            staticList_.addItem("TLS_DHE_DSS_WITH_AES_256_CBC_SHA256"         , 106);
            staticList_.addItem("TLS_DHE_RSA_WITH_AES_256_CBC_SHA256"         , 107);
            staticList_.addItem("TLS_DH_anon_WITH_AES_128_CBC_SHA256"         , 108);
            staticList_.addItem("TLS_DH_anon_WITH_AES_256_CBC_SHA256"         , 109);
            staticList_.addItem("TLS_RSA_WITH_CAMELLIA_256_CBC_SHA"           , 132);
            staticList_.addItem("TLS_DH_DSS_WITH_CAMELLIA_256_CBC_SHA"        , 133);
            staticList_.addItem("TLS_DH_RSA_WITH_CAMELLIA_256_CBC_SHA"        , 134);
            staticList_.addItem("TLS_DHE_DSS_WITH_CAMELLIA_256_CBC_SHA"       , 135);
            staticList_.addItem("TLS_DHE_RSA_WITH_CAMELLIA_256_CBC_SHA"       , 136);
            staticList_.addItem("TLS_DH_anon_WITH_CAMELLIA_256_CBC_SHA"       , 137);
            staticList_.addItem("TLS_PSK_WITH_RC4_128_SHA"                    , 138);
            staticList_.addItem("TLS_PSK_WITH_3DES_EDE_CBC_SHA"               , 139);
            staticList_.addItem("TLS_PSK_WITH_AES_128_CBC_SHA"                , 140);
            staticList_.addItem("TLS_PSK_WITH_AES_256_CBC_SHA"                , 141);
            staticList_.addItem("TLS_DHE_PSK_WITH_RC4_128_SHA"                , 142);
            staticList_.addItem("TLS_DHE_PSK_WITH_3DES_EDE_CBC_SHA"           , 143);
            staticList_.addItem("TLS_DHE_PSK_WITH_AES_128_CBC_SHA"            , 144);
            staticList_.addItem("TLS_DHE_PSK_WITH_AES_256_CBC_SHA"            , 145);
            staticList_.addItem("TLS_RSA_PSK_WITH_RC4_128_SHA"                , 146);
            staticList_.addItem("TLS_RSA_PSK_WITH_3DES_EDE_CBC_SHA"           , 147);
            staticList_.addItem("TLS_RSA_PSK_WITH_AES_128_CBC_SHA"            , 148);
            staticList_.addItem("TLS_RSA_PSK_WITH_AES_256_CBC_SHA"            , 149);
            staticList_.addItem("TLS_RSA_WITH_SEED_CBC_SHA"                   , 150);
            staticList_.addItem("TLS_DH_DSS_WITH_SEED_CBC_SHA"                , 151);
            staticList_.addItem("TLS_DH_RSA_WITH_SEED_CBC_SHA"                , 152);
            staticList_.addItem("TLS_DHE_DSS_WITH_SEED_CBC_SHA"               , 153);
            staticList_.addItem("TLS_DHE_RSA_WITH_SEED_CBC_SHA"               , 154);
            staticList_.addItem("TLS_DH_anon_WITH_SEED_CBC_SHA"               , 155);
            staticList_.addItem("TLS_RSA_WITH_AES_128_GCM_SHA256"             , 156);
            staticList_.addItem("TLS_RSA_WITH_AES_256_GCM_SHA384"             , 157);
            staticList_.addItem("TLS_DHE_RSA_WITH_AES_128_GCM_SHA256"         , 158);
            staticList_.addItem("TLS_DHE_RSA_WITH_AES_256_GCM_SHA384"         , 159);
            staticList_.addItem("TLS_DH_RSA_WITH_AES_128_GCM_SHA256"          , 160);
            staticList_.addItem("TLS_DH_RSA_WITH_AES_256_GCM_SHA384"          , 161);
            staticList_.addItem("TLS_DHE_DSS_WITH_AES_128_GCM_SHA256"         , 162);
            staticList_.addItem("TLS_DHE_DSS_WITH_AES_256_GCM_SHA384"         , 163);
            staticList_.addItem("TLS_DH_DSS_WITH_AES_128_GCM_SHA256"          , 164);
            staticList_.addItem("TLS_DH_DSS_WITH_AES_256_GCM_SHA384"          , 165);
            staticList_.addItem("TLS_DH_anon_WITH_AES_128_GCM_SHA256"         , 166);
            staticList_.addItem("TLS_DH_anon_WITH_AES_256_GCM_SHA384"         , 167);
            staticList_.addItem("TLS_PSK_WITH_AES_128_GCM_SHA256"             , 168);
            staticList_.addItem("TLS_PSK_WITH_AES_256_GCM_SHA384"             , 169);
            staticList_.addItem("TLS_DHE_PSK_WITH_AES_128_GCM_SHA256"         , 170);
            staticList_.addItem("TLS_DHE_PSK_WITH_AES_256_GCM_SHA384"         , 171);
            staticList_.addItem("TLS_RSA_PSK_WITH_AES_128_GCM_SHA256"         , 172);
            staticList_.addItem("TLS_RSA_PSK_WITH_AES_256_GCM_SHA384"         , 173);
            staticList_.addItem("TLS_PSK_WITH_AES_128_CBC_SHA256"             , 174);
            staticList_.addItem("TLS_PSK_WITH_AES_256_CBC_SHA384"             , 175);
            staticList_.addItem("TLS_PSK_WITH_NULL_SHA256"                    , 176);
            staticList_.addItem("TLS_PSK_WITH_NULL_SHA384"                    , 177);
            staticList_.addItem("TLS_DHE_PSK_WITH_AES_128_CBC_SHA256"         , 178);
            staticList_.addItem("TLS_DHE_PSK_WITH_AES_256_CBC_SHA384"         , 179);
            staticList_.addItem("TLS_DHE_PSK_WITH_NULL_SHA256"                , 180);
            staticList_.addItem("TLS_DHE_PSK_WITH_NULL_SHA384"                , 181);
            staticList_.addItem("TLS_RSA_PSK_WITH_AES_128_CBC_SHA256"         , 182);
            staticList_.addItem("TLS_RSA_PSK_WITH_AES_256_CBC_SHA384"         , 183);
            staticList_.addItem("TLS_RSA_PSK_WITH_NULL_SHA256"                , 184);
            staticList_.addItem("TLS_RSA_PSK_WITH_NULL_SHA384"                , 185);
            staticList_.addItem("TLS_RSA_WITH_CAMELLIA_128_CBC_SHA256"        , 186);
            staticList_.addItem("TLS_DH_DSS_WITH_CAMELLIA_128_CBC_SHA256"     , 187);
            staticList_.addItem("TLS_DH_RSA_WITH_CAMELLIA_128_CBC_SHA256"     , 188);
            staticList_.addItem("TLS_DHE_DSS_WITH_CAMELLIA_128_CBC_SHA256"    , 189);
            staticList_.addItem("TLS_DHE_RSA_WITH_CAMELLIA_128_CBC_SHA256"    , 190);
            staticList_.addItem("TLS_DH_anon_WITH_CAMELLIA_128_CBC_SHA256"    , 191);
            staticList_.addItem("TLS_RSA_WITH_CAMELLIA_256_CBC_SHA256"        , 192);
            staticList_.addItem("TLS_DH_DSS_WITH_CAMELLIA_256_CBC_SHA256"     , 193);
            staticList_.addItem("TLS_DH_RSA_WITH_CAMELLIA_256_CBC_SHA256"     , 194);
            staticList_.addItem("TLS_DHE_DSS_WITH_CAMELLIA_256_CBC_SHA256"    , 195);
            staticList_.addItem("TLS_DHE_RSA_WITH_CAMELLIA_256_CBC_SHA256"    , 196);
            staticList_.addItem("TLS_DH_anon_WITH_CAMELLIA_256_CBC_SHA256"    , 197);
            staticList_.addItem("TLS_EMPTY_RENEGOTIATION_INFO_SCSV"           , 255);
            staticList_.addItem("TLS_FALLBACK_SCSV"                           , 22016);
            staticList_.addItem("TLS_ECDH_ECDSA_WITH_NULL_SHA"                , 49153);
            staticList_.addItem("TLS_ECDH_ECDSA_WITH_RC4_128_SHA"             , 49154);
            staticList_.addItem("TLS_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA"        , 49155);
            staticList_.addItem("TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA"         , 49156);
            staticList_.addItem("TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA"         , 49157);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_NULL_SHA"               , 49158);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_RC4_128_SHA"            , 49159);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA"       , 49160);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA"        , 49161);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA"        , 49162);
            staticList_.addItem("TLS_ECDH_RSA_WITH_NULL_SHA"                  , 49163);
            staticList_.addItem("TLS_ECDH_RSA_WITH_RC4_128_SHA"               , 49164);
            staticList_.addItem("TLS_ECDH_RSA_WITH_3DES_EDE_CBC_SHA"          , 49165);
            staticList_.addItem("TLS_ECDH_RSA_WITH_AES_128_CBC_SHA"           , 49166);
            staticList_.addItem("TLS_ECDH_RSA_WITH_AES_256_CBC_SHA"           , 49167);
            staticList_.addItem("TLS_ECDHE_RSA_WITH_NULL_SHA"                 , 49168);
            staticList_.addItem("TLS_ECDHE_RSA_WITH_RC4_128_SHA"              , 49169);
            staticList_.addItem("TLS_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA"         , 49170);
            staticList_.addItem("TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA"          , 49171);
            staticList_.addItem("TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA"          , 49172);
            staticList_.addItem("TLS_ECDH_anon_WITH_NULL_SHA"                 , 49173);
            staticList_.addItem("TLS_ECDH_anon_WITH_RC4_128_SHA"              , 49174);
            staticList_.addItem("TLS_ECDH_anon_WITH_3DES_EDE_CBC_SHA"         , 49175);
            staticList_.addItem("TLS_ECDH_anon_WITH_AES_128_CBC_SHA"          , 49176);
            staticList_.addItem("TLS_ECDH_anon_WITH_AES_256_CBC_SHA"          , 49177);
            staticList_.addItem("TLS_SRP_SHA_WITH_3DES_EDE_CBC_SHA"           , 49178);
            staticList_.addItem("TLS_SRP_SHA_RSA_WITH_3DES_EDE_CBC_SHA"       , 49179);
            staticList_.addItem("TLS_SRP_SHA_DSS_WITH_3DES_EDE_CBC_SHA"       , 49180);
            staticList_.addItem("TLS_SRP_SHA_WITH_AES_128_CBC_SHA"            , 49181);
            staticList_.addItem("TLS_SRP_SHA_RSA_WITH_AES_128_CBC_SHA"        , 49182);
            staticList_.addItem("TLS_SRP_SHA_DSS_WITH_AES_128_CBC_SHA"        , 49183);
            staticList_.addItem("TLS_SRP_SHA_WITH_AES_256_CBC_SHA"            , 49184);
            staticList_.addItem("TLS_SRP_SHA_RSA_WITH_AES_256_CBC_SHA"        , 49185);
            staticList_.addItem("TLS_SRP_SHA_DSS_WITH_AES_256_CBC_SHA"        , 49186);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256"     , 49187);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384"     , 49188);
            staticList_.addItem("TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256"      , 49189);
            staticList_.addItem("TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA384"      , 49190);
            staticList_.addItem("TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256"       , 49191);
            staticList_.addItem("TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384"       , 49192);
            staticList_.addItem("TLS_ECDH_RSA_WITH_AES_128_CBC_SHA256"        , 49193);
            staticList_.addItem("TLS_ECDH_RSA_WITH_AES_256_CBC_SHA384"        , 49194);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256"     , 49195);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384"     , 49196);
            staticList_.addItem("TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256"      , 49197);
            staticList_.addItem("TLS_ECDH_ECDSA_WITH_AES_256_GCM_SHA384"      , 49198);
            staticList_.addItem("TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256"       , 49199);
            staticList_.addItem("TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384"       , 49200);
            staticList_.addItem("TLS_ECDH_RSA_WITH_AES_128_GCM_SHA256"        , 49201);
            staticList_.addItem("TLS_ECDH_RSA_WITH_AES_256_GCM_SHA384"        , 49202);
            staticList_.addItem("TLS_ECDHE_PSK_WITH_RC4_128_SHA"              , 49203);
            staticList_.addItem("TLS_ECDHE_PSK_WITH_3DES_EDE_CBC_SHA"         , 49204);
            staticList_.addItem("TLS_ECDHE_PSK_WITH_AES_128_CBC_SHA"          , 49205);
            staticList_.addItem("TLS_ECDHE_PSK_WITH_AES_256_CBC_SHA"          , 49206);
            staticList_.addItem("TLS_ECDHE_PSK_WITH_AES_128_CBC_SHA256"       , 49207);
            staticList_.addItem("TLS_ECDHE_PSK_WITH_AES_256_CBC_SHA384"       , 49208);
            staticList_.addItem("TLS_ECDHE_PSK_WITH_NULL_SHA"                 , 49209);
            staticList_.addItem("TLS_ECDHE_PSK_WITH_NULL_SHA256"              , 49210);
            staticList_.addItem("TLS_ECDHE_PSK_WITH_NULL_SHA384"              , 49211);
            staticList_.addItem("TLS_RSA_WITH_ARIA_128_CBC_SHA256"            , 49212);
            staticList_.addItem("TLS_RSA_WITH_ARIA_256_CBC_SHA384"            , 49213);
            staticList_.addItem("TLS_DH_DSS_WITH_ARIA_128_CBC_SHA256"         , 49214);
            staticList_.addItem("TLS_DH_DSS_WITH_ARIA_256_CBC_SHA384"         , 49215);
            staticList_.addItem("TLS_DH_RSA_WITH_ARIA_128_CBC_SHA256"         , 49216);
            staticList_.addItem("TLS_DH_RSA_WITH_ARIA_256_CBC_SHA384"         , 49217);
            staticList_.addItem("TLS_DHE_DSS_WITH_ARIA_128_CBC_SHA256"        , 49218);
            staticList_.addItem("TLS_DHE_DSS_WITH_ARIA_256_CBC_SHA384"        , 49219);
            staticList_.addItem("TLS_DHE_RSA_WITH_ARIA_128_CBC_SHA256"        , 49220);
            staticList_.addItem("TLS_DHE_RSA_WITH_ARIA_256_CBC_SHA384"        , 49221);
            staticList_.addItem("TLS_DH_anon_WITH_ARIA_128_CBC_SHA256"        , 49222);
            staticList_.addItem("TLS_DH_anon_WITH_ARIA_256_CBC_SHA384"        , 49223);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_ARIA_128_CBC_SHA256"    , 49224);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_ARIA_256_CBC_SHA384"    , 49225);
            staticList_.addItem("TLS_ECDH_ECDSA_WITH_ARIA_128_CBC_SHA256"     , 49226);
            staticList_.addItem("TLS_ECDH_ECDSA_WITH_ARIA_256_CBC_SHA384"     , 49227);
            staticList_.addItem("TLS_ECDHE_RSA_WITH_ARIA_128_CBC_SHA256"      , 49228);
            staticList_.addItem("TLS_ECDHE_RSA_WITH_ARIA_256_CBC_SHA384"      , 49229);
            staticList_.addItem("TLS_ECDH_RSA_WITH_ARIA_128_CBC_SHA256"       , 49230);
            staticList_.addItem("TLS_ECDH_RSA_WITH_ARIA_256_CBC_SHA384"       , 49231);
            staticList_.addItem("TLS_RSA_WITH_ARIA_128_GCM_SHA256"            , 49232);
            staticList_.addItem("TLS_RSA_WITH_ARIA_256_GCM_SHA384"            , 49233);
            staticList_.addItem("TLS_DHE_RSA_WITH_ARIA_128_GCM_SHA256"        , 49234);
            staticList_.addItem("TLS_DHE_RSA_WITH_ARIA_256_GCM_SHA384"        , 49235);
            staticList_.addItem("TLS_DH_RSA_WITH_ARIA_128_GCM_SHA256"         , 49236);
            staticList_.addItem("TLS_DH_RSA_WITH_ARIA_256_GCM_SHA384"         , 49237);
            staticList_.addItem("TLS_DHE_DSS_WITH_ARIA_128_GCM_SHA256"        , 49238);
            staticList_.addItem("TLS_DHE_DSS_WITH_ARIA_256_GCM_SHA384"        , 49239);
            staticList_.addItem("TLS_DH_DSS_WITH_ARIA_128_GCM_SHA256"         , 49240);
            staticList_.addItem("TLS_DH_DSS_WITH_ARIA_256_GCM_SHA384"         , 49241);
            staticList_.addItem("TLS_DH_anon_WITH_ARIA_128_GCM_SHA256"        , 49242);
            staticList_.addItem("TLS_DH_anon_WITH_ARIA_256_GCM_SHA384"        , 49243);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_ARIA_128_GCM_SHA256"    , 49244);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_ARIA_256_GCM_SHA384"    , 49245);
            staticList_.addItem("TLS_ECDH_ECDSA_WITH_ARIA_128_GCM_SHA256"     , 49246);
            staticList_.addItem("TLS_ECDH_ECDSA_WITH_ARIA_256_GCM_SHA384"     , 49247);
            staticList_.addItem("TLS_ECDHE_RSA_WITH_ARIA_128_GCM_SHA256"      , 49248);
            staticList_.addItem("TLS_ECDHE_RSA_WITH_ARIA_256_GCM_SHA384"      , 49249);
            staticList_.addItem("TLS_ECDH_RSA_WITH_ARIA_128_GCM_SHA256"       , 49250);
            staticList_.addItem("TLS_ECDH_RSA_WITH_ARIA_256_GCM_SHA384"       , 49251);
            staticList_.addItem("TLS_PSK_WITH_ARIA_128_CBC_SHA256"            , 49252);
            staticList_.addItem("TLS_PSK_WITH_ARIA_256_CBC_SHA384"            , 49253);
            staticList_.addItem("TLS_DHE_PSK_WITH_ARIA_128_CBC_SHA256"        , 49254);
            staticList_.addItem("TLS_DHE_PSK_WITH_ARIA_256_CBC_SHA384"        , 49255);
            staticList_.addItem("TLS_RSA_PSK_WITH_ARIA_128_CBC_SHA256"        , 49256);
            staticList_.addItem("TLS_RSA_PSK_WITH_ARIA_256_CBC_SHA384"        , 49257);
            staticList_.addItem("TLS_PSK_WITH_ARIA_128_GCM_SHA256"            , 49258);
            staticList_.addItem("TLS_PSK_WITH_ARIA_256_GCM_SHA384"            , 49259);
            staticList_.addItem("TLS_DHE_PSK_WITH_ARIA_128_GCM_SHA256"        , 49260);
            staticList_.addItem("TLS_DHE_PSK_WITH_ARIA_256_GCM_SHA384"        , 49261);
            staticList_.addItem("TLS_RSA_PSK_WITH_ARIA_128_GCM_SHA256"        , 49262);
            staticList_.addItem("TLS_RSA_PSK_WITH_ARIA_256_GCM_SHA384"        , 49263);
            staticList_.addItem("TLS_ECDHE_PSK_WITH_ARIA_128_CBC_SHA256"      , 49264);
            staticList_.addItem("TLS_ECDHE_PSK_WITH_ARIA_256_CBC_SHA384"      , 49265);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_CAMELLIA_128_CBC_SHA256", 49266);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_CAMELLIA_256_CBC_SHA384", 49267);
            staticList_.addItem("TLS_ECDH_ECDSA_WITH_CAMELLIA_128_CBC_SHA256" , 49268);
            staticList_.addItem("TLS_ECDH_ECDSA_WITH_CAMELLIA_256_CBC_SHA384" , 49269);
            staticList_.addItem("TLS_ECDHE_RSA_WITH_CAMELLIA_128_CBC_SHA256"  , 49270);
            staticList_.addItem("TLS_ECDHE_RSA_WITH_CAMELLIA_256_CBC_SHA384"  , 49271);
            staticList_.addItem("TLS_ECDH_RSA_WITH_CAMELLIA_128_CBC_SHA256"   , 49272);
            staticList_.addItem("TLS_ECDH_RSA_WITH_CAMELLIA_256_CBC_SHA384"   , 49273);
            staticList_.addItem("TLS_RSA_WITH_CAMELLIA_128_GCM_SHA256"        , 49274);
            staticList_.addItem("TLS_RSA_WITH_CAMELLIA_256_GCM_SHA384"        , 49275);
            staticList_.addItem("TLS_DHE_RSA_WITH_CAMELLIA_128_GCM_SHA256"    , 49276);
            staticList_.addItem("TLS_DHE_RSA_WITH_CAMELLIA_256_GCM_SHA384"    , 49277);
            staticList_.addItem("TLS_DH_RSA_WITH_CAMELLIA_128_GCM_SHA256"     , 49278);
            staticList_.addItem("TLS_DH_RSA_WITH_CAMELLIA_256_GCM_SHA384"     , 49279);
            staticList_.addItem("TLS_DHE_DSS_WITH_CAMELLIA_128_GCM_SHA256"    , 49280);
            staticList_.addItem("TLS_DHE_DSS_WITH_CAMELLIA_256_GCM_SHA384"    , 49281);
            staticList_.addItem("TLS_DH_DSS_WITH_CAMELLIA_128_GCM_SHA256"     , 49282);
            staticList_.addItem("TLS_DH_DSS_WITH_CAMELLIA_256_GCM_SHA384"     , 49283);
            staticList_.addItem("TLS_DH_anon_WITH_CAMELLIA_128_GCM_SHA256"    , 49284);
            staticList_.addItem("TLS_DH_anon_WITH_CAMELLIA_256_GCM_SHA384"    , 49285);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_CAMELLIA_128_GCM_SHA256", 49286);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_CAMELLIA_256_GCM_SHA384", 49287);
            staticList_.addItem("TLS_ECDH_ECDSA_WITH_CAMELLIA_128_GCM_SHA256" , 49288);
            staticList_.addItem("TLS_ECDH_ECDSA_WITH_CAMELLIA_256_GCM_SHA384" , 49289);
            staticList_.addItem("TLS_ECDHE_RSA_WITH_CAMELLIA_128_GCM_SHA256"  , 49290);
            staticList_.addItem("TLS_ECDHE_RSA_WITH_CAMELLIA_256_GCM_SHA384"  , 49291);
            staticList_.addItem("TLS_ECDH_RSA_WITH_CAMELLIA_128_GCM_SHA256"   , 49292);
            staticList_.addItem("TLS_ECDH_RSA_WITH_CAMELLIA_256_GCM_SHA384"   , 49293);
            staticList_.addItem("TLS_PSK_WITH_CAMELLIA_128_GCM_SHA256"        , 49294);
            staticList_.addItem("TLS_PSK_WITH_CAMELLIA_256_GCM_SHA384"        , 49295);
            staticList_.addItem("TLS_DHE_PSK_WITH_CAMELLIA_128_GCM_SHA256"    , 49296);
            staticList_.addItem("TLS_DHE_PSK_WITH_CAMELLIA_256_GCM_SHA384"    , 49297);
            staticList_.addItem("TLS_RSA_PSK_WITH_CAMELLIA_128_GCM_SHA256"    , 49298);
            staticList_.addItem("TLS_RSA_PSK_WITH_CAMELLIA_256_GCM_SHA384"    , 49299);
            staticList_.addItem("TLS_PSK_WITH_CAMELLIA_128_CBC_SHA256"        , 49300);
            staticList_.addItem("TLS_PSK_WITH_CAMELLIA_256_CBC_SHA384"        , 49301);
            staticList_.addItem("TLS_DHE_PSK_WITH_CAMELLIA_128_CBC_SHA256"    , 49302);
            staticList_.addItem("TLS_DHE_PSK_WITH_CAMELLIA_256_CBC_SHA384"    , 49303);
            staticList_.addItem("TLS_RSA_PSK_WITH_CAMELLIA_128_CBC_SHA256"    , 49304);
            staticList_.addItem("TLS_RSA_PSK_WITH_CAMELLIA_256_CBC_SHA384"    , 49305);
            staticList_.addItem("TLS_ECDHE_PSK_WITH_CAMELLIA_128_CBC_SHA256"  , 49306);
            staticList_.addItem("TLS_ECDHE_PSK_WITH_CAMELLIA_256_CBC_SHA384"  , 49307);
            staticList_.addItem("TLS_RSA_WITH_AES_128_CCM"                    , 49308);
            staticList_.addItem("TLS_RSA_WITH_AES_256_CCM"                    , 49309);
            staticList_.addItem("TLS_DHE_RSA_WITH_AES_128_CCM"                , 49310);
            staticList_.addItem("TLS_DHE_RSA_WITH_AES_256_CCM"                , 49311);
            staticList_.addItem("TLS_RSA_WITH_AES_128_CCM_8"                  , 49312);
            staticList_.addItem("TLS_RSA_WITH_AES_256_CCM_8"                  , 49313);
            staticList_.addItem("TLS_DHE_RSA_WITH_AES_128_CCM_8"              , 49314);
            staticList_.addItem("TLS_DHE_RSA_WITH_AES_256_CCM_8"              , 49315);
            staticList_.addItem("TLS_PSK_WITH_AES_128_CCM"                    , 49316);
            staticList_.addItem("TLS_PSK_WITH_AES_256_CCM"                    , 49317);
            staticList_.addItem("TLS_DHE_PSK_WITH_AES_128_CCM"                , 49318);
            staticList_.addItem("TLS_DHE_PSK_WITH_AES_256_CCM"                , 49319);
            staticList_.addItem("TLS_PSK_WITH_AES_128_CCM_8"                  , 49320);
            staticList_.addItem("TLS_PSK_WITH_AES_256_CCM_8"                  , 49321);
            staticList_.addItem("TLS_PSK_DHE_WITH_AES_128_CCM_8"              , 49322);
            staticList_.addItem("TLS_PSK_DHE_WITH_AES_256_CCM_8"              , 49323);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_AES_128_CCM"            , 49324);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_AES_256_CCM"            , 49325);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_AES_128_CCM_8"          , 49326);
            staticList_.addItem("TLS_ECDHE_ECDSA_WITH_AES_256_CCM_8"          , 49327);
            staticList_.addFallbackItem("unknown");
        }
    }


    /* Function to create another instance of class "TEnum_CipherSuite" */
    TEnum_CipherSuite* newInstance_() const {

        TEnum_CipherSuite* du = new TEnum_CipherSuite();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_CipherSuite" */
EnumerationItemList TEnum_CipherSuite::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_ClientHello_cipher_suites" corresponding to Struct "ClientHello_cipher_suites" */
class TStruct_ClientHello_cipher_suites : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ClientHello_cipher_suites" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 245, "ClientHello_cipher_suites");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ClientHello_cipher_suites" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ClientHello_cipher_suites" */
    TStruct_ClientHello_cipher_suites() : CompositeDataUnit() {

        this->setName("ClientHello_cipher_suites");
    }


    /* Function to create another instance of class "TStruct_ClientHello_cipher_suites" */
    TStruct_ClientHello_cipher_suites* newInstance_() const {

        TStruct_ClientHello_cipher_suites* du = new TStruct_ClientHello_cipher_suites();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TEnum_CipherSuite* _M1_V = new TEnum_CipherSuite();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_DTLSClientHello_cipher_suites" corresponding to Struct "DTLSClientHello_cipher_suites" */
class TStruct_DTLSClientHello_cipher_suites : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_DTLSClientHello_cipher_suites" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 246, "DTLSClientHello_cipher_suites");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_DTLSClientHello_cipher_suites" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_DTLSClientHello_cipher_suites" */
    TStruct_DTLSClientHello_cipher_suites() : CompositeDataUnit() {

        this->setName("DTLSClientHello_cipher_suites");
    }


    /* Function to create another instance of class "TStruct_DTLSClientHello_cipher_suites" */
    TStruct_DTLSClientHello_cipher_suites* newInstance_() const {

        TStruct_DTLSClientHello_cipher_suites* du = new TStruct_DTLSClientHello_cipher_suites();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TEnum_CipherSuite* _M1_V = new TEnum_CipherSuite();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_Signature_signature" corresponding to Struct "Signature_signature" */
class TStruct_Signature_signature : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Signature_signature" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 247, "Signature_signature");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Signature_signature" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Signature_signature" */
    TStruct_Signature_signature() : CompositeDataUnit() {

        this->setName("Signature_signature");
    }


    /* Function to create another instance of class "TStruct_Signature_signature" */
    TStruct_Signature_signature* newInstance_() const {

        TStruct_Signature_signature* du = new TStruct_Signature_signature();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_ASN1SequenceOfIntegers_tag" corresponding to Enum "ASN1SequenceOfIntegers_tag" */
class TEnum_ASN1SequenceOfIntegers_tag : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_ASN1SequenceOfIntegers_tag" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 248, "ASN1SequenceOfIntegers_tag");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_ASN1SequenceOfIntegers_tag" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_ASN1SequenceOfIntegers_tag" */
    TEnum_ASN1SequenceOfIntegers_tag() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("ASN1SequenceOfIntegers_tag");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("sequence", 48);
        }
    }


    /* Function to create another instance of class "TEnum_ASN1SequenceOfIntegers_tag" */
    TEnum_ASN1SequenceOfIntegers_tag* newInstance_() const {

        TEnum_ASN1SequenceOfIntegers_tag* du = new TEnum_ASN1SequenceOfIntegers_tag();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_ASN1SequenceOfIntegers_tag" */
EnumerationItemList TEnum_ASN1SequenceOfIntegers_tag::staticList_;


/* ========================================================================= */

/* Definition of class "TEnum_ASN1Integer_tag" corresponding to Enum "ASN1Integer_tag" */
class TEnum_ASN1Integer_tag : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_ASN1Integer_tag" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 249, "ASN1Integer_tag");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_ASN1Integer_tag" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_ASN1Integer_tag" */
    TEnum_ASN1Integer_tag() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("ASN1Integer_tag");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("integer", 2);
        }
    }


    /* Function to create another instance of class "TEnum_ASN1Integer_tag" */
    TEnum_ASN1Integer_tag* newInstance_() const {

        TEnum_ASN1Integer_tag* du = new TEnum_ASN1Integer_tag();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_ASN1Integer_tag" */
EnumerationItemList TEnum_ASN1Integer_tag::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_ASN1Integer_int" corresponding to Struct "ASN1Integer_int" */
class TStruct_ASN1Integer_int : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ASN1Integer_int" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 250, "ASN1Integer_int");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ASN1Integer_int" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ASN1Integer_int" */
    TStruct_ASN1Integer_int() : CompositeDataUnit() {

        this->setName("ASN1Integer_int");
    }


    /* Function to create another instance of class "TStruct_ASN1Integer_int" */
    TStruct_ASN1Integer_int* newInstance_() const {

        TStruct_ASN1Integer_int* du = new TStruct_ASN1Integer_int();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ASN1Integer" corresponding to Struct "ASN1Integer" */
class TStruct_ASN1Integer : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ASN1Integer" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 251, "ASN1Integer");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ASN1Integer" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ASN1Integer" */
    TStruct_ASN1Integer() : CompositeDataUnit() {

        this->setName("ASN1Integer");
    }


    /* Function to create another instance of class "TStruct_ASN1Integer" */
    TStruct_ASN1Integer* newInstance_() const {

        TStruct_ASN1Integer* du = new TStruct_ASN1Integer();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "tag" ===== */
            TEnum_ASN1Integer_tag* _M0 = new TEnum_ASN1Integer_tag();
            this->appendChildRenamed(_M0, "tag");
            /* ===== Struct member "int" ===== */
            TStruct_ASN1Integer_int* _M1 = new TStruct_ASN1Integer_int();
            this->appendChildRenamed(_M1, "int");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ASN1SequenceOfIntegers_ints" corresponding to Struct "ASN1SequenceOfIntegers_ints" */
class TStruct_ASN1SequenceOfIntegers_ints : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ASN1SequenceOfIntegers_ints" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 252, "ASN1SequenceOfIntegers_ints");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ASN1SequenceOfIntegers_ints" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ASN1SequenceOfIntegers_ints" */
    TStruct_ASN1SequenceOfIntegers_ints() : CompositeDataUnit() {

        this->setName("ASN1SequenceOfIntegers_ints");
    }


    /* Function to create another instance of class "TStruct_ASN1SequenceOfIntegers_ints" */
    TStruct_ASN1SequenceOfIntegers_ints* newInstance_() const {

        TStruct_ASN1SequenceOfIntegers_ints* du = new TStruct_ASN1SequenceOfIntegers_ints();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TStruct_ASN1Integer* _M1_V = new TStruct_ASN1Integer();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ASN1SequenceOfIntegers" corresponding to Struct "ASN1SequenceOfIntegers" */
class TStruct_ASN1SequenceOfIntegers : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ASN1SequenceOfIntegers" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 253, "ASN1SequenceOfIntegers");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ASN1SequenceOfIntegers" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ASN1SequenceOfIntegers" */
    TStruct_ASN1SequenceOfIntegers() : CompositeDataUnit() {

        this->setName("ASN1SequenceOfIntegers");
    }


    /* Function to create another instance of class "TStruct_ASN1SequenceOfIntegers" */
    TStruct_ASN1SequenceOfIntegers* newInstance_() const {

        TStruct_ASN1SequenceOfIntegers* du = new TStruct_ASN1SequenceOfIntegers();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "tag" ===== */
            TEnum_ASN1SequenceOfIntegers_tag* _M0 = new TEnum_ASN1SequenceOfIntegers_tag();
            this->appendChildRenamed(_M0, "tag");
            /* ===== Struct member "ints" ===== */
            TStruct_ASN1SequenceOfIntegers_ints* _M1 = new TStruct_ASN1SequenceOfIntegers_ints();
            this->appendChildRenamed(_M1, "ints");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ECDSASignature" corresponding to Struct "ECDSASignature" */
class TStruct_ECDSASignature : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ECDSASignature" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 254, "ECDSASignature");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ECDSASignature" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ECDSASignature" */
    TStruct_ECDSASignature() : CompositeDataUnit() {

        this->setName("ECDSASignature");
    }


    /* Function to create another instance of class "TStruct_ECDSASignature" */
    TStruct_ECDSASignature* newInstance_() const {

        TStruct_ECDSASignature* du = new TStruct_ECDSASignature();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "rs" ===== */
            TStruct_ASN1SequenceOfIntegers* _M0 = new TStruct_ASN1SequenceOfIntegers();
            this->appendChildRenamed(_M0, "rs");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ClientKeyExchange" corresponding to Struct "ClientKeyExchange" */
class TStruct_ClientKeyExchange : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ClientKeyExchange" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 255, "ClientKeyExchange");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ClientKeyExchange" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ClientKeyExchange" */
    TStruct_ClientKeyExchange() : CompositeDataUnit() {

        this->setName("ClientKeyExchange");
    }


    /* Function to create another instance of class "TStruct_ClientKeyExchange" */
    TStruct_ClientKeyExchange* newInstance_() const {

        TStruct_ClientKeyExchange* du = new TStruct_ClientKeyExchange();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "length" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "length");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "content" ===== */
            int _value_length = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value_length, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "content");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: length <--- f(content) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ECParameters_explicit_prime_prime_p" corresponding to Struct "ECParameters_explicit_prime_prime_p" */
class TStruct_ECParameters_explicit_prime_prime_p : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ECParameters_explicit_prime_prime_p" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 256, "ECParameters_explicit_prime_prime_p");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ECParameters_explicit_prime_prime_p" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ECParameters_explicit_prime_prime_p" */
    TStruct_ECParameters_explicit_prime_prime_p() : CompositeDataUnit() {

        this->setName("ECParameters_explicit_prime_prime_p");
    }


    /* Function to create another instance of class "TStruct_ECParameters_explicit_prime_prime_p" */
    TStruct_ECParameters_explicit_prime_prime_p* newInstance_() const {

        TStruct_ECParameters_explicit_prime_prime_p* du = new TStruct_ECParameters_explicit_prime_prime_p();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ECParameters_explicit_prime_order" corresponding to Struct "ECParameters_explicit_prime_order" */
class TStruct_ECParameters_explicit_prime_order : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ECParameters_explicit_prime_order" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 257, "ECParameters_explicit_prime_order");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ECParameters_explicit_prime_order" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ECParameters_explicit_prime_order" */
    TStruct_ECParameters_explicit_prime_order() : CompositeDataUnit() {

        this->setName("ECParameters_explicit_prime_order");
    }


    /* Function to create another instance of class "TStruct_ECParameters_explicit_prime_order" */
    TStruct_ECParameters_explicit_prime_order* newInstance_() const {

        TStruct_ECParameters_explicit_prime_order* du = new TStruct_ECParameters_explicit_prime_order();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ECParameters_explicit_prime_cofactor" corresponding to Struct "ECParameters_explicit_prime_cofactor" */
class TStruct_ECParameters_explicit_prime_cofactor : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ECParameters_explicit_prime_cofactor" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 258, "ECParameters_explicit_prime_cofactor");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ECParameters_explicit_prime_cofactor" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ECParameters_explicit_prime_cofactor" */
    TStruct_ECParameters_explicit_prime_cofactor() : CompositeDataUnit() {

        this->setName("ECParameters_explicit_prime_cofactor");
    }


    /* Function to create another instance of class "TStruct_ECParameters_explicit_prime_cofactor" */
    TStruct_ECParameters_explicit_prime_cofactor* newInstance_() const {

        TStruct_ECParameters_explicit_prime_cofactor* du = new TStruct_ECParameters_explicit_prime_cofactor();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ECCurve_a" corresponding to Struct "ECCurve_a" */
class TStruct_ECCurve_a : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ECCurve_a" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 259, "ECCurve_a");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ECCurve_a" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ECCurve_a" */
    TStruct_ECCurve_a() : CompositeDataUnit() {

        this->setName("ECCurve_a");
    }


    /* Function to create another instance of class "TStruct_ECCurve_a" */
    TStruct_ECCurve_a* newInstance_() const {

        TStruct_ECCurve_a* du = new TStruct_ECCurve_a();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ECCurve_b" corresponding to Struct "ECCurve_b" */
class TStruct_ECCurve_b : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ECCurve_b" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 260, "ECCurve_b");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ECCurve_b" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ECCurve_b" */
    TStruct_ECCurve_b() : CompositeDataUnit() {

        this->setName("ECCurve_b");
    }


    /* Function to create another instance of class "TStruct_ECCurve_b" */
    TStruct_ECCurve_b* newInstance_() const {

        TStruct_ECCurve_b* du = new TStruct_ECCurve_b();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ECCurve" corresponding to Struct "ECCurve" */
class TStruct_ECCurve : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ECCurve" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 261, "ECCurve");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ECCurve" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ECCurve" */
    TStruct_ECCurve() : CompositeDataUnit() {

        this->setName("ECCurve");
    }


    /* Function to create another instance of class "TStruct_ECCurve" */
    TStruct_ECCurve* newInstance_() const {

        TStruct_ECCurve* du = new TStruct_ECCurve();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "a" ===== */
            TStruct_ECCurve_a* _M0 = new TStruct_ECCurve_a();
            this->appendChildRenamed(_M0, "a");
            /* ===== Struct member "b" ===== */
            TStruct_ECCurve_b* _M1 = new TStruct_ECCurve_b();
            this->appendChildRenamed(_M1, "b");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_ECCurveType" corresponding to Enum "ECCurveType" */
class TEnum_ECCurveType : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_ECCurveType" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 262, "ECCurveType");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_ECCurveType" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_ECCurveType" */
    TEnum_ECCurveType() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("ECCurveType");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("explicit_prime", 1);
            staticList_.addItem("explicit_char2", 2);
            staticList_.addItem("named_curve"   , 3);
            staticList_.addFallbackItem("unknown");
        }
    }


    /* Function to create another instance of class "TEnum_ECCurveType" */
    TEnum_ECCurveType* newInstance_() const {

        TEnum_ECCurveType* du = new TEnum_ECCurveType();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_ECCurveType" */
EnumerationItemList TEnum_ECCurveType::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_ECPoint_point" corresponding to Struct "ECPoint_point" */
class TStruct_ECPoint_point : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ECPoint_point" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 263, "ECPoint_point");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ECPoint_point" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ECPoint_point" */
    TStruct_ECPoint_point() : CompositeDataUnit() {

        this->setName("ECPoint_point");
    }


    /* Function to create another instance of class "TStruct_ECPoint_point" */
    TStruct_ECPoint_point* newInstance_() const {

        TStruct_ECPoint_point* du = new TStruct_ECPoint_point();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ECPoint" corresponding to Struct "ECPoint" */
class TStruct_ECPoint : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ECPoint" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 264, "ECPoint");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ECPoint" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ECPoint" */
    TStruct_ECPoint() : CompositeDataUnit() {

        this->setName("ECPoint");
    }


    /* Function to create another instance of class "TStruct_ECPoint" */
    TStruct_ECPoint* newInstance_() const {

        TStruct_ECPoint* du = new TStruct_ECPoint();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "point" ===== */
            TStruct_ECPoint_point* _M0 = new TStruct_ECPoint_point();
            this->appendChildRenamed(_M0, "point");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ECParameters_explicit_prime" corresponding to Struct "ECParameters_explicit_prime" */
class TStruct_ECParameters_explicit_prime : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ECParameters_explicit_prime" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 265, "ECParameters_explicit_prime");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ECParameters_explicit_prime" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ECParameters_explicit_prime" */
    TStruct_ECParameters_explicit_prime() : CompositeDataUnit() {

        this->setName("ECParameters_explicit_prime");
    }


    /* Function to create another instance of class "TStruct_ECParameters_explicit_prime" */
    TStruct_ECParameters_explicit_prime* newInstance_() const {

        TStruct_ECParameters_explicit_prime* du = new TStruct_ECParameters_explicit_prime();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "prime_p" ===== */
            TStruct_ECParameters_explicit_prime_prime_p* _M0 = new TStruct_ECParameters_explicit_prime_prime_p();
            this->appendChildRenamed(_M0, "prime_p");
            /* ===== Struct member "curve" ===== */
            TStruct_ECCurve* _M1 = new TStruct_ECCurve();
            this->appendChildRenamed(_M1, "curve");
            /* ===== Struct member "base" ===== */
            TStruct_ECPoint* _M2 = new TStruct_ECPoint();
            this->appendChildRenamed(_M2, "base");
            /* ===== Struct member "order" ===== */
            TStruct_ECParameters_explicit_prime_order* _M3 = new TStruct_ECParameters_explicit_prime_order();
            this->appendChildRenamed(_M3, "order");
            /* ===== Struct member "cofactor" ===== */
            TStruct_ECParameters_explicit_prime_cofactor* _M4 = new TStruct_ECParameters_explicit_prime_cofactor();
            this->appendChildRenamed(_M4, "cofactor");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_NameType" corresponding to Enum "NameType" */
class TEnum_NameType : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_NameType" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 266, "NameType");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_NameType" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_NameType" */
    TEnum_NameType() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("NameType");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("host_name", 0);
            staticList_.addFallbackItem("unknown");
        }
    }


    /* Function to create another instance of class "TEnum_NameType" */
    TEnum_NameType* newInstance_() const {

        TEnum_NameType* du = new TEnum_NameType();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_NameType" */
EnumerationItemList TEnum_NameType::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_HostName" corresponding to Struct "HostName" */
class TStruct_HostName : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_HostName" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 267, "HostName");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_HostName" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_HostName" */
    TStruct_HostName() : CompositeDataUnit() {

        this->setName("HostName");
    }


    /* Function to create another instance of class "TStruct_HostName" */
    TStruct_HostName* newInstance_() const {

        TStruct_HostName* du = new TStruct_HostName();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ServerName" corresponding to Struct "ServerName" */
class TStruct_ServerName : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ServerName" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 268, "ServerName");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ServerName" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ServerName" */
    TStruct_ServerName() : CompositeDataUnit() {

        this->setName("ServerName");
    }


    /* Function to create another instance of class "TStruct_ServerName" */
    TStruct_ServerName* newInstance_() const {

        TStruct_ServerName* du = new TStruct_ServerName();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "name_type" ===== */
            TEnum_NameType* _M0 = new TEnum_NameType();
            this->appendChildRenamed(_M0, "name_type");

        } else if (len == 1 && decoded >= 1) {

            int _value_name_type = (*this)[0]->propGet<int>(".value");
            if (_value_name_type == 0) {
                /* ===== Struct member "hostName" ===== */
                TStruct_HostName* _C_M0 = new TStruct_HostName();
                this->appendChildRenamed(_C_M0, "hostName");
            } else {
            /* ===== Struct member "_M0" ===== */
            OpaqueField* _C_M0 = new OpaqueField(BC(-1, 0));
            this->appendChildRenamed(_C_M0, "_M0");}
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: name_type <--- f-of-cases-in(name) */
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ServerNameList_server_name_list" corresponding to Struct "ServerNameList_server_name_list" */
class TStruct_ServerNameList_server_name_list : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ServerNameList_server_name_list" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 269, "ServerNameList_server_name_list");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ServerNameList_server_name_list" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ServerNameList_server_name_list" */
    TStruct_ServerNameList_server_name_list() : CompositeDataUnit() {

        this->setName("ServerNameList_server_name_list");
    }


    /* Function to create another instance of class "TStruct_ServerNameList_server_name_list" */
    TStruct_ServerNameList_server_name_list* newInstance_() const {

        TStruct_ServerNameList_server_name_list* du = new TStruct_ServerNameList_server_name_list();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TStruct_ServerName* _M1_V = new TStruct_ServerName();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ServerNameList" corresponding to Struct "ServerNameList" */
class TStruct_ServerNameList : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ServerNameList" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 270, "ServerNameList");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ServerNameList" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ServerNameList" */
    TStruct_ServerNameList() : CompositeDataUnit() {

        this->setName("ServerNameList");
    }


    /* Function to create another instance of class "TStruct_ServerNameList" */
    TStruct_ServerNameList* newInstance_() const {

        TStruct_ServerNameList* du = new TStruct_ServerNameList();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "server_name_list" ===== */
            TStruct_ServerNameList_server_name_list* _M0 = new TStruct_ServerNameList_server_name_list();
            this->appendChildRenamed(_M0, "server_name_list");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_MaxFragmentLength" corresponding to Enum "MaxFragmentLength" */
class TEnum_MaxFragmentLength : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_MaxFragmentLength" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 271, "MaxFragmentLength");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_MaxFragmentLength" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_MaxFragmentLength" */
    TEnum_MaxFragmentLength() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("MaxFragmentLength");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("max256" , 1);
            staticList_.addItem("max512" , 2);
            staticList_.addItem("max2048", 3);
            staticList_.addItem("max4096", 4);
            staticList_.addFallbackItem("unknown");
        }
    }


    /* Function to create another instance of class "TEnum_MaxFragmentLength" */
    TEnum_MaxFragmentLength* newInstance_() const {

        TEnum_MaxFragmentLength* du = new TEnum_MaxFragmentLength();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_MaxFragmentLength" */
EnumerationItemList TEnum_MaxFragmentLength::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_MaxFragmentLengthExtension" corresponding to Struct "MaxFragmentLengthExtension" */
class TStruct_MaxFragmentLengthExtension : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_MaxFragmentLengthExtension" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 272, "MaxFragmentLengthExtension");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_MaxFragmentLengthExtension" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_MaxFragmentLengthExtension" */
    TStruct_MaxFragmentLengthExtension() : CompositeDataUnit() {

        this->setName("MaxFragmentLengthExtension");
    }


    /* Function to create another instance of class "TStruct_MaxFragmentLengthExtension" */
    TStruct_MaxFragmentLengthExtension* newInstance_() const {

        TStruct_MaxFragmentLengthExtension* du = new TStruct_MaxFragmentLengthExtension();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "maxFragment" ===== */
            TEnum_MaxFragmentLength* _M0 = new TEnum_MaxFragmentLength();
            this->appendChildRenamed(_M0, "maxFragment");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_CertChainType" corresponding to Enum "CertChainType" */
class TEnum_CertChainType : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_CertChainType" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 273, "CertChainType");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_CertChainType" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_CertChainType" */
    TEnum_CertChainType() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("CertChainType");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("individual_certs", 0);
            staticList_.addItem("pkipath"         , 1);
        }
    }


    /* Function to create another instance of class "TEnum_CertChainType" */
    TEnum_CertChainType* newInstance_() const {

        TEnum_CertChainType* du = new TEnum_CertChainType();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_CertChainType" */
EnumerationItemList TEnum_CertChainType::staticList_;


/* ========================================================================= */

/* Definition of class "TEnum_URLAndHashPadding" corresponding to Enum "URLAndHashPadding" */
class TEnum_URLAndHashPadding : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_URLAndHashPadding" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 274, "URLAndHashPadding");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_URLAndHashPadding" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_URLAndHashPadding" */
    TEnum_URLAndHashPadding() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("URLAndHashPadding");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("one", 1);
        }
    }


    /* Function to create another instance of class "TEnum_URLAndHashPadding" */
    TEnum_URLAndHashPadding* newInstance_() const {

        TEnum_URLAndHashPadding* du = new TEnum_URLAndHashPadding();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_URLAndHashPadding" */
EnumerationItemList TEnum_URLAndHashPadding::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_URLAndHash_url" corresponding to Struct "URLAndHash_url" */
class TStruct_URLAndHash_url : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_URLAndHash_url" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 275, "URLAndHash_url");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_URLAndHash_url" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_URLAndHash_url" */
    TStruct_URLAndHash_url() : CompositeDataUnit() {

        this->setName("URLAndHash_url");
    }


    /* Function to create another instance of class "TStruct_URLAndHash_url" */
    TStruct_URLAndHash_url* newInstance_() const {

        TStruct_URLAndHash_url* du = new TStruct_URLAndHash_url();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_URLAndHash" corresponding to Struct "URLAndHash" */
class TStruct_URLAndHash : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_URLAndHash" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 276, "URLAndHash");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_URLAndHash" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_URLAndHash" */
    TStruct_URLAndHash() : CompositeDataUnit() {

        this->setName("URLAndHash");
    }


    /* Function to create another instance of class "TStruct_URLAndHash" */
    TStruct_URLAndHash* newInstance_() const {

        TStruct_URLAndHash* du = new TStruct_URLAndHash();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "url" ===== */
            TStruct_URLAndHash_url* _M0 = new TStruct_URLAndHash_url();
            this->appendChildRenamed(_M0, "url");
            /* ===== Struct member "padding" ===== */
            TEnum_URLAndHashPadding* _M1 = new TEnum_URLAndHashPadding();
            this->appendChildRenamed(_M1, "padding");
            /* ===== Struct member "SHA1Hash" ===== */
            OpaqueField* _M2 = new OpaqueField(BC(20, 0));
            this->appendChildRenamed(_M2, "SHA1Hash");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_CertificateURL_url_and_hash_list" corresponding to Struct "CertificateURL_url_and_hash_list" */
class TStruct_CertificateURL_url_and_hash_list : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_CertificateURL_url_and_hash_list" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 277, "CertificateURL_url_and_hash_list");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_CertificateURL_url_and_hash_list" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_CertificateURL_url_and_hash_list" */
    TStruct_CertificateURL_url_and_hash_list() : CompositeDataUnit() {

        this->setName("CertificateURL_url_and_hash_list");
    }


    /* Function to create another instance of class "TStruct_CertificateURL_url_and_hash_list" */
    TStruct_CertificateURL_url_and_hash_list* newInstance_() const {

        TStruct_CertificateURL_url_and_hash_list* du = new TStruct_CertificateURL_url_and_hash_list();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TStruct_URLAndHash* _M1_V = new TStruct_URLAndHash();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_CertificateURL" corresponding to Struct "CertificateURL" */
class TStruct_CertificateURL : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_CertificateURL" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 278, "CertificateURL");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_CertificateURL" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_CertificateURL" */
    TStruct_CertificateURL() : CompositeDataUnit() {

        this->setName("CertificateURL");
    }


    /* Function to create another instance of class "TStruct_CertificateURL" */
    TStruct_CertificateURL* newInstance_() const {

        TStruct_CertificateURL* du = new TStruct_CertificateURL();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "type" ===== */
            TEnum_CertChainType* _M0 = new TEnum_CertChainType();
            this->appendChildRenamed(_M0, "type");
            /* ===== Struct member "url_and_hash_list" ===== */
            TStruct_CertificateURL_url_and_hash_list* _M1 = new TStruct_CertificateURL_url_and_hash_list();
            this->appendChildRenamed(_M1, "url_and_hash_list");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_IdentifierType" corresponding to Enum "IdentifierType" */
class TEnum_IdentifierType : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_IdentifierType" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 279, "IdentifierType");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_IdentifierType" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_IdentifierType" */
    TEnum_IdentifierType() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("IdentifierType");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("pre_agreed"    , 0);
            staticList_.addItem("key_sha1_hash" , 1);
            staticList_.addItem("x509_name"     , 2);
            staticList_.addItem("cert_sha1_hash", 3);
            staticList_.addFallbackItem("unknown");
        }
    }


    /* Function to create another instance of class "TEnum_IdentifierType" */
    TEnum_IdentifierType* newInstance_() const {

        TEnum_IdentifierType* du = new TEnum_IdentifierType();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_IdentifierType" */
EnumerationItemList TEnum_IdentifierType::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_DistinguishedName" corresponding to Struct "DistinguishedName" */
class TStruct_DistinguishedName : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_DistinguishedName" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 280, "DistinguishedName");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_DistinguishedName" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_DistinguishedName" */
    TStruct_DistinguishedName() : CompositeDataUnit() {

        this->setName("DistinguishedName");
    }


    /* Function to create another instance of class "TStruct_DistinguishedName" */
    TStruct_DistinguishedName* newInstance_() const {

        TStruct_DistinguishedName* du = new TStruct_DistinguishedName();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_TrustedAuthority_identifier__C0__M0" corresponding to Struct "TrustedAuthority_identifier__C0__M0" */
class TStruct_TrustedAuthority_identifier__C0__M0 : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_TrustedAuthority_identifier__C0__M0" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 281, "TrustedAuthority_identifier__C0__M0");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_TrustedAuthority_identifier__C0__M0" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_TrustedAuthority_identifier__C0__M0" */
    TStruct_TrustedAuthority_identifier__C0__M0() : CompositeDataUnit() {

        this->setName("TrustedAuthority_identifier__C0__M0");
        this->setExpanded();
    }


    /* Function to create another instance of class "TStruct_TrustedAuthority_identifier__C0__M0" */
    TStruct_TrustedAuthority_identifier__C0__M0* newInstance_() const {

        TStruct_TrustedAuthority_identifier__C0__M0* du = new TStruct_TrustedAuthority_identifier__C0__M0();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_TrustedAuthority" corresponding to Struct "TrustedAuthority" */
class TStruct_TrustedAuthority : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_TrustedAuthority" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 282, "TrustedAuthority");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_TrustedAuthority" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_TrustedAuthority" */
    TStruct_TrustedAuthority() : CompositeDataUnit() {

        this->setName("TrustedAuthority");
    }


    /* Function to create another instance of class "TStruct_TrustedAuthority" */
    TStruct_TrustedAuthority* newInstance_() const {

        TStruct_TrustedAuthority* du = new TStruct_TrustedAuthority();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "identifier_type" ===== */
            TEnum_IdentifierType* _M0 = new TEnum_IdentifierType();
            this->appendChildRenamed(_M0, "identifier_type");

        } else if (len == 1 && decoded >= 1) {

            int _value_identifier_type = (*this)[0]->propGet<int>(".value");
            if (_value_identifier_type == 0) {
                /* ===== Struct member "_M0" ===== */
                TStruct_TrustedAuthority_identifier__C0__M0* _C_M0 = new TStruct_TrustedAuthority_identifier__C0__M0();
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_identifier_type == 1) {
                /* ===== Struct member "keySHA1Hash" ===== */
                OpaqueField* _C_M0 = new OpaqueField(BC(20, 0));
                this->appendChildRenamed(_C_M0, "keySHA1Hash");
            } else if (_value_identifier_type == 2) {
                /* ===== Struct member "x509Name" ===== */
                TStruct_DistinguishedName* _C_M0 = new TStruct_DistinguishedName();
                this->appendChildRenamed(_C_M0, "x509Name");
            } else if (_value_identifier_type == 3) {
                /* ===== Struct member "certSHA1Hash" ===== */
                OpaqueField* _C_M0 = new OpaqueField(BC(20, 0));
                this->appendChildRenamed(_C_M0, "certSHA1Hash");
            } else {
            /* ===== Struct member "_M0" ===== */
            OpaqueField* _C_M0 = new OpaqueField(BC(-1, 0));
            this->appendChildRenamed(_C_M0, "_M0");}
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: identifier_type <--- f-of-cases-in(identifier) */
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_TrustedAuthorities_trusted_authorities_list" corresponding to Struct "TrustedAuthorities_trusted_authorities_list" */
class TStruct_TrustedAuthorities_trusted_authorities_list : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_TrustedAuthorities_trusted_authorities_list" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 283, "TrustedAuthorities_trusted_authorities_list");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_TrustedAuthorities_trusted_authorities_list" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_TrustedAuthorities_trusted_authorities_list" */
    TStruct_TrustedAuthorities_trusted_authorities_list() : CompositeDataUnit() {

        this->setName("TrustedAuthorities_trusted_authorities_list");
    }


    /* Function to create another instance of class "TStruct_TrustedAuthorities_trusted_authorities_list" */
    TStruct_TrustedAuthorities_trusted_authorities_list* newInstance_() const {

        TStruct_TrustedAuthorities_trusted_authorities_list* du = new TStruct_TrustedAuthorities_trusted_authorities_list();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TStruct_TrustedAuthority* _M1_V = new TStruct_TrustedAuthority();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_TrustedAuthorities" corresponding to Struct "TrustedAuthorities" */
class TStruct_TrustedAuthorities : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_TrustedAuthorities" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 284, "TrustedAuthorities");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_TrustedAuthorities" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_TrustedAuthorities" */
    TStruct_TrustedAuthorities() : CompositeDataUnit() {

        this->setName("TrustedAuthorities");
    }


    /* Function to create another instance of class "TStruct_TrustedAuthorities" */
    TStruct_TrustedAuthorities* newInstance_() const {

        TStruct_TrustedAuthorities* du = new TStruct_TrustedAuthorities();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "trusted_authorities_list" ===== */
            TStruct_TrustedAuthorities_trusted_authorities_list* _M0 = new TStruct_TrustedAuthorities_trusted_authorities_list();
            this->appendChildRenamed(_M0, "trusted_authorities_list");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_TruncatedHMACExtension" corresponding to Struct "TruncatedHMACExtension" */
class TStruct_TruncatedHMACExtension : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_TruncatedHMACExtension" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 285, "TruncatedHMACExtension");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_TruncatedHMACExtension" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_TruncatedHMACExtension" */
    TStruct_TruncatedHMACExtension() : CompositeDataUnit() {

        this->setName("TruncatedHMACExtension");
        this->setExpanded();
    }


    /* Function to create another instance of class "TStruct_TruncatedHMACExtension" */
    TStruct_TruncatedHMACExtension* newInstance_() const {

        TStruct_TruncatedHMACExtension* du = new TStruct_TruncatedHMACExtension();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ResponderID" corresponding to Struct "ResponderID" */
class TStruct_ResponderID : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ResponderID" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 286, "ResponderID");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ResponderID" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ResponderID" */
    TStruct_ResponderID() : CompositeDataUnit() {

        this->setName("ResponderID");
    }


    /* Function to create another instance of class "TStruct_ResponderID" */
    TStruct_ResponderID* newInstance_() const {

        TStruct_ResponderID* du = new TStruct_ResponderID();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_Extensions" corresponding to Struct "Extensions" */
class TStruct_Extensions : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Extensions" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 287, "Extensions");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Extensions" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Extensions" */
    TStruct_Extensions() : CompositeDataUnit() {

        this->setName("Extensions");
    }


    /* Function to create another instance of class "TStruct_Extensions" */
    TStruct_Extensions* newInstance_() const {

        TStruct_Extensions* du = new TStruct_Extensions();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_OCSPStatusRequest_responder_id_list" corresponding to Struct "OCSPStatusRequest_responder_id_list" */
class TStruct_OCSPStatusRequest_responder_id_list : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_OCSPStatusRequest_responder_id_list" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 288, "OCSPStatusRequest_responder_id_list");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_OCSPStatusRequest_responder_id_list" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_OCSPStatusRequest_responder_id_list" */
    TStruct_OCSPStatusRequest_responder_id_list() : CompositeDataUnit() {

        this->setName("OCSPStatusRequest_responder_id_list");
    }


    /* Function to create another instance of class "TStruct_OCSPStatusRequest_responder_id_list" */
    TStruct_OCSPStatusRequest_responder_id_list* newInstance_() const {

        TStruct_OCSPStatusRequest_responder_id_list* du = new TStruct_OCSPStatusRequest_responder_id_list();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TStruct_ResponderID* _M1_V = new TStruct_ResponderID();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_OCSPStatusRequest" corresponding to Struct "OCSPStatusRequest" */
class TStruct_OCSPStatusRequest : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_OCSPStatusRequest" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 289, "OCSPStatusRequest");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_OCSPStatusRequest" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_OCSPStatusRequest" */
    TStruct_OCSPStatusRequest() : CompositeDataUnit() {

        this->setName("OCSPStatusRequest");
    }


    /* Function to create another instance of class "TStruct_OCSPStatusRequest" */
    TStruct_OCSPStatusRequest* newInstance_() const {

        TStruct_OCSPStatusRequest* du = new TStruct_OCSPStatusRequest();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "responder_id_list" ===== */
            TStruct_OCSPStatusRequest_responder_id_list* _M0 = new TStruct_OCSPStatusRequest_responder_id_list();
            this->appendChildRenamed(_M0, "responder_id_list");
            /* ===== Struct member "request_extensions" ===== */
            TStruct_Extensions* _M1 = new TStruct_Extensions();
            this->appendChildRenamed(_M1, "request_extensions");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_UserMappingType" corresponding to Enum "UserMappingType" */
class TEnum_UserMappingType : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_UserMappingType" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 290, "UserMappingType");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_UserMappingType" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_UserMappingType" */
    TEnum_UserMappingType() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("UserMappingType");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("upn_domain_hint", 64);
            staticList_.addFallbackItem("unknown");
        }
    }


    /* Function to create another instance of class "TEnum_UserMappingType" */
    TEnum_UserMappingType* newInstance_() const {

        TEnum_UserMappingType* du = new TEnum_UserMappingType();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_UserMappingType" */
EnumerationItemList TEnum_UserMappingType::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_UserMappingTypeList_user_mapping_types" corresponding to Struct "UserMappingTypeList_user_mapping_types" */
class TStruct_UserMappingTypeList_user_mapping_types : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_UserMappingTypeList_user_mapping_types" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 291, "UserMappingTypeList_user_mapping_types");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_UserMappingTypeList_user_mapping_types" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_UserMappingTypeList_user_mapping_types" */
    TStruct_UserMappingTypeList_user_mapping_types() : CompositeDataUnit() {

        this->setName("UserMappingTypeList_user_mapping_types");
    }


    /* Function to create another instance of class "TStruct_UserMappingTypeList_user_mapping_types" */
    TStruct_UserMappingTypeList_user_mapping_types* newInstance_() const {

        TStruct_UserMappingTypeList_user_mapping_types* du = new TStruct_UserMappingTypeList_user_mapping_types();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TEnum_UserMappingType* _M1_V = new TEnum_UserMappingType();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_UserMappingTypeList" corresponding to Struct "UserMappingTypeList" */
class TStruct_UserMappingTypeList : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_UserMappingTypeList" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 292, "UserMappingTypeList");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_UserMappingTypeList" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_UserMappingTypeList" */
    TStruct_UserMappingTypeList() : CompositeDataUnit() {

        this->setName("UserMappingTypeList");
    }


    /* Function to create another instance of class "TStruct_UserMappingTypeList" */
    TStruct_UserMappingTypeList* newInstance_() const {

        TStruct_UserMappingTypeList* du = new TStruct_UserMappingTypeList();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "user_mapping_types" ===== */
            TStruct_UserMappingTypeList_user_mapping_types* _M0 = new TStruct_UserMappingTypeList_user_mapping_types();
            this->appendChildRenamed(_M0, "user_mapping_types");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_AuthzDataFormat" corresponding to Enum "AuthzDataFormat" */
class TEnum_AuthzDataFormat : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_AuthzDataFormat" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 293, "AuthzDataFormat");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_AuthzDataFormat" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_AuthzDataFormat" */
    TEnum_AuthzDataFormat() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("AuthzDataFormat");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("x509_attr_cert"    , 0);
            staticList_.addItem("saml_assertion"    , 1);
            staticList_.addItem("x509_attr_cert_url", 2);
            staticList_.addItem("saml_assertion_url", 3);
            staticList_.addFallbackItem("unknown");
        }
    }


    /* Function to create another instance of class "TEnum_AuthzDataFormat" */
    TEnum_AuthzDataFormat* newInstance_() const {

        TEnum_AuthzDataFormat* du = new TEnum_AuthzDataFormat();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_AuthzDataFormat" */
EnumerationItemList TEnum_AuthzDataFormat::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_AuthzDataFormats" corresponding to Struct "AuthzDataFormats" */
class TStruct_AuthzDataFormats : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_AuthzDataFormats" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 294, "AuthzDataFormats");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_AuthzDataFormats" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_AuthzDataFormats" */
    TStruct_AuthzDataFormats() : CompositeDataUnit() {

        this->setName("AuthzDataFormats");
    }


    /* Function to create another instance of class "TStruct_AuthzDataFormats" */
    TStruct_AuthzDataFormats* newInstance_() const {

        TStruct_AuthzDataFormats* du = new TStruct_AuthzDataFormats();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TEnum_AuthzDataFormat* _M1_V = new TEnum_AuthzDataFormat();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_NamedCurve" corresponding to Enum "NamedCurve" */
class TEnum_NamedCurve : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_NamedCurve" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 295, "NamedCurve");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_NamedCurve" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_NamedCurve" */
    TEnum_NamedCurve() : EnumerationField(BC(0, 16), staticList_) {

        this->setName("NamedCurve");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("sect163k1"                      , 1);
            staticList_.addItem("sect163r1"                      , 2);
            staticList_.addItem("sect163r2"                      , 3);
            staticList_.addItem("sect193r1"                      , 4);
            staticList_.addItem("sect193r2"                      , 5);
            staticList_.addItem("sect233k1"                      , 6);
            staticList_.addItem("sect233r1"                      , 7);
            staticList_.addItem("sect239k1"                      , 8);
            staticList_.addItem("sect283k1"                      , 9);
            staticList_.addItem("sect283r1"                      , 10);
            staticList_.addItem("sect409k1"                      , 11);
            staticList_.addItem("sect409r1"                      , 12);
            staticList_.addItem("sect571k1"                      , 13);
            staticList_.addItem("sect571r1"                      , 14);
            staticList_.addItem("secp160k1"                      , 15);
            staticList_.addItem("secp160r1"                      , 16);
            staticList_.addItem("secp160r2"                      , 17);
            staticList_.addItem("secp192k1"                      , 18);
            staticList_.addItem("secp192r1"                      , 19);
            staticList_.addItem("secp224k1"                      , 20);
            staticList_.addItem("secp224r1"                      , 21);
            staticList_.addItem("secp256k1"                      , 22);
            staticList_.addItem("secp256r1"                      , 23);
            staticList_.addItem("secp384r1"                      , 24);
            staticList_.addItem("secp521r1"                      , 25);
            staticList_.addItem("arbitrary_explicit_prime_curves", 65281);
            staticList_.addItem("arbitrary_explicit_char2_curves", 65282);
            staticList_.addFallbackItem("unknown");
        }
    }


    /* Function to create another instance of class "TEnum_NamedCurve" */
    TEnum_NamedCurve* newInstance_() const {

        TEnum_NamedCurve* du = new TEnum_NamedCurve();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_NamedCurve" */
EnumerationItemList TEnum_NamedCurve::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_ECParameters" corresponding to Struct "ECParameters" */
class TStruct_ECParameters : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ECParameters" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 296, "ECParameters");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ECParameters" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ECParameters" */
    TStruct_ECParameters() : CompositeDataUnit() {

        this->setName("ECParameters");
    }


    /* Function to create another instance of class "TStruct_ECParameters" */
    TStruct_ECParameters* newInstance_() const {

        TStruct_ECParameters* du = new TStruct_ECParameters();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "curve_type" ===== */
            TEnum_ECCurveType* _M0 = new TEnum_ECCurveType();
            this->appendChildRenamed(_M0, "curve_type");

        } else if (len == 1 && decoded >= 1) {

            int _value_curve_type = (*this)[0]->propGet<int>(".value");
            if (_value_curve_type == 1) {
                /* ===== Struct member "_M0" ===== */
                TStruct_ECParameters_explicit_prime* _C_M0 = new TStruct_ECParameters_explicit_prime();
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_curve_type == 3) {
                /* ===== Struct member "namedcurve" ===== */
                TEnum_NamedCurve* _C_M0 = new TEnum_NamedCurve();
                this->appendChildRenamed(_C_M0, "namedcurve");
            } else {
            /* ===== Struct member "curve" ===== */
            OpaqueField* _C_M0 = new OpaqueField(BC(-1, 0));
            this->appendChildRenamed(_C_M0, "curve");}
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: curve_type <--- f-of-cases-in(_M1) */
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ServerECDHParams" corresponding to Struct "ServerECDHParams" */
class TStruct_ServerECDHParams : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ServerECDHParams" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 297, "ServerECDHParams");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ServerECDHParams" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ServerECDHParams" */
    TStruct_ServerECDHParams() : CompositeDataUnit() {

        this->setName("ServerECDHParams");
    }


    /* Function to create another instance of class "TStruct_ServerECDHParams" */
    TStruct_ServerECDHParams* newInstance_() const {

        TStruct_ServerECDHParams* du = new TStruct_ServerECDHParams();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "curve_params" ===== */
            TStruct_ECParameters* _M0 = new TStruct_ECParameters();
            this->appendChildRenamed(_M0, "curve_params");
            /* ===== Struct member "public" ===== */
            TStruct_ECPoint* _M1 = new TStruct_ECPoint();
            this->appendChildRenamed(_M1, "public");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_EllipticCurveList_elliptic_curve_list" corresponding to Struct "EllipticCurveList_elliptic_curve_list" */
class TStruct_EllipticCurveList_elliptic_curve_list : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_EllipticCurveList_elliptic_curve_list" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 298, "EllipticCurveList_elliptic_curve_list");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_EllipticCurveList_elliptic_curve_list" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_EllipticCurveList_elliptic_curve_list" */
    TStruct_EllipticCurveList_elliptic_curve_list() : CompositeDataUnit() {

        this->setName("EllipticCurveList_elliptic_curve_list");
    }


    /* Function to create another instance of class "TStruct_EllipticCurveList_elliptic_curve_list" */
    TStruct_EllipticCurveList_elliptic_curve_list* newInstance_() const {

        TStruct_EllipticCurveList_elliptic_curve_list* du = new TStruct_EllipticCurveList_elliptic_curve_list();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TEnum_NamedCurve* _M1_V = new TEnum_NamedCurve();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_EllipticCurveList" corresponding to Struct "EllipticCurveList" */
class TStruct_EllipticCurveList : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_EllipticCurveList" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 299, "EllipticCurveList");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_EllipticCurveList" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_EllipticCurveList" */
    TStruct_EllipticCurveList() : CompositeDataUnit() {

        this->setName("EllipticCurveList");
    }


    /* Function to create another instance of class "TStruct_EllipticCurveList" */
    TStruct_EllipticCurveList* newInstance_() const {

        TStruct_EllipticCurveList* du = new TStruct_EllipticCurveList();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "elliptic_curve_list" ===== */
            TStruct_EllipticCurveList_elliptic_curve_list* _M0 = new TStruct_EllipticCurveList_elliptic_curve_list();
            this->appendChildRenamed(_M0, "elliptic_curve_list");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_ECPointFormat" corresponding to Enum "ECPointFormat" */
class TEnum_ECPointFormat : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_ECPointFormat" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 300, "ECPointFormat");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_ECPointFormat" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_ECPointFormat" */
    TEnum_ECPointFormat() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("ECPointFormat");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("uncompressed"             , 0);
            staticList_.addItem("ansiX962_compressed_prime", 1);
            staticList_.addItem("ansiX962_compressed_char2", 2);
            staticList_.addFallbackItem("unknown");
            staticList_.addItem("reserved                 ", 248, 255);
        }
    }


    /* Function to create another instance of class "TEnum_ECPointFormat" */
    TEnum_ECPointFormat* newInstance_() const {

        TEnum_ECPointFormat* du = new TEnum_ECPointFormat();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_ECPointFormat" */
EnumerationItemList TEnum_ECPointFormat::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_ECPointFormatList_ec_point_format_list" corresponding to Struct "ECPointFormatList_ec_point_format_list" */
class TStruct_ECPointFormatList_ec_point_format_list : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ECPointFormatList_ec_point_format_list" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 301, "ECPointFormatList_ec_point_format_list");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ECPointFormatList_ec_point_format_list" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ECPointFormatList_ec_point_format_list" */
    TStruct_ECPointFormatList_ec_point_format_list() : CompositeDataUnit() {

        this->setName("ECPointFormatList_ec_point_format_list");
    }


    /* Function to create another instance of class "TStruct_ECPointFormatList_ec_point_format_list" */
    TStruct_ECPointFormatList_ec_point_format_list* newInstance_() const {

        TStruct_ECPointFormatList_ec_point_format_list* du = new TStruct_ECPointFormatList_ec_point_format_list();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TEnum_ECPointFormat* _M1_V = new TEnum_ECPointFormat();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ECPointFormatList" corresponding to Struct "ECPointFormatList" */
class TStruct_ECPointFormatList : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ECPointFormatList" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 302, "ECPointFormatList");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ECPointFormatList" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ECPointFormatList" */
    TStruct_ECPointFormatList() : CompositeDataUnit() {

        this->setName("ECPointFormatList");
    }


    /* Function to create another instance of class "TStruct_ECPointFormatList" */
    TStruct_ECPointFormatList* newInstance_() const {

        TStruct_ECPointFormatList* du = new TStruct_ECPointFormatList();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "ec_point_format_list" ===== */
            TStruct_ECPointFormatList_ec_point_format_list* _M0 = new TStruct_ECPointFormatList_ec_point_format_list();
            this->appendChildRenamed(_M0, "ec_point_format_list");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_SRPExtension_srp_I" corresponding to Struct "SRPExtension_srp_I" */
class TStruct_SRPExtension_srp_I : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_SRPExtension_srp_I" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 303, "SRPExtension_srp_I");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_SRPExtension_srp_I" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_SRPExtension_srp_I" */
    TStruct_SRPExtension_srp_I() : CompositeDataUnit() {

        this->setName("SRPExtension_srp_I");
    }


    /* Function to create another instance of class "TStruct_SRPExtension_srp_I" */
    TStruct_SRPExtension_srp_I* newInstance_() const {

        TStruct_SRPExtension_srp_I* du = new TStruct_SRPExtension_srp_I();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_SRPExtension" corresponding to Struct "SRPExtension" */
class TStruct_SRPExtension : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_SRPExtension" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 304, "SRPExtension");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_SRPExtension" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_SRPExtension" */
    TStruct_SRPExtension() : CompositeDataUnit() {

        this->setName("SRPExtension");
    }


    /* Function to create another instance of class "TStruct_SRPExtension" */
    TStruct_SRPExtension* newInstance_() const {

        TStruct_SRPExtension* du = new TStruct_SRPExtension();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "srp_I" ===== */
            TStruct_SRPExtension_srp_I* _M0 = new TStruct_SRPExtension_srp_I();
            this->appendChildRenamed(_M0, "srp_I");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_SignatureAlgorithm" corresponding to Enum "SignatureAlgorithm" */
class TEnum_SignatureAlgorithm : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_SignatureAlgorithm" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 305, "SignatureAlgorithm");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_SignatureAlgorithm" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_SignatureAlgorithm" */
    TEnum_SignatureAlgorithm() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("SignatureAlgorithm");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("anonymous", 0);
            staticList_.addItem("rsa"      , 1);
            staticList_.addItem("dsa"      , 2);
            staticList_.addItem("ecdsa"    , 3);
            staticList_.addFallbackItem("unknown");
        }
    }


    /* Function to create another instance of class "TEnum_SignatureAlgorithm" */
    TEnum_SignatureAlgorithm* newInstance_() const {

        TEnum_SignatureAlgorithm* du = new TEnum_SignatureAlgorithm();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_SignatureAlgorithm" */
EnumerationItemList TEnum_SignatureAlgorithm::staticList_;


/* ========================================================================= */

/* Definition of class "TEnum_HashAlgorithm" corresponding to Enum "HashAlgorithm" */
class TEnum_HashAlgorithm : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_HashAlgorithm" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 306, "HashAlgorithm");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_HashAlgorithm" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_HashAlgorithm" */
    TEnum_HashAlgorithm() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("HashAlgorithm");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("none"   , 0);
            staticList_.addItem("md5"    , 1);
            staticList_.addItem("sha1"   , 2);
            staticList_.addItem("sha224" , 3);
            staticList_.addItem("sha256" , 4);
            staticList_.addItem("sha384" , 5);
            staticList_.addItem("sha512" , 6);
            staticList_.addFallbackItem("unknown");
        }
    }


    /* Function to create another instance of class "TEnum_HashAlgorithm" */
    TEnum_HashAlgorithm* newInstance_() const {

        TEnum_HashAlgorithm* du = new TEnum_HashAlgorithm();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_HashAlgorithm" */
EnumerationItemList TEnum_HashAlgorithm::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_SignatureAndHashAlgorithm" corresponding to Struct "SignatureAndHashAlgorithm" */
class TStruct_SignatureAndHashAlgorithm : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_SignatureAndHashAlgorithm" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 307, "SignatureAndHashAlgorithm");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_SignatureAndHashAlgorithm" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_SignatureAndHashAlgorithm" */
    TStruct_SignatureAndHashAlgorithm() : CompositeDataUnit() {

        this->setName("SignatureAndHashAlgorithm");
    }


    /* Function to create another instance of class "TStruct_SignatureAndHashAlgorithm" */
    TStruct_SignatureAndHashAlgorithm* newInstance_() const {

        TStruct_SignatureAndHashAlgorithm* du = new TStruct_SignatureAndHashAlgorithm();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "hash" ===== */
            TEnum_HashAlgorithm* _M0 = new TEnum_HashAlgorithm();
            this->appendChildRenamed(_M0, "hash");
            /* ===== Struct member "signature" ===== */
            TEnum_SignatureAlgorithm* _M1 = new TEnum_SignatureAlgorithm();
            this->appendChildRenamed(_M1, "signature");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }


    std::string getDynamicTypeName_() const {

        std::string dynamicType;
        DataUnit* du;
        du = (*this)[0];
        if (du != 0) {
            dynamicType += du->propGetDefault<std::string>(".name", "");
        }
        dynamicType += "+";
        du = (*this)[1];
        if (du != 0) {
            dynamicType += du->propGetDefault<std::string>(".name", "");
        }
        return dynamicType;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_Signature" corresponding to Struct "Signature" */
class TStruct_Signature : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Signature" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 308, "Signature");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Signature" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Signature" */
    TStruct_Signature() : CompositeDataUnit() {

        this->setName("Signature");
    }


    /* Function to create another instance of class "TStruct_Signature" */
    TStruct_Signature* newInstance_() const {

        TStruct_Signature* du = new TStruct_Signature();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "algo" ===== */
            TStruct_SignatureAndHashAlgorithm* _M0 = new TStruct_SignatureAndHashAlgorithm();
            this->appendChildRenamed(_M0, "algo");
            /* ===== Struct member "signature" ===== */
            TStruct_Signature_signature* _M1 = new TStruct_Signature_signature();
            this->appendChildRenamed(_M1, "signature");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ServerKeyExchange" corresponding to Struct "ServerKeyExchange" */
class TStruct_ServerKeyExchange : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ServerKeyExchange" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 309, "ServerKeyExchange");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ServerKeyExchange" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ServerKeyExchange" */
    TStruct_ServerKeyExchange() : CompositeDataUnit() {

        this->setName("ServerKeyExchange");
    }


    /* Function to create another instance of class "TStruct_ServerKeyExchange" */
    TStruct_ServerKeyExchange* newInstance_() const {

        TStruct_ServerKeyExchange* du = new TStruct_ServerKeyExchange();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "params" ===== */
            TStruct_ServerECDHParams* _M0 = new TStruct_ServerECDHParams();
            this->appendChildRenamed(_M0, "params");
            /* ===== Struct member "signed_params" ===== */
            TStruct_Signature* _M1 = new TStruct_Signature();
            this->appendChildRenamed(_M1, "signed_params");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_SignatureAndHashAlgorithms" corresponding to Struct "SignatureAndHashAlgorithms" */
class TStruct_SignatureAndHashAlgorithms : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_SignatureAndHashAlgorithms" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 310, "SignatureAndHashAlgorithms");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_SignatureAndHashAlgorithms" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_SignatureAndHashAlgorithms" */
    TStruct_SignatureAndHashAlgorithms() : CompositeDataUnit() {

        this->setName("SignatureAndHashAlgorithms");
    }


    /* Function to create another instance of class "TStruct_SignatureAndHashAlgorithms" */
    TStruct_SignatureAndHashAlgorithms* newInstance_() const {

        TStruct_SignatureAndHashAlgorithms* du = new TStruct_SignatureAndHashAlgorithms();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TStruct_SignatureAndHashAlgorithm* _M1_V = new TStruct_SignatureAndHashAlgorithm();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TVector_SRTPProtectionProfile" corresponding to Vector "SRTPProtectionProfile" */
class TVector_SRTPProtectionProfile : public StreamVectorDataUnit {

    public:


    /* Static function returning type descriptor of class "TVector_SRTPProtectionProfile" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(StreamVectorDataUnit::typeDescriptor(), 311, "SRTPProtectionProfile");
        return desc;
    }


    /* Function returning type descriptor of class "TVector_SRTPProtectionProfile" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TVector_SRTPProtectionProfile" */
    TVector_SRTPProtectionProfile() : StreamVectorDataUnit(BC(2, 0)) {

        this->setName("SRTPProtectionProfile");
        /* set the vector element template */
        IntegerField* _T = new IntegerField(BC(0, 8), false);
        this->setElementTemplate(_T);
    }


    /* Function to create another instance of class "TVector_SRTPProtectionProfile" */
    TVector_SRTPProtectionProfile* newInstance_() const {

        TVector_SRTPProtectionProfile* du = new TVector_SRTPProtectionProfile();
        return du;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_SRTPProtectionProfiles" corresponding to Struct "SRTPProtectionProfiles" */
class TStruct_SRTPProtectionProfiles : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_SRTPProtectionProfiles" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 312, "SRTPProtectionProfiles");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_SRTPProtectionProfiles" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_SRTPProtectionProfiles" */
    TStruct_SRTPProtectionProfiles() : CompositeDataUnit() {

        this->setName("SRTPProtectionProfiles");
    }


    /* Function to create another instance of class "TStruct_SRTPProtectionProfiles" */
    TStruct_SRTPProtectionProfiles* newInstance_() const {

        TStruct_SRTPProtectionProfiles* du = new TStruct_SRTPProtectionProfiles();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TVector_SRTPProtectionProfile* _M1_V = new TVector_SRTPProtectionProfile();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_UseSRTPData_srtp_mki" corresponding to Struct "UseSRTPData_srtp_mki" */
class TStruct_UseSRTPData_srtp_mki : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_UseSRTPData_srtp_mki" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 313, "UseSRTPData_srtp_mki");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_UseSRTPData_srtp_mki" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_UseSRTPData_srtp_mki" */
    TStruct_UseSRTPData_srtp_mki() : CompositeDataUnit() {

        this->setName("UseSRTPData_srtp_mki");
    }


    /* Function to create another instance of class "TStruct_UseSRTPData_srtp_mki" */
    TStruct_UseSRTPData_srtp_mki* newInstance_() const {

        TStruct_UseSRTPData_srtp_mki* du = new TStruct_UseSRTPData_srtp_mki();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_UseSRTPData" corresponding to Struct "UseSRTPData" */
class TStruct_UseSRTPData : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_UseSRTPData" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 314, "UseSRTPData");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_UseSRTPData" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_UseSRTPData" */
    TStruct_UseSRTPData() : CompositeDataUnit() {

        this->setName("UseSRTPData");
    }


    /* Function to create another instance of class "TStruct_UseSRTPData" */
    TStruct_UseSRTPData* newInstance_() const {

        TStruct_UseSRTPData* du = new TStruct_UseSRTPData();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "SRTPProtectionProfilesXX" ===== */
            TStruct_SRTPProtectionProfiles* _M0 = new TStruct_SRTPProtectionProfiles();
            this->appendChildRenamed(_M0, "SRTPProtectionProfilesXX");
            /* ===== Struct member "srtp_mki" ===== */
            TStruct_UseSRTPData_srtp_mki* _M1 = new TStruct_UseSRTPData_srtp_mki();
            this->appendChildRenamed(_M1, "srtp_mki");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_HeartbeatMode" corresponding to Enum "HeartbeatMode" */
class TEnum_HeartbeatMode : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_HeartbeatMode" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 315, "HeartbeatMode");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_HeartbeatMode" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_HeartbeatMode" */
    TEnum_HeartbeatMode() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("HeartbeatMode");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("peer_allowed_to_send"    , 1);
            staticList_.addItem("peer_not_allowed_to_send", 2);
            staticList_.addFallbackItem("unknown");
        }
    }


    /* Function to create another instance of class "TEnum_HeartbeatMode" */
    TEnum_HeartbeatMode* newInstance_() const {

        TEnum_HeartbeatMode* du = new TEnum_HeartbeatMode();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_HeartbeatMode" */
EnumerationItemList TEnum_HeartbeatMode::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_HeartbeatExtension" corresponding to Struct "HeartbeatExtension" */
class TStruct_HeartbeatExtension : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_HeartbeatExtension" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 316, "HeartbeatExtension");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_HeartbeatExtension" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_HeartbeatExtension" */
    TStruct_HeartbeatExtension() : CompositeDataUnit() {

        this->setName("HeartbeatExtension");
    }


    /* Function to create another instance of class "TStruct_HeartbeatExtension" */
    TStruct_HeartbeatExtension* newInstance_() const {

        TStruct_HeartbeatExtension* du = new TStruct_HeartbeatExtension();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "mode" ===== */
            TEnum_HeartbeatMode* _M0 = new TEnum_HeartbeatMode();
            this->appendChildRenamed(_M0, "mode");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ProtocolName" corresponding to Struct "ProtocolName" */
class TStruct_ProtocolName : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ProtocolName" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 317, "ProtocolName");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ProtocolName" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ProtocolName" */
    TStruct_ProtocolName() : CompositeDataUnit() {

        this->setName("ProtocolName");
    }


    /* Function to create another instance of class "TStruct_ProtocolName" */
    TStruct_ProtocolName* newInstance_() const {

        TStruct_ProtocolName* du = new TStruct_ProtocolName();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ProtocolNameList_protocol_name_list" corresponding to Struct "ProtocolNameList_protocol_name_list" */
class TStruct_ProtocolNameList_protocol_name_list : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ProtocolNameList_protocol_name_list" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 318, "ProtocolNameList_protocol_name_list");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ProtocolNameList_protocol_name_list" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ProtocolNameList_protocol_name_list" */
    TStruct_ProtocolNameList_protocol_name_list() : CompositeDataUnit() {

        this->setName("ProtocolNameList_protocol_name_list");
    }


    /* Function to create another instance of class "TStruct_ProtocolNameList_protocol_name_list" */
    TStruct_ProtocolNameList_protocol_name_list* newInstance_() const {

        TStruct_ProtocolNameList_protocol_name_list* du = new TStruct_ProtocolNameList_protocol_name_list();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TStruct_ProtocolName* _M1_V = new TStruct_ProtocolName();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ProtocolNameList" corresponding to Struct "ProtocolNameList" */
class TStruct_ProtocolNameList : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ProtocolNameList" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 319, "ProtocolNameList");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ProtocolNameList" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ProtocolNameList" */
    TStruct_ProtocolNameList() : CompositeDataUnit() {

        this->setName("ProtocolNameList");
    }


    /* Function to create another instance of class "TStruct_ProtocolNameList" */
    TStruct_ProtocolNameList* newInstance_() const {

        TStruct_ProtocolNameList* du = new TStruct_ProtocolNameList();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "protocol_name_list" ===== */
            TStruct_ProtocolNameList_protocol_name_list* _M0 = new TStruct_ProtocolNameList_protocol_name_list();
            this->appendChildRenamed(_M0, "protocol_name_list");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_CertificateStatusType" corresponding to Enum "CertificateStatusType" */
class TEnum_CertificateStatusType : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_CertificateStatusType" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 320, "CertificateStatusType");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_CertificateStatusType" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_CertificateStatusType" */
    TEnum_CertificateStatusType() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("CertificateStatusType");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("ocsp"      , 1);
            staticList_.addItem("ocsp_multi", 2);
        }
    }


    /* Function to create another instance of class "TEnum_CertificateStatusType" */
    TEnum_CertificateStatusType* newInstance_() const {

        TEnum_CertificateStatusType* du = new TEnum_CertificateStatusType();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_CertificateStatusType" */
EnumerationItemList TEnum_CertificateStatusType::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_CertificateStatusRequest" corresponding to Struct "CertificateStatusRequest" */
class TStruct_CertificateStatusRequest : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_CertificateStatusRequest" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 321, "CertificateStatusRequest");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_CertificateStatusRequest" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_CertificateStatusRequest" */
    TStruct_CertificateStatusRequest() : CompositeDataUnit() {

        this->setName("CertificateStatusRequest");
    }


    /* Function to create another instance of class "TStruct_CertificateStatusRequest" */
    TStruct_CertificateStatusRequest* newInstance_() const {

        TStruct_CertificateStatusRequest* du = new TStruct_CertificateStatusRequest();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "status_type" ===== */
            TEnum_CertificateStatusType* _M0 = new TEnum_CertificateStatusType();
            this->appendChildRenamed(_M0, "status_type");

        } else if (len == 1 && decoded >= 1) {

            int _value_status_type = (*this)[0]->propGet<int>(".value");
            if (_value_status_type == 1) {
                /* ===== Struct member "_M0" ===== */
                TStruct_OCSPStatusRequest* _C_M0 = new TStruct_OCSPStatusRequest();
                this->appendChildRenamed(_C_M0, "_M0");
            } else {
            /* ===== Struct member "status" ===== */
            OpaqueField* _C_M0 = new OpaqueField(BC(-1, 0));
            this->appendChildRenamed(_C_M0, "status");}
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: status_type <--- f-of-cases-in(request) */
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_CertificateStatusRequestItemV2" corresponding to Struct "CertificateStatusRequestItemV2" */
class TStruct_CertificateStatusRequestItemV2 : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_CertificateStatusRequestItemV2" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 322, "CertificateStatusRequestItemV2");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_CertificateStatusRequestItemV2" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_CertificateStatusRequestItemV2" */
    TStruct_CertificateStatusRequestItemV2() : CompositeDataUnit() {

        this->setName("CertificateStatusRequestItemV2");
    }


    /* Function to create another instance of class "TStruct_CertificateStatusRequestItemV2" */
    TStruct_CertificateStatusRequestItemV2* newInstance_() const {

        TStruct_CertificateStatusRequestItemV2* du = new TStruct_CertificateStatusRequestItemV2();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "status_type" ===== */
            TEnum_CertificateStatusType* _M0 = new TEnum_CertificateStatusType();
            this->appendChildRenamed(_M0, "status_type");
            /* ===== Struct member "request_length" ===== */
            IntegerField* _M1 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M1, "request_length");

        } else if (len == 2 && decoded >= 2) {

            int _value_status_type = (*this)[0]->propGet<int>(".value");
            int _value_request_length = (*this)[1]->propGet<int>(".value");
            if (_value_status_type == 1) {
                /* ===== Struct member "request1" ===== */
                TStruct_OCSPStatusRequest* _C_M0 = new TStruct_OCSPStatusRequest();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_request_length);
                this->appendChildRenamed(_C_M0, "request1");
            } else if (_value_status_type == 2) {
                /* ===== Struct member "request2" ===== */
                TStruct_OCSPStatusRequest* _C_M0 = new TStruct_OCSPStatusRequest();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_request_length);
                this->appendChildRenamed(_C_M0, "request2");
            } else {
            /* ===== Struct member "_M0" ===== */
            OpaqueField* _C_M0 = new OpaqueField(BC(_value_request_length, 0));
            _C_M0->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_C_M0, "_M0");}
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: status_type <--- f-of-cases-in(request) */
        } else if (index == 1) {
            /* 1: request_length <--- f-of-cases-in(request) */
            int _value_0 = 0;
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            (*this)[1]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_CertificateStatusRequestListV2_certificate_status_req_list" corresponding to Struct "CertificateStatusRequestListV2_certificate_status_req_list" */
class TStruct_CertificateStatusRequestListV2_certificate_status_req_list : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_CertificateStatusRequestListV2_certificate_status_req_list" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 323, "CertificateStatusRequestListV2_certificate_status_req_list");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_CertificateStatusRequestListV2_certificate_status_req_list" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_CertificateStatusRequestListV2_certificate_status_req_list" */
    TStruct_CertificateStatusRequestListV2_certificate_status_req_list() : CompositeDataUnit() {

        this->setName("CertificateStatusRequestListV2_certificate_status_req_list");
    }


    /* Function to create another instance of class "TStruct_CertificateStatusRequestListV2_certificate_status_req_list" */
    TStruct_CertificateStatusRequestListV2_certificate_status_req_list* newInstance_() const {

        TStruct_CertificateStatusRequestListV2_certificate_status_req_list* du = new TStruct_CertificateStatusRequestListV2_certificate_status_req_list();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TStruct_CertificateStatusRequestItemV2* _M1_V = new TStruct_CertificateStatusRequestItemV2();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_CertificateStatusRequestListV2" corresponding to Struct "CertificateStatusRequestListV2" */
class TStruct_CertificateStatusRequestListV2 : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_CertificateStatusRequestListV2" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 324, "CertificateStatusRequestListV2");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_CertificateStatusRequestListV2" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_CertificateStatusRequestListV2" */
    TStruct_CertificateStatusRequestListV2() : CompositeDataUnit() {

        this->setName("CertificateStatusRequestListV2");
    }


    /* Function to create another instance of class "TStruct_CertificateStatusRequestListV2" */
    TStruct_CertificateStatusRequestListV2* newInstance_() const {

        TStruct_CertificateStatusRequestListV2* du = new TStruct_CertificateStatusRequestListV2();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "certificate_status_req_list" ===== */
            TStruct_CertificateStatusRequestListV2_certificate_status_req_list* _M0 = new TStruct_CertificateStatusRequestListV2_certificate_status_req_list();
            this->appendChildRenamed(_M0, "certificate_status_req_list");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_Client_SignedCertificateTimestamp" corresponding to Struct "Client_SignedCertificateTimestamp" */
class TStruct_Client_SignedCertificateTimestamp : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Client_SignedCertificateTimestamp" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 325, "Client_SignedCertificateTimestamp");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Client_SignedCertificateTimestamp" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Client_SignedCertificateTimestamp" */
    TStruct_Client_SignedCertificateTimestamp() : CompositeDataUnit() {

        this->setName("Client_SignedCertificateTimestamp");
        this->setExpanded();
    }


    /* Function to create another instance of class "TStruct_Client_SignedCertificateTimestamp" */
    TStruct_Client_SignedCertificateTimestamp* newInstance_() const {

        TStruct_Client_SignedCertificateTimestamp* du = new TStruct_Client_SignedCertificateTimestamp();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_CertificateType" corresponding to Enum "CertificateType" */
class TEnum_CertificateType : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_CertificateType" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 326, "CertificateType");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_CertificateType" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_CertificateType" */
    TEnum_CertificateType() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("CertificateType");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("X509"        , 0);
            staticList_.addItem("OpenPGP"     , 1);
            staticList_.addItem("RawPublicKey", 2);
        }
    }


    /* Function to create another instance of class "TEnum_CertificateType" */
    TEnum_CertificateType* newInstance_() const {

        TEnum_CertificateType* du = new TEnum_CertificateType();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_CertificateType" */
EnumerationItemList TEnum_CertificateType::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_Client_CertificateTypeExtension_certificate_types" corresponding to Struct "Client_CertificateTypeExtension_certificate_types" */
class TStruct_Client_CertificateTypeExtension_certificate_types : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Client_CertificateTypeExtension_certificate_types" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 327, "Client_CertificateTypeExtension_certificate_types");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Client_CertificateTypeExtension_certificate_types" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Client_CertificateTypeExtension_certificate_types" */
    TStruct_Client_CertificateTypeExtension_certificate_types() : CompositeDataUnit() {

        this->setName("Client_CertificateTypeExtension_certificate_types");
    }


    /* Function to create another instance of class "TStruct_Client_CertificateTypeExtension_certificate_types" */
    TStruct_Client_CertificateTypeExtension_certificate_types* newInstance_() const {

        TStruct_Client_CertificateTypeExtension_certificate_types* du = new TStruct_Client_CertificateTypeExtension_certificate_types();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TEnum_CertificateType* _M1_V = new TEnum_CertificateType();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_Client_CertificateTypeExtension" corresponding to Struct "Client_CertificateTypeExtension" */
class TStruct_Client_CertificateTypeExtension : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Client_CertificateTypeExtension" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 328, "Client_CertificateTypeExtension");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Client_CertificateTypeExtension" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Client_CertificateTypeExtension" */
    TStruct_Client_CertificateTypeExtension() : CompositeDataUnit() {

        this->setName("Client_CertificateTypeExtension");
    }


    /* Function to create another instance of class "TStruct_Client_CertificateTypeExtension" */
    TStruct_Client_CertificateTypeExtension* newInstance_() const {

        TStruct_Client_CertificateTypeExtension* du = new TStruct_Client_CertificateTypeExtension();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "certificate_types" ===== */
            TStruct_Client_CertificateTypeExtension_certificate_types* _M0 = new TStruct_Client_CertificateTypeExtension_certificate_types();
            this->appendChildRenamed(_M0, "certificate_types");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_Client_ClientCertTypeExtension_client_certificate_types" corresponding to Struct "Client_ClientCertTypeExtension_client_certificate_types" */
class TStruct_Client_ClientCertTypeExtension_client_certificate_types : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Client_ClientCertTypeExtension_client_certificate_types" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 329, "Client_ClientCertTypeExtension_client_certificate_types");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Client_ClientCertTypeExtension_client_certificate_types" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Client_ClientCertTypeExtension_client_certificate_types" */
    TStruct_Client_ClientCertTypeExtension_client_certificate_types() : CompositeDataUnit() {

        this->setName("Client_ClientCertTypeExtension_client_certificate_types");
    }


    /* Function to create another instance of class "TStruct_Client_ClientCertTypeExtension_client_certificate_types" */
    TStruct_Client_ClientCertTypeExtension_client_certificate_types* newInstance_() const {

        TStruct_Client_ClientCertTypeExtension_client_certificate_types* du = new TStruct_Client_ClientCertTypeExtension_client_certificate_types();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TEnum_CertificateType* _M1_V = new TEnum_CertificateType();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_Client_ClientCertTypeExtension" corresponding to Struct "Client_ClientCertTypeExtension" */
class TStruct_Client_ClientCertTypeExtension : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Client_ClientCertTypeExtension" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 330, "Client_ClientCertTypeExtension");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Client_ClientCertTypeExtension" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Client_ClientCertTypeExtension" */
    TStruct_Client_ClientCertTypeExtension() : CompositeDataUnit() {

        this->setName("Client_ClientCertTypeExtension");
    }


    /* Function to create another instance of class "TStruct_Client_ClientCertTypeExtension" */
    TStruct_Client_ClientCertTypeExtension* newInstance_() const {

        TStruct_Client_ClientCertTypeExtension* du = new TStruct_Client_ClientCertTypeExtension();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "client_certificate_types" ===== */
            TStruct_Client_ClientCertTypeExtension_client_certificate_types* _M0 = new TStruct_Client_ClientCertTypeExtension_client_certificate_types();
            this->appendChildRenamed(_M0, "client_certificate_types");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_Client_ServerCertTypeExtension_server_certificate_types" corresponding to Struct "Client_ServerCertTypeExtension_server_certificate_types" */
class TStruct_Client_ServerCertTypeExtension_server_certificate_types : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Client_ServerCertTypeExtension_server_certificate_types" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 331, "Client_ServerCertTypeExtension_server_certificate_types");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Client_ServerCertTypeExtension_server_certificate_types" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Client_ServerCertTypeExtension_server_certificate_types" */
    TStruct_Client_ServerCertTypeExtension_server_certificate_types() : CompositeDataUnit() {

        this->setName("Client_ServerCertTypeExtension_server_certificate_types");
    }


    /* Function to create another instance of class "TStruct_Client_ServerCertTypeExtension_server_certificate_types" */
    TStruct_Client_ServerCertTypeExtension_server_certificate_types* newInstance_() const {

        TStruct_Client_ServerCertTypeExtension_server_certificate_types* du = new TStruct_Client_ServerCertTypeExtension_server_certificate_types();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TEnum_CertificateType* _M1_V = new TEnum_CertificateType();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_Client_ServerCertTypeExtension" corresponding to Struct "Client_ServerCertTypeExtension" */
class TStruct_Client_ServerCertTypeExtension : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Client_ServerCertTypeExtension" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 332, "Client_ServerCertTypeExtension");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Client_ServerCertTypeExtension" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Client_ServerCertTypeExtension" */
    TStruct_Client_ServerCertTypeExtension() : CompositeDataUnit() {

        this->setName("Client_ServerCertTypeExtension");
    }


    /* Function to create another instance of class "TStruct_Client_ServerCertTypeExtension" */
    TStruct_Client_ServerCertTypeExtension* newInstance_() const {

        TStruct_Client_ServerCertTypeExtension* du = new TStruct_Client_ServerCertTypeExtension();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "server_certificate_types" ===== */
            TStruct_Client_ServerCertTypeExtension_server_certificate_types* _M0 = new TStruct_Client_ServerCertTypeExtension_server_certificate_types();
            this->appendChildRenamed(_M0, "server_certificate_types");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_PaddingByte" corresponding to Enum "PaddingByte" */
class TEnum_PaddingByte : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_PaddingByte" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 333, "PaddingByte");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_PaddingByte" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_PaddingByte" */
    TEnum_PaddingByte() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("PaddingByte");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("zero", 0);
        }
    }


    /* Function to create another instance of class "TEnum_PaddingByte" */
    TEnum_PaddingByte* newInstance_() const {

        TEnum_PaddingByte* du = new TEnum_PaddingByte();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_PaddingByte" */
EnumerationItemList TEnum_PaddingByte::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_PaddingExtension" corresponding to Struct "PaddingExtension" */
class TStruct_PaddingExtension : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_PaddingExtension" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 334, "PaddingExtension");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_PaddingExtension" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_PaddingExtension" */
    TStruct_PaddingExtension() : CompositeDataUnit() {

        this->setName("PaddingExtension");
    }


    /* Function to create another instance of class "TStruct_PaddingExtension" */
    TStruct_PaddingExtension* newInstance_() const {

        TStruct_PaddingExtension* du = new TStruct_PaddingExtension();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "padding" ===== */
            VectorDataUnit* _M0 = new StreamVectorDataUnit();
            TEnum_PaddingByte* _M0_V = new TEnum_PaddingByte();
            _M0->setElementTemplate(_M0_V);
            _M0->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M0, "padding");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_EncryptThenMacExtension" corresponding to Struct "EncryptThenMacExtension" */
class TStruct_EncryptThenMacExtension : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_EncryptThenMacExtension" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 335, "EncryptThenMacExtension");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_EncryptThenMacExtension" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_EncryptThenMacExtension" */
    TStruct_EncryptThenMacExtension() : CompositeDataUnit() {

        this->setName("EncryptThenMacExtension");
        this->setExpanded();
    }


    /* Function to create another instance of class "TStruct_EncryptThenMacExtension" */
    TStruct_EncryptThenMacExtension* newInstance_() const {

        TStruct_EncryptThenMacExtension* du = new TStruct_EncryptThenMacExtension();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ExtendedMasterSecretExtension" corresponding to Struct "ExtendedMasterSecretExtension" */
class TStruct_ExtendedMasterSecretExtension : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ExtendedMasterSecretExtension" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 336, "ExtendedMasterSecretExtension");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ExtendedMasterSecretExtension" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ExtendedMasterSecretExtension" */
    TStruct_ExtendedMasterSecretExtension() : CompositeDataUnit() {

        this->setName("ExtendedMasterSecretExtension");
        this->setExpanded();
    }


    /* Function to create another instance of class "TStruct_ExtendedMasterSecretExtension" */
    TStruct_ExtendedMasterSecretExtension* newInstance_() const {

        TStruct_ExtendedMasterSecretExtension* du = new TStruct_ExtendedMasterSecretExtension();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TEnum_CachedInformationType" corresponding to Enum "CachedInformationType" */
class TEnum_CachedInformationType : public EnumerationField {

    public:


    /* Static function returning type descriptor of class "TEnum_CachedInformationType" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(EnumerationField::typeDescriptor(), 337, "CachedInformationType");
        return desc;
    }


    /* Function returning type descriptor of class "TEnum_CachedInformationType" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TEnum_CachedInformationType" */
    TEnum_CachedInformationType() : EnumerationField(BC(0, 8), staticList_) {

        this->setName("CachedInformationType");

        /* Populate class-specific, static list of enumeration items if not yet done */
        if (staticList_.getNItems() == 0) {
            staticList_.addItem("cert"    , 1);
            staticList_.addItem("cert_req", 2);
        }
    }


    /* Function to create another instance of class "TEnum_CachedInformationType" */
    TEnum_CachedInformationType* newInstance_() const {

        TEnum_CachedInformationType* du = new TEnum_CachedInformationType();
        return du;
    }


    static EnumerationItemList staticList_;



};


/* List of enumeration items for enumeration class "TEnum_CachedInformationType" */
EnumerationItemList TEnum_CachedInformationType::staticList_;


/* ========================================================================= */

/* Definition of class "TStruct_Client_CachedObject_hash_value" corresponding to Struct "Client_CachedObject_hash_value" */
class TStruct_Client_CachedObject_hash_value : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Client_CachedObject_hash_value" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 338, "Client_CachedObject_hash_value");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Client_CachedObject_hash_value" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Client_CachedObject_hash_value" */
    TStruct_Client_CachedObject_hash_value() : CompositeDataUnit() {

        this->setName("Client_CachedObject_hash_value");
    }


    /* Function to create another instance of class "TStruct_Client_CachedObject_hash_value" */
    TStruct_Client_CachedObject_hash_value* newInstance_() const {

        TStruct_Client_CachedObject_hash_value* du = new TStruct_Client_CachedObject_hash_value();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_Client_CachedObject" corresponding to Struct "Client_CachedObject" */
class TStruct_Client_CachedObject : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Client_CachedObject" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 339, "Client_CachedObject");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Client_CachedObject" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Client_CachedObject" */
    TStruct_Client_CachedObject() : CompositeDataUnit() {

        this->setName("Client_CachedObject");
    }


    /* Function to create another instance of class "TStruct_Client_CachedObject" */
    TStruct_Client_CachedObject* newInstance_() const {

        TStruct_Client_CachedObject* du = new TStruct_Client_CachedObject();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "type" ===== */
            TEnum_CachedInformationType* _M0 = new TEnum_CachedInformationType();
            this->appendChildRenamed(_M0, "type");
            /* ===== Struct member "hash_value" ===== */
            TStruct_Client_CachedObject_hash_value* _M1 = new TStruct_Client_CachedObject_hash_value();
            this->appendChildRenamed(_M1, "hash_value");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_Server_CachedObject" corresponding to Struct "Server_CachedObject" */
class TStruct_Server_CachedObject : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Server_CachedObject" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 340, "Server_CachedObject");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Server_CachedObject" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Server_CachedObject" */
    TStruct_Server_CachedObject() : CompositeDataUnit() {

        this->setName("Server_CachedObject");
    }


    /* Function to create another instance of class "TStruct_Server_CachedObject" */
    TStruct_Server_CachedObject* newInstance_() const {

        TStruct_Server_CachedObject* du = new TStruct_Server_CachedObject();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "type" ===== */
            TEnum_CachedInformationType* _M0 = new TEnum_CachedInformationType();
            this->appendChildRenamed(_M0, "type");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_Client_CachedInformation_cached_info" corresponding to Struct "Client_CachedInformation_cached_info" */
class TStruct_Client_CachedInformation_cached_info : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Client_CachedInformation_cached_info" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 341, "Client_CachedInformation_cached_info");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Client_CachedInformation_cached_info" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Client_CachedInformation_cached_info" */
    TStruct_Client_CachedInformation_cached_info() : CompositeDataUnit() {

        this->setName("Client_CachedInformation_cached_info");
    }


    /* Function to create another instance of class "TStruct_Client_CachedInformation_cached_info" */
    TStruct_Client_CachedInformation_cached_info* newInstance_() const {

        TStruct_Client_CachedInformation_cached_info* du = new TStruct_Client_CachedInformation_cached_info();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TStruct_Client_CachedObject* _M1_V = new TStruct_Client_CachedObject();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_Client_CachedInformation" corresponding to Struct "Client_CachedInformation" */
class TStruct_Client_CachedInformation : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Client_CachedInformation" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 342, "Client_CachedInformation");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Client_CachedInformation" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Client_CachedInformation" */
    TStruct_Client_CachedInformation() : CompositeDataUnit() {

        this->setName("Client_CachedInformation");
    }


    /* Function to create another instance of class "TStruct_Client_CachedInformation" */
    TStruct_Client_CachedInformation* newInstance_() const {

        TStruct_Client_CachedInformation* du = new TStruct_Client_CachedInformation();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "cached_info" ===== */
            TStruct_Client_CachedInformation_cached_info* _M0 = new TStruct_Client_CachedInformation_cached_info();
            this->appendChildRenamed(_M0, "cached_info");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_Server_CachedInformation_cached_info" corresponding to Struct "Server_CachedInformation_cached_info" */
class TStruct_Server_CachedInformation_cached_info : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Server_CachedInformation_cached_info" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 343, "Server_CachedInformation_cached_info");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Server_CachedInformation_cached_info" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Server_CachedInformation_cached_info" */
    TStruct_Server_CachedInformation_cached_info() : CompositeDataUnit() {

        this->setName("Server_CachedInformation_cached_info");
    }


    /* Function to create another instance of class "TStruct_Server_CachedInformation_cached_info" */
    TStruct_Server_CachedInformation_cached_info* newInstance_() const {

        TStruct_Server_CachedInformation_cached_info* du = new TStruct_Server_CachedInformation_cached_info();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TStruct_Server_CachedObject* _M1_V = new TStruct_Server_CachedObject();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_Server_CachedInformation" corresponding to Struct "Server_CachedInformation" */
class TStruct_Server_CachedInformation : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Server_CachedInformation" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 344, "Server_CachedInformation");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Server_CachedInformation" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Server_CachedInformation" */
    TStruct_Server_CachedInformation() : CompositeDataUnit() {

        this->setName("Server_CachedInformation");
    }


    /* Function to create another instance of class "TStruct_Server_CachedInformation" */
    TStruct_Server_CachedInformation* newInstance_() const {

        TStruct_Server_CachedInformation* du = new TStruct_Server_CachedInformation();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "cached_info" ===== */
            TStruct_Server_CachedInformation_cached_info* _M0 = new TStruct_Server_CachedInformation_cached_info();
            this->appendChildRenamed(_M0, "cached_info");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_RenegotiationInfo_renegotiated_connection" corresponding to Struct "RenegotiationInfo_renegotiated_connection" */
class TStruct_RenegotiationInfo_renegotiated_connection : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_RenegotiationInfo_renegotiated_connection" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 345, "RenegotiationInfo_renegotiated_connection");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_RenegotiationInfo_renegotiated_connection" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_RenegotiationInfo_renegotiated_connection" */
    TStruct_RenegotiationInfo_renegotiated_connection() : CompositeDataUnit() {

        this->setName("RenegotiationInfo_renegotiated_connection");
    }


    /* Function to create another instance of class "TStruct_RenegotiationInfo_renegotiated_connection" */
    TStruct_RenegotiationInfo_renegotiated_connection* newInstance_() const {

        TStruct_RenegotiationInfo_renegotiated_connection* du = new TStruct_RenegotiationInfo_renegotiated_connection();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            OpaqueField* _M1 = new OpaqueField(BC(_value__N, 0));
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_RenegotiationInfo" corresponding to Struct "RenegotiationInfo" */
class TStruct_RenegotiationInfo : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_RenegotiationInfo" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 346, "RenegotiationInfo");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_RenegotiationInfo" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_RenegotiationInfo" */
    TStruct_RenegotiationInfo() : CompositeDataUnit() {

        this->setName("RenegotiationInfo");
    }


    /* Function to create another instance of class "TStruct_RenegotiationInfo" */
    TStruct_RenegotiationInfo* newInstance_() const {

        TStruct_RenegotiationInfo* du = new TStruct_RenegotiationInfo();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "renegotiated_connection" ===== */
            TStruct_RenegotiationInfo_renegotiated_connection* _M0 = new TStruct_RenegotiationInfo_renegotiated_connection();
            this->appendChildRenamed(_M0, "renegotiated_connection");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_Extension" corresponding to Struct "Extension" */
class TStruct_Extension : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_Extension" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 347, "Extension");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_Extension" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_Extension" */
    TStruct_Extension() : CompositeDataUnit() {

        this->setName("Extension");
    }


    /* Function to create another instance of class "TStruct_Extension" */
    TStruct_Extension* newInstance_() const {

        TStruct_Extension* du = new TStruct_Extension();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "type" ===== */
            TEnum_ExtensionType* _M0 = new TEnum_ExtensionType();
            this->appendChildRenamed(_M0, "type");
            /* ===== Struct member "length" ===== */
            IntegerField* _M1 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M1, "length");

        } else if (len == 2 && decoded >= 2) {

            int _value_type = (*this)[0]->propGet<int>(".value");
            int _value_length = (*this)[1]->propGet<int>(".value");
            if (_value_type == 0) {
                /* ===== Struct member "_M0" ===== */
                TStruct_ServerNameList* _C_M0 = new TStruct_ServerNameList();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 1) {
                /* ===== Struct member "_M0" ===== */
                TStruct_MaxFragmentLengthExtension* _C_M0 = new TStruct_MaxFragmentLengthExtension();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 2) {
                /* ===== Struct member "_M0" ===== */
                TStruct_CertificateURL* _C_M0 = new TStruct_CertificateURL();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 3) {
                /* ===== Struct member "_M0" ===== */
                TStruct_TrustedAuthorities* _C_M0 = new TStruct_TrustedAuthorities();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 4) {
                /* ===== Struct member "_M0" ===== */
                TStruct_TruncatedHMACExtension* _C_M0 = new TStruct_TruncatedHMACExtension();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 5) {
                /* ===== Struct member "_M0" ===== */
                TStruct_CertificateStatusRequest* _C_M0 = new TStruct_CertificateStatusRequest();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 6) {
                /* ===== Struct member "_M0" ===== */
                TStruct_UserMappingTypeList* _C_M0 = new TStruct_UserMappingTypeList();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if ((_value_type == 7) || (_value_type == 8)) {
                /* ===== Struct member "_M0" ===== */
                TStruct_AuthzDataFormats* _C_M0 = new TStruct_AuthzDataFormats();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 9) {
                /* ===== Struct member "_M0" ===== */
                TStruct_Client_CertificateTypeExtension* _C_M0 = new TStruct_Client_CertificateTypeExtension();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 10) {
                /* ===== Struct member "_M0" ===== */
                TStruct_EllipticCurveList* _C_M0 = new TStruct_EllipticCurveList();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 11) {
                /* ===== Struct member "_M0" ===== */
                TStruct_ECPointFormatList* _C_M0 = new TStruct_ECPointFormatList();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 12) {
                /* ===== Struct member "_M0" ===== */
                TStruct_SRPExtension* _C_M0 = new TStruct_SRPExtension();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 13) {
                /* ===== Struct member "_M0" ===== */
                TStruct_SignatureAndHashAlgorithms* _C_M0 = new TStruct_SignatureAndHashAlgorithms();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 14) {
                /* ===== Struct member "_M0" ===== */
                TStruct_UseSRTPData* _C_M0 = new TStruct_UseSRTPData();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 15) {
                /* ===== Struct member "_M0" ===== */
                TStruct_HeartbeatExtension* _C_M0 = new TStruct_HeartbeatExtension();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 16) {
                /* ===== Struct member "_M0" ===== */
                TStruct_ProtocolNameList* _C_M0 = new TStruct_ProtocolNameList();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 17) {
                /* ===== Struct member "_M0" ===== */
                TStruct_CertificateStatusRequestListV2* _C_M0 = new TStruct_CertificateStatusRequestListV2();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 18) {
                /* ===== Struct member "_M0" ===== */
                TStruct_Client_SignedCertificateTimestamp* _C_M0 = new TStruct_Client_SignedCertificateTimestamp();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 19) {
                /* ===== Struct member "_M0" ===== */
                TStruct_Client_ClientCertTypeExtension* _C_M0 = new TStruct_Client_ClientCertTypeExtension();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 20) {
                /* ===== Struct member "_M0" ===== */
                TStruct_Client_ServerCertTypeExtension* _C_M0 = new TStruct_Client_ServerCertTypeExtension();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 21) {
                /* ===== Struct member "_M0" ===== */
                TStruct_PaddingExtension* _C_M0 = new TStruct_PaddingExtension();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 22) {
                /* ===== Struct member "_M0" ===== */
                TStruct_EncryptThenMacExtension* _C_M0 = new TStruct_EncryptThenMacExtension();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 23) {
                /* ===== Struct member "_M0" ===== */
                TStruct_ExtendedMasterSecretExtension* _C_M0 = new TStruct_ExtendedMasterSecretExtension();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 25) {
                /* ===== Struct member "_M0" ===== */
                TStruct_Client_CachedInformation* _C_M0 = new TStruct_Client_CachedInformation();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else if (_value_type == 65281) {
                /* ===== Struct member "_M0" ===== */
                TStruct_RenegotiationInfo* _C_M0 = new TStruct_RenegotiationInfo();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "_M0");
            } else {
            /* ===== Struct member "data" ===== */
            OpaqueField* _C_M0 = new OpaqueField(BC(_value_length, 0));
            _C_M0->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_C_M0, "data");}
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: type <--- f-of-cases-in(datax) */
        } else if (index == 1) {
            /* 1: length <--- f-of-cases-in(datax) */
            int _value_0 = 0;
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            (*this)[1]->propSet<int>(".value", _value_0);
        }
        return ok;
    }


    std::string getDynamicTypeName_() const {

        DataUnit* du = (*this)[0];
        return (du != 0) ? du->propGetDefault<std::string>(".name", "") : "";
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ClientHello_extensions" corresponding to Struct "ClientHello_extensions" */
class TStruct_ClientHello_extensions : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ClientHello_extensions" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 348, "ClientHello_extensions");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ClientHello_extensions" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ClientHello_extensions" */
    TStruct_ClientHello_extensions() : CompositeDataUnit() {

        this->setName("ClientHello_extensions");
    }


    /* Function to create another instance of class "TStruct_ClientHello_extensions" */
    TStruct_ClientHello_extensions* newInstance_() const {

        TStruct_ClientHello_extensions* du = new TStruct_ClientHello_extensions();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TStruct_Extension* _M1_V = new TStruct_Extension();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ClientHello" corresponding to Struct "ClientHello" */
class TStruct_ClientHello : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ClientHello" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 349, "ClientHello");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ClientHello" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ClientHello" */
    TStruct_ClientHello() : CompositeDataUnit() {

        this->setName("ClientHello");
    }


    /* Function to create another instance of class "TStruct_ClientHello" */
    TStruct_ClientHello* newInstance_() const {

        TStruct_ClientHello* du = new TStruct_ClientHello();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "version" ===== */
            TEnum_Version* _M0 = new TEnum_Version();
            this->appendChildRenamed(_M0, "version");
            /* ===== Struct member "random" ===== */
            OpaqueField* _M1 = new OpaqueField(BC(32, 0));
            this->appendChildRenamed(_M1, "random");
            /* ===== Struct member "session_id_length" ===== */
            IntegerField* _M2 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M2, "session_id_length");

        } else if (len == 3 && decoded >= 3) {

            /* ===== Struct member "session_id" ===== */
            int _value_session_id_length = (*this)[2]->propGet<int>(".value");
            OpaqueField* _M3 = new OpaqueField(BC(_value_session_id_length, 0));
            _M3->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M3, "session_id");
            /* ===== Struct member "cipher_suites" ===== */
            TStruct_ClientHello_cipher_suites* _M4 = new TStruct_ClientHello_cipher_suites();
            this->appendChildRenamed(_M4, "cipher_suites");
            /* ===== Struct member "compression_methods" ===== */
            TStruct_ClientHello_compression_methods* _M5 = new TStruct_ClientHello_compression_methods();
            this->appendChildRenamed(_M5, "compression_methods");
            /* ===== Struct member "extensions" ===== */
            TStruct_ClientHello_extensions* _M6 = new TStruct_ClientHello_extensions();
            this->appendChildRenamed(_M6, "extensions");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 2) {
            /* 2: session_id_length <--- f(session_id) */
            int _value_0 = 0;
            if ((*this)[3] != 0) {
                _value_0 = (*this)[3]->getLength().byteAligned();
            }
            (*this)[2]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_DTLSClientHello_extensions" corresponding to Struct "DTLSClientHello_extensions" */
class TStruct_DTLSClientHello_extensions : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_DTLSClientHello_extensions" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 350, "DTLSClientHello_extensions");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_DTLSClientHello_extensions" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_DTLSClientHello_extensions" */
    TStruct_DTLSClientHello_extensions() : CompositeDataUnit() {

        this->setName("DTLSClientHello_extensions");
    }


    /* Function to create another instance of class "TStruct_DTLSClientHello_extensions" */
    TStruct_DTLSClientHello_extensions* newInstance_() const {

        TStruct_DTLSClientHello_extensions* du = new TStruct_DTLSClientHello_extensions();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TStruct_Extension* _M1_V = new TStruct_Extension();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_DTLSClientHello" corresponding to Struct "DTLSClientHello" */
class TStruct_DTLSClientHello : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_DTLSClientHello" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 351, "DTLSClientHello");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_DTLSClientHello" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_DTLSClientHello" */
    TStruct_DTLSClientHello() : CompositeDataUnit() {

        this->setName("DTLSClientHello");
    }


    /* Function to create another instance of class "TStruct_DTLSClientHello" */
    TStruct_DTLSClientHello* newInstance_() const {

        TStruct_DTLSClientHello* du = new TStruct_DTLSClientHello();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "version" ===== */
            TEnum_Version* _M0 = new TEnum_Version();
            this->appendChildRenamed(_M0, "version");
            /* ===== Struct member "random" ===== */
            OpaqueField* _M1 = new OpaqueField(BC(32, 0));
            this->appendChildRenamed(_M1, "random");
            /* ===== Struct member "session_id_length" ===== */
            IntegerField* _M2 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M2, "session_id_length");

        } else if (len == 3 && decoded >= 3) {

            /* ===== Struct member "session_id" ===== */
            int _value_session_id_length = (*this)[2]->propGet<int>(".value");
            OpaqueField* _M3 = new OpaqueField(BC(_value_session_id_length, 0));
            _M3->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M3, "session_id");
            /* ===== Struct member "cookie" ===== */
            TStruct_DTLSClientHello_cookie* _M4 = new TStruct_DTLSClientHello_cookie();
            this->appendChildRenamed(_M4, "cookie");
            /* ===== Struct member "cipher_suites" ===== */
            TStruct_DTLSClientHello_cipher_suites* _M5 = new TStruct_DTLSClientHello_cipher_suites();
            this->appendChildRenamed(_M5, "cipher_suites");
            /* ===== Struct member "compression_methods" ===== */
            TStruct_DTLSClientHello_compression_methods* _M6 = new TStruct_DTLSClientHello_compression_methods();
            this->appendChildRenamed(_M6, "compression_methods");
            /* ===== Struct member "extensions" ===== */
            TStruct_DTLSClientHello_extensions* _M7 = new TStruct_DTLSClientHello_extensions();
            this->appendChildRenamed(_M7, "extensions");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 2) {
            /* 2: session_id_length <--- f(session_id) */
            int _value_0 = 0;
            if ((*this)[3] != 0) {
                _value_0 = (*this)[3]->getLength().byteAligned();
            }
            (*this)[2]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_DTLSHandshakeMessage" corresponding to Struct "DTLSHandshakeMessage" */
class TStruct_DTLSHandshakeMessage : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_DTLSHandshakeMessage" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 352, "DTLSHandshakeMessage");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_DTLSHandshakeMessage" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_DTLSHandshakeMessage" */
    TStruct_DTLSHandshakeMessage() : CompositeDataUnit() {

        this->setName("DTLSHandshakeMessage");
    }


    /* Function to create another instance of class "TStruct_DTLSHandshakeMessage" */
    TStruct_DTLSHandshakeMessage* newInstance_() const {

        TStruct_DTLSHandshakeMessage* du = new TStruct_DTLSHandshakeMessage();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "type" ===== */
            TEnum_HandshakeType* _M0 = new TEnum_HandshakeType();
            this->appendChildRenamed(_M0, "type");
            /* ===== Struct member "length" ===== */
            IntegerField* _M1 = new IntegerField(BC(0, 24), false);
            this->appendChildRenamed(_M1, "length");
            /* ===== Struct member "message_seq" ===== */
            IntegerField* _M2 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M2, "message_seq");
            /* ===== Struct member "fragment_offset" ===== */
            IntegerField* _M3 = new IntegerField(BC(0, 24), false);
            this->appendChildRenamed(_M3, "fragment_offset");
            /* ===== Struct member "fragment_length" ===== */
            IntegerField* _M4 = new IntegerField(BC(0, 24), false);
            this->appendChildRenamed(_M4, "fragment_length");

        } else if (len == 5 && decoded >= 2) {

            int _value_type = (*this)[0]->propGet<int>(".value");
            int _value_length = (*this)[1]->propGet<int>(".value");
            if (_value_type == 1) {
                /* ===== Struct member "clientHello" ===== */
                TStruct_DTLSClientHello* _C_M0 = new TStruct_DTLSClientHello();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "clientHello");
            } else {
            /* ===== Struct member "unknown" ===== */
            OpaqueField* _C_M0 = new OpaqueField(BC(_value_length, 0));
            _C_M0->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_C_M0, "unknown");}
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: type <--- f-of-cases-in(msg) */
        } else if (index == 1) {
            /* 1: length <--- f-of-cases-in(msg) */
            int _value_0 = 0;
            if (true) {
                if ((*this)[5] != 0) {
                    _value_0 = (*this)[5]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[5] != 0) {
                    _value_0 = (*this)[5]->getLength().byteAligned();
                }
            }
            (*this)[1]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_DTLSRecord" corresponding to Struct "DTLSRecord" */
class TStruct_DTLSRecord : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_DTLSRecord" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 353, "DTLSRecord");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_DTLSRecord" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_DTLSRecord" */
    TStruct_DTLSRecord() : CompositeDataUnit() {

        this->setName("DTLSRecord");
    }


    /* Function to create another instance of class "TStruct_DTLSRecord" */
    TStruct_DTLSRecord* newInstance_() const {

        TStruct_DTLSRecord* du = new TStruct_DTLSRecord();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "type" ===== */
            TEnum_Type* _M0 = new TEnum_Type();
            this->appendChildRenamed(_M0, "type");
            /* ===== Struct member "version" ===== */
            TEnum_Version* _M1 = new TEnum_Version();
            this->appendChildRenamed(_M1, "version");
            /* ===== Struct member "epoch" ===== */
            IntegerField* _M2 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M2, "epoch");
            /* ===== Struct member "sequence_number" ===== */
            IntegerField* _M3 = new IntegerField(BC(0, 48), false);
            this->appendChildRenamed(_M3, "sequence_number");
            /* ===== Struct member "length" ===== */
            IntegerField* _M4 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M4, "length");

        } else if (len == 5 && decoded >= 5) {

            int _value_type = (*this)[0]->propGet<int>(".value");
            int _value_length = (*this)[4]->propGet<int>(".value");
            if (_value_type == 21) {
                /* ===== Struct member "alert" ===== */
                TStruct_Alert* _C_M0 = new TStruct_Alert();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "alert");
            } else if (_value_type == 22) {
                /* ===== Struct member "hsMsg" ===== */
                TStruct_DTLSHandshakeMessage* _C_M0 = new TStruct_DTLSHandshakeMessage();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "hsMsg");
            } else {
            /* ===== Struct member "unknown" ===== */
            OpaqueField* _C_M0 = new OpaqueField(BC(_value_length, 0));
            _C_M0->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_C_M0, "unknown");}
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: type <--- f-of-cases-in(msg) */
        } else if (index == 4) {
            /* 4: length <--- f-of-cases-in(msg) */
            int _value_0 = 0;
            if (true) {
                if ((*this)[5] != 0) {
                    _value_0 = (*this)[5]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[5] != 0) {
                    _value_0 = (*this)[5]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[5] != 0) {
                    _value_0 = (*this)[5]->getLength().byteAligned();
                }
            }
            (*this)[4]->propSet<int>(".value", _value_0);
        }
        return ok;
    }


    std::string getDynamicTypeName_() const {

        DataUnit* du = (*this)[0];
        return (du != 0) ? du->propGetDefault<std::string>(".name", "") : "";
    }
};



/* ========================================================================= */

/* Definition of class "TVector_DTLSMainType" corresponding to Vector "DTLSMainType" */
class TVector_DTLSMainType : public StreamVectorDataUnit {

    public:


    /* Static function returning type descriptor of class "TVector_DTLSMainType" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(StreamVectorDataUnit::typeDescriptor(), 354, "DTLSMainType");
        return desc;
    }


    /* Function returning type descriptor of class "TVector_DTLSMainType" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TVector_DTLSMainType" */
    TVector_DTLSMainType() : StreamVectorDataUnit() {

        this->setName("DTLSMainType");
        /* set the vector element template */
        TStruct_DTLSRecord* _T = new TStruct_DTLSRecord();
        this->setElementTemplate(_T);
    }


    /* Function to create another instance of class "TVector_DTLSMainType" */
    TVector_DTLSMainType* newInstance_() const {

        TVector_DTLSMainType* du = new TVector_DTLSMainType();
        return du;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ServerHello_extensions" corresponding to Struct "ServerHello_extensions" */
class TStruct_ServerHello_extensions : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ServerHello_extensions" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 355, "ServerHello_extensions");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ServerHello_extensions" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ServerHello_extensions" */
    TStruct_ServerHello_extensions() : CompositeDataUnit() {

        this->setName("ServerHello_extensions");
    }


    /* Function to create another instance of class "TStruct_ServerHello_extensions" */
    TStruct_ServerHello_extensions* newInstance_() const {

        TStruct_ServerHello_extensions* du = new TStruct_ServerHello_extensions();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "_N" ===== */
            IntegerField* _M0 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M0, "_N");

        } else if (len == 1 && decoded >= 1) {

            /* ===== Struct member "_V" ===== */
            int _value__N = (*this)[0]->propGet<int>(".value");
            VectorDataUnit* _M1 = new StreamVectorDataUnit(BC(_value__N, 0));
            TStruct_Extension* _M1_V = new TStruct_Extension();
            _M1->setElementTemplate(_M1_V);
            _M1->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M1, "_V");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: _N <--- f(_V) */
            int _value_0 = 0;
            if ((*this)[1] != 0) {
                _value_0 = (*this)[1]->getLength().byteAligned();
            }
            (*this)[0]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_ServerHello" corresponding to Struct "ServerHello" */
class TStruct_ServerHello : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_ServerHello" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 356, "ServerHello");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_ServerHello" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_ServerHello" */
    TStruct_ServerHello() : CompositeDataUnit() {

        this->setName("ServerHello");
    }


    /* Function to create another instance of class "TStruct_ServerHello" */
    TStruct_ServerHello* newInstance_() const {

        TStruct_ServerHello* du = new TStruct_ServerHello();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "version" ===== */
            TEnum_Version* _M0 = new TEnum_Version();
            this->appendChildRenamed(_M0, "version");
            /* ===== Struct member "random" ===== */
            OpaqueField* _M1 = new OpaqueField(BC(32, 0));
            this->appendChildRenamed(_M1, "random");
            /* ===== Struct member "session_id_length" ===== */
            IntegerField* _M2 = new IntegerField(BC(0, 8), false);
            this->appendChildRenamed(_M2, "session_id_length");

        } else if (len == 3 && decoded >= 3) {

            /* ===== Struct member "session_id" ===== */
            int _value_session_id_length = (*this)[2]->propGet<int>(".value");
            OpaqueField* _M3 = new OpaqueField(BC(_value_session_id_length, 0));
            _M3->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_M3, "session_id");
            /* ===== Struct member "cipher_suite" ===== */
            TEnum_CipherSuite* _M4 = new TEnum_CipherSuite();
            this->appendChildRenamed(_M4, "cipher_suite");
            /* ===== Struct member "compression_method" ===== */
            TEnum_CompressionMethod* _M5 = new TEnum_CompressionMethod();
            this->appendChildRenamed(_M5, "compression_method");
            /* ===== Struct member "extensions" ===== */
            TStruct_ServerHello_extensions* _M6 = new TStruct_ServerHello_extensions();
            this->appendChildRenamed(_M6, "extensions");
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 2) {
            /* 2: session_id_length <--- f(session_id) */
            int _value_0 = 0;
            if ((*this)[3] != 0) {
                _value_0 = (*this)[3]->getLength().byteAligned();
            }
            (*this)[2]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_HandshakeMessage" corresponding to Struct "HandshakeMessage" */
class TStruct_HandshakeMessage : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_HandshakeMessage" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 357, "HandshakeMessage");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_HandshakeMessage" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_HandshakeMessage" */
    TStruct_HandshakeMessage() : CompositeDataUnit() {

        this->setName("HandshakeMessage");
    }


    /* Function to create another instance of class "TStruct_HandshakeMessage" */
    TStruct_HandshakeMessage* newInstance_() const {

        TStruct_HandshakeMessage* du = new TStruct_HandshakeMessage();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "type" ===== */
            TEnum_HandshakeType* _M0 = new TEnum_HandshakeType();
            this->appendChildRenamed(_M0, "type");
            /* ===== Struct member "length" ===== */
            IntegerField* _M1 = new IntegerField(BC(0, 24), false);
            this->appendChildRenamed(_M1, "length");

        } else if (len == 2 && decoded >= 2) {

            int _value_type = (*this)[0]->propGet<int>(".value");
            int _value_length = (*this)[1]->propGet<int>(".value");
            if (_value_type == 1) {
                /* ===== Struct member "clientHello" ===== */
                TStruct_ClientHello* _C_M0 = new TStruct_ClientHello();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "clientHello");
            } else if (_value_type == 2) {
                /* ===== Struct member "serverHello" ===== */
                TStruct_ServerHello* _C_M0 = new TStruct_ServerHello();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "serverHello");
            } else if (_value_type == 11) {
                /* ===== Struct member "certificates" ===== */
                TStruct_HandshakeMessage_msg__C2_certificates* _C_M0 = new TStruct_HandshakeMessage_msg__C2_certificates();
                this->appendChildRenamed(_C_M0, "certificates");
            } else if (_value_type == 12) {
                /* ===== Struct member "serverKeyExchange" ===== */
                TStruct_ServerKeyExchange* _C_M0 = new TStruct_ServerKeyExchange();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "serverKeyExchange");
            } else if (_value_type == 16) {
                /* ===== Struct member "clientKeyExchange" ===== */
                TStruct_ClientKeyExchange* _C_M0 = new TStruct_ClientKeyExchange();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "clientKeyExchange");
            } else {
            /* ===== Struct member "unknown" ===== */
            OpaqueField* _C_M0 = new OpaqueField(BC(_value_length, 0));
            _C_M0->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_C_M0, "unknown");}
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: type <--- f-of-cases-in(msg) */
        } else if (index == 1) {
            /* 1: length <--- f-of-cases-in(msg) */
            int _value_0 = 0;
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {

            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[2] != 0) {
                    _value_0 = (*this)[2]->getLength().byteAligned();
                }
            }
            (*this)[1]->propSet<int>(".value", _value_0);
        }
        return ok;
    }
};



/* ========================================================================= */

/* Definition of class "TStruct_TLSRecord" corresponding to Struct "TLSRecord" */
class TStruct_TLSRecord : public CompositeDataUnit {

    public:


    /* Static function returning type descriptor of class "TStruct_TLSRecord" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(CompositeDataUnit::typeDescriptor(), 358, "TLSRecord");
        return desc;
    }


    /* Function returning type descriptor of class "TStruct_TLSRecord" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TStruct_TLSRecord" */
    TStruct_TLSRecord() : CompositeDataUnit() {

        this->setName("TLSRecord");
    }


    /* Function to create another instance of class "TStruct_TLSRecord" */
    TStruct_TLSRecord* newInstance_() const {

        TStruct_TLSRecord* du = new TStruct_TLSRecord();
        return du;
    }


    bool expand_(size_t len, size_t decoded, bool dry, bool ahead) {

        /* will be set to true once expansion is complete */
        bool complete = false;
        if (len == 0) {

            /* ===== Struct member "type" ===== */
            TEnum_Type* _M0 = new TEnum_Type();
            this->appendChildRenamed(_M0, "type");
            /* ===== Struct member "version" ===== */
            TEnum_Version* _M1 = new TEnum_Version();
            this->appendChildRenamed(_M1, "version");
            /* ===== Struct member "length" ===== */
            IntegerField* _M2 = new IntegerField(BC(0, 16), false);
            this->appendChildRenamed(_M2, "length");

        } else if (len == 3 && decoded >= 3) {

            int _value_type = (*this)[0]->propGet<int>(".value");
            int _value_length = (*this)[2]->propGet<int>(".value");
            if (_value_type == 21) {
                /* ===== Struct member "alert" ===== */
                TStruct_Alert* _C_M0 = new TStruct_Alert();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "alert");
            } else if (_value_type == 22) {
                /* ===== Struct member "hsMsg" ===== */
                TStruct_HandshakeMessage* _C_M0 = new TStruct_HandshakeMessage();
                _C_M0->propSet<int>("_dynlen", 1);
                _C_M0->dissector().setSize(_value_length);
                this->appendChildRenamed(_C_M0, "hsMsg");
            } else {
            /* ===== Struct member "unknown" ===== */
            OpaqueField* _C_M0 = new OpaqueField(BC(_value_length, 0));
            _C_M0->propSet<int>("_dynlen", 1);
            this->appendChildRenamed(_C_M0, "unknown");}
            complete = true;

        }
        return complete;
    }


    bool updateMember_(size_t index) {

        bool ok = true;
        if (index == 0) {
            /* 0: type <--- f-of-cases-in(msg) */
        } else if (index == 2) {
            /* 2: length <--- f-of-cases-in(msg) */
            int _value_0 = 0;
            if (true) {
                if ((*this)[3] != 0) {
                    _value_0 = (*this)[3]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[3] != 0) {
                    _value_0 = (*this)[3]->getLength().byteAligned();
                }
            }
            if (true) {
                if ((*this)[3] != 0) {
                    _value_0 = (*this)[3]->getLength().byteAligned();
                }
            }
            (*this)[2]->propSet<int>(".value", _value_0);
        }
        return ok;
    }


    std::string getDynamicTypeName_() const {

        DataUnit* du = (*this)[0];
        return (du != 0) ? du->propGetDefault<std::string>(".name", "") : "";
    }
};



/* ========================================================================= */

/* Definition of class "TVector_MainType" corresponding to Vector "MainType" */
class TVector_MainType : public StreamVectorDataUnit {

    public:


    /* Static function returning type descriptor of class "TVector_MainType" */
    static inline const TypeDescriptor& typeDescriptor() {

        static const TypeDescriptor desc(StreamVectorDataUnit::typeDescriptor(), 359, "MainType");
        return desc;
    }


    /* Function returning type descriptor of class "TVector_MainType" */
    const TypeDescriptor& getTypeDescriptor() const {

        return typeDescriptor();
    }


    /* Default constructor of class "TVector_MainType" */
    TVector_MainType() : StreamVectorDataUnit() {

        this->setName("MainType");
        /* set the vector element template */
        TStruct_TLSRecord* _T = new TStruct_TLSRecord();
        this->setElementTemplate(_T);
    }


    /* Function to create another instance of class "TVector_MainType" */
    TVector_MainType* newInstance_() const {

        TVector_MainType* du = new TVector_MainType();
        return du;
    }
};
