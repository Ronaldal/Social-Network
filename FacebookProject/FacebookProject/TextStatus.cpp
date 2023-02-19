#include "TextStatus.h"

//text status is one of the ineritant of the status class. 
void TextStatus::showStatus() const
{
	cout << "The status is text  " << text << endl;
	Status::showStatus();
}
//relevant ostream for the text status.
void TextStatus::toOs(ostream& os) const
{
	os << text;
}
bool TextStatus::operator==(const Status& other) const
{
	const TextStatus* temp = dynamic_cast<const TextStatus*>(&other);
	return(text == temp->text ? true : false);
}

bool TextStatus::operator!=(const Status& other) const
{
	return!(*this == other);
}

const TextStatus& TextStatus::operator=(const TextStatus& other)
{
	Status::operator=(other);
	text = other.text;
	return *this;
}
TextStatus::TextStatus(const TextStatus& other)
{
	*this = other;
}

const TextStatus& TextStatus::operator=(const TextStatus&& other)
{
	Status::operator=(other);
	text = other.text;
	return *this;
}
TextStatus::TextStatus(const TextStatus&& other)
{
	*this = other;
}
Status* TextStatus::clone() const
{
	return new TextStatus(*this);
}