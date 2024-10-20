#include <iostream>
#include "hider.h"
#include "unittest.cpp"

template <typename T>
list<T>::list() {
    next = nullptr;
}

template <typename T>
list<T>::list(T new_item) {
    item = new_item;
    next = nullptr;
}

template <typename T>
list<T>::~list(){
    if (next != nullptr)
        delete next;
}

template <typename T>
T list<T>::get_item() {
    return item;
}

//присваивает значение
template <typename T>
void list<T>::put_item(T new_item) {
    item = new_item;
}

//присваивает ссылку на следующий элемент
template <typename T>
void list<T>::put_next(list<T>* next) {
    this->next = next;
}

//рекурсивно спускаемся до последнего элемента и создаём новый элемент
template <typename T>
void list<T>::add_item_in_last(T new_item) {
    if (next == nullptr)
        next = new list(new_item);
    else
        next->add_item_in_last(new_item);
    return;
}

//рекурсивно проходим по всему списку и выводим значания элементов
template <typename T>
void list<T>::print_all_item() {
    std::cout << item << " ";
    if (next != nullptr)
        next->print_all_item();
    else
        std::cout << "\n";
}

//в last сохраниться ссылка на новое начало списка
//рекурсивно проходим весь список и на обратном ходе заменяем ссылки
template <typename T>
void list<T>::reverse_list(list<T>** last, list<T>* first) {
if (next == nullptr) {
        *last = this;                        //Когда дошли до последнего элемента, сохранили ссылку на этот последний элемеент
    } else {
        next->reverse_list(last, first);     //заходим в каждый элемент
        next->put_next(this);                //меняем указатели
        if (this == first)                   //если мы находимся в первом элементе, то
            next = nullptr;                  //обнуляем ссылку на следующий
    }
    return;
}

//пробегает по всем ссылкам, добавляя в вектор элементы
template <typename T>
std::vector<T> list<T>::toVector() {
std::vector<T> allItem;
list* temp = next;
    allItem.push_back(item);
    while (temp != nullptr) {
        allItem.push_back(temp->item);
        temp = temp->next;
    }
    return allItem;
}

template <typename T>
void print_vector(std::vector<T> items){
    while (!items.empty()) {
        std::cout << items.back();
        items.pop_back();
    }
    std::cout << "\n";
}


int main() {
    test_list_int();
    test_list_str();
    test_list_char();
    
    

/*std::vector<int> items;
    //std::string str;
    //list<std::string>* first = new list<std::string>("qwe");
    list<int>* first = new list<int>(0);
    for (int i = 1; i < 10; ++i) {
        //std::cin >> str;
        first -> add_item_in_last(i);
    }
    first->print_all_item();
    first->reverse_list(&first, first);
    first->print_all_item();
    
    items = first->toVector();
    print_vector(items);
    delete first;*/
    return 0;
}

