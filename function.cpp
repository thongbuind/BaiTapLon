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

void check_regex (string modun, string input, string& output) {
    // hàm để lọc keyworld từ input
    regex sach_giai_tich ("sach giai tich");
    regex sach_vat_ly ("sach vat ly");
    regex sach_tin_hoc ("sach tin hoc");
    regex cap_sach ("cap sach");
    regex ao_dong_phuc ("ao dong phuc");
    regex quan_dong_phuc ("quan dong phuc");
    regex may_chieu ("may chieu");
    regex danh_sach ("danh sach");
    regex vi_tri ("vi tri");
    regex lam ("lam");
    regex giup ("giup");
    regex thong_tin ("thong tin");
    if (modun == "name") {
        if (regex_search(input, sach_giai_tich)) {
            output = "sach giai tich";
        } else if (regex_search(input, sach_vat_ly)) {
            output = "sach vat ly";
        } else if (regex_search(input, sach_tin_hoc)) {
            output = "sach tin hoc";
        } else if (regex_search(input, cap_sach)) {
            output = "cap sach";
        } else if (regex_search(input, ao_dong_phuc)) {
            output = "ao dong phuc";
        } else if (regex_search(input, quan_dong_phuc)) {
            output = "quan dong phuc";
        } else if (regex_search(input, may_chieu)) {
            output = "may chieu";
        } else {
            output = input;
        }
    } else if (modun == "gioi thieu") {
        if (regex_search(input, lam)) {
            output = "lam";
        } else if (regex_search(input, giup)) {
            output = "giup";
        } else if (regex_search(input, thong_tin)) {
            output = "thong tin";
        } else {
            output = input;
        }
    } else if (modun == "danh sach") {
        if (regex_search(input, danh_sach)) {
            output = "danh sach";
        } else if (regex_search(input, vi_tri)) {
            output = "vi tri";
        } else {
            output = input;
        }
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
