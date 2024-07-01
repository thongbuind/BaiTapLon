#include "header.h"

void nidai_assistant (vector<product>& p, int& count, int& money_out, int& money_in, vector<manage>& m, string name_staff_tmp, int& number_in, int& number_out) {
    // tương tự trên nhưng giao tiếp 1 cách thoải mái hơn
    string oders;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << setw(50) << right << "🤖ニダイ" << endl;
    cout << "Xin chao, toi la ニダイ assistant, rat han hanh" << endl;
    cout << "duoc lam quen. Toi co the giup ban trong cong " << endl;
    cout << "viec xuat nhap kho." << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    do {
        cout << "You: ";
        getline(cin, oders);
        check_oders(oders);
        switch (check_oders(oders)) {
            case 0:
                cout << setw(50) << right << "🤖ニダイ" << endl;
                cout << setw(46) << right << "Toi chua hieu y ban cho lam" << endl;
                cout << setw(46) << right << "Ban co the noi ro hon khong?" << endl;
                break;
            case 1: {
                // tra cứu
                string q;
                string q_regex;
                cout << setw(50) << right << "🤖ニダイ" << endl;
                cout << setw(46) << right << "Toi co the giup ban:" << endl;
                cout << setw(46) << right << "Tra cuu danh sach" << endl;
                cout << setw(46) << right << "Tra cuu vi tri" << endl;
                do {
                    cout << "You: ";
                    getline(cin, q);
                    check_regex("danh sach", q, q_regex);
                    if (q_regex == "danh sach") {
                        tra_cuu_danh_sach(count, p);
                        q = "ok, cam on";
                        // nếu rảnh sẽ nâng cấp
                    } else if (q_regex == "vi tri") {
                        string name;
                        string name_regex;
                        char y;
                        int x;
                        int check = 0;
                        cout << setw(50) << right << "🤖ニダイ" << endl;
                        cout << setw(46) << right << "Ban muon tra cuu vi tri" << endl;
                        cout << setw(46) << right << "cua san pham nao?" << endl;
                        cout << "You: ";
                        getline(cin, name);
                        check_regex("name", name, name_regex);
                        tra_cuu_vi_tri(name_regex, count, p, y, x, check);
                        if (check==1) {
                            cout << setw(50) << right << "🤖ニダイ" << endl;
                            cout << setw(44) << right << "San pham o vi tri: " << y << x << endl;
                            q = "ok, cam on";
                            // nếu rảnh sẽ nâng cấp
                        } else {
                            cout << setw(50) << right << "🤖ニダイ" << endl;
                            cout << setw(46) << right << "San pham nay khong ton tai" << endl;
                            cout << setw(46) << right << "trong kho, ban hay kiem" << endl;
                            cout << setw(46) << right << "tra lai danh sach kho" << endl;
                            cout << setw(46) << right << "hoac loi chinh ta nhe" << endl;
                            q = "ok, cam on";
                            // nếu rảnh sẽ nâng cấp
                        }
                    } else {
                        cout << setw(50) << right << "🤖ニダイ" << endl;
                        cout << setw(46) << right << "Toi chua hieu y ban." << endl;
                    }
                } while (q != "ok, cam on");
                break;
            }
            case 2: {
                // thêm mới
                string name;
                int quantity;
                int price;
                int check_name = 0;
                int check_them_kho = 1;
                cout << setw(50) << right << "🤖ニダイ" << endl;
                cout << setw(46) << right << "Ten san pham ban muon" << endl;
                cout << setw(46) << right << "them moi vao kho la gi?" << endl;
                do {
                    cout << "You: ";
                    getline(cin, name);
                    check_name = 1;
                    for (int i=0; i<count; i++) {
                        if (name == p[i].name) {
                            check_name = 0;
                            string q;
                            cout << setw(50) << right << "🤖ニダイ" << endl;
                            cout << setw(46) << right << "San pham nay da co trong kho," << endl;
                            cout << setw(46) << right << "ban co muon nhap kho khong?" << endl;
                            do {
                                cout << "You: ";
                                getline(cin, q);
                                if (check_yes_no(q) == 1) {
                                    check_them_kho = 1;
                                    check_name = 1;
                                } else if (check_yes_no(q) == 0) {
                                    check_them_kho = 0;
                                    check_name = 1;
                                } else {
                                    cout << setw(50) << right << "🤖ニダイ" << endl;
                                    cout << setw(46) << right << "Toi chua hieu y ban" << endl;
                                }
                            } while (check_them_kho != 1 && check_them_kho != 0);
                        }
                    }
                } while (check_name == 0);
                if (check_them_kho == 1) {
                    cout << setw(50) << right << "🤖ニダイ" << endl;
                    cout << setw(46) << right << "So luong la bao nhieu?" << endl;
                    do {
                        cout << "You: ";
                        cin >> quantity;
                        if (cin.fail() || quantity <= 0) {
                            cout << setw(50) << right << "🤖ニダイ" << endl;
                            cout << setw(46) << right << "So luong san pham phai lon" << endl;
                            cout << setw(46) << right << "hon 0, vui long nhap lai" << endl;
                            cin.clear();
                            cin.ignore(100, '\n');
                        }
                    } while (quantity <= 0 || cin.fail());
                    cin.ignore(100, '\n');
                    cout << setw(50) << right << "🤖ニダイ" << endl;
                    cout << setw(46) << right << "San pham nay co" << endl;
                    cout << setw(46) << right << "gia bao nhieu?" << endl;
                    do {
                        cout << "You: ";
                        cin >> price;
                        if (cin.fail() || price <= 0) {
                            cout << setw(50) << right << "🤖ニダイ" << endl;
                            cout << setw(46) << right << "Gia tien san pham phai lon" << endl;
                            cout << setw(46) << right << "hon 0, vui long nhap lai" << endl;
                            cin.clear();
                            cin.ignore(100, '\n');
                        }
                    } while (price <= 0 || cin.fail());
                    cin.ignore(100, '\n');
                    them(name, quantity, price, count, p, check_them_kho, money_out, m, name_staff_tmp, number_in);
                    cout << setw(50) << right << "🤖ニダイ" << endl;
                    cout << setw(46) << right << "San pham da duoc them vao kho" << endl;
                }
                break;
            }
            case 3: {
                // chào
                cout << setw(50) << right << "🤖ニダイ" << endl;
                cout << setw(46) << right << "Chao mot ngay moi tot lanh" << endl;
                cout << setw(46) << right << "Toi co the giup gi cho ban" << endl;
                break;
            }
            case 4: {
                // xuất kho
                string name;
                string name_regex;
                int quantity;
                int check_name = 0;
                int check_quantity = 0;
                cout << setw(50) << right << "🤖ニダイ" << endl;
                cout << setw(46) << right << "Ban muon xuat kho" << endl;
                cout << setw(46) << right << "san pham nao?" << endl;
                do {
                    cout << "You: ";
                    getline(cin, name);
                    check_regex("name", name, name_regex);
                    for (int i=0; i<count; i++) {
                        if (name_regex == p[i].name) {
                            check_name = 1;
                            break;
                        }
                    }
                    if (check_name == 0) {
                        cout << setw(50) << right << "🤖ニダイ" << endl;
                        cout << setw(46) << right << "San pham nay khong ton tai" << endl;
                        cout << setw(46) << right << "trong kho, ban hay kiem" << endl;
                        cout << setw(46) << right << "tra lai danh sach kho" << endl;
                        cout << setw(46) << right << "hoac loi chinh ta nhe" << endl;
                    }
                } while (check_name == 0);
                cout << setw(50) << right << "🤖ニダイ" << endl;
                cout << setw(46) << right << "So luong xuat kho" << endl;
                cout << setw(46) << right << "la bao nhieu?" << endl;
                do {
                    do {
                        cout << "You: ";
                        cin >> quantity;
                        if (cin.fail() || quantity <= 0) {
                            cout << setw(50) << right << "🤖ニダイ" << endl;
                            cout << setw(46) << right << "So luong san pham phai lon" << endl;
                            cout << setw(46) << right << "hon 0, vui long nhap lai" << endl;
                            cin.clear();
                            cin.ignore(100, '\n');
                        }
                    } while (quantity <= 0 || cin.fail());
                    for (int i=0; i<count; i++) {
                        if (name_regex == p[i].name) {
                            if (quantity > p[i].quantity) {
                                cout << setw(50) << right << "🤖ニダイ" << endl;
                                cout << setw(46) << right << "So luong ban yeu cau lon hon" << endl;
                                cout << setw(46) << right << "so san pham dang co trong" << endl;
                                cout << setw(46) << right << "kho, vui long nhap lai" << endl;
                            } else {
                                check_quantity = 1;
                            }
                        }
                    }
                } while (check_quantity == 0);
                xuat_kho(name_regex, quantity, count, p, check_name, money_in, m, name_staff_tmp, number_out);
                cout << setw(50) << right << "🤖ニダイ" << endl;
                cout << setw(46) << right << "Xuat kho thanh cong" << endl;
                cin.ignore();
                break;
            }
            case 5: {
                // nhập kho
                string name;
                string name_regex;
                int quantity = 0;
                int check_name = 0;
                cout << setw(50) << right << "🤖ニダイ" << endl;
                cout << setw(46) << right << "Ban muon nhap kho" << endl;
                cout << setw(46) << right << "san pham nao?" << endl;
                cout << "You: ";
                getline(cin, name);
                check_regex("name", name, name_regex);
                for (int i=0; i<count; i++) {
                    if (name_regex == p[i].name) {
                        check_name = 1;
                        cout << setw(50) << right << "🤖ニダイ" << endl;
                        cout << setw(46) << right << "So luong la bao nhieu?" << endl;
                        do {
                            cout << "You: ";
                            cin >> quantity;
                            if (cin.fail() || quantity <= 0) {
                                cout << setw(50) << right << "🤖ニダイ" << endl;
                                cout << setw(46) << right << "So luong san pham phai lon" << endl;
                                cout << setw(46) << right << "hon 0, vui long nhap lai" << endl;
                                cin.clear();
                                cin.ignore(100, '\n');
                            }
                        } while (quantity <= 0 || cin.fail());
                        cin.ignore();
                        nhap_kho(name_regex, quantity, count, p, check_name, money_out, m, name_staff_tmp, number_in);
                        cout << setw(50) << right << "🤖ニダイ" << endl;
                        cout << setw(46) << right << "Nhap kho thanh cong" << endl;
                    }
                }
                if (check_name == 0) {
                    string q;
                    int quantity = 0;
                    int price;
                    cout << setw(50) << right << "🤖ニダイ" << endl;
                    cout << setw(46) << right << "San pham nay chua co trong" << endl;
                    cout << setw(46) << right << "kho, ban co muon them moi" << endl;
                    cout << setw(46) << right << "san pham vao kho khong?" << endl;
                    do {
                        cout << "You: ";
                        getline(cin, q);
                        cout << q << endl;
                        if (check_yes_no(q) == 1) {
                            cout << setw(50) << right << "🤖ニダイ" << endl;
                            cout << setw(46) << right << "San pham nay gia bao nhieu" << endl;
                            do {
                                cout << "You: ";
                                cin >> price;
                                if (cin.fail() || price <= 0) {
                                    cout << setw(50) << right << "🤖ニダイ" << endl;
                                    cout << setw(46) << right << "Gia tien san pham phai lon" << endl;
                                    cout << setw(46) << right << "hon 0, vui long nhap lai" << endl;
                                    cin.clear();
                                    cin.ignore(100, '\n');
                                }
                            } while (price <= 0 || cin.fail());
                            cin.ignore();
                            cout << setw(50) << right << "🤖ニダイ" << endl;
                            cout << setw(46) << right << "So luong la bao nhieu?" << endl;
                            do {
                                cout << "You: ";
                                cin >> quantity;
                                if (cin.fail() || quantity <= 0) {
                                    cout << setw(50) << right << "🤖ニダイ" << endl;
                                    cout << setw(46) << right << "So luong san pham phai lon" << endl;
                                    cout << setw(46) << right << "hon 0, vui long nhap lai" << endl;
                                    cin.clear();
                                    cin.ignore(100, '\n');
                                }
                            } while (quantity <= 0 || cin.fail());
                            cin.ignore();
                            them(name_regex, quantity, price, count, p, check_name, money_out, m, name_staff_tmp, number_in);
                            cout << setw(50) << right << "🤖ニダイ" << endl;
                            cout << setw(46) << right << "Them moi thanh cong" << endl;
                        } else if (check_yes_no(q) == 0) {
                            break;
                        }
                    } while (check_yes_no(q) != 1 && check_yes_no(q) != 2);
                }
                break;
            }
            case 6: {
                // tinh toan
                string q;
                int index;
                cout << setw(50) << right << "🤖ニダイ" << endl;
                cout << setw(46) << right << "Ban can tinh tien bao" << endl;
                cout << setw(46) << right << "nhieu loai san pham?" << endl;
                do {
                    cout << "You: ";
                    cin >> index;
                    if (cin.fail() || index <= 0) {
                        cout << setw(50) << right << "🤖ニダイ" << endl;
                        cout << setw(46) << right << "So san pham phai lon hon 0" << endl;
                        cin.clear();
                        cin.ignore(100, '\n');
                    }
                } while (index <= 0 || cin.fail());
                string name[index];
                string name_regex[index];
                int quantity[index];
                int check[index];
                for (int i=0; i<index; i++) {
                    do {
                        cout << setw(50) << right << "🤖ニダイ" << endl;
                        cout << setw(45) << right  << "Nhap ten san pham " << i+1 << endl;
                        cout << "You: ";
                        cin.ignore();
                        getline(cin, name[i]);
                        check_regex("name", name[i], name_regex[i]);
                        for (int j=0; j<count; j++) {
                            if (name_regex[i] == p[j].name) {
                                check[i]=1;
                            }
                        }
                        do {
                            cout << setw(50) << right << "🤖ニダイ" << endl;
                            cout << setw(45) << right  << "Nhap so luong cua mat hang " << i+1 << endl;
                            cout << "You: ";
                            cin >> quantity[i];
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                            }
                        } while (quantity[i] <= 0 || cin.fail());
                        if (check[i] != 1) {
                            cout << setw(50) << right << "🤖ニダイ" << endl;
                            cout << setw(46) << right << "San pham nay khong ton" << endl;
                            cout << setw(46) << right << "tai trong kho, vui long" << endl;
                            cout << setw(46) << right << "kiem tra lai." << endl;
                        }
                    } while (check[i] != 1);
                }
                cout << setw(50) << right << "🤖ニダイ" << endl;
                cout << setw(36) << right << "Thanh tien: " << tinh_toan(name_regex, quantity, index, count, p) << " VND" << endl;
                cin.ignore();
                break;
            }
            case 7: {
                // quan ly
                cout << setw(50) << right << "🤖ニダイ" << endl;
                cout << setw(46) << right << "Toi khong co quyen truy cap" << endl;
                cout << setw(46) << right << "vao tinh nang quan ly" << endl;
                break;
            }
            case 8: {
                string q;
                string q_regex;
                cout << setw(50) << right << "🤖ニダイ" << endl;
                cout << setw(50) << right << "Toi ten la ニダイ assistant, toi" << endl;
                cout << setw(46) << right << "duoc tao ra de giup ban trong" << endl;
                cout << setw(46) << right << "viec xuat nhap kho, ban muon" << endl;
                cout << setw(46) << right << "biet them thong tin ve toi hay" << endl;
                cout << setw(46) << right << "nhung viec ma toi co the lam?" << endl;
                cout << "You: ";
                getline(cin, q);
                check_regex("gioi thieu", q, q_regex);
                if (q_regex == "thong tin") {
                    cout << setw(50) << right << "🤖ニダイ" << endl;
                    cout << setw(46) << right << "Dm tao gioi thieu het roi" << endl;
                    // tự giới thiệu 1 xíu nhé
                } else if (q_regex == "lam" || q_regex == "giup") {
                    cout << setw(50) << right << "🤖ニダイ" << endl;
                    cout << setw(46) << right << "Duoi day la danh sach nhung" << endl;
                    cout << setw(46) << right << "viec toi co the lam:" << endl;
                    cout << setw(46) << right << "Tra cuu danh sach hang hoa" << endl;
                    cout << setw(46) << right << "Tra cuu vi tri hang hoa" << endl;
                    cout << setw(46) << right << "Them san pham moi vao kho" << endl;
                    cout << setw(46) << right << "Tinh toan gia tri don hang" << endl;
                    cout << setw(46) << right << "Xuat kho" << endl;
                    cout << setw(46) << right << "Nhap kho" << endl;
                }
                cout << setw(50) << right << "🤖ニダイ" << endl;
                cout << setw(46) << right << "Ban muon toi giup gi nao" << endl;
                break;
            }
            case 10:
                cout << setw(50) << right << "🤖ニダイ" << endl;
                cout << setw(46) << right << "Hen gap lai" << endl;
                break;
                
            default:
                cout << "Khong xac dinh duoc lenh." << endl;
                break;
        }
        if (check_oders(oders) != 3 && check_oders(oders) != 10 && check_oders(oders) != 0 && check_oders(oders) != 8) {
            cout << setw(50) << right << "🤖ニダイ" << endl;
            cout << setw(46) << right << "Ban co muon toi giup" << endl;
            cout << setw(46) << right << "them gi nua khong?" << endl;
        }
    } while (check_oders(oders) != 10);
}

int check_oders (string oders) {
    regex tra_cuu ("tra cuu");
    regex kiem_tra ("kiem tra");
    regex danh_sach ("danh sach");
    regex danh_muc ("danh muc");
    regex xem ("xem");
    regex them ("them");
    regex xuat_kho ("xuat kho");
    regex nhap_kho ("nhap kho");
    regex tinh_toan ("tinh toan");
    regex quan_ly ("quan ly");
    regex gioi_thieu ("gioi thieu");
    regex chao ("chao");
    regex hello ("hello");
    regex hey ("hey");

    if (regex_search(oders, tra_cuu) || regex_search(oders, danh_sach) || regex_search(oders, danh_muc) || regex_search(oders, kiem_tra) || regex_search(oders, xem)) {
        return 1;
    } else if (regex_search(oders, them)) {
        return 2;
    } else if (regex_search(oders, chao) || regex_search(oders, hello) || regex_search(oders, hey)) {
        return 3;
    } else if (regex_search(oders, xuat_kho)) {
        return 4;
    } else if (regex_search(oders, nhap_kho)) {
        return 5;
    } else if (regex_search(oders, tinh_toan)) {
        return 6;
    } else if (regex_search(oders, quan_ly)) {
        return 7;
    } else if (regex_search(oders, gioi_thieu)) {
        return 8;
    }
    if (oders == "k" || oders == "ko" || oders == "khong" || oders == "no" || oders == "noo" || oders == "nooo" || oders == "bye" || oders == "bye bye" || oders == "bai" || oders == "bai bai" || oders == "tam biet" || oders == "oke, bye" || oders == "oke bye" || oders == "oke, chao" || oders == "oke chao" || oders == "oke, tam biet" || oders == "oke tam biet" || oders == "ok, bye" || oders == "ok bye" || oders == "ok, chao" || oders == "ok chao" || oders == "ok, tam biet" || oders == "ok tam biet" || oders == "k can dau, cam on" || oders == "k can nua dau, cam on" || oders == "ko can dau, cam on" || oders == "ko can nua dau, cam on" || oders == "khong can dau, cam on" || oders == "khong can nua dau, cam on" || oders == "toi het cau hoi roi, bye" || oders == "thoi khong con gi nua dau"|| oders == "deo") {
        return 10;
    }
    return 0;
}

int check_yes_no (string q) {
    if (q == "dong y" || q == "co" || q == "yes" || q == "yess" || q == "yesss" || q == "ok" || q == "oke" || q == "okee" || q == "okeee" || q == "duoc" || q == "duoc thoi" || q == "uh" || q == "uhm" || q == "uhmm" || q == "uk" || q == "ukm" || q == "ukmm" || q == "uhm duoc" || q == "uhm ok" || q == "uhm oke" || q == "ukm ok" || q == "ukm oke") {
            return 1;
    } else if (q == "no" || q == "noo" || q == "nooo" || q == "thoi" || q == "thoii" || q == "thoiii" || q == "k" || q == "ko" || q == "khong" || q == "khongg" || q == "khonggg" || q == "tu choi" || q == "thoi khoi" || q == "khong can dau" || q == "ko can dau" || q == "k can dau" || q == "khong can" || q == "ko can" || q == "k can" || q == "deo") {
        return 0;
    }
    return 3;
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
