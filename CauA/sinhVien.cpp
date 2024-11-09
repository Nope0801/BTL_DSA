#include <bits/stdc++.h>

#ifndef __sinhVien__cpp__
#define __sinhVien__cpp__

using namespace std;
class sinhVien
{
public:
    string masv;
    string ten;
    int tuoi;
    float diem;
    sinhVien()
    {
        masv = "";
        ten = "";
        tuoi = 0;
        diem = 0;
    }
    sinhVien(string masv, string ten, int tuoi, float diem)
    {
        this->masv = masv;
        this->ten = ten;
        this->tuoi = tuoi;
        this->diem = diem;
    }
    friend istream &operator>>(istream &is, sinhVien &obj)
    {
        cout << "Nhap ma sinh vien: ";
        is >> obj.masv;
        cout << "Nhap ten sinh vien: ";
        is.ignore();
        getline(is, obj.ten);
        cout << "Nhap tuoi sinh vien: ";
        is >> obj.tuoi;
        cout << "Nhap diem sinh vien: ";
        is >> obj.diem;
        return is;
    }
    friend ostream &operator<<(ostream &os, sinhVien &obj)
    {

        os << endl;
        os  << "==  Ma sinh vien: " << obj.masv << "\t";
        os  << "Ten sinh vien: "<< obj.ten << "\t";
        os  << "Tuoi sinh vien: "<< obj.tuoi << "\t";
        os  << "Diem sinh vien: "<< obj.diem << "  ==";
        return os;
    }

    float getDiem() { return diem; }
    string getTen() { return ten; }
    string getMaSv() { return masv; }
    int getTuoi() { return tuoi; }

    bool operator<(const sinhVien &test)
    {
        return this->diem < test.diem;
    }
    bool operator>(const sinhVien &test)
    {
        return this->diem > test.diem;
    }
    void print()
    {
        cout << "Ma sinh vien: " << "\t";
        cout << "Ten sinh vien: " << "\t";
        cout << "Tuoi sinh vien: " << "\t";
        cout << "Diem sinh vien: ";
    }
};
#endif