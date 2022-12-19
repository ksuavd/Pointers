// References.cpp 
#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "");
    int a = 2;
    int& ra=a;
    ra += 3;
    cout << a << endl;
    cout << &a << endl;
    cout << &ra << endl;
}