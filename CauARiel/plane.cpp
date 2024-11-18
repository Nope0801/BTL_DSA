#ifndef __plane__cpp__
#define __plane__cpp__
#include<bits/stdc++.h>
 
using namespace std;

class plane{
    private:
        string name, id;
        int speed, weight, capacity, consumption;
    public:
        plane(){
            name = "";
            speed = 0;
            weight = 0;
            capacity = 0;
            consumption = 0;
        }
        plane(string id,string name, int speed, int weight, int capacity, int consumption){
            this->id = id;
            this->name = name;
            this->speed = speed;
            this->weight = weight;
            this->capacity = capacity;
            this->consumption = consumption;
        }
        friend istream &operator>>(istream &is, plane &obj){
            cout << "Nhap id may bay: ";
            getline(is, obj.id);
            cout << "Nhap ten may bay: ";
            getline(is, obj.name);
            cout << "Nhap toc do: ";
            is >> obj.speed;
            cout << "Nhap trong luong: ";
            is >> obj.weight;
            cout << "Nhap suc chua: ";
            is >> obj.capacity;
            cout << "Nhap muc tieu thu nhien lieu: ";
            is >> obj.consumption;
            return is;

        }
        friend ostream &operator<<(ostream &os, plane &obj){
            os << "==  Id: " << obj.id << "\t";
            os << "Ten: " << obj.name << "\t";
            os << "Toc do: " << obj.speed << "\t";
            os << "Trong luong: " << obj.weight << "\t";
            os << "Suc chua: " << obj.capacity << "\t";
            os << "Muc tieu thu nhien lieu: " << obj.consumption << "  ==";
            os << endl;
            return os;
        }
        string getName(){
            return name;
        }
        string getId(){
            return id;
        }
        int getSpeed(){
            return speed;
        }
        int getWeight(){
            return weight;
        }
        int getCapacity(){
            return capacity;
        }
        int getConsumption(){
            return consumption;
        }
        void setId(string id){
            this->id = id;
        }
        void setName(string name){
            this->name = name;
        }
        void setSpeed(int speed){
            this->speed = speed;
        }
        void setWeight(int weight){
            this->weight = weight;
        }
        void setCapacity(int capacity){
            this->capacity = capacity;
        }
        void setConsumption(int consumption){
            this->consumption = consumption;
        }
};
#endif