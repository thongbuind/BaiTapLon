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


// Khai báo các hàm
void menu_0();


#endif // HEADER_H
