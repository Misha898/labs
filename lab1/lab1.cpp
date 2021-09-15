//Var 21
#include<iostream>
#include"lab1.hpp"

template <class T>
int getNum(T &a) {
    std::cin >> a;
    if (!std::cin.good())
        return -1;
return 1;
}

void input(Table *table, int rown, int coln) {
    int column, value;
    for (int i = 0; i < rown; ++i) {
        for(;;) {
            std::cout << "There is " << i + 1 << "th row now\n";
            std::cout << "You must enter pair: column and number" << std::endl;
            std::cout << "Go to a new line: \'0\'" << std::endl;
            getNum(column);
            if (!column || column > coln)
                break;
            getNum(value);
            table[i].insert(column - 1, value);
            //I want to enter 'n' to go to next line... 
        }
    }
    return;
}

void print_m(Table *table, int rown, int coln) {
    Item *tmp;
    for (int i = 0; i < rown; ++i) {
        tmp = table[i].next;
        for (int j = 0; j < coln; ++j) {
            if (tmp && tmp->column == j) {
                std::cout << tmp->value << " ";
                tmp = tmp->next;
            }
            else {
                std::cout << 0 << " ";
            }
        }
        std::cout << "\n";
    }
    return;
}

void swap_min(Table *table2, int n) {
    Item *tmp_fir, *tmp_min, *tmp;
    //int min;
    int sw;
    for (int i = 0; i < n; ++i) {
        tmp_fir = tmp = tmp_min = table2[i].next;
        if (!tmp_fir)
            continue;
        //min = tmp_min->value;
        tmp = tmp->next;
        while (tmp) {
            if (tmp->value < tmp_min->value)
                tmp_min = tmp;
            tmp = tmp->next;
        }
        //std::cout << "tmp_min->value: " << tmp_min->value
          //      << " " << tmp_min->column << std::endl;
        sw = tmp_fir->value;
        tmp_fir->value = tmp_min->value;
        tmp_min->value = sw;
    }
    return;
}

void main_func(Table *table, Table *table2, int n) {
    Item *tmp, *tmp2, *tmp_prev;
    for (int i = 0; i < n; ++i) {
        tmp = table[i].next;
        table2[i].next = tmp_prev = tmp;
        if (tmp) {
            table2[i].next = tmp_prev = new Item;
            tmp_prev->column = tmp->column;
            tmp_prev->value = tmp->value;
            tmp = tmp->next;
        }
        while (tmp) {
            tmp2 = new Item;
            tmp2->value = tmp->value;
            tmp2->column = tmp->column;
            tmp_prev->next = tmp2;
            tmp_prev = tmp2;
            tmp = tmp->next;
        }
    }
    swap_min(table2, n);
}

int main() {
    int n, m;
    Table *table, *table2; // "Table" or "class Table"(typedef)?
    std::cout << "Enter count of rows" << std::endl;
    getNum(n);
    std::cout << "Enter count of columns" << std::endl;
    getNum(m);
    std::cout << "Column: " << m << "\nRow: " << n << std::endl;  
    table = new Table [n];
    row_init(table, n);
    input(table, n, m);
    print_m(table, n, m);
    //delete [] table;
    // ***************************
    table2 = new Table[n];
    for (int i = 0; i < n; ++i) { // I don't like this::<<(
        table2[i] = table[i];
        std::cout << table[i].next << " debug \n\n"; // debug
    }
    main_func(table, table2, n);
    print_m(table2, n, m);
    // ***************************
    delete [] table;
    delete [] table2;
    return 0; 
}
