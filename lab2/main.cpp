#include"tractrix.h"

static const std::string str = "1 - p3), 2 - p4), 3 - p5), 4 - p6), 5 - p7), 6 - p8 \n";
static const std::string str1 = "Enter angle\n";

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
        case 5:
            tr.square_rot();
            break;
        case 6:
            tr.volume();
            break;
        default:
            return;
        } 
    }
}

int main() {
    Tractrix tr;
    double a;
    getNum(a, "Enter constant\n");
    tr.set_a(a);
    dialog(tr);
    return 0;
}
