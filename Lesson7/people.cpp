#include "people.h"

People::People()
{
    for (int i=0; i<100; i++)
    {
        people[i].name[0] = 0;
    }
}

void People::addHuman()
{
    human buffer;
    cout << "Enter name: ";
    cin.getline(buffer.name, 100);
    cout << "Enter age: ";
    cin >> buffer.age;
    cout << "Enter sex: ";
    cin.getline(buffer.sex, 100);
    cin.getline(buffer.sex, 100);
    for (int i=0; i<100; i++) {
        if (people[i].name[0] == 0) {
            people[i] = buffer;
            return;
        }
    }
}

void People::showAllHumans()
{
    for (int i=0; i<100; i++) {
        if (people[i].name[0] != 0) {
            cout << people[i].name << ":::" << people[i].age << ":::" << people[i].sex << endl;
        }
    }
}

void People::deleteHuman()
{
    human buffer;
    cout << "Enter name: ";
    cin.getline(buffer.name, 100);
    cout << "Enter age: ";
    cin >> buffer.age;
    cout << "Enter sex: ";
    cin.getline(buffer.sex, 100);
    cin.getline(buffer.sex, 100);
    deleteHuman(buffer);
}

void People::deleteHuman(human humanToDelete)
{
    /*for (int i=0; i<100; i++)
    {
        human buffer = people[i];
        if (humanToDelete.name == buffer.name &&
                humanToDelete.age == buffer.age &&
                humanToDelete.sex == buffer.sex)
            people[i].name[0] = 0;
    }*/
}
