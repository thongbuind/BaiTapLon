#include "header.h"

void menu_0 () {
    cout << "~~~~~~~ HE THONG QUAN LY XUAT NHAP KHO ~~~~~~~" << endl;
    cout << "      1.Dang nhap                2.Thoat      " << endl;
    cout << "               3.Tro ly ao ニダイ              " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void menu_main () {
    cout << "~~~~~~~ HE THONG QUAN LY XUAT NHAP KHO ~~~~~~~" << endl;
    cout << "1.Tra cuu                 4.Nhap kho " << endl;
    cout << "2.Them moi                5.Tinh toan" << endl;
    cout << "3.Xuat kho                6.Quan ly " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void yesno_question (string q, int& ynq) {
    if (q == "yes" || q == "y" || q == "co" || q == "yesss" || q == "ye" || q == "yess" || q == "1" || q == "coo" || q == "cooo" || q == "coooo" || q == "yessss") {
        ynq=1;
    } else if (q == "no" || q == "n" || q == "khong" || q == "noo" || q == "nooo" || q == "khongg" || q == "0" || q == "khonggg") {
        ynq=0;
    } else {
        ynq=3;
    }
}

int change_input_main (string input) {
    int option;
    if (input == "1" || input == "tra cuu") {
        option = 1;
    } else if (input == "2" || input == "them moi") {
        option = 2;
    } else if (input == "3" || input == "xuat kho") {
        option = 3;
    } else if (input == "4" || input == "nhap kho") {
        option = 4;
    } else if (input == "5" || input == "tinh toan") {
        option = 5;
    } else if (input == "6" || input == "quan ly") {
        option = 6;
    } else {
        option = 0;
    }
    return option;
}
