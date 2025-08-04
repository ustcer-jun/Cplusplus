#include "class.h"

// 类里面可以定义：1成员变量，2成员方法(函数)

// class Person {
// public:
//     void showInfo(){
//         cout<< _name<<"-"<<_sex<<"-"<<_age<<"-"<<endl;
//     }

// public:           // 访问权限
//     char* _name;  // 成员变量
//     char* _sex;
//     int _age;
// };

// void Person::showInfo(){
//     cout<< _name<<"-"<<_sex<<"-"<<_age<<"-"<<endl;
// }

// int main(){
//     Person p1;
//     p1._age = 20;
//     p1._name = "Yajun";
//     p1._sex = "Man";
// }

// //利用类实现数据结构中的栈。
// class Stack{
//     public:
//         void STInit(size_t size){
//             //..../
//         }
//         void STpush(size_t x){
//             //..../
//         }
//         void STpop(){
//             //..../
//         }
//         void PrintST(size_t size){
//             //..../
//         }
//         void Destroy(){
//             //..../
//         }
//     private:
//         int Top;
//         int* _arr;
//         int _capacity;
// };

// int main(){
//     Stack ST;
//     ST.STInit(10);
//     ST.STpush(1);
//     ST.STpush(10);
// }



// 如何定义一个类
//封装
// 1、数据和方法放到定义一起
// 2、把想给你看的数据给你看，不想给你看的封装起来 利用访问限定符
//
//c语言用于定义结构体
// struct ListNodeC{
//     struct ListNodeC* prev;
//     struct ListNodeC* next;
// };
// //c++定义结构体
// struct ListNodeCPP{
//     //同时也可以定义类
//     ListNodeCPP* prev;
//     ListNodeCPP* next;

//     //这里仍然可以定义函数->成员函数
//     ListNodeCPP* Creat();
// }

// class Stack{
//     //1、成员函数
// public:
//     void Push(int x); //函数的声明
//     void Pop(); //函数可以在类中定义，也可以在类外定义。  
//     bool IsEmpty();
//     //2、成员变量
// public:
//     int* _arr;
//     int _size;
//     size_t _capactity;

// };
// // 成员函数定义
// void Stack::Push(int x) {
//     cout << "Push called with value: " << x << endl;
// }  

// class A2{
    
// public:
//     void f1();
// };

// class A3{

// };

// int main(){
//     //类实例化出对象，相当于定义出类的成员变量
//     Stack s1;
//     Stack s2;
//     Stack s3;
//     // s1.Push(1);
//     cout << sizeof(s1) << endl;
//     //如何理解？
//     cout << sizeof(A2) << endl;
//     cout << sizeof(A3) << endl;
//     return 0;
// }



// int main() {
//     MyClass obj;
//     std::cout << "&obj: " << &obj << std::endl;
//     obj.Show();  // this 是 &obj，存在于栈帧中
// }

// class MyClass {
// public:
//     void Print() {
//         // std::cout << "hello" << std::endl;
//         std::cout << x <<endl;
//     }
// private:
//     int x;
// };

// int main() {
//     MyClass* p = nullptr;
//     p->Print();  // undefined behavior！但这可能运行成功！
//     // print 函数没有访问成员变量，可能运行成功
// }

class Date{
    public:
    void Init(int year,int month,int day){
        _year = year;
        _month = month;
        _day = day;
    }
    void Print(){
        cout<< _year<<"-"<<_month<<"-"<<_day<<endl;
    };

    private:
    int _year;
    int _month;
    int _day;

};

int main(){
    Date d1;
    d1.Print();
    d1.Init(2025,7,28);
    d1.Print();

}
