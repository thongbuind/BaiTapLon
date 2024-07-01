#include "header.h"

int main() {
    vector<product> p;
    vector<manage> m;
    p.push_back({"sach giai tich", 19, 30000});
    p.push_back({"sach vat ly", 15, 23000});
    p.push_back({"sach tin hoc", 17, 20000});
    p.push_back({"cap sach", 16, 300000});
    p.push_back({"ao dong phuc", 61, 150000});
    p.push_back({"quan dong phuc", 61, 110000});
    p.push_back({"may chieu", 7, 1100000});
    int count = 7;
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
                            tinh_nang_tra_cuu(p, count);
                            break;
                        }
                        case 2: {
                            tinh_nang_them(p, m, number_in, money_out, count, name_staff_tmp);
                            break;
                        }
                        case 3: {
                            tinh_nang_xuat_kho(p, m, money_in, number_out, count, name_staff_tmp);
                            break;
                        }
                        case 4: {
                            tinh_nang_nhap_kho(p, m, money_out, number_in, count, name_staff_tmp);
                            break;
                        }
                        case 5: {
                            tinh_nang_tinh_toan(p, m, money_in, number_out, count, name_staff_tmp);
                            break;
                        }
                        case 6: {
                            tinh_nang_quan_ly(p, count, m, total_money, money_in, money_out, number_in, number_out, index_staff, staff);
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
            } else if (option_0 == 3) {
                cout << "Nhap ten nhan vien: ";
                cin.ignore();
                getline(cin, staff[index_staff]);
                string name_staff_tmp = staff[index_staff];
                index_staff+=1;
                // ///////////////////////////////////////////////////////////////
                nidai_assistant(p, count, money_out, money_in, m, name_staff_tmp, number_in, number_out);
                // ///////////////////////////////////////////////////////////////
            } else {
                cout << "❌Khong xac dinh duoc lenh, vui long nhap lai." << endl;
            }
            menu_0();
            cout << "Nhap thao tac: ";
        } while (option_0!=1 && option_0!=2);
    } while (option_0==1);
}
