#include <iostream>
#include <string>
#include "DB.h"

using namespace std;

int main() 
{
    DB database;
    int choice;
    bool quit = false;

    while (!quit)
    {
        cout << "\nOptions Menu:" << endl;
        cout << "1. Enter person's data." << endl;
        cout << "2. Remove person's data." << endl;
        cout << "3. Modify person's data." << endl;
        cout << "4. Search person's data by name." << endl;
        cout << "5. Show list of birthdays." << endl;
        cout << "6. Quit program." << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
        case 1: {
            //cin >> database;
            PersonInfo person;
            cin >> person;
            database.addPerson(person);
            cout << "Person added successfully." << endl;
            break;
        }
        case 2: 
        {
            PersonInfo person;
            cout << "Enter the person to remove:\n";
            cin >> person;
            database.removePerson(person);
            cout << "Person removed successfully." << endl;
            break;
        }
        case 3:
        {
            PersonInfo personOld;
            PersonInfo personNew;
            cout << "Enter the person to modify: ";
            cin >> personOld;
            cout << "Modify their contents: ";
            cin >> personNew;
            database.modifyPerson(personOld, personNew);
            break;
        }
        case 4: 
        {
            string name;
            Date date;
            cout << "Enter person's name to search: ";
            cin >> name;
            cout << "Enter person's birthday to search: ";
            cin >> date;
            database.searchPersonByName(name, date);
            break;
        }
        case 5: 
        {
            database.displayBirthdays();
            break;
        }
        case 6: 
        {
            cout << "Goodbye!" << endl;
            quit = true;
            break;
        }
        default: 
        {
            cout << "Invalid choice. Try again." << endl;
            break;
        }
        }
    }
    return 0;
}

/*
    DB database;
    int choice;
    bool quit = false;

    while (!quit)
    {
        cout << "Options Menu:" << endl;
        cout << "1. Enter person's data." << endl;
        cout << "2. Remove person's data." << endl;
        cout << "3. Modify person's data." << endl;
        cout << "4. Search person's data by name." << endl;
        cout << "5. Show list of birthdays." << endl;
        cout << "6. Quit program." << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
        case 1: {
            PersonInfo person;
            cin >> person;
            database.addPerson(person);
            cout << "Person added successfully." << endl;
            break;
        }
        case 2: {
            PersonInfo person;
            cin >> person;
            database.removePerson(person);
            cout << "Person removed successfully." << endl;
            break;
        }
        case 3: {
            PersonInfo person;
            cin >> person;
            database.removePerson(person);
            cout << "Person removed successfully." << endl;
            cout << "Enter modified data:" << endl;
            cin >> person;
            database.addPerson(person);
            cout << "Person modified successfully." << endl;
            break;
        }
        case 4: {
            string name;
            cout << "Enter person's name: ";
            cin >> name;
            database.displayPersonsByFullName(name);
            break;
        }
        case 5: {
            database.displayAllPersons();
            break;
        }
        case 6: {
            cout << "Goodbye!" << endl;
            quit = true;
            break;
        }
        default: {
            cout << "Invalid choice. Try again." << endl;
            break;
        }
        }
    }

*/









/*
 DB my_db;

    int choice;
    do
    {
        cout << "Select an option:\n";
        cout << "1. Add a record\n";
        cout << "2. View all records\n";
        cin >> choice;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice == 1)
        {
            cin >> my_db;

        }
        else if (choice == 2)
        {
            my_db.displayAllPersons();
        }
    } while (choice != 3);
    return 0;
*/