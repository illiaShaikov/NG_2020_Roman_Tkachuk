#include <iostream>
#include "people.h"

using namespace std;

int main()
{
    People workers;
    workers.addHuman();
    workers.addHuman();
    workers.deleteHuman();
    workers.showAllHumans();
    return 0;
}
