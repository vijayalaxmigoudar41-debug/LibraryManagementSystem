#include "Library.h"
#include "Book.h"
#include "Journal.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


// Constructor
Library::Library()
{
}


// Destructor (Dynamic Memory Management)
Library::~Library()
{
    for(MediaItem* item : items)
    {
        delete item;
    }

    items.clear();
}


// Add Item
void Library::addItem(MediaItem* item)
{
    items.push_back(item);
    cout << "Item added successfully.\n";
}


// Display Items (Polymorphism)
void Library::displayItems()
{
    if(items.empty())
    {
        cout << "No items available.\n";
        return;
    }

    cout << "\n===== Library Catalog =====\n";

    for(MediaItem* item : items)
    {
        item->display();
        cout << "--------------------------\n";
    }
}


// Checkout
void Library::checkoutItem(int id)
{
    for(MediaItem* item : items)
    {
        if(item->getId() == id)
        {
            item->checkout();
            cout << "Item checked out successfully.\n";
            return;
        }
    }

    cout << "Item not found.\n";
}


// Return
void Library::returnItem(int id)
{
    int days;

    for(MediaItem* item : items)
    {
        if(item->getId() == id)
        {
            item->returnItem();

            cout << "Enter overdue days: ";
            cin >> days;

            cout << "Fine = Rs. "
                 << item->calculateFine(days)
                 << endl;

            return;
        }
    }

    cout << "Item not found.\n";
}


// Save Catalog
void Library::saveToFile()
{
    ofstream file("catalog.txt");


    for(MediaItem* item : items)
    {
        file << item->getType()
             << ","
             << item->getId()
             << ","
             << item->getTitle()
             << ","
             << item->getDetails()
             << endl;
    }


    file.close();

    cout << "Catalog saved successfully.\n";
}


// Load Catalog
void Library::loadFromFile()
{
    ifstream file("catalog.txt");


    if(!file)
    {
        return;
    }


    string line;


    while(getline(file,line))
    {
        string type,id,title,details;


        stringstream ss(line);


        getline(ss,type,',');
        getline(ss,id,',');
        getline(ss,title,',');
        getline(ss,details,',');


        if(type=="Book")
        {
            items.push_back(
                new Book(stoi(id),title,details)
            );
        }


        else if(type=="Journal")
        {
            items.push_back(
                new Journal(stoi(id),title,stoi(details))
            );
        }
    }


    file.close();
}