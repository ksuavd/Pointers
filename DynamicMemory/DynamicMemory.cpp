// DynamicMemory.cpp 
#include <iostream>
using namespace std;
#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int *arr, const int n);
int* push_back(int* arr,  int& n, int value);
int* push_front(int* arr, int& n, int value);
int main()
{
    setlocale(LC_ALL, ""); 
    int n;
    cout << "Введите количество элементов: "; cin >> n;
    int* arr = new int[n];
    FillRand(arr, n);
    Print(arr, n);
    int value;

    cout << "Введите добавляемое значение: "; cin >> value;
   arr= push_back(arr, n, value);
    Print(arr, n);
    delete[] arr;

    cout << "Введите добавляемое значение: "; cin >> value;
    arr = push_front( arr, n, value);
    Print(arr, n);
    delete[] arr;
}
void FillRand(int arr[], const int n)
{
    cout << typeid(arr).name() << endl;
    for (int i = 0; i < n; i++)
    {
        //1. обращаемся к элементу массива через арифметику указателей и оператор разыменования:
        *(arr + i) = rand() % 100;
    }
}
void Print(int arr[], const int n)
{
    cout << typeid(arr).name() << endl;
    for (int i = 0; i < n; i++)
    {
        //2. обращаемся к элементу массива через оператор индексирования:
        //[]- квадратные скобки это оператор индексирования (Subscript operator)
        cout << arr[i] << tab;
    }
    cout << endl;
}
int* push_back(int* arr,  int& n, int value)
{
    //1) Создаем новый массив нужного размера:
    int* buffer = new int[n + 1];
    //2)Копируем все содержимое исходного массива в буферный:
    for (int i = 0; i < n; i++)
    {
        buffer[i] = arr[i];
    }
    //3)Удаляем исходный массив:
    delete[] arr;
    //4) Подменяем адрес в указателе 'arr' адресом нового массива:
    arr = buffer;
    //5) Только после всего этого в конец массива 'arr'можно добавить значение:
    arr[n] = value;
    //6) После добавления в массив 'arr' элемента, количество его элементов увеличивается на 1. 
    n++;
    //7)Mission complite-элемент добавлен!
    return arr;
}
int* push_front(int* arr, int& n, int value)
{
    int* buffer = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        buffer[i+1] = arr[i];
    }
    delete[] arr;
    arr = buffer;
    arr[0] = value;
    n++;
    return arr;
}