#include<bits/stdc++.h>
#include "list_plane.cpp"
using namespace std;
class app{
private:
    list_plane lplist;
public:
    void show(){
        int t;
        showMenu();
        do{
            cout << "Nhap lua chon (8 de hien menu): ";
            cin >> t;
            input(t);
        }while(t != 0);
    }
    void input(int t){
        switch(t){
            case 1:
                lplist.read_from_file();
                break;
            case 2:
                lplist.add_plane();
                break;
            case 3:
                lplist.edit_plane();
                break;
            case 4:
                lplist.sort_Speed();
                break;
            case 5:
                lplist.sort_Weight();
                break;
            case 6:
                lplist.sort_Capacity();
                break;
            case 7:
                lplist.sort_Consumption();
                break;
            case 8:
                lplist.show();
                break;
            case 9:
                showMenu();
                break;
            case 10:
                lplist.print_to_file();
                break;
            case 11:
                lplist.search_plane();
                break;
            case 12:
                lplist.remove_plane();
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
        cout << "==               CHUONG TRINH QUAN LY MAY BAY                 ==\n";
        cout << "================================================================\n";
        cout << "== 1. Doc tu file                                             ==\n";
        cout << "== 2. Them san pham                                           ==\n";
        cout << "== 3. Sua san pham                                            ==\n";
        cout << "== 4. Sap xep theo toc do                                     ==\n";
        cout << "== 5. Sap xep theo trong luong                                ==\n";
        cout << "== 6. Sap xep theo suc chua                                   ==\n";
        cout << "== 7. Sap xep theo tieu thu                                   ==\n";
        cout << "== 8. Xem danh sach                                           ==\n";
        cout << "== 9. Hien thi menu                                           ==\n";
        cout << "== 10.Xuat ra file                                            ==\n";
        cout << "== 11.Tim kiem may bay                                        ==\n";
        cout << "== 12.Xoa may bay                                             ==\n";
        cout << "== 0. Thoat                                                   ==\n";
        cout << "================================================================\n";
    }
};
int main(){
    app QuanLyMayBay;
    QuanLyMayBay.show();
    return 0;
}