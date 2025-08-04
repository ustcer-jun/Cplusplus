#include<iostream>

using namespace std;

class Date
{
private:
    int _year;
    int _month;
    int _day;
public:
    Date(int year =2025,int month =7,int day =29){
        _year = year;
        _month = month;
        _day = day;
    }; // 构造函数
    ~Date(){
        cout << "~Date()"<<endl;
    }; //析构函数
};

class Stack{
private:
    int* _arr;
    int _size;
    int _capacity;
public:
    Stack(int capacity = 10){
        _arr = (int*)malloc(sizeof(int)*capacity);
        cout << "malloc " << _arr << endl;
    }
    ~Stack(){
        cout << "free " << _arr << endl;
        free(_arr);
        _arr = nullptr;
    }

};
  
int main(){
    Stack s1;
    Stack s2;
}
