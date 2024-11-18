#ifndef __DaThuc__cpp__
#define __DaThuc__cpp__
#include <bits/stdc++.h>
#include "node.cpp"

using namespace std;

template<typename T>
class DaThuc {
private:
    node<T>* head;
public:
    DaThuc() {
        head = new node<T>();
    }
    ~DaThuc() {
        node<T>* current = head;
        while (current != nullptr) {
            node<T>* next = current->getNext();
            delete current;
            current = next;
        }
    }
    void insert(T heso, int somu){
        if(heso == 0){
            return;
        }
        node<T>* h = head;
        while(h->getNext() != nullptr && h->getNext()->getSoMu() > somu){
            h = h->getNext();
        }
        if(h->getNext() != nullptr && h->getNext()->getSoMu() == somu){
            h->getNext()->getHeSo() += heso;
        }
        else{
            node<T>* n = new node<T>(heso, somu);
            n->setNext(h->getNext());
            h->setNext(n);
        }
    }
    void print(){
        node<T> *h = head->getNext();
        while(h!=nullptr){
            cout << h->getHeSo() << "x^" << h->getSoMu();
            if(h->getNext() != nullptr && h->getNext()->getHeSo() > 0) cout << " + ";
            else cout << "   ";
            h = h->getNext();
        }
        cout << endl;
    }
    DaThuc operator+(const DaThuc &dathuc){
        DaThuc result;
        node<T>* p1 = this->head->getNext();
        node<T>* p2 = dathuc.head->getNext();
        while(p1 != nullptr){
            result.insert(p1->getHeSo(), p1->getSoMu());
            p1 = p1->getNext();
        }
        while(p2 != nullptr){
            result.insert(p2->getHeSo(), p2->getSoMu());
            p2 = p2->getNext();
        }
        return result;
    }
    DaThuc operator-(const DaThuc &dathuc){
        DaThuc result;
        node<T>* p1 = this->head->getNext();
        node<T>* p2 = dathuc.head->getNext();
        while(p1!= nullptr){
            result.insert(p1->getHeSo(), p1->getSoMu());
            p1 = p1->getNext();
        }
        while(p2 != nullptr){
            result.insert(p2->getHeSo() * -1, p2->getSoMu());
            p2 = p2->getNext();
        }
        return result;
    }
    DaThuc operator*(const DaThuc &dathuc){
        DaThuc result;
        node<T>* p1 = this->head->getNext();
        while(p1 != nullptr){
            node<T>* p2 = dathuc.head->getNext();
            while(p2 != nullptr){
                result.insert(p1->getHeSo() * p2->getHeSo(), p1->getSoMu() + p2->getSoMu());
                p2 = p2->getNext();
            }
            p1 = p1->getNext();
        }
        return result;
    }
    friend istream &operator>>(istream &is, DaThuc &dt){
        int n;
        cout << "Nhap bac cua da thuc: ";
        is >> n;
        T heso;
        int somu;
        for(int i = 0; i <= n; i++){
            cout << "Nhap he so: ";
            is >> heso; 
            cout << "Nhap so mu: ";
            is >> somu;
            dt.insert(heso, somu);
        }
        return is;
    }
    friend ostream &operator<<(ostream &os, const DaThuc &dt){
        node<T>* h = dt.head->getNext();
        while(h != nullptr){
            os << h->getHeSo() << "x^" << h->getSoMu();
            if(h->getNext() != nullptr && h->getNext()->getHeSo() > 0) os << " + ";
            else cout << "   ";
            h = h->getNext();
        }
        cout << endl;
        return os;
    }
    void read_form_file(const string& filename){
        ifstream infile(filename);
        if(infile.is_open()){
            int n, somu;
            T heso;
            infile >> n;
            for(int i = 0; i < n; i++){
                infile >> heso >> somu;
                insert(heso, somu);
            }
            cout << "Mo file thanh cong!" << endl;
        }
        else{
            cout << "Mo file that bai!" << endl;
        }
        infile.close();
    }
    void writeToFile(const string& filename){
        ofstream outfile(filename, ios::app);
        if (outfile.is_open()) {
            node<T>* h = head->getNext();
            while (h != nullptr) {
                outfile << h->getHeSo() << "x^" << h->getSoMu();
                if (h->getNext() != nullptr && h->getNext()->getHeSo() > 0) outfile << " + ";
                else cout << "   ";
                h = h->getNext();
            }
            outfile << endl;
            outfile.close();
        } else {
            cout << "Khong the mo file" << endl;
        }
    }
    T calculate(T x){
        T result = 0;
        node<T>* h = head->getNext();
        while(h != nullptr){
            result += h->getHeSo() * pow(x, h->getSoMu());
            h = h->getNext();
        }
        return result;
    }
};
#endif
int main(){
    DaThuc<int> dt1, dt2;
    cout << "Chon phuong thuc nhap da thuc:\n";
    cout << "1. Nhap da thuc tu ban phim\n";
    cout << "2. Nhap da thuc tu fule\n";
    int choice;
    cin >> choice;
    if(choice == 1){
        cout << "Nhap da thuc thu nhat: " << endl;
        cin >> dt1;
        cout << "Nhap da thuc thu hai: "<< endl;
        cin >> dt2;
        cout << "Da thuc 1: " << dt1;
        cout << "Da thuc 2: " << dt2;
        DaThuc<int> tong = dt1 + dt2;
        cout << "\nTong 2 da thuc: " << tong;
        DaThuc<int> hieu = dt1 - dt2;
        cout << "\nHieu 2 da thuc: " << hieu;
        DaThuc<int> tich = dt1 * dt2;
        cout << "\nTich 2 da thuc: " << tich;
    }
    else{
        ofstream outfile("DaThuc_output.txt", ios::out);
        outfile.close();
        ofstream outfile1("DaThuc_output.txt", ios::app);
        dt1.read_form_file("DaThuc1_input.txt");
        dt2.read_form_file("DaThuc2_input.txt");
        dt1.writeToFile("DaThuc_output.txt");
        dt2.writeToFile("DaThuc_output.txt");
        if(outfile1.is_open()){
            outfile1 << "\nTong 2 da thuc: " << dt1 + dt2;
            outfile1 << "\nHieu 2 da thuc: " << dt1 - dt2;
            outfile1 << "\nTich 2 da thuc: " << dt1 * dt2;
            outfile1.close();
        }
        else{
            cout << "Khong the mo file" << endl;
        }
    }
}