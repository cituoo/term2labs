#include "string.h"

String::String() : Data(nullptr) {} // Обнуляем переменную при пустой инициализации

String::~String() { delete [] Data; } // Обнуляем массив

String::String(const String& rhs) // Присваиваем переменной значение копируемой переменной
{
    int i = 0; // Объявляем итератор
    while (rhs.Data[i] != '\0') // В конце каждого масива чара есть специальный символ, обозначающий конец)))
    {
        i++; // Считаем длину для выделения памяти
    }
    
    Data = new char[i]; // Выделяем память
    int j = 0;
    while (j < i)
    {
        Data[j] = rhs.Data[j];
        j++;
    }

}

String::String(const char * data) // Присваиваем значание переменной такое, которое в скобках
{
    int i = 0;
    while (data[i] != '\0')
    {
        i++;
    }

    Data = new char[i]; // Выделяем память
    i = 0;
    while (data[i] != '\0')
    {
        Data[i] = data[i];
        i++;
    }



}

String& String::operator=(const String& rhs) // Перегружаем оператор "=", по сути делает тоже самое, что и конструктор копирования
{
    int i = 0;
    while (rhs.Data[i] != '\0')
    {

        i++;
    }
    Data = new char[i];
    i = 0;
    while (rhs.Data[i] != '\0')
    {
        Data[i] = rhs.Data[i];
        i++;
    }

    return *this;
}

String& String::operator+=(const String& rhs)
{
    int i = 0;
    while (Data[i] != '\0') // Подсчитываем длину значения которое у нас уже есть
    {
        i++;
    }

    int j = 0;
    while (rhs.Data[j] != '\0') // Подсчитываем длину значения которое нужно добавить
    {
        j++;
    }


    int size = i + j;
    char * newData = new char[size]; // Выделяем память под эти значения

    int q = 0;
    while (q < i) // Присваиваем значения первой переменной
    {
        newData[q] = Data[q];
        q++;
    }
    i = 0;

    while (i < j)
    {
        newData[q] = rhs.Data[i];
        i++;
        q++;
    }

    Data = newData;

    return *this;
}

bool String::operator==(const String& rhs) const
{
    bool returnedBool = true;
    int i = 0;
    while (Data[i] != '\0') // Подсчитываем длину значения которое у нас уже есть
    {
        i++;
    }

    int j = 0;
    while (rhs.Data[j] != '\0') // Подсчитываем длину значения которое нужно добавить
    {
        j++;
    }


    if (i == j) // Только если их длины равны, есть смысл продолжать проверять посимвольно
    {
        int q = 0;
        while (Data[q] != '\0')
        {
            if (Data[q] != rhs.Data[q])
            {
                returnedBool = false;
                break;
            }
            q++;
        }
    }
    else returnedBool = false;
    return returnedBool;
}

bool String::operator<(const String& rhs) const
{
    bool returnedBool = false;
    int i = 0;
    while (Data[i] != '\0') // Подсчитываем длину значения которое у нас уже есть
    {
        i++;
    }

    int j = 0;
    while (rhs.Data[j] != '\0') // Подсчитываем длину значения которое нужно добавить
    {
        j++;
    }

    if (i < j) returnedBool = true;
    return returnedBool;
}

size_t String::Find(const String& substr) const
{
    size_t returnedFing = -1;
    int lenAll, lenSearch;
    int flag = 0;
    for (lenAll = 0; Data[lenAll]; lenAll++); // Размер общей строки
    for (lenSearch = 0; substr.Data[lenSearch]; lenSearch++); // Размер искомой строки

    for (int i = 0; i < lenAll-lenSearch; i++)
    {
        for (int j = i; j < lenSearch; j++)
        {
            if (Data[j] != Data[i]) break;
            else flag++;
        }
        if (flag == lenSearch)
        {
            returnedFing = i;
            break;
        }
        else flag = 0;
    }

    return returnedFing;
}



void String::Show()
{
    int j = 0;
    while (Data[j] != '\0') // Подсчитываем длину второго значения
    {
        std::cout<<Data[j]<<"";
        j++;
    }
    std::cout<<std::endl;
}