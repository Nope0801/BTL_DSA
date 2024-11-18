#ifndef __node__cpp__
#define __node__cpp__
#include<bits/stdc++.h>
 
using namespace std;
template<typename T>
class node{
private:
    T heso;
    int somu;
    node *next;
public:
    node(T heso = 0, int somu = 0, node<T> *next = nullptr){
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
    void setNext(node<T> *n = nullptr){
        next = n;
    }
    void setHeSo(T heso){
        this -> heso = heso;
    }
    void setSoMu(int somu){
        this->somu = somu;
    }
};
#endif