#include <iostream>

#include "Library.h"
#include "Book.h"
#include "Journal.h"

using namespace std;

int main()
{
    Library library;

    // Load existing catalog
    library.loadFromFile();

    int choice;
    int id;
    int issueNo;
    string title;
    string author;


    do
    {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add Journal\n";
        cout << "3. Display Items\n";
        cout << "4. Checkout Item\n";
        cout << "5. Return Item\n";
        cout << "6. Save Catalog\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;


        switch(choice)
        {

        case 1:

            cout << "Enter Book ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Book Title: ";
            getline(cin,title);

            cout << "Enter Author Name: ";
            getline(cin,author);


            library.addItem(
                new Book(id,title,author)
            );

            break;



        case 2:

            cout << "Enter Journal ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Journal Title: ";
            getline(cin,title);


            cout << "Enter Issue Number: ";
            cin >> issueNo;


            library.addItem(
                new Journal(id,title,issueNo)
            );

            break;



        case 3:

            library.displayItems();

            break;



        case 4:

            cout << "Enter Item ID: ";
            cin >> id;

            library.checkoutItem(id);

            break;



        case 5:

            cout << "Enter Item ID: ";
            cin >> id;

            library.returnItem(id);

            break;



        case 6:

            library.saveToFile();

            break;



        case 7:

            cout << "Exiting program...\n";

            break;



        default:

            cout << "Invalid choice!\n";

        }


    }while(choice != 7);



    return 0;
}