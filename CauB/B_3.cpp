#include<bits/stdc++.h>
 
using namespace std;

template<typename T>
class node{
private:
    T heso;
    int somu;
    node *next;
public:
    node(T heso = 0, int somu = 0, node<T> *next = NULL){
        this->heso = heso;
        this->somu = somu;
        this->next = next;
    } 
    node<T> *&getNext(){
        return next;
    }
    T &getHeSo(){
        return heso;
    }
    int &getSoMu(){
        return somu;
    }
    void setNext(node<T> *n = NULL){
        next = n;
    }
    void setHeSo(int heso){
        this -> heso = heso;
    }
    void setSoMu(T somu){
        this->somu = somu;
    }
};

template<class T>
class Dathuc{
private:
    node<T> *head;
public:
    Dathuc(){
        head = nullptr;
    }
    ~Dathuc(){
        node<T> *current = head;
        while(current!= nullptr){
            node<T> *next = current->next;
            delete current;
            current = next;
        }
    }
    void insert(int heso, T somu){
        if(heso == 0){
            return;
        }
        node<T> *newNode = new node<T>(heso, somu);
        if(head == nullptr){
            head = newNode;
        }
        else{
            node<T> *current = head;
            while(current->next!= nullptr){
                current = current->next;
            }
            current->next = newNode;  
        }
    }
    T tinhGiaTri(T x){
        T result = 0;
        node<T> *current = head;
        while(current != nullptr){
            result += current->heso * pow(x, current->somu);
            current = current->somu;
        }
        return result;
    }
    Dathuc add(Dathuc other){
        Dathuc result;
        node<T> *p1 = head;
        node<T> *p2 = other.head;
        while(p1 != nullptr && p2 != nullptr){
            if(p1->somu > p2->somu){
                result.insert(p1->heso, p1->somu);
                p1 = p1->next;
            }
            else if(p1->somu < p2->somu){
                result.insert(p2->heso, p2->somu);
                p2 = p2->next;
            }
            else{
                result.insert(p1->heso + p2->heso, p1->somu);
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        while(p1 != nullptr){
            result.insert(p1->heso, p1->somu);
            p1 = p1->next;
        }
        while(p2 != nullptr){
            result.insert(p2->heso, p2->somu);
            p2 = p2->next;
        }
    }
};
int main(){
    //freopen("IN.INP", "r", stdin);
    //freopen("OUT.OUT", "w", stdout);
    return 0;
}