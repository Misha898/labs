#include"tractrix.h"

static const std::string str = "1 - p3), 2 - p4), 3 - p5), 4 - p6)\n";
static const std::string str1 = "Enter angle\n";

template<typename T>
void getNum(T &a, std::string msg = "Enter number\n") { 
    cout << msg;
    cin >> a;
    while(!cin.good()) {
        cin.clear();
        cin.ignore(255,'\n');
        cout << msg;
        cin >> a;
    }
}

void dialog(Tractrix &tr) {
    int cs;
    double arc;
    while (1) {
    cout << str;
    getNum(cs, "Enter int number(make choice)\n");
        switch (cs) {
        case 1:
            getNum(arc, str1);
            tr.func3(arc);
            break;
        case 2:
            getNum(arc, str1);
            tr.len(arc);
            break;
        case 3:
            getNum(arc, str1);
            tr.radius(arc);
            break;
        case 4:
            tr.square(); 
            break;
        default:
            return;
        } 
    }
}

int main() {
    Tractrix tr;
    double a;
    //cout << tan(1) << endl;
    ////cout << tan(0.5) << endl;
    getNum(a, "Enter constant\n");
    tr.set_a(a);
    dialog(tr);
    return 0;
}
