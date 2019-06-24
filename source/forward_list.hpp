//
// Created by Yaroslav Haus on 2019-06-20.
//
#ifndef SOURCE_FORWARD_LIST_HPP_
#define SOURCE_FORWARD_LIST_HPP_

#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class ForwardList
{
private:
    struct node
    {
        T data;
        node* next = nullptr;
    };
    node *_head;
    node *_tail;
    size_t list_size{};

public:
    ForwardList();

    ForwardList(const ForwardList<T>&);

    explicit ForwardList(const T& value);

    ~ForwardList();

    T operator[](size_t i) const;

    T &operator[](size_t i);

    ForwardList<T> &operator=(const ForwardList<T> &);

    ForwardList<T> &swap(ForwardList<T>& swappedList);

    ForwardList<T> &reverse();

    size_t size() const;

    bool empty() const;

    bool unique(const T &) const;

    void push_back(const T &);

    void push_front(const T &);

    void insert_after(const T &, const T &);

    void pop_back();

    void pop_front();

    void erase(const T &);

    void print() const;

    void clear() const;

    void create_first_node(const T&);
};

template <typename T> // Пустая инициализация листа:
ForwardList<T>::ForwardList() : _head(nullptr), _tail(nullptr), list_size(0) {}

template <typename T> // Деструктор
ForwardList<T>::~ForwardList()
{
    delete _tail;
    _tail = nullptr;
    delete _head;
    _head = nullptr;
};

template <typename T> // Инициализация первого лемента списка:
void ForwardList<T>::create_first_node(const T& value)
{
    // Создаем новый элемент в списке
    node* elem = new node;
    // Значение элемента == заданому значению
    elem->data = value;
    // След элемент = nullptr(конец)
    elem->next = nullptr;
    // Указатели на начало и конец =, так как элемент единственынй
    _head = elem;
    _tail = elem;
    // Увеличиваем нашу длину
    ++list_size;
}

template <typename T> // Добавление нового элемента в конец списка:
void ForwardList<T>::push_back(const T& value)
{
    // Если наш лист пуст:
    if (_tail == nullptr)
    {   // Просто создаем первый элемент
        ForwardList<T>::create_first_node(value);
    }else // Если уже есть элементы:
    {
        // Создаем новый элемент
        node* elem = new node;
        // Присваиваем значению элемента заданное значение
        elem->data = value;
        // Следующий элемент = концу
        elem->next = nullptr;
        _tail->next = elem;
        _tail = elem;
        // Увеличиваем длину списка
        ++list_size;
    }
};

template <typename T> // Инициализация от листа
ForwardList<T>::ForwardList(const ForwardList<T>& obj)
{
    // Освобождаем память:
    _head = nullptr;
    _tail = nullptr;
    list_size = 0;
    // Идем по всем элементам второго списка и добавляем элементы через пушбэк
    for (node* tmp = obj._head; tmp != nullptr; tmp = tmp->next)
    {
        ForwardList::push_back(tmp->data);
    }
};

template <typename T> // Перегружаем оператор =
ForwardList<T>& ForwardList<T>::operator=(const ForwardList<T>& obj)
{   // Если приравниваем одинавовые объекты, просто возвращаем себя
    if (this == &obj)
    {
        return *this;
    }
    // Если нет, то пользуемся конструктором от листа
    *this(obj);
    return *this;
}

template <typename T> // Инициализация от переменной
ForwardList<T>::ForwardList(const T &value)
{   // Просто задаем 1 элемент листа = этой переменной
    ForwardList<T>::create_first_node(value);
}

template <typename T> // Получение длины листа:
size_t ForwardList<T>::size() const
{
    size_t length = 0;
    for (node* tmp = _head; tmp != nullptr; tmp = tmp->next)
        ++length;

    return length;
};


template <typename T> // Проверка на пустоту:
bool ForwardList<T>::empty() const
{
    return list_size == 0;
};

template <typename T> // Добавление нового элемента в начало списка:
void ForwardList<T>::push_front(const T& value)
{
    // Если наш лист был пуст, то создаем первый элемент в нем:
    if (_head == nullptr)
    {
        ForwardList<T>::create_first_node(value);
    }else
    {
        // Создаем новый элемент
        node* elem = new node;
        // Значение элемента = заданному значению
        elem->data = value;
        // Указываем, что наш элемент - первый
        elem->next = _head;
        // Присваиваем верхушке списка сдвинутый указатель
        _head = elem;
        // Увеличиваем длину
        ++list_size;
    }
};

template <typename T> // Вставить элемент после заданного индекса:
void ForwardList<T>::insert_after(const T& value, const T& index)
{
    // Объявляем начало списка
    size_t indexChecker = 1;
    // Идем по всем элементам нашего списка
    for (node* tmp = _head; tmp != nullptr; tmp = tmp->next)
    {
        // Если наш элемент под нужным индексом:
        if (indexChecker == index)
        {
            // Создаем новый элемент
            node* elem = new node;
            // Присваиваем ему новое значение
            elem->data = value;
            // Указатель на следующий элемент
            elem->next = tmp->next;
            tmp->next = elem;
            // Если этот элемент находится в конце
            if (tmp == _tail)
            {
                _tail = elem;
            }
            // увеличиваем длину списка
            ++list_size;
        }
        // Сдвигаем счетчик индекса
        indexChecker++;
    }
};



template <typename T> // Удалить элемент под заданным индексом
void ForwardList<T>::erase(const T& index)
{   // Если длина = 1, то просто удаляем этот элемент
    if (index == 1)
    {
        pop_front();
    }else
    {
        // Создаем новый элемент, он указывает на начало
        node *temp = this->_head;
        // Сдвигаем указатель до нашего индекса
        for (int i = 1; i < index - 1; i++)
        {
            temp = temp->next;
        }
        // Создаем еще 1 эдемент, который указывает на следующий
        node *del = temp->next;
        // Присваиваем следующему элементу указатель на следующий
        temp->next = del->next;
        // Освобожадем память
        delete del;
        // Уменьшаем длину
        list_size--;
    }
};

template <typename T> // Метод принт
void ForwardList<T>::print() const
{
    // Если лист пустой
    if (_head == nullptr)
    {
        std::cout << "Not elements" << std::endl;
        return;
    }else
    {   // Выводим значение каждого элемента
        for (node* tmp = _head; tmp != nullptr; tmp = tmp->next)
            std::cout << tmp->data << " ";
        std::cout << std::endl;
    }
};


template <typename T> // Убрать последний элемент:
void ForwardList<T>::pop_back()
{   // Если в списке больше 1 элемента:
    if (size() >= 2)
    {   // Идем до конца списка
        for (node* tmp = _head; tmp != nullptr; tmp = tmp->next)
            // Если наш следующий элемент последний
            if (tmp->next == _tail)
            {   // То обнуляем указатель на него
                tmp->next = nullptr;
                // А сейчашний элемент становится последним
                _tail = tmp;
                list_size--;
            }
    }else if (size() == 1) // Если элемент 1, убираем его
        pop_front();
    else // Если элементов нет вообще:
        std::cout << "Not elements" << std::endl;

};

template <typename T> // Удаление элемента с начала списка
void ForwardList<T>::pop_front()
{
    if (_head != nullptr)
    {
        // Тут у меня не получилось красиво сделать=((
        for (node *tmp = _head; tmp != nullptr; tmp = tmp->next)
        {   // Если наш элемент = первому элементу(А он равен)))
            if (tmp == _head)
            {
                // То присваиваем ему указатель на следующий
                tmp = _head->next;
                // Очищаем память:
                _head = nullptr;
                _tail = nullptr;
                list_size = 0;
                // Сдвигаем наш первый элемент
                _head = tmp;
            }
        }
    }else
        std::cout << "Not elements" << std::endl;
}

template<typename T> // Очистка всего листа
void ForwardList<T>::clear() const
{
    _head = nullptr;
    _tail = nullptr;
    list_size = 0;
}

template<typename T> // Перегружаем [](для значения по индексу элемента)
T &ForwardList<T>::operator[](const size_t i)
{
    size_t j = 0;
    for (node* tmp = _head; tmp != nullptr; tmp = tmp->next)
    {
        j++;
        if (j == i)
            return tmp->data;
    }
}

template<typename T>
T ForwardList<T>::operator[](const size_t i) const
{
    size_t j = 0;
    for (node* tmp = _head; tmp != nullptr; tmp = tmp->next)
    {
        j++;
        if (j == i)
            return tmp->data;
    }
}

template<typename T> // Метод реверс:
ForwardList<T>& ForwardList<T>::reverse()
{   // Сохраняем наш изначальный список
    ForwardList<T> bufList(*this);
    // Очищаем
    _head = nullptr;
    _tail = nullptr;
    list_size = 0;
    // Идем по всем элементам списка
    for (node* tmp = bufList._head; tmp != nullptr; tmp=tmp->next)
        // Пушфрнотим, таким образом у нас получится обратный порядок))
        ForwardList::push_front(tmp->data);
    // Возвращаем длину нашему списку
    list_size = bufList.size();
    return *this;
}

template<typename T> // Проверка значения на уникальность в списке:
bool ForwardList<T>::unique(const T & value) const
{   // Ставим счетчик совпадений
    int checker = 0;
    // Идем по всем элементам
    for (node* tmp = _head; tmp != nullptr; tmp=tmp->next)
    {   // Если есть совпадения прибавляем
        if (tmp->data == value)
            checker++;
        // Если наш счетчик вдруг стал >1 значит искомое значение-не уникально
        if (checker > 1)
            return false;
    }
    // Если дошли до сюда, значит счетчик не превысил 1
    return true;
}


template<typename T> // Метод свап((
ForwardList<T> &ForwardList<T>::swap(ForwardList<T>& swappedList)
{
    // Сохраняем наш список
    ForwardList<T> bufList(*this);
    // Очищаем
    _head = nullptr;
    _tail = nullptr;
    list_size = 0;
    // Заполняем заново наш список значениями другого списка
    for (node* tmp = swappedList._head; tmp != nullptr; tmp=tmp->next)
        ForwardList::push_back(tmp->data);
    // Возвращаем дилну
    list_size = swappedList.size();
    // Очищаем второй список
    swappedList._head = nullptr;
    swappedList._tail = nullptr;
    swappedList.list_size = 0;
    // Присваиваем ему значения из сохраненного списка
    for (node* tmp = bufList._head; tmp != nullptr; tmp=tmp->next)
        swappedList.push_back(tmp->data);
    // Возвращаем длину
    swappedList.list_size = bufList.size();
    return *this;
}

#endif //SOURCE_FORWARD_LIST_HPP_
