
#include "VideoStatus.h"

void VideoStatus::showStatus() const
{
	cout << "The status is video  " << video << endl;
	Status::showStatus();
	system("start myvideo.mov");
}
void VideoStatus::toOs(ostream& os) const
{
	os << video;
}

bool VideoStatus::operator==(const Status& other) const
{
	const VideoStatus* temp = dynamic_cast<const VideoStatus*>(&other);
	return(video == temp->video ? true : false);
}

bool VideoStatus::operator!=(const Status& other) const
{
	return!(*this == other);
}

const VideoStatus& VideoStatus::operator=(const VideoStatus& other)
{
	Status::operator=(other);
	video = other.video;
	return *this;
}
VideoStatus::VideoStatus(const VideoStatus& other)
{
	*this = other;
}

const VideoStatus& VideoStatus::operator=(const VideoStatus&& other)
{
	Status::operator=(other);
	video = other.video;
	return *this;
}
VideoStatus::VideoStatus(const VideoStatus&& other)
{
	*this = other;
}
Status* VideoStatus::clone() const
{
	return new VideoStatus(*this);
}