#include<bits/stdc++.h>
#ifndef __node__cpp__
#define __node__cpp__

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
    void setHeSo(T heso){
        this -> heso = heso;
    }
    void setSoMu(int somu){
        this->somu = somu;
    }
};
#endif 
