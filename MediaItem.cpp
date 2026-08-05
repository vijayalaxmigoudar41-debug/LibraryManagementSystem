#include "MediaItem.h"

MediaItem::MediaItem(int id, string title)
{
    this->id = id;
    this->title = title;
    checkedOut = false;
}

MediaItem::~MediaItem()
{
}

void MediaItem::checkout()
{
    checkedOut = true;
}

void MediaItem::returnItem()
{
    checkedOut = false;
}

bool MediaItem::isCheckedOut()
{
    return checkedOut;
}

int MediaItem::getId()
{
    return id;
}

string MediaItem::getTitle()
{
    return title;
}

double MediaItem::calculateFine(int overdueDays)
{
    return overdueDays * 5;
}