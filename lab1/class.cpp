#include<iostream>
#include"lab1.hpp"

inline Table::Table(const Table &o) {
   row = o.row; 
}

void Table::operator=(const Table &o) {
    row = o.row; // this->row = o.row
    //someones return *this for same purposes, why?
}

Table::~Table() {
    Item *tmp = next, *tmp_prev;
    std::cout << "destructor\n";
    if (next == nullptr) {
        std::cout << "Empty row\n";
        return;
    }
    while (tmp) {
        tmp_prev = tmp;
        tmp = tmp->next;
        delete tmp_prev;
        std::cout << "Item from " << row + 1 << "th row was freed\n";
    }
    return;
} 

void row_init(Table *table, int n) { // How to do it more convinient?
    for (int i = 0; i < n; ++i) {
        table[i].row = i;
    }
    return;
}

int Table::insert(int column, int value) {
    Item *tmp, *tmp_prev;
    if (value == 0)
        return 0;
    if (next == nullptr) {
        next = new Item;
        next->value = value;
        next->column = column;
        return 0;
    }
    tmp = next;
    while (tmp) {
        if (tmp->column == column) {
            std::cout << "Cell already busy\n";
            return 1;
        }
        if (tmp->column < column) {
            tmp_prev = tmp;
            tmp = tmp->next;
        }
        else 
            break;
    }
    if (tmp == next) {
        next = new Item;
        next->next = tmp;
        next->column = column;
        next->value = value;
        return 0;
    }
    tmp = tmp_prev->next;
    tmp_prev->next = new Item;
    tmp_prev->next->next = tmp;
    tmp_prev->next->column = column;
    tmp_prev->next->value = value;
    return 0;
}

