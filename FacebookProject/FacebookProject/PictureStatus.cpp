#include "PictureStatus.h"

//picture status is one of the ineritant of the status class. 
void PictureStatus::showStatus() const
{
	cout << "The status is picture  " << picture << endl;
	Status::showStatus();
	system("start mypicture.jpg");
}

void PictureStatus::toOs(ostream& os) const
{
	os << picture;
}
bool PictureStatus::operator==(const Status& other) const
{
	const PictureStatus* temp = dynamic_cast<const PictureStatus*>(&other);
	return(picture == temp->picture ? true : false);
}

bool PictureStatus::operator!=(const Status& other) const
{
	return!(*this == other);
}
//operator = for picture status.
const PictureStatus& PictureStatus::operator=(const PictureStatus& other)
{
	Status::operator=(other);
	picture = other.picture;
	return *this;
}
PictureStatus::PictureStatus(const PictureStatus& other)
{
	*this = other;
}

const PictureStatus& PictureStatus::operator=(const PictureStatus&& other)
{
	Status::operator=(other);
	picture = other.picture;
	return *this;
}//move
PictureStatus::PictureStatus(const PictureStatus&& other)
{
	*this = other;
}
Status* PictureStatus:: clone() const
{
	return new PictureStatus(*this);
}