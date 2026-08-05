#ifndef JOURNAL_H
#define JOURNAL_H

#include "MediaItem.h"

class Journal : public MediaItem
{
private:
    int issueNo;

public:
    Journal(int id, string title, int issueNo);

    void display() override;
    string getType() override;
    string getDetails() override;

    int getIssueNo();
};

#endif