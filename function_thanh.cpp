#include "header.h"

void xuat_kho (string name, int quantity_out, int count, vector<product>& p, int& check, int& money_in, vector<manage>& m, int& index_manage, string name_staff_tmp, int& number_out) {
    for (int i=0; i<count; i++) {
        if (name == p[i].name ) {
            if (p[i].quantity >= quantity_out) {
                p[i].quantity = p[i].quantity - quantity_out;
                money_in += p[i].price * quantity_out;
                check=1;
                m[index_manage] = {name, -quantity_out, name_staff_tmp};
                index_manage++;
                number_out++;
            } else {
                check=3;
            }
        }
    }
}

void nhap_kho (string name, int quantity_in, int count, vector<product>& p, int& check, int& money_out, vector<manage>& m, int& index_manage, string name_staff_tmp, int& number_in) {
    for (int i=0; i<count; i++) {
        if (name == p[i].name) {
            p[i].quantity = p[i].quantity + quantity_in;
            money_out += p[i].price * quantity_in;
            check=1;
            // m.push_back({name, quantity_in, name_staff_tmp});
            m[index_manage] = {name, quantity_in, name_staff_tmp};
            index_manage++;
            number_in++;
        }
    }
}

void tinh_nang_xuat_kho (vector<product>& p, vector<manage>& m, int& index_manage, int& money_in, int& number_out,int& count, string name_staff_tmp) {
    string name_out;
    int quantity_out;
    int check=0;
    cout << "   Nhap ten mat hang xuat kho: ";
    cin.ignore();
    getline(cin, name_out);
    // vòng do while để nhập số lượng
    do {
        cout << "   Nhap so luong: ";
        cin >> quantity_out;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
        }
    } while (quantity_out <= 0 || cin.fail());
    // dùng hàm xuất kho
    xuat_kho(name_out, quantity_out, count, p, check, money_in, m, index_manage, name_staff_tmp, number_out);
    if (check==1) {
        cout << "   ✅Xuat kho thanh cong." << endl;
    } else if (check==0) {
        cout << "   ❌Khong ton tai hang hoa trong kho." << endl;
    } else if (check==3) {
        cout << "   ❌Khong du so luong." << endl;
    }
}

void tinh_nang_nhap_kho (vector<product>& p, vector<manage>& m, int& index_manage, int& money_out, int& number_in, int& count, string name_staff_tmp) {
    string name_in;
    int quantity_in;
    int check=0;
    int price;
    cout << "   Nhap ten mat hang nhap kho: ";
    cin.ignore();
    getline(cin, name_in);
    // dùng vòng do while để nhập số lượng hợp lệ
    do {
        cout << "   Nhap so luong: ";
        cin >> quantity_in;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
        }
    } while (quantity_in <= 0 || cin.fail());
    nhap_kho(name_in, quantity_in, count, p, check, money_out, m, index_manage, name_staff_tmp, number_in);
    // kiểm tra nhập kho thành công hay không
    if (check==1) {
        cout << "   ✅Nhap kho thanh cong." << endl;
    } else {
        // nếu ko thành công thì tức là do sản phẩm chưa có sẵn trong kho, hỏi xem có muốn nhập kho hay không
        string q;
        int ynq;
        do {
            cout << "   San pham nay chua co san trong kho, ban co muon them khong(yes/no): ";
            cin >> q;
            yesno_question(q, ynq);
            if (ynq==1) {
                // dùng vòng do while để nhập giá
                do {
                    cout << "   Nhap gia san pham: ";
                    cin >> price;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100, '\n');
                    }
                } while (price <= 0 || cin.fail());
                them(name_in, quantity_in, price, count, p, check, money_out, m, index_manage, name_staff_tmp, number_in);
                cout << "   ✅Them san pham thanh cong." << endl;
            } else if (ynq==2) {
                cout << "   ❌San pham khong duoc them vao kho" << endl;
            } else {
                cout << "   ❌Khong xac dinh duoc lenh." << endl;
            }
        } while (ynq!=0 && ynq!=1);
    }
}
