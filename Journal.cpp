#include "Journal.h"
#include <iostream>

using namespace std;

Journal::Journal(int id, string title, int issueNo)
    : MediaItem(id, title)
{
    this->issueNo = issueNo;
}

void Journal::display()
{
    cout << "Type        : Journal" << endl;
    cout << "ID          : " << id << endl;
    cout << "Title       : " << title << endl;
    cout << "Issue No    : " << issueNo << endl;
    cout << "Status      : "
         << (checkedOut ? "Checked Out" : "Available")
         << endl;
}

string Journal::getType()
{
    return "Journal";
}

string Journal::getDetails()
{
    return to_string(issueNo);
}

int Journal::getIssueNo()
{
    return issueNo;
}