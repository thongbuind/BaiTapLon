#include "header.h"

int tinh_toan (string name[], int quantity[], int index, int count, vector<product>& p) {
    int sum=0;
    for (int i=0; i<index; i++){
        for (int j=0; j<count; j++) {
            if (name[i] == p[j].name) {
                sum += p[j].price * quantity[i];
            }
        }
    }
    return sum;
}

void tinh_nang_tinh_toan (vector<product>& p, vector<manage>& m, int& index_manage, int& money_in, int& number_out, int& count, string name_staff_tmp) {
    int index;
    int checkcheck;
    string q;
    // dùng vòng do while để nhập số lượng
    do {
        cout << "   Nhap so luong mat hang can tinh: ";
        cin >> index;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
        }
    } while (index <= 0 || cin.fail());
    // phải khai báo biến ở đây vì index vừa mới nhập
    string name[index];
    int quantity[index];
    int check[index];
    int ynq;
    for (int i=0; i<index; i++) {
        // dùng vòng do while để nhập và check tên sp
        do {
            cout << "   Nhap ten mat hang " << i+1 << ": ";
            cin.ignore();
            getline(cin, name[i]);
            for (int j=0; j<count; j++) {
                if (name[i] == p[j].name) {
                        check[i] = 1;
                }
            }
            // dùng vòng do while để nhập số lượng
            do {
                cout << "   Nhap so luong cua mat hang " << i+1 << ": ";
                cin >> quantity[i];
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                // kiểm tra số lượng có đủ trong kho không
                if (!cin.fail()) {
                    for (int j=0; j<count; j++) {
                        if (name[i] == p[j].name) {
                            if (quantity[i] > p[j].quantity) {
                                check[i] = 0;
                                cout << "   ❌So luong san pham khong du trong kho." << endl;
                            }
                        }
                    }
                }
            } while (quantity[i] <= 0 || cin.fail());
        } while (check[i]!=1);
    }
    cout << "   Thanh tien: " << tinh_toan(name, quantity, index, count, p) << " VND" << endl;
    // hỏi xem muốn xuất kho những sản phẩm trên không
    do {
        cout << "   Ban muon xuat hoa don khong? ";
        cin >> q;
        yesno_question(q, ynq);
        if (ynq==1) {
            for (int i=0; i<index; i++) {
                xuat_kho(name[i], quantity[i], count, p, checkcheck, money_in, m, index_manage, name_staff_tmp, number_out);
            }
            cout << "   ✅Xuat kho thanh cong." << endl;
        } else if (ynq==3) {
            cout << "   ❌Khong xac dinh duoc lenh." << endl;
        }
    } while (ynq==3);
}

void tinh_nang_quan_ly (vector<product>& p, int count, vector<manage>& m, int& total_money, int& money_in, int& money_out, int& number_in, int& number_out, int& index_staff, string staff[]) {
    // check xem nhân viên có được cấp quyền truy cập tính năng không
    if (staff[index_staff-1] == "quanly") {
        int option_6;
        total_money = total_money + money_in - money_out;
        menu_6(total_money);
        do {
            cout << "   Chon thao tac: ";
            cin >> option_6;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
            }
        } while (option_6 > 5 || option_6 < 1 || cin.fail());
        switch (option_6) {
            case 1: {
                cout << "       Tong tien chi ra: " << money_out << endl;
                cout << "       Tong tien thu vao: " << money_in << endl;
                break;
            }
            case 2: {
                cout << "           Tong so nhan vien lam viec: " << index_staff << endl;
                for (int i=0; i<index_staff; i++) {
                    cout << "       |" << setw(1) << i+1 << "|" << setw(20) << left << staff[i] << "|" << endl;
                }
                break;
            }
            case 3: {
                int stt=1;
                cout << "       So lan xuat kho: " << number_out << endl;
                cout << "       |STT|    TEN MAT HANG    |SO LUONG|   TEN NHAN VIEN    |" << endl;
                for (int i=0; i<(number_out+number_in); i++) {
                    if (m[i].quantity<0) {
                        cout << "       |" << setw(2) << right << stt << " |" << setw(20) << left  << m[i].name_product << "|" << setw(5) << right << -m[i].quantity << "   |" << setw(20) << right << m[i].name_staff << "|" << endl;
                        stt++;
                    }
                }
                break;
            }
            case 4: {
                int stt=1;
                cout << "       So lan nhap kho: " << number_in << endl;
                cout << "       |STT|    TEN MAT HANG    |SO LUONG|   TEN NHAN VIEN    |" << endl;
                for (int i=0; i<(number_out+number_in); i++) {
                    if (m[i].quantity>0) {
                        cout << "       |" << setw(2) << right << stt << " |" << setw(20) << left  << m[i].name_product << "|" << setw(5) << right << m[i].quantity << "   |" << setw(20) << right << m[i].name_staff << "|" << endl;
                        stt++;
                    }
                }
                break;
            }
            case 5: { // Sắp xếp lại danh sách kho
                int q;
                cout << "   Sap xep theo:" << endl;
                cout << "       1. Gia tien tang dan" << endl;
                cout << "       2. Gia tien giam dan" << endl;
                cout << "       3. So luong ton kho tang dan" << endl;
                cout << "       4. So luong ton kho giam dan" << endl;

                cout << "   Chon thao tac: ";
                cin >> q;
                switch (q) {
                    case 1: {
                        for (int i=0; i<count; i++) {
                            int min_index = i;
                            for (int j=i; j<count; j++) {
                                if (p[j].price < p[min_index].price) {
                                    min_index = j;
                                }
                            }
                            struct product tmp = p[i];
                            p[i] = p[min_index];
                            p[min_index] = tmp;
                        }
                        cout << "   ✅Sap xep thanh cong" << endl;
                        break;
                    }
                    case 2: {
                        for (int i=0; i<count; i++) {
                            int max_index = i;
                            for (int j=i; j<count; j++) {
                                if (p[j].price > p[max_index].price) {
                                    max_index = j;
                                }
                            }
                            struct product tmp = p[i];
                            p[i] = p[max_index];
                            p[max_index] = tmp;
                        }
                        cout << "   ✅Sap xep thanh cong" << endl;
                        break;
                    }
                    case 3: {
                        for (int i=0; i<count; i++) {
                            int min_index = i;
                            for (int j=i; j<count; j++) {
                                if (p[j].quantity < p[min_index].quantity) {
                                    min_index = j;
                                }
                            }
                            struct product tmp = p[i];
                            p[i] = p[min_index];
                            p[min_index] = tmp;
                        }
                        cout << "   ✅Sap xep thanh cong" << endl;
                        break;
                    }
                    case 4: {
                        for (int i=0; i<count; i++) {
                            int max_index = i;
                            for (int j=i; j<count; j++) {
                                if (p[j].quantity > p[max_index].quantity) {
                                    max_index = j;
                                }
                            }
                            struct product tmp = p[i];
                            p[i] = p[max_index];
                            p[max_index] = tmp;
                        }
                        cout << "   ✅Sap xep thanh cong" << endl;
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            default:
                cout << "   ❌Khong xac dinh duoc lenh, vui long thu lai." << endl;
                // không bao giờ xảy ra vì vòng do while ở trên không cho phép nhập sai
                break;
        }
    } else {
        cout << "   ❌Ban khong co quyen truy cap quan ly." << endl;
    }
}



