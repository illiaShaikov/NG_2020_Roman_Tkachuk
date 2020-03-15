#include <iostream>

using namespace std;

int main()
{
    char array[10000];
    cout << "Введите строку: ";
    cin.getline(array, 10000);
    cout << "Ваша строка: " << array << endl;
    int spacesCount = 0;
    int index = 0;
    while (array[index] != 0)
    {
        if (array[index] == ' ')
            spacesCount++;
        index++;
    }
    cout << "Колличество пробелов = " << spacesCount << endl;
    cout << endl;
}
