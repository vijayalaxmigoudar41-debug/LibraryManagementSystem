#ifndef BOOK_H
#define BOOK_H

#include "MediaItem.h"

class Book : public MediaItem
{
private:
    string author;

public:
    Book(int id, string title, string author);

    void display() override;
    string getType() override;
    string getDetails() override;

    string getAuthor();
};

#endif