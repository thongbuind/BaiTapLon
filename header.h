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
void tra_cuu_danh_sach(int, product[]);
void tra_cuu_vi_tri(string, int, product[], char&, int&, int&);
void tinh_nang_tra_cuu (product[], int&);
void them(string, int, int, int&, product[], int&, int&, manage[], int&, string, int&);
void tinh_nang_them (product[], manage[], int&, int&, int&, int&, string);

// Khai báo các hàm của Thiên





#endif // HEADER_H
