#ifndef _DB
#define _DB
#include "BinarySearchTree.h"
#include "PersonInfo.h"

template<class ItemType>
void display(ItemType& anItem)
{
	cout << anItem << ",";
}


class DB
{
private:
	BinarySearchTree<PersonInfo> db; //holds the database of persons.
	int numberOfpersons; //holds the number of persons in the Binary Search Tree.
public:
	DB();
	~DB();
	void addPerson(PersonInfo person);
	void removePerson(PersonInfo person);
	void displayAllPersons();
	void displayPerson(PersonInfo person);
	void displayPersonsByAge(int age);
	void displayPersonsByAgeRange(int minAge, int maxAge);
	void displayPersonsByFullName(string Name);
	void displayPersonsByBirthDate(Date birthDate);
	void displayPersonsByBirthDateRange(Date minBirthDate, Date maxBirthDate);
	friend ostream& operator<<(ostream& out, const DB& rightHandItem);
	friend istream& operator>>(istream& in, DB& rightHandItem);
};
DB::DB()
{
	numberOfpersons = 0;
}
DB::~DB()
{
	numberOfpersons = 0;
}
void DB::addPerson(PersonInfo person)
{
	db.add(person);
	numberOfpersons++;
}
void DB::removePerson(PersonInfo person)
{
	db.remove(person);
	numberOfpersons--;
}
void DB::displayAllPersons()
{
	db.inorderTraverse(display<PersonInfo>);
}
void DB::displayPerson(PersonInfo person)
{
	db.getEntry(person);
}
void DB::displayPersonsByAge(int age)
{
	PersonInfo person;
	person.setAge(Date(age, 0, 0));
	db.getEntry(person);
}
void DB::displayPersonsByAgeRange(int minAge, int maxAge)
{
	PersonInfo person;
	person.setAge(Date(minAge, 0, 0));
	db.getEntry(person);
	person.setAge(Date(maxAge, 0, 0));
	db.getEntry(person);
}
void DB::displayPersonsByFullName(string Name)
{
	PersonInfo person;
	person.setName(Name);
	db.getEntry(person);
}
void DB::displayPersonsByBirthDate(Date birthDate)
{
	PersonInfo person;
	person.setAge(birthDate);
	db.getEntry(person);
}
void DB::displayPersonsByBirthDateRange(Date minBirthDate, Date maxBirthDate)
{
	PersonInfo person;
	person.setAge(minBirthDate);
	db.getEntry(person);
	person.setAge(maxBirthDate);
	db.getEntry(person);
}
ostream& operator<<(ostream& out, const DB& rightHandItem)
{
	out << rightHandItem.db;
	return out;
}
istream& operator>>(istream& in, DB& rightHandItem)
{
	in >> rightHandItem.db;
	return in;
}

#endif

/*
    void displayPersonsByBirthMonth(int birthMonth);
	void displayPersonsByBirthMonthRange(int minBirthMonth, int maxBirthMonth);
	void displayPersonsByBirthYear(int birthYear);
	void displayPersonsByBirthYearRange(int minBirthYear, int maxBirthYear);
	void displayPersonsByBirthDateMonth(int birthMonth, int birthYear);
	void displayPersonsByBirthDateMonthRange(int minBirthMonth, int maxBirthMonth, int minBirthYear, int maxBirthYear);
	void displayPersonsByBirthDateYear(int birthYear, int birthMonth);
	void displayPersonsByBirthDateYearRange(int minBirthYear, int maxBirthYear, int minBirthMonth, int maxBirthMonth);
	void displayPersonsByBirthDateMonthYear(int birthMonth, int birthYear);
	void displayPersonsByBirthDateMonthYearRange(int minBirthMonth, int maxBirthMonth, int minBirthYear, int maxBirthYear);
	void displayPersonsByBirthDateYearMonth(int birthYear, int birthMonth);
	void displayPersonsByBirthDateYearMonthRange(int minBirthYear, int maxBirthYear, int minBirthMonth, int maxBirthMonth);
	void displayPersonsByBirthDateDay(int birthDay);
	void displayPersonsByBirthDateDayRange(int minBirthDay, int maxBirthDay);
	void displayPersonsByBirthDateDayMonth(int birthDay, int birthMonth);
	void displayPersonsByBirthDateDayMonthRange(int minBirthDay, int maxBirthDay, int minBirthMonth, int maxBirthMonth);
	void displayPersonsByBirthDateDayYear(int birthDay, int birthYear);
	void displayPersonsByBirthDateDayYearRange(int minBirthDay, int maxBirthDay, int minBirthYear, int maxBirthYear);
	void displayPersonsByBirthDateDayMonthYear(int birthDay, int birthMonth, int birthYear);
	void displayPersonsByBirthDateDayMonthYearRange(int minBirthDay, int maxBirthDay, int);
*/