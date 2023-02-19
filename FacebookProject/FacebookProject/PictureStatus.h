#ifndef __PICTURESTATUS_H
#define __PICTURESTATUS_H
#include "Status.h"

//inherit from status class and have its own data.
class PictureStatus :public Status
{
	string picture;
public:
	PictureStatus(const string& picture) :picture(picture) {};
	void showStatus() const;
	virtual bool operator==(const Status& other) const;
	virtual bool operator!=(const Status& other) const;
	const PictureStatus& operator=(const PictureStatus& other);
	PictureStatus(const PictureStatus& other);
	const PictureStatus& operator=(const PictureStatus&& other);
	PictureStatus(const PictureStatus&& other);
	virtual Status* clone() const override;
	virtual void toOs(ostream& os) const;
	virtual ~PictureStatus() {};
};
#endif // !__PICTURESTATUS_H

