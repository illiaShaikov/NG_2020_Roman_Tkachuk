#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>

using namespace std;

struct human {
    char name[100];
    int age;
    char sex[100];
};

class People
{
public:
    People();
    void addHuman();
    void showAllHumans();
    void deleteHuman();
    void deleteHuman(human humanToDelete);
private:
    human people[100];
};

#endif // PEOPLE_H
