#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <vector>
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

// Khai báo các hàm c?a Thông
void menu_0();
void menu_main();
void menu_6 (int);
void yesno_question(string, int&);
int change_input_main (string);
// Khai báo các hàm c?a Long
void tra_cuu_danh_sach(int, vector<product>);
void tra_cuu_vi_tri(string, int, vector<product>, char&, int&, int&);
void tinh_nang_tra_cuu (vector<product>&, int&);
void them(string, int, int, int&, vector<product>&, int&, int&, vector<manage>&, int&, string, int&);
void tinh_nang_them (vector<product>&, vector<manage>&, int&, int&, int&, int&, string);
// Khai báo các hàm c?a Thành
void xuat_kho(string, int, int, vector<product>&, int&, int&, vector<manage>&, int&, string, int&);
void nhap_kho(string, int, int, vector<product>&, int&, int&, vector<manage>&, int&, string, int&);
void tinh_nang_xuat_kho (vector<product>&, vector<manage>&, int&, int&, int& , int&, string);
void tinh_nang_nhap_kho (vector<product>&, vector<manage>&, int&, int&, int&, int&, string);
// Khai báo các hàm c?a Thiên
int tinh_toan(string[], int[], int, int, vector<product>&);
void tinh_nang_tinh_toan (vector<product>&, vector<manage>&, int&, int&, int&, int&, string);
void tinh_nang_quan_ly (vector<product>&, int, vector<manage>&, int&, int&, int&, int&, int&, int&, string[]);
// Làm cho zui
void nidai_assistant (vector<product>&, int&, int&, int&, vector<manage>&, int&, string, int&, int&);
int check_oders (string);
int check_yes_no (string);
void check_regex (string, string, string&);

#endif // HEADER_H
