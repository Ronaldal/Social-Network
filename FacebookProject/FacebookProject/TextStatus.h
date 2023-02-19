#ifndef __TEXTSTATUS_H
#define __TEXTSTATUS_H
#include "Status.h"

//inherit from status class and have its own data.
class TextStatus : public Status
{
	string text;
public:
	TextStatus(const string& text) : text(text) {};
	void showStatus() const;
	virtual bool operator==(const Status& other) const;
	virtual bool operator!=(const Status& other) const;
	const TextStatus& operator=(const TextStatus& other);
	TextStatus(const TextStatus& other);
	const TextStatus& operator=(const TextStatus&& other);
	TextStatus(const TextStatus&& other);
	virtual Status* clone() const override;
	virtual void toOs(ostream& os) const;
	virtual ~TextStatus() {};
};
#endif // !__TEXTSTATUS_H

