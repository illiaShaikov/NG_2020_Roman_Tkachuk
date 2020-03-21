#include <iostream>

using namespace std;

int getValue(char str[]) {
    cout << "Enter " << str << " value: ";
    int value;
    cin >> value;
    return value;
}

int getAction() {
    cout << "Select action: " << endl;
    cout << " 1 - add" << endl;
    cout << " 2 - subst" << endl;
    cout << " 3 - mul" << endl;
    cout << " 4 - div" << endl;
    cout << ">>";
    int action;
    cin >> action;
    return action;
}

void processAction(int action, int value1, int value2) {
    switch (action) {
    case 1: cout << value1 + value2; break;
    case 2: cout << value1 - value2; break;
    case 3: cout << value1 * value2; break;
    case 4: cout << value1 / value2; break;
    default: cout << "ERR";
    }

    cout << endl;
}

void getNumbers(int arr[], int size) {
    for (int index=0; index<size; index++) {
        cout << "Enter " << index << "-th number: ";
        cin >> arr[index];
    }
}

void getNumber(int number) {
    cout << "Enter number: ";
    cin >> number;
    cout << "Number in function: " << number << endl;
}

void showArray(int arr[], int size) {
    cout << "Array from separate function: ";
    for (int index=0; index<size; index++)
    {
        cout << arr[index] << " ";
    }
    cout << endl;
}

void drawLine(int size) {
    for (int index=0; index<size; index++)
    {
        cout << "*";
    }
    cout << endl;
}

void drawTriangle(int size) {
    drawLine(size);
    if (size > 0) {
        drawTriangle(size-1);
    }
    drawLine(size);
}

int main()
{
//    Example with simple compiler
//    int value1 = getValue("first");
//    int value2 = getValue("second");
//    processAction(getAction(), value1, value2);
//====================================================
//    Fun with functions
//    int numbers[10];
//    int number = 0;
//    getNumber(number);
//    cout << "Number from main: " << number << endl;
//    getNumbers(numbers, 10);
//    showArray(numbers, 10);
//    cout << "Array from main: ";
//    for (int index=0; index<10; index++)
//    {
//        cout << numbers[index] << " ";
//    }
//    cout << endl;
//    cout << "Our array: " << numbers << endl;
//=====================================================
//    Why do we need keep size of our array
//    int a = 9;
//    int b[10];
//    b[-1] = 2;
//    cout << a;
//=====================================================
//    Recursion
//    drawTriangle(10);
}
