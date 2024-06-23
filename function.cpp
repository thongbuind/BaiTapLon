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

void tra_cuu_danh_sach (int count, product p[]) {
    cout << "      Tong mat hang: " << count << endl;
    cout << "  |STT|    TEN MAT HANG    |SO LUONG|GIA TIEN|" << endl;
    for (int i=0; i<count; i++) {
        cout << "  |" << setw(2) << right << i+1 << " |" << setw(20) << left << p[i].name << "|" << setw(5) << right << p[i].quantity << "   |" << setw(8) << p[i].price << "|" << endl;
    }
}

void tra_cuu_vi_tri (string name, int count, product p[], char& y, int& x, int& check) {
    for (int i=0; i<count; i++) {
        if (name == p[i].name) {
            if (p[i].price<100000) {
                y = 'A';
            } else if (p[i].price<=1000000) {
                y = 'B';
            } else if (p[i].price<=10000000) {
                y = 'C';
            } else {
                y = 'D';
            }
            if (p[i].quantity<30) {
                x = 1;
            } else if (p[i].quantity<=70) {
                x = 2;
            } else if (p[i].quantity<=100) {
                x = 3;
            } else {
                x = 4;
            }
            check=1;
        }
    }
}

void tinh_nang_tra_cuu (product p[], int& count) {
    int q;
    // hiển thị menu cho người dùng chọn
    cout << "   Ban muon tra cuu gi? " << endl;
    cout << "       1.Danh sach" << endl;
    cout << "       2.Vi tri hang hoa" << endl;
    // vòng do while cho người dùng chọn thao tác
    do {
        cout << "   Chon thao tac: ";
        cin >> q;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "   Thao tac khong hop le, vui long chon lai. " << endl;
        }
    } while ((q!=1 && q!=2) || cin.fail());
    // hàm if else
    if (q==1) {
        tra_cuu_danh_sach(count, p);
    } else if (q==2) {
        string name_search;
        char y;
        int x;
        int check=0;
        cout << "   Nhap ten san pham muon tra cuu: ";
        cin.ignore();
        getline(cin, name_search);
        tra_cuu_vi_tri(name_search, count, p, y, x, check);
        if (check==1) {
            cout << "   Vi tri san pham: " << y << x << endl;
        } else {
            cout << "   ❌Khong nhan dien duoc san pham" << endl;
        }
    }
}

void them (string name, int quantity_add, int price, int& count, product p[], int& check, int& money_out, manage m[], int& index_manage, string name_staff_tmp, int& number_in) {
    p[count] = {name, quantity_add, price};
    count+=1;
    money_out += price * quantity_add;
    m[index_manage] = {name, quantity_add, name_staff_tmp};
    index_manage++;
    number_in++;
}

void tinh_nang_them (product p[], manage m[], int& index_manage, int& number_in, int& money_out, int& count, string name_staff_tmp) {
    string name_add;
    int quantity_add;
    int price;
    int tmp=count;
    int check=0;
    int checkcheck=0;
    cout << "   Nhap ten san pham muon them: ";
    cin.ignore();
    getline(cin, name_add);
    // vòng do while để nhập số lượng thêm vào kho
    do {
        cout << "   Nhap so luong: ";
        cin >> quantity_add;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
        }
    } while (quantity_add <= 0 || cin.fail());
    // vòng do while để nhập số lượng thêm vào kho
    do {
        cout << "   Nhap gia tien cua san pham: ";
        cin >> price;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
        }
    } while (price <= 0 || cin.fail());
    // check xem sản phẩm đã có trong kho chưa
    // nếu có trong kho rồi thì hỏi có muốn nhập kho không
    for (int i=0; i<count; i++) {
        if (name_add == p[i].name) {
            string q;
            int ynq;
            do {
                cout << "   San pham nay da co san trong kho, ban co muon nhap kho khong(yes/no): ";
                cin >> q;
                yesno_question(q, ynq);
                if (ynq==1) {
                    nhap_kho(name_add, quantity_add, count, p, check, money_out, m, index_manage, name_staff_tmp, number_in);
                }
                checkcheck=1;
            } while (ynq!=0 && ynq!=1);
            break;
        }
    }
    // nếu chưa có trong kho thì thêm vào
    if (checkcheck==0) {
        them(name_add, quantity_add, price, count, p, check, money_out, m, index_manage, name_staff_tmp, number_in);
    }
    if (count > tmp) {
        check=1;
    }
    if (check==1) {
        cout << "   ✅Nhap kho thanh cong." << endl;
    } else {
        cout << "   ❌San pham khong duoc them vao kho, xin thu lai." << endl;
    }
}
