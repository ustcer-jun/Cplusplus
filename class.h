#include<iostream>
using namespace std;

class Person {
public:
    //显示基本信息
    void showInfo();

public:           // 访问权限
    string _name;  // 成员变量
    int _age;
    string _sex;

};