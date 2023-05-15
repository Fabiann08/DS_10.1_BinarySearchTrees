#ifndef _PersonInfo
#define _PersonInfo
#include <string>
#include "Date.h"
using namespace std;

class PersonInfo
{
private:
	string name;
	Date age;
public:
	PersonInfo();
	PersonInfo(string name, Date age);
	string getName() const;
	Date getAge() const;
	void setName(string name);
	void setAge(Date age);
	bool operator==(const PersonInfo& rightHandItem) const;
	bool operator>(const PersonInfo& rightHandItem) const;
	bool operator<(const PersonInfo& rightHandItem) const;
	bool operator>=(const PersonInfo& rightHandItem) const;
	bool operator<=(const PersonInfo& rightHandItem) const;
	friend ostream& operator<<(ostream& out, const PersonInfo& rightHandItem)
	{
		out << rightHandItem.name << " " << rightHandItem.age.getDay() << "/" << rightHandItem.age.getMonth() << "/" << rightHandItem.age.getYear();
		return out;
	}
	friend istream& operator>>(istream& in, PersonInfo& rightHandItem)
	{
		string name;
		int day, month, year;
		cout << "Enter Name: ";
		in >> name;
		cout << "Enter day: ";
		in >> day;
		cout << "Enter month: ";
		in >> month;
		cout << "Enter year: ";
		in >> year;
		rightHandItem.setName(name);
		rightHandItem.setAge(Date(day, month, year));
		return in;
	}
};
PersonInfo::PersonInfo()
{
	name = "";
	age = Date();
}
PersonInfo::PersonInfo(string name, Date age)
{
	this->name = name;
	this->age = age;
}
string PersonInfo::getName() const
{
	return name;
}
Date PersonInfo::getAge() const
{
	return age;
}
void PersonInfo::setName(string name)
{
	this->name = name;
}
void PersonInfo::setAge(Date age)
{
	this->age = age;
}
bool PersonInfo::operator==(const PersonInfo& rightHandItem) const
{
	return (name == rightHandItem.name && age == rightHandItem.age);
}
bool PersonInfo::operator>(const PersonInfo& rightHandItem) const
{
	return (name > rightHandItem.name);
}
bool PersonInfo::operator<(const PersonInfo& rightHandItem) const
{
	return (name < rightHandItem.name);
}
bool PersonInfo::operator>=(const PersonInfo& rightHandItem) const
{
	return (name >= rightHandItem.name);
}
bool PersonInfo::operator<=(const PersonInfo& rightHandItem) const
{
	return (name <= rightHandItem.name);
}
#endif