#include <iostream>

using namespace std;

int main()
{
    int amount = 100;
    int counter = 0;

    // while example

    while (counter < amount)
    {
        cout << counter << ":*" << endl;
        counter += 1;
    }

    cout << "================================" << endl;

    counter = 100;
    do
    {
        cout << counter << ":*" << endl;
        counter += 1;
    } while (counter < amount);

    cout << "================================" << endl;

    for (int i=0; i<amount; i++)
    {
        cout << i << ":*\t";
    }

}
