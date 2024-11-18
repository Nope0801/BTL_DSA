#ifndef __danhSachSinhVienList__cpp__
#define __danhSachSinhVienList__cpp__
#include <bits/stdc++.h>
#include "sinhVien.cpp"
using namespace std;

// class danhSachSinhVienVector{
// private:
//     vector<sinhVien> ds;
// public:
//     void nhap(){
//         int n;
//         cout << "Nhap so luong sinh vien: ";
//         cin >> n;
//         for(int i = 0; i < n; i++){
//             sinhVien sv;
//             cin >> sv;
//             ds.push_back(sv);
//         }
//     }
//     // void xoaSv(string masv){

//     // }
//     void xuat(){
//         for(const auto& s: ds){
//             cout << s  << endl;
//         }
//     }
//     void sapXepDanhSach(){
//         sort(ds.begin(), ds.end());
//     }
//     sinhVien timMax(){
//         return *max_element(ds.begin(), ds.end());
//     }
//     sinhVien timMin(){
//         return *min_element(ds.begin(), ds.end());
//     }
//     void themsv(sinhVien& s){
//         ds.push_back(s);
//     }

// };
class danhSachSinhVienList
{
private:
    list<sinhVien> ds;

public:
    void nhap()
    {
        int n;
        cout << "Nhap so luong sinh vien them vao: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            sinhVien sv;
            cin >> sv;
            ds.push_back(sv);
        }
    }
    void xuat()
    {            
        cout << "==============================================================================================" << endl;
        cout << "==                                  Danh sach sinh vien                                    ===" << endl;
        cout << "==============================================================================================";
        for (auto &sv : ds)
        {
            cout << sv;
        }
        cout << "\n==============================================================================================" << endl;
    }
    void sapXepDanhSach()
    {
        ds.sort();
    }
    void themsv(sinhVien &s)
    {
        ds.push_back(s);
    }
    void xoaSv()
    {
        string maSV;
        cout << "Nhap ma sinh vien can xoa: ";
        cin >> maSV;
        bool check = false;
        for (auto it = ds.begin(); it != ds.end(); it++)
        {
            if (it->getMaSv() == maSV)
            {
                ds.erase(it);
                check = true;
                cout << "Da xoa sinh vien " << endl;
                break;
            }
        }
        if (check == false)
        {
            cout << "Khong tim thay sinh vien can xoa!" << endl;
        }
    }
    void timSvDiemMax()
    {
        float max = -1;
        for (auto it = ds.begin(); it != ds.end(); it++)
        {
            if (it->getDiem() > max)
            {
                max = it->getDiem();
            }
        }
        for (auto it = ds.begin(); it != ds.end(); it++)
        {
            if (it->getDiem() == max)
            {
                cout << *it << endl;
            }
        }
    }
    void timSvDiemMin()
    {
        float min = 11;
        for (auto it = ds.begin(); it != ds.end(); it++)
        {
            if (it->getDiem() < min)
            {
                min = it->getDiem();
            }
        }
        for (auto it = ds.begin(); it != ds.end(); it++)
        {
            if (it->getDiem() == min)
            {
                cout << *it << endl;
            }
        }
    }
    void xoaDs()
    {
        ds.clear();
        cout << "Da xoa danh sach sinh vien!" << endl;
    }
    void timSv()
    {
        string maSV;
        cout << "Nhap ma sinh vien can tim: ";
        cin >> maSV;
        bool check = false;
        for (auto it = ds.begin(); it != ds.end(); it++)
        {
            if (it->getMaSv() == maSV)
            {
                cout << *it << endl;
                check = true;
                break;
            }
        }
        if (check == false)
        {
            cout << "Khong tim thay sinh vien!" << endl;
        }
    }
};
#endif