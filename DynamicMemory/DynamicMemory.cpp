// DynamicMemory.cpp 
#include <iostream>
using namespace std;
#define tab "\t"
#define delimiter  "-------------------------------"

//#define DynamicMemory_1
#define DynamicMemory_2
void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int* arr, const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int* arr,  int& n, int value);
int* push_front(int* arr, int& n, int value);
//ДЗ
int* insert(int* arr, int& n, int value, int value_index);
int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* erase(int* arr, int& n, int value_index);

int** push_row_back(int** arr, int& rows, const int cols);

int main()
{
    setlocale(LC_ALL, ""); 
#ifdef DynamicMemory_1
    int n; int value_index;
    cout << "Введите количество элементов: "; cin >> n;
    int* arr = new int[n];
    FillRand(arr, n);
    Print(arr, n);
    int value;

    cout << "Введите добавляемое значение (в конец массива): "; cin >> value;
    arr= push_back(arr, n, value);
    Print(arr, n);

    cout << "Введите добавляемое значение (в начало массива): "; cin >> value;
    arr = push_front( arr, n, value);
    Print(arr, n);

    cout << "Введите добавляемое значение: "; cin >> value;  cout << "Введите индекс: "; cin >> value_index;
    arr = insert (arr, n, value, value_index);
    Print(arr, n);

    arr = pop_back(arr, n);
    Print(arr, n);

    arr = pop_front(arr, n);
    Print(arr, n);

    cout << "Введите индекс: "; cin >> value_index;
    arr = erase(arr, n, value_index);
    Print(arr, n);
   
    delete[] arr;
#endif // DynamicMemory_1
    int rows;	//количество строк
    int cols;	//количество столбцов (количество элементов строки)
    cout << "Введите количество строк: "; cin >> rows;
    cout << "Введите количество элементов строки: "; cin >> cols;

    int** arr = new int* [rows];	//создаем массив указателей
    for (int i = 0; i < rows; i++)
    {
        //создаем строки двумерного массива:
        arr[i] = new int[cols];
    }

    FillRand(arr, rows, cols);
    Print(arr, rows, cols);
    delimiter;
    arr = push_row_back(arr, rows, cols);
    Print(arr, rows, cols);
    //1.удаляем строки двумерного массива
    for (int i = 0; i < rows; i++)
    {
        delete[]arr[i];
    }
   //2. удаляем массив указателей
    delete[]arr;
}
void FillRand(int** arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)	//i - нумерует строки
    {
        for (int j = 0; j < cols; j++)	//j - нумерует элементы строки
        {
            arr[i][j] = rand() % 100;
        }
    }
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
void Print(int** arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << tab;
        }
        cout << endl;
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
int* insert(int* arr, int& n, int value, int value_index)
{
    int* buffer = new int[n + 1];
    /*for (int i = 0; i < value_index; i++) buffer[i] = arr[i];
   for (int i = value_index;i<n;i++) buffer[i+1] = arr[i];*/
    for (int i = 0; i < n; i++)
    {
       // if (i < value_index)buffer[i] = arr[i]; else buffer[i + 1] = arr[i];
        //(i < value_index ? buffer[i] : buffer[i + 1]) = arr[i];
        buffer[i < value_index ? i : i + 1] = arr[i];
    }
    buffer[value_index] = value;
    delete[] arr;
    arr = buffer;
    n++;
    return arr;
}
int* pop_back(int* arr, int& n)
{
    int* buffer = new int[n - 1];
    for (int i = 0; i < n-1; i++)
    {
        buffer[i] = arr[i];
    }
    delete[] arr;
    arr = buffer;
    n--;
    return arr;
}
int* pop_front(int* arr, int& n)
{
    int* buffer = new int[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        buffer[i] = arr[i+1];
    }
    delete[] arr;
    arr = buffer;
    n--;
    return arr;
}
int* erase(int* arr, int& n, int value_index)
{
    int* buffer = new int[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        if (i < value_index) buffer[i] = arr[i]; else buffer[i] = arr[i];
    }
    delete[] arr;
    arr = buffer;
    n--;
    return arr;
}
int** push_row_back(int** arr, int& rows, const int cols)
{
    //1) Создаем буферный массив указателей:
    int** buffer = new int* [rows + 1];
    //2) Копируем адреса строк в новый массив указателей:
    for (int i = 0; i < rows; i++)
    {
        buffer[i] = arr[i];
    }
    //3) Удаляем исходный массив указателей:
    delete[] arr;
    //4) Подменяем адрес в указателе 'arr' адресом нового массива:
    arr = buffer;
    //5) Создаем новую строку:
    arr[rows] = new int[cols] {};
    //6) После добавления строки, количество строк увеличивается на 1:
    rows++;
    //7) Mission complete - строка добавлена. Возвращаем новый массив:
    return arr;
}
