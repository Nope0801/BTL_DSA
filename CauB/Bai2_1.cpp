#include<bits/stdc++.h>

using namespace std;
class node{
    private:
        int heso;
        int somu;
        node *next;
    public:
        node (int heso = 0, int somu = 0, node *n = NULL){
            this -> heso = heso;
            this -> somu = somu;
            next = n;
        }
        node*&getnext(){
            return next;
        }
        int &getheso(){
            return heso;
        }
        int &getsomu(){
            return somu;
        }
        void setNext(node *n = NULL){
            next = n;
        }
        void setheso(int heso){
            this -> heso = heso;
        }
        void setsomu(int somu){
            this -> somu = somu;
        }
};
class DaThuc{
    private:
        node *head, *trailer;
    public:
        DaThuc(){
            head = new node();
            trailer = new node();
            head -> getnext() = trailer;
        }
        void insert(int heso, int somu){
            node *p = head;
            while(p -> getnext() != trailer && p -> getnext() -> getsomu() > somu){
                p = p -> getnext();
            }
            if(p -> getnext() -> getsomu() == somu){
                p -> getnext() -> getheso() += heso;
            }
            else{
                node *q = new node(heso, somu);
                q -> getnext() = p -> getnext();
                p -> getnext() = q;
            }

        }
        void print(){
            node *p = head -> getnext();
            while(p != trailer){
                cout << p -> getheso() << "x^" << p -> getsomu() << " ";
                p = p -> getnext();
            }
        }

};
int main(){
    DaThuc a;
    a.insert(2, 3);
    a.insert(3, 2);
    a.insert(4, 3);
    a.insert(4, 2);
    a.print();
    return 0;
}
