#include "Book.h"
#include <iostream>

using namespace std;

Book::Book(int id, string title, string author)
    : MediaItem(id, title)
{
    this->author = author;
}

void Book::display()
{
    cout << "Type   : Book" << endl;
    cout << "ID     : " << id << endl;
    cout << "Title  : " << title << endl;
    cout << "Author : " << author << endl;
    cout << "Status : "
         << (checkedOut ? "Checked Out" : "Available")
         << endl;
}

string Book::getType()
{
    return "Book";
}

string Book::getDetails()
{
    return author;
}

string Book::getAuthor()
{
    return author;
}