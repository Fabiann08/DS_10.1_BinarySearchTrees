#ifndef _DB
#define _DB
#include "BinarySearchTree.h"
#include "PersonInfo.h"
#include <vector>
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
	DB(const DB& otherDB);
	~DB();
	int getNumberOfPersons() const { return numberOfpersons; }

	// Mutators
	void addPerson(PersonInfo person);
	void removePerson(PersonInfo person);
	void modifyPerson(PersonInfo oldPerson, PersonInfo newPerson);

	// Accessors
	void displayAllPersons();
	void searchPersonByName(string name, Date date);
	void displayBirthdays();

	// Overloaded operators
	DB& operator=(const DB& otherDB)
	{
		db = otherDB.db;
		numberOfpersons = otherDB.numberOfpersons;
		return *this;
	}

	friend istream& operator>>(istream& in, DB& rightHandItem)
	{
		PersonInfo person;
		in >> person;
		rightHandItem.addPerson(person);
		return in;
	}
};
DB::DB()
{
	numberOfpersons = 0;
}
DB::DB(const DB& otherDB)
{
	db = otherDB.db;
	numberOfpersons = otherDB.numberOfpersons;
}
DB::~DB()
{
	numberOfpersons = 0;
}
void DB::addPerson(PersonInfo person)
{
	db.add(person);
	numberOfpersons++;
}//works
void DB::removePerson(PersonInfo person)
{
	db.remove(person);
	numberOfpersons--;
}//works
void DB::modifyPerson(PersonInfo oldPerson, PersonInfo newPerson)
{
	db.remove(oldPerson);
	db.add(newPerson);
}//works
void DB::displayAllPersons()
{
	db.inorderTraverse(display<PersonInfo>);
}//works
void DB::searchPersonByName(string name, Date date)
{
	//PersonInfo person1("John", Date(1, 1, 1990));

	PersonInfo person;
	person.setName(name);
	person.setAge(date);
	if (db.contains(person))
	{
		cout << "Found: " << endl;
		PersonInfo foundPerson = db.getEntry(person); // Store the returned object
		cout << foundPerson << endl; // Display the found person
	}
	else
	{
		cout << "Person not found." << endl;
	}
}////

void DB::displayBirthdays()
{
	db.inorderTraverse([](PersonInfo& person) {cout << person.getName() << " - " << person.getAge() << endl;});
}

#endif
