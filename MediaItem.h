#ifndef MEDIAITEM_H
#define MEDIAITEM_H

#include <iostream>
#include <string>

using namespace std;

class MediaItem
{
protected:
    int id;
    string title;
    bool checkedOut;

public:
    MediaItem(int id, string title);
    virtual ~MediaItem();

    virtual void display() = 0;
    virtual string getType() = 0;

    void checkout();
    void returnItem();

    bool isCheckedOut();
    int getId();
    string getTitle();

    virtual string getDetails() = 0;

    double calculateFine(int overdueDays);
};

#endif