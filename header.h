#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
using namespace std;

struct product {
    string name;
    int quantity;
    int price;
};

struct manage {
    string name_product;
    int quantity;
    string name_staff;
};


// Khai báo các hàm của Thông
void menu_0();
void menu_main();
void yesno_question(string, int&);
int change_input_main (string);
// Làm cho zui
void nidai_assistant (product[], int&, int&, int&, manage[], int&, string, int&, int&);
int check_oders (string);
int check_yes_no (string);
void check_regex (string, string, string&);
// Khai báo các hàm của Thành

// Khai báo các hàm của Long

// Khai báo các hàm của Thiên





#endif // HEADER_H
