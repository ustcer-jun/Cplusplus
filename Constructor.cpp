#include<iostream>
using namespace std;


// class Date{
// public:
//     //带参数的构造函数
//     Date(int year,int month,int day){
//         //构造函数，函数名与类型相同，完成初始化工作
//         _year = year;
//         _month = month;
//         _day = day;
//     }
//     //无参数的构造函数
//     Date(){
//         _year = 0;
//         _month = 1;
//         _day = 30;
//     }//构造函数可以重载

//     void Init(int year,int month,int day){
//         // 普通函数
//         _year = year;
//         _month = month;
//         _day = day;
//     }
//     void Print(){
//         // 普通函数
//         cout<< _year<<"-"<<_month<<"-"<<_day<<endl;
//     };
// private:
//     int _year;
//     int _month;
//     int _day;
// };
// class Time{
//     public:
//     int _hour;
//     int _minute;
//     int _second ;
// };
// class Date{
 
// public:
//     Date(int year = 2025,int month = 7, int day = 29){
//         _year = year;
//         _month = month;
//         _day = day;
//     }
//     void Print(){
//         // 普通函数
//         cout<< _year<<"-"<<_month<<"-"<<_day<<endl;
//     };
// private:
//     int _year;
//     int _month;
//     int _day;
// };


// int main(){
//     Date d; //编译器自己生成了构造函数用于类的初始化。
//     d.Print();
// }