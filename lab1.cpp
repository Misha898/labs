//Var 21
#include<iostream>

struct Item {
    int value;
    int column;
    Item *next;
    Item() {std::cout << "Item constructor\n";next = nullptr;};
};
// Can I use classes instead structures(Same memory expenses), (imho no differences)?
class Table {
public:
    Item *next;
    int row;
    int insert (int column, int value);
    Table() {std::cout << "constructor\n";next = nullptr;};
    ~Table();
};

Table::~Table() {
    Item *tmp = next, *tmp_prev;
    std::cout << "destructor\n";
    if (next == nullptr){
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

void getNum (char &num) {
    std::cin >> num;
}

//Templates????
void getNum (int &num) {
    std::cin >> num;
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

int main() {
    int n, m;
    Table *table; // "Table" or "class Table"(typedef)?
    //Table mit;
    std::cout << "Enter count of rows" << std::endl;
    std::cin >> n;
    std::cout << "Enter count of columns" << std::endl;
    std::cin >> m;
    std::cout << "Column: " << m << "\nRow: " << n << std::endl;  
    table = new Table [n];
    row_init(table, n);
    //table = (Table *) malloc(sizeof(Table) * n);
    input(table, n, m);
    print_m(table, n, m);
    delete [] table;
    return 0; 
}
