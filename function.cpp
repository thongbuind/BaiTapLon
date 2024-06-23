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

int tinh_toan (string name[], int quantity[], int index, int count, product p[]) {
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

void tinh_nang_tinh_toan (product p[], manage m[], int& index_manage, int& money_in, int& number_out, int& count, string name_staff_tmp) {
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

void tinh_nang_quan_ly (product p[], int count, manage m[], int& total_money, int& money_in, int& money_out, int& number_in, int& number_out, int& index_staff, string staff[]) {
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
