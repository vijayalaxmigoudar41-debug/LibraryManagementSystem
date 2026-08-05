#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "MediaItem.h"

using namespace std;

class Library
{
private:
    vector<MediaItem*> items;

public:
    Library();
    ~Library();

    void addItem(MediaItem* item);
    void displayItems();

    void checkoutItem(int id);
    void returnItem(int id);

    void saveToFile();
    void loadFromFile();
};

#endif