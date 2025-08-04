#include<iostream>
using namespace std;

// class Date{
//     friend ostream&  operator<<(ostream& out,Date& d);
//     friend istream& operator>>(istream& in,Date& d);
//     friend void Print(const Date& d);
//     public:
//         Date(int year = 2025,int month = 8,int day = 1){
//             _year = year;
//             _month = month;
//             _day = day;
//         }


//     private:
//         int _year;
//         int _month;
//         int _day;
// };
// void Print(const Date& d){
//     cout<<d._year<<"-"<<d._month<<"-"<<d._day<<endl;
// }
// ostream& operator<<(ostream& out,Date& d){
//     out<<d._year<<"-"<<d._month<<"-"<<d._day<<endl;
//     return out;
// }

// istream& operator>>(istream& in,Date& d){
//     in>>d._year>>d._month>>d._day;
//     return in;
// }

// int main(){
//     Date d1;
//     Date d2;
//     cin>>d1>>d2;
//     cout<<d1;
//     cout<<d2;
// }

//友元类的定义

// class A {
// private:
//     int secret = 999;
//     friend class B;  // B 是 A 的友元类
// };

// class B {
// public:
//     void accessA(A& a) {
//         std::cout << a.secret << std::endl;  // 直接访问 A 的私有变量
//     }
// };

// int main(){
//     A a;
//     B b;
//     b.accessA(a);
// }



class Time{
    friend class Date;
    public:
    Time(int hour = 16,int minute = 11,int second = 59)
    :_hour(hour),_minute(minute),_second(second)
    {}

    private:
    int _hour;
    int _minute;
    int _second;
};

class Date{
    public:
    Date(int year = 2025,int month = 8,int day = 1)
    :_year(year),_month(month),_day(day)
    {
        _t._hour = 12;
    }

    void Print(){
        cout<<_year<<"-"<<_month<<"-"<<_day<<"-"<<_t._hour<<"-"<<_t._minute<<"-"<<_t._second<<endl;
    }
    private:
    int _year;
    int _month;
    int _day;
    Time _t;
};

int main(){
    Date d1;
    Time t;
    d1.Print();
}