void test_list_int(){
    std::vector<int> res_items = {9,8,7,6,5,4,3,2,1,0};  //то что должно быть в результате
    std::vector<int> items;
    list<int>* first = new list<int>(0);
    for (int i = 1; i < 10; ++i) {
        first -> add_item_in_last(i);        //заполняю список цифрами
    }
    first->reverse_list(&first, first);
    items = first->toVector();
    
    if (items == res_items)                 //сравниваю два вектора
        std::cout << "test_list_int OK\n";
    else
        std::cout << "test_list_int error\n";
    delete first;
    return;
}

void test_list_str() {
    std::vector<std::string> initially_items = {"a","b","c","d","e","f","g","h"};
    std::vector<std::string> res_items = {"h","g","f","e","d","c","b","a"};
    std::vector<std::string> items;
    
    list<std::string>* first = new list<std::string>(initially_items[0]);
    for (int i = 1; i < 8; ++i) {
        first -> add_item_in_last(initially_items[i]);
    }
    first->reverse_list(&first, first);
    
    items = first->toVector();
    if (items == res_items)
        std::cout << "test_list_str OK\n";
    else
        std::cout << "test_list_str error\n";
    delete first;
    return;
}


void test_list_char() {
    std::vector<char> initially_items = {'a','b','c','d','e','f','g','h'};
    std::vector<char> res_items = {'h','g','f','e','d','c','b','a'};
    std::vector<char> items;
    
    list<char>* first = new list<char>(initially_items[0]);
    for (int i = 1; i < 8; ++i) {
        first -> add_item_in_last(initially_items[i]);
    }
    first->reverse_list(&first, first);
    
    items = first->toVector();
    if (items == res_items)
        std::cout << "test_list_char OK\n";
    else
        std::cout << "test_list_char error\n";
    delete first;
    return;
}

