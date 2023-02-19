#ifndef __Exceptions_H
#define __Exceptions_H
#include <iostream>

//in this file we create the exceptions for all our classes. 
//each class and its relevant excption.

class MemberException : public std::exception
{
public:
	virtual const char* what() const override { return "The member already exist!!"; }
};
class FanPageException : public MemberException
{
public:
	virtual const char* what() const override { return "The fan page already exist!!"; }
};
class FanPageFollowException : public MemberException
{
public:
	virtual const char* what() const override { return "The entities are not following each other";}
};

class MemberNotExistException : public MemberException
{
public:
	virtual const char* what() const override { return "The member dosent exist!!"; }
};
class FanPageNotExistException : public MemberException
{
public:
	virtual const char* what() const override { return "The fan page dosent exist!!"; }
};
class AddMemberException : public MemberException
{
public:
	virtual const char* what() const override { return "Invalid member to add"; }
};
class RemoveMemberException : public MemberException
{
public:
	virtual const char* what() const override { return "Invalid member to remove"; }
};
class AddFanPageException : public MemberException
{
public:
	virtual const char* what() const override { return "Invalid fan page to add"; }
};
class DateException : public std::exception
{
public:
	virtual const char* what() const override { return "invalid date."; }
};
class StatusTypeException : public std::exception
{
public:
	virtual const char* what() const override { return "invalid status type."; }
};
class UserTypeException : public std::exception
{
public:
	virtual const char* what() const override { return "User type incorrect.\n"; }
};

class UserChooseException : public std::exception
{
public:
	virtual const char* what() const override { return "Choose not in range, please pick again-- > "; }
};
#endif // !__Exceptions_H

