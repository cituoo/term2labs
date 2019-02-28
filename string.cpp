#include "string.h"

String::String() : Data(nullptr) {} // Обнуляем переменную при пустой инициализации

String::~String() { delete [] Data; } // Обнуляем массив


// Выделить в отдельную функцию заполнение чар масива.

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
    Data[i] = '\0';


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
    Data[i] = '\0';



}

String& String::operator=(const String& rhs) // Перегружаем оператор "=", по сути делает тоже самое, что и конструктор копирования
{
    int i = 0;
    while (rhs.Data[i] != '\0')
    {

        i++;
    }
    Data = new char[i];
    // i = 0;
    i=0;
    while (rhs.Data[i] != '\0')
    {
        Data[i] = rhs.Data[i];
        i++;
    }
    Data[i] = '\0';

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


void String::Replace(char oldSymbol, char newSymbol)
{
    int j = 0;
    while (Data[j] != '\0')
    {
        if (Data[j] == oldSymbol)
            Data[j] = newSymbol;
        j++;
    }
}


size_t String::Find(const String& substr) const
{
    int flag = 0, i = 0, findedindex = -1;
    int checker = 0;
    int bigLen, lilLen;
    for (bigLen = 0; Data[bigLen]; bigLen++); // Размер общей строки
    for (lilLen = 0; substr.Data[lilLen]; lilLen++); // Размер искомой строки


    while (i < bigLen - lilLen && flag == 0)
    {
        for (int j = 0; (j < lilLen); j++)
        {
            if (Data[i+j] == substr[j])
                checker ++;
        }

        if (checker == lilLen)
            flag = 1;
        else {
            checker = 0;
            i++;

        }
        findedindex++;
    }

    // Если искомая строка == 0, то непонятно найдено ли слово или не найдено;
    return static_cast<size_t>(findedindex); // size_t не имеет отр чисел, как вернуть -1?
}

size_t String::Size() const
{
    size_t returnedSize = 0;
    for (returnedSize = 0; Data[returnedSize]; returnedSize++);
    return returnedSize;
}

void String::Show()
{
    int j = 0;
    while (Data[j] != '\0')
    {
        std::cout<<Data[j]<<"";
        j++;
    }
    std::cout<<std::endl;
}



char String::operator[](size_t index) const
{
    return Data[index];
}

char& String::operator[](size_t index)
{
    char& returnedChar = Data[index];
    return returnedChar;
}

void String::LTrim(char symbol) {
    size_t i = 0, j = 0;
    while (Data[i] == symbol)
        i++;
    while (Data[j + i] != '\0') {
        Data[j] = Data[j + i];
        j++;
    }
    Data[j] = '\0';

}

void String::RTrim(char symbol) {
    size_t i = 0;
    for (i = 0; Data[i]; i++);
    i--;
    while (Data[i] == symbol) {
        Data[i] = '\0';
        i--;
    }
}


bool String::Empty() const
{
    return strlen(Data) == 0;
}

std::ostream &operator<<(std::ostream &, const String &) {

    return <#initializer#>;
}



// Доделать.
/*std::ostream &operator<<(std::ostream &, const String &) {
    return <#initializer#>;
}
*/
