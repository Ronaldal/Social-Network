#ifndef __BILLBOARD_H
#define __BILLBOARD_H

#include "TextStatus.h"
#include "VideoStatus.h"
#include "PictureStatus.h"
// The class Billboard is for saving every member or fan page the statuses they have.
class BillBoard
{
private:
	vector<Status*> statusArr;
public:
	BillBoard();
	BillBoard(const BillBoard& other) = delete;
	BillBoard(const BillBoard&& other) = delete;
	void addStatus(Status* statusToAdd);
	void showMemberBillboard()  const;
	void showBillBoard() const;
	friend ostream& operator<<(ostream& os, const BillBoard& billboard);
	friend istream& operator>>(istream& in, BillBoard& billboard);
	
	~BillBoard();
};

#endif // !__BILLBOARD_H
