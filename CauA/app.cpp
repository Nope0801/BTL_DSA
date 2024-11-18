#include "danhSachSinhVienList.cpp"
#include <bits/stdc++.h>
using namespace std;
class app
{
private:
    danhSachSinhVienList dssvList;
    // danhSachSinhVienVector dssvVector;
public:
    void show()
    {
        int t;
        showMenu();
        do
        {
            cout << "Nhap lua chon: ";
            cin >> t;
            input(t);
        } while (t != 0);
    }
    void input(int t)
    {
        switch (t)
        {
        case 1:
            dssvList.nhap();
            break;
        case 2:
            dssvList.xuat();
            break;
        case 3:
            dssvList.sapXepDanhSach();
            break;
        case 4:
            dssvList.xoaSv();
            break;
        case 5:
            dssvList.timSv();
            break;
        case 6:
            dssvList.timSvDiemMax();
            break;
        case 7:
            dssvList.timSvDiemMin();
            break;
        case 8:
            dssvList.xoaDs();
            break;
        case 9:
            showMenu();
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
    }
    void showMenu(){
        cout << "================================================================\n";
        cout << "==        CHUONG TRINH QUAN LY SINH VIEN                      ==\n";
        cout << "================================================================\n";
        cout << "==        Menu:                                               ==\n";
        cout << "==        1. Nhap danh sach                                   ==\n";
        cout << "==        2. Xuat danh sach                                   ==\n";
        cout << "==        3. Sap xep danh sach bang diem sinh vien            ==\n";
        cout << "==        4. Xoa sinh vien                                    ==\n";
        cout << "==        5. Tim sinh vien bang ma sinh vien                  ==\n";
        cout << "==        6. Xuat danh sach sinh vien co diem cao nhat        ==\n";
        cout << "==        7. Xuat danh sach sinh vien co diem thap nhat       ==\n";
        cout << "==        8. Xoa danh sach sinh vien                          ==\n";
        cout << "==        9. Hien thi menu                                    ==\n";
        cout << "==        0. Thoat                                            ==\n";
        cout << "================================================================\n";
    }
};
int main()
{
    app QuanLySinhVien;
    QuanLySinhVien.show();
    return 0;
}