struct Item {
    int value;
    int column;
    Item *next;
    Item() {std::cout << "Item constructor\n";next = nullptr;}
};

class Table {
public:
    int row;
    Item *next;
    int insert(int column, int value);
    //constructor
    Table() {std::cout << "constructor\n";next = nullptr;}
    //destructor
    ~Table();
    //copy constructor
    Table(const Table &o);
    //copy assignment constuctor
    void operator=(const Table &o);
};


void row_init(Table *table, int n); // More convinient?
