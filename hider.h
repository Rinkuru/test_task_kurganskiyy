#pragma once
#include <vector>

template <typename T>
class list {
    T item;
    list<T>* next;
public:
    list();
    list(T new_item);
    ~list();
    T get_item();
    void put_item(T new_item);
    void put_next(list<T>* next);
    void add_item_in_last(T new_item);
    void print_all_item();
    void reverse_list(list<T>** last, list<T>* first);
    std::vector<T> toVector();
};
