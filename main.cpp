#include <iostream>
#include "header.h"

int main() {
    product p[100];
    manage m[100];
    p[0] = {"sach giai tich", 19, 3000};
    p[1] = {"sach vat ly", 15, 23000};
    p[2] = {"sach tin hoc", 17, 20000};
    p[3] = {"cap sach", 16, 300000};
    p[4] = {"ao dong phuc", 61, 150000};
    p[5] = {"quan dong phuc", 61, 110000};
    p[6] = {"may chieu", 7, 1100000};
    int count = 7;
    int index_manage = 0;
    int number_in = 0;
    int number_out = 0;
    int total_money = 10000000;
    int money_in = 0;
    int money_out = 0;
    int option_0;
    string input_main;
    int option_main = 0;
    int ynq0;
    string c;
    int index_staff = 0;
    string staff[50];
    menu_0();
    cout << "Nhap thao tac: ";
    do {
        do {
            do {
                cin >> option_0;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(100, '\n');
                }
            } while (cin.fail());
            if (option_0 == 1) {
                cout << "Nhap ten nhan vien: ";
                cin.ignore();
                getline(cin, staff[index_staff]);
                string name_staff_tmp = staff[index_staff];
                index_staff+=1;
                do {
                    menu_main();
                    do {
                        cout << "Chon thao tac: ";
                        cin >> input_main;
                        option_main = change_input_main(input_main);
                    } while (option_main == 0);
                    switch (option_main) {
                        case 1: {
                            // dùng hàm tính năng tra cứu
                            cout << "Tinh nang tra cuu";
                            break;
                        }
                        case 2: {
                            // dùng hàm tính năng thêm
                            cout << "Tinh nang them";
                            break;
                        }
                        case 3: {
                            // dùng hàm tính năng xuất kho
                            cout << "Tinh nang xuat kho";
                            break;
                        }
                        case 4: {
                            // dùng hàm tính năng nhập kho
                            cout << "Tinh nang nhap kho";
                            break;
                        }
                        case 5: {
                            // dùng hàm tính năng tính toán
                            cout << "Tinh nang tinh toan";
                            break;
                        }
                        case 6: {
                            // dùng hàm tính năng quản lý
                            cout << "Tinh nang quan ly";
                            break;
                        }
                        default:
                            cout << "   ❌Khong xac dinh duoc lenh." << endl;
                            break;
                    }
                    do {
                        cout << "Ban muon tiep tuc khong(yes/no): ";
                        cin >> c;
                        yesno_question(c, ynq0);
                        if (ynq0==3) {
                            cout << "❌Khong xac dinh duoc lenh." << endl;
                        }
                    } while (ynq0==3);
                } while (ynq0==1);
            } else if (option_0 == 2) {
                break;
            } else {
                cout << "❌Khong xac dinh duoc lenh, vui long nhap lai." << endl;
            }
            menu_0();
            cout << "Nhap thao tac: ";
        } while (option_0!=1 && option_0!=2);
    } while (option_0==1);
}
