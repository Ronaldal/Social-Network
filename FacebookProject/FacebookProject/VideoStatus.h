#ifndef _VIDEOSTATUS__H
#define _VIDEOSTATUS__H
#include "Status.h"

//inherit from status class and have its own data.
class VideoStatus :public Status
{
	string video;
public:
	VideoStatus(const string& video) : video(video) {};
	void showStatus() const;
	virtual bool operator==(const Status& other) const;
	virtual bool operator!=(const Status& other) const;
	const VideoStatus& operator=(const VideoStatus& other);
	VideoStatus(const VideoStatus& other);
	const VideoStatus& operator=(const VideoStatus&& other);
	VideoStatus(const VideoStatus&& other);
	virtual Status* clone() const override;
	virtual void toOs(ostream& os) const;
	virtual ~VideoStatus() {};
};
#endif // !_VIDEOSTATUS__
