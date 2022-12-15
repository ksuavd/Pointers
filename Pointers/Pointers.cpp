// Pointers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
using namespace std;

//#define POINTER_BASICS

int main()
{
    setlocale(LC_ALL, "");
#ifdef POINTER_BASICS
    int a = 2;
    int* pa = &a;//Pointer to 'a' (указатель на 'a')
    cout << a << endl;//значение переменной
    cout << &a << endl;//взятие адреса переменной 'a' прямо при выводе 
    cout << pa << endl;//вывод адреса переменной 'a', хранящегося в указателе 'pa'
    cout << *pa << endl;//разыменование указателя 'ра' и вывод на экран значения переменной 'а' по адресу 

    int* pb; //просто объявление указателя (без инициализации)
    int b = 3;
    pb = &b;//инициализируем указатель после объявления
    //int-int
    //int* -указатель на int
#endif // POINTER_BASICS

    const int n = 5;
    int arr[n] = { 3,5,8,13,21 };
    cout << arr << endl;
    cout << *arr << endl;
    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i) << "\t";
    }
   
}

