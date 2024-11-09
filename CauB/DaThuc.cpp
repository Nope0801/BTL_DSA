#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

template <typename T>
class DaThuc
{
private:
    node<T> *head, *trailer;

public:
    DaThuc()
    {
        head = new node<T>();
        trailer = new node<T>();
        head->getNext() = trailer;
    }
    ~DaThuc()
    {
        node<T> *current = head;
        while (current != nullptr)
        {
            node<T> *next = current->getNext();
            delete current;
            current = next;
        }
    }
    void insert(T heso, T somu)
    {
        if (heso == 0)
        {
            return;
        }
        node<T> *h = head;
        while (h->getNext() != trailer && h->getNext()->getSoMu() > somu)
        {
            h = h->getNext();
        }
        if (h->getNext()->getSoMu() == somu)
        {
            h->getNext()->getHeSo() += heso;
        }
        else
        {
            node<T> *n = new node(heso, somu);
            n->getNext() = h->getNext();
            h->getNext() = n;
        }
    }
    void print()
    {
        node<T> *h = head->getNext();
        while (h != trailer)
        {
            cout << h->getHeSo() << "x^" << h->getSoMu();
            if (h->getNext() != trailer && h->getNext()->getHeSo() > 0)
                cout << " + ";
            h = h->getNext();
        }
        cout << endl;
    }
    T calculate(T x)
    {
        T result = 0;
        node<T> *h = head->getNext();
        while (h != trailer)
        {
            result += pow(x, h->getSoMu()) * h->getHeSo();
            h = h->getNext();
        }
        return result;
    }
    DaThuc operator+(const DaThuc &dathuc)
    {
        DaThuc result;
        node<T> *p1 = this->head->getNext();
        node<T> *p2 = dathuc.head->getNext();
        while (p1 != this->trailer)
        {
            result.insert(p1->getHeSo(), p1->getSoMu());
            p1 = p1->getNext();
        }
        while (p2 != dathuc.trailer)
        {
            result.insert(p2->getHeSo(), p2->getSoMu());
            p2 = p2->getNext();
        }
        return result;
    }
    DaThuc operator-(const DaThuc &dathuc)
    {
        DaThuc result;
        node<T> *p1 = this->head->getNext();
        node<T> *p2 = dathuc.head->getNext();
        while (p1 != this->trailer || p2 != dathuc.trailer)
        {
            if (p1 != this->trailer && (p2 == dathuc.trailer || p1->getSoMu() > p2->getSoMu()))
            {
                result.insert(p1->getHeSo(), p1->getSoMu());
                p1 = p1->getNext();
            }
            else if (p2 != this->trailer && (p1 == dathuc.trailer || p2->getSoMu() > p1->getSoMu()))
            {
                result.insert(p2->getHeSo() * -1, p2->getSoMu());
                p2 = p2->getNext();
            }
            else
            {
                result.insert(p1->getHeSo() - p2->getHeSo(), p1->getSoMu());
                p1 = p1->getNext();
                p2 = p2->getNext();
            }
        }
        return result;
    }
    DaThuc operator*(const DaThuc &dathuc)
    {
        DaThuc result;
        node<T> *p1 = this->head->getNext();
        while (p1 != this->trailer)
        {
            node<T> *p2 = dathuc.head->getNext();
            while (p2 != dathuc.trailer)
            {
                result.insert(p1->getHeSo() * p2->getHeSo(), p1->getSoMu() + p2->getSoMu());
                p2 = p2->getNext();
            }
            p1 = p1->getNext();
        }
        return result;
    }
    friend istream &operator>>(istream &is, DaThuc &dt)
    {
        int n;
        // cout << "Nhap bac cua da thuc: ";
        is >> n;
        T heso, somu;
        for (int i = 0; i < n; i++)
        {
            // cout << "Nhap he so va so mu: ";
            is >> heso >> somu;
            dt.insert(heso, somu);
        }
        return is;
    }
    friend ostream &operator<<(ostream &os, const DaThuc &dt)
    {
        node<T> *h = dt.head->getNext();
        // cout << "Da thuc ban vua nhap la:\n";
        while (h != dt.trailer)
        {
            os << h->getHeSo() << "x^" << h->getSoMu();
            if (h->getNext() != dt.trailer && h->getNext()->getHeSo() > 0)
                os << " + ";
            else
                cout << " ";
            h = h->getNext();
        }
        cout << "\n";
        return os;
    }
    void readFromFile(const string& filename){
        ifstream infile(filename);
        if(infile.is_open()){
            int n, somu;
            T heso;
            infile >> n;
            for(int i = 0; i < n; i++){
                infile >> heso >> somu;
                insert(heso, somu);
            }
            cout << "Mo file thanh cong!"<< endl;
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
            while (h != trailer) {
                outfile << h->getHeSo() << "x^" << h->getSoMu();
                if (h->getNext() != trailer && h->getNext()->getHeSo() > 0) outfile << " + ";
                h = h->getNext();
            }
            outfile << endl;
            outfile.close();
        } else {
            cout << "Khong the mo file" << endl;
        }
    }
};

int main()
{
    //freopen("IN.INP", "r", stdin);
    //freopen("OUT.OUT", "w", stdout);
    int choice;
    DaThuc<int> a, b;
    cout << "Chon phuong thuc nhap da thuc:\n";
    cout << "1. Nhap da thuc tu ban phim\n";
    cout << "2. Nhap da thuc tu fule\n";
    cin >> choice;
    if (choice == 1){
        cout << "Nhap da thuc a: ";
        cin >> a;
        cout << "Nhap da thuc b: ";
        cin >> b;
        cout << "Da thuc a: " << a;
        cout << "Da thuc b: " << b;
        cout << "\nTong 2 da thuc: " << a + b;
        cout << "\nHieu 2 da thuc: " << a - b;
        cout << "\nTich 2 da thuc: " << a * b;

    }
    else if (choice == 2){
        a.readFromFile("input1.txt");
        b.readFromFile("input2.txt");
        a.writeToFile("output.txt");
        b.writeToFile("output.txt");
        ofstream outfile("output.txt", ios::app);
        if (outfile.is_open()){
            outfile << "\nTong 2 da thuc: " << a + b;
            outfile << "\nHieu 2 da thuc: " << a - b;
            outfile << "\nTich 2 da thuc: " << a * b;
            outfile << endl;
            outfile.close();
        } else {
            cout << "Khong the mo file" << endl;
        }
    }
    else{
        cout << "Lua chon khong hop le!";
    }
}
