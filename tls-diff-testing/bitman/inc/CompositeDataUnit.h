#ifndef __CompositeDataUnit_H__
#define __CompositeDataUnit_H__

#include "DataUnit.h"

/* ==========================================================================
 *
 *
 *
 * ========================================================================== */

class CompositeDataUnit : public DataUnit {

private:

	/* this class type's descriptor */
	static TypeDescriptor desc_;


	/* TODO: Add description */
	DataUnit* child_;

	/* TODO: Add description */
	bool autoExtend_;

	/* TODO: Add description */
	bool expanded_;

	/* TODO: Add description */
	bool stalled_;

	/* TODO: Add description */
	size_t dissectionHeadIndex_;


protected:

	/* TODO: Add description */
	CompositeDataUnit(bool expanded);


	/* TODO: Add description */
	virtual void printBody(const PrintOptions& options) const;

	/* === To be implemented by sub-classes: =============================== */

	/* TODO: Add description */
	virtual bool expand_(size_t len, size_t decoded, bool dry, bool ahead);

	/* TODO: Add description */
	virtual bool updateMember_(size_t index);

	/* ===================================================================== */

	/* --- from DataUnit -> ProtocolDissector class: ----------------------- */

	/* TODO: Add description */
	virtual void dissectorBodyReset();

	/* TODO: Add description */
	virtual bool dissectorBodyIsAccepting() const;

	/* TODO: Add description */
	virtual BC dissectorBodyDissect(StreamReader& reader);

	/* --- from DataUnit -> BufferReader class: ---------------------------- */

	/* TODO: Add description */
	virtual bool getBit_(const BC& bc) const;

	/* TODO: Add description */
	virtual uint8_t getByte_(const BC& bc) const;

	/* TODO: Add description */
	virtual BC copyTo_(BufferWriter& buffer) const;

	/* TODO: Add description */
	virtual BC getLength_() const;

	/* --- from DataUnit class: -------------------------------------------- */

	/* TODO: Add description */
	virtual bool isDecoded_() const;

	/* TODO: Add description */
	virtual DataUnit* getChild_() const;

	/* TODO: Add description */
	virtual void setChild_(DataUnit* child);

	/* TODO: Add description */
	virtual bool repair_(bool recursive = true);

	/* --------------------------------------------------------------------- */

	/* TODO: Add description */
	virtual bool propRedirectHook_(std::string& name,
			PropertyNode*& node) const;


	/* TODO: Add description */
	virtual std::string getAnchorBrackets_() const;

	/* TODO: Add description */
	virtual bool printCollapsed_() const;


public:

	/* TODO: Add description */
	static inline const TypeDescriptor& typeDescriptor() {

		return desc_;
	}


	/* TODO: Add description */
	CompositeDataUnit();


	/* TODO: Add description */
	const TypeDescriptor& getTypeDescriptor() const;


	/* --- from DataUnit -> BufferWriter class: ---------------------------- */

	/* TODO: Add description */
	virtual bool appendBit(bool bit);

	/* TODO: Add description */
	virtual bool appendByte(uint8_t byte);

	/* --- from DataUnit -> BufferModifier class: -------------------------- */

	/* TODO: Add description */
	virtual bool setBit(const BC& bc, bool bit);

	/* TODO: Add description */
	virtual bool setByte(const BC& bc, uint8_t byte);

	/* TODO: Add description */
	virtual void clear();

	/* TODO: Add description */
	virtual void truncate(const BC& length);

	/* --------------------------------------------------------------------- */

	/* TODO: Add description */
	virtual std::string getAsText() const;


	/* TODO: Add description */
	bool appendChild(DataUnit* dataUnit);

	/* TODO: Add description */
	bool appendChildRenamed(DataUnit* dataUnit, const std::string& newName);


	/* TODO: Add description */
	size_t getNDecoded() const;


	/* TODO: Add description */
	bool expand(bool dry);

	/* TODO: Add description */
	void setExpanded() {

		expanded_ = true;
	}


	/* TODO: Add description */
	inline bool updateMember(size_t index) {

		return this->updateMember_(index);
	}


	/* TODO: Add description */
	size_t deleteChildren(size_t from = 0);


	/* TODO: Add description */
	virtual ~CompositeDataUnit();

};

#endif
