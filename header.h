#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <vector> // Quan ly mang dong
#include <iomanip> // Can le cho bang
#include <regex> // Tim kiem tu khoa cho tro ly ao
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

// Khai bao ham cua Thong
void menu_0();
void menu_main();
void menu_6 (int);
void yesno_question(string, int&);
int change_input_main (string);
// Khai bao cac ham cua Long
void tra_cuu_danh_sach(int, vector<product>);
void tra_cuu_vi_tri(string, int, vector<product>, char&, int&, int&);
void tinh_nang_tra_cuu (vector<product>&, int&);
void them (string, int, int, int&, vector<product>&, int&, int&, vector<manage>&, string, int&);
void tinh_nang_them (vector<product>&, vector<manage>&, int&, int&, int&, string);
// Khai bao cac ham của Thanh
void xuat_kho(string, int, int, vector<product>&, int&, int&, vector<manage>&, string, int&);
void nhap_kho(string, int, int, vector<product>&, int&, int&, vector<manage>&, string, int&);
void tinh_nang_xuat_kho (vector<product>&, vector<manage>&, int&, int& , int&, string);
void tinh_nang_nhap_kho (vector<product>&, vector<manage>&, int&, int&, int&, string);
// Khai bao cac ham cua Thien
int tinh_toan(string[], int[], int, int, vector<product>&);
void tinh_nang_tinh_toan (vector<product>&, vector<manage>&, int&, int&, int&, string);
void tinh_nang_quan_ly (vector<product>&, int, vector<manage>&, int&, int&, int&, int&, int&, int&, string[]);
// Lam cho zui
void nidai_assistant (vector<product>&, int&, int&, int&, vector<manage>&, string, int&, int&);
int check_orders (string);
int check_yes_no (string);
void check_regex (string, string, string&);

#endif // HEADER_H


