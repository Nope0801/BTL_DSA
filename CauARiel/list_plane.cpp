#ifndef __list_plane__cpp__
#define __list_plane__cpp__
#include "plane.cpp"
#include<bits/stdc++.h>
 
using namespace std;

class list_plane{
private:
    list<plane> lp;
public:
    void read_from_file(){
        ifstream fileIn;
        fileIn.open("plane_input.txt");
        if(fileIn.is_open()){
            while(!fileIn.eof()){
                int num;
                fileIn >> num;
                for(int i = 0; i < num; i++){
                    string id_plane, name_plane;
                    int speed_plane, weight_plane, capacity_plane, consumption_plane;
                    fileIn.ignore();
                    getline(fileIn, id_plane);
                    getline(fileIn, name_plane);
                    fileIn >> speed_plane;
                    fileIn >> weight_plane;
                    fileIn >> capacity_plane;
                    fileIn >> consumption_plane;
                    plane obj(id_plane, name_plane, speed_plane, weight_plane, capacity_plane, consumption_plane);
                    lp.push_back(obj);
                }
            }
            cout << "Doc file thanh cong" << endl;
            fileIn.close();
        }
        else{
            cout << "Khong the mo file" << endl;
        }
    }
    void print_to_file(){
        ofstream fileOut;
        fileOut.open("plane_output.txt");
        if(fileOut.is_open()){
            for(auto i: lp){
                fileOut << "ID: "<< i.getId() << "\t";
                fileOut << "Name: "<< i.getName() << "\t";
                fileOut << "Speed: " << i.getSpeed() << "\t";
                fileOut <<"Weight: "<< i.getWeight() << "\t";
                fileOut <<"Capacity: "<< i.getCapacity() << "\t";
                fileOut <<"Consumption: "<< i.getConsumption() << endl;

            }
            cout << "Xuat file thanh cong" << endl;
            fileOut.close();
        }
        else{
            cout << "Khong the mo file" << endl;
        }
    }
    void add_plane(){
        plane obj;
        cin.ignore();
        cin >> obj;
        if(findByID(obj.getId()) == NULL){
            lp.push_back(obj);
        }
        else{
            cout << "\nSan pham da ton tai" << endl;
        }
    }
    void edit_plane(){
        cout << "Tim san pham can sua bang ID hoac ten: ";
        cout << "\n1. Tim bang ID san pham?";
        cout << "\n2. Tim bang ten?";
        cout << "\n0. Thoat";
        cout << "\nChon: ";
        int choice;
        plane* found;
        while(1){
            cin >> choice;
            cin.ignore();
            if(choice == 1){
                string id;
                cout << "Nhap ID: ";
                getline(cin, id);
                found = findByID(id);
                break;
            }
            else if(choice == 2){
                string name;
                cout << "Nhap ten: ";
                getline(cin, name);
                found = findByName(name);
                break;
            }
            else if(choice == 0){
                cout << "Thoat" << endl;
                return;
            }
            else{
                cout << "Lua chon khong hop le" << endl;
                cout << "\nMoi ban nhap lai: ";
            }
        }
        if(found == NULL){
            cout << "Khong tim thay may bay" << endl;
            cout << "Ban co muon them may bay moi khong?(Y/N): ";
            char choice;
            cin >> choice;
            if(choice == 'Y' || choice == 'y'){
                cout << "Thong tin may bay moi:" << endl;
                add_plane();
                cout << "Them thanh cong" << endl;
            }
        }
        else
        {
            cout << "Thong tin may bay can sua: " << endl;
            cout << *found;
            plane obj;
            cout << "Nhap thong tin moi: " << endl;
            cin >> obj;
            auto it = lp.begin();
            while(1){
                if(&(*it) == found){
                    it = lp.erase(it);
                    break;
                }
                else{
                    it++;
                }
            }
            lp.insert(it, obj);
            cout << "Sua thanh cong" << endl;
        }
    }
    void remove_plane(){
        cout << "Tim san pham can xoa bang ID hoac ten: ";
        cout << "\n1. Tim bang ID san pham?";
        cout << "\n2. Tim bang ten?";
        cout << "\n0. Thoat";
        cout << "\nChon: ";
        int choice;
        plane* found;
        while(1){
            cin >> choice;
            cin.ignore();
            if(choice == 1){
                string id;
                cout << "Nhap ID: ";
                getline(cin, id);
                found = findByID(id);
                break;
            }
            else if(choice == 2){
                string name;
                cout << "Nhap ten: ";
                getline(cin, name);
                found = findByName(name);
                break;
            }
            else if(choice == 0){
                cout << "Thoat" << endl;
                return;
            }
            else{
                cout << "Lua chon khong hop le" << endl;
                cout << "\nMoi ban nhap lai: ";
            }
        }
        if(found != NULL){
            auto it = lp.begin();
            while(1){
                if(&(*it) == found){
                    lp.erase(it);
                    break;
                }
                it++;
            }
            cout << "Xoa thanh cong" << endl;
        }
        else{
            cout << "Khong tim thay may bay" << endl;

        }
    }
    void sort_Consumption(){
        cout << "\nSap xep theo muc tieu thu nhien lieu: ";
        cout << "\n1. Tang dan";
        cout << "\n2. Giam dan";
        cout << "\n0. Thoat";
        cout << "\nChon: ";
        int choice;
        while(1){
            cin >> choice;
            if(choice == 1){
                lp.sort([](plane a, plane b){
                    return a.getConsumption() < b.getConsumption();
                });
                break;
            }
            else if(choice == 2){
                lp.sort([](plane a, plane b){
                    return a.getConsumption() > b.getConsumption();
                });
                break;
            }
            else if(choice == 0){
                cout << "Thoat" << endl;
                return;
            }
            else{
                cout << "Lua chon khong hop le" << endl;
                cout << "\nMoi ban nhap lai: ";
            }
        }
    }
    void sort_Speed(){
        cout << "\nSap xep theo toc do: ";
        cout << "\n1. Tang dan";
        cout << "\n2. Giam dan";
        cout << "\n0. Thoat";
        cout << "\nChon: ";
        int choice;
        while(1){
            cin >> choice;
            if(choice == 1){
                lp.sort([](plane a, plane b){
                    return a.getSpeed() < b.getSpeed();
                });
                break;
            }
            else if(choice == 2){
                lp.sort([](plane a, plane b){
                    return a.getSpeed() > b.getSpeed();
                });
                break;
            }
            else if(choice == 0){
                cout << "Thoat" << endl;
                return;
            }
            else{
                cout << "Lua chon khong hop le" << endl;
                cout << "\nMoi ban nhap lai: ";
            }
        }
    }
    void sort_Weight(){
        cout << "\nSap xep theo trong luong: ";
        cout << "\n1. Tang dan";
        cout << "\n2. Giam dan";
        cout << "\n0. Thoat";
        cout << "\nChon: ";
        int choice;
        while(1){
            cin >> choice;
            if(choice == 1){
                lp.sort([](plane a, plane b){
                    return a.getWeight() < b.getWeight();
                });
                break;
            }
            else if(choice == 2){
                lp.sort([](plane a, plane b){
                    return a.getWeight() > b.getWeight();
                });
                break;
            }
            else if(choice == 0){
                cout << "Thoat" << endl;
                return;
            }
            else{
                cout << "Lua chon khong hop le" << endl;
                cout << "\nMoi ban nhap lai: ";
            }
        }
    }
    void sort_Capacity(){
        cout << "\nSap xep theo suc chua: ";
        cout << "\n1. Tang dan";
        cout << "\n2. Giam dan";
        cout << "\n0. Thoat";
        cout << "\nChon: ";
        int choice;
        while(1){
            cin >> choice;
            if(choice == 1){
                lp.sort([](plane a, plane b){
                    return a.getCapacity() < b.getCapacity();
                });
                break;
            }
            else if(choice == 2){
                lp.sort([](plane a, plane b){
                    return a.getCapacity() > b.getCapacity();
                });
                break;
            }
            else if(choice == 0){
                cout << "Thoat" << endl;
                return;
            }
            else{
                cout << "Lua chon khong hop le" << endl;
                cout << "\nMoi ban nhap lai: ";
            }
        }
    }
    void show(){
        cout << "================================================================================================================================" << endl;
        cout << "==                                                 Danh sach may bay                                                          ==" << endl;
        cout << "================================================================================================================================"<< endl;
        for(auto i = lp.begin(); i != lp.end(); i++){
            cout << *i;
        }
        cout << "================================================================================================================================" << endl;
    }

    plane *findByID(string id){
        for(auto i = lp.begin(); i != lp.end(); i++){
            if(i->getId() == id){
                return &(*i);
            }
        }
        return NULL;
    }
    plane *findByName(string name){
        for(auto i = lp.begin(); i != lp.end(); i++){
            if(i->getName() == name){
                return &(*i);
            }
        }
        return NULL;
    }
    void search_plane(){
        cout << "Tim san pham bang ID hoac ten: ";
        cout << "\n1. Tim bang ID san pham?";
        cout << "\n2. Tim bang ten?";
        cout << "\n0. Thoat";
        cout << "\nChon: ";
        int choice;
        plane* found;
        while(1){
            cin >> choice;
            cin.ignore();
            if(choice == 1){
                string id;
                cout << "Nhap ID: ";
                getline(cin, id);
                found = findByID(id);
                break;
            }
            else if(choice == 2){
                string name;
                cout << "Nhap ten: ";
                getline(cin, name);
                found = findByName(name);
                break;
            }
            else if(choice == 0){
                cout << "Thoat" << endl;
                return;
            }
            else{
                cout << "Lua chon khong hop le" << endl;
                cout << "\nMoi ban nhap lai: ";
            }
        }
        if(found != NULL){
            cout << "Thong tin may bay: " << endl;
            cout << *found;
        }
        else{
            cout << "Khong tim thay may bay" << endl;
        }
    }
};
#endif
