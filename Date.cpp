#include<iostream>
using namespace std;

class Date{
public:
    int GetMonthDay(int year, int month){
        static int monthDays[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; //静态变量，程序结束才销毁吗，只初始化一次。
        if(month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)){
            return 29;
        }
        return monthDays[month];
    }
    void Print(){
        // 普通函数
        cout<< _year<<"-"<<_month<<"-"<<_day<<endl;
    }; 
    Date(int year = 2025,int month = 7, int day = 30){
        if(year>=0 && month>=1 &&month<=12 && day>= 1 && day<= GetMonthDay(year,month)){
           _year = year;
            _month = month;
            _day = day; 
        }
        else{
            cout << "非法日期" << endl;
        }
    }
    Date(const Date& d1){
        _year = d1._year;
        _month = d1._month;
        _day = d1._day;
    }
    //隐藏了this指针，相当于bool operator==(Date* &D1,const Date& D2)
    bool operator==(const Date& D2){
        return _year == D2._year && _month == D2._month
        && _day == D2._day;
    };
    //调用时d1. operator==(&D1,D2);
    bool operator > (const Date& D2){ // bool operator <= (Date* this, const Date &d);
        if(_year>D2._year){
            return true;
        }
        if(_year == D2._year){
            if(_month > D2._month){
                return true;
            }
            else if(_month == D2._month){
                if(_day > D2._day){
                    return true;
                }
            }
        }
        return false;
    };
    //逻辑运算符复用
    // 在实现 >= 的运算符时，可以使用已实现的运算符如>和 == 运算符。>= 等价于 > || ==;
    bool operator>=(const Date& D2){ // bool operator>=(Date* this, const Date& D2)
        return *this > D2 || *this == D2;
    };
    bool operator<(const Date& D2){ // bool operator>=(Date* this, const Date& D2)
        return !(*this > D2);
    };
    bool operator <= (const Date& D2){ // bool operator>=(Date* this, const Date& D2)
        return !(*this >= D2);
    };
    bool operator != (const Date& D2){ // bool operator>=(Date* this, const Date& D2)
        return !(*this == D2);
    }; 
//-------------------------------------------------------------"
    int DateToDays(){
        int total = 0;
        for(int y = 1; y < _year; ++y)
            total += ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? 366 : 365;
        for(int m = 1; m < _month; ++m)
            total += GetMonthDay(_year, m);
        total += _day;
        return total;
    };

    int operator-(Date& d2){
        return this->DateToDays() - d2.DateToDays();
    }
//-------------------------------------------------------------"
    Date operator+(int Days){
        Date ret(*this); //拷贝构造一个ret
        int Day_std = GetMonthDay(ret._year,ret._month);
        ret._day += Days;
        while (ret._day > Day_std)
        {
            ret._day-=Day_std;
            ret._month++;
            if(ret._month>12){
                ret._month = 1;
                ret._year++;
            }
            Day_std = GetMonthDay(ret._year,ret._month);
        }
        return ret;
    };
//-------------------------------------------------------------"
    Date operator-(int Days){
        Date ret(*this);
        int Day_std = GetMonthDay(ret._year,ret._month);
        ret._day-=Days;
        while(ret._day<=0){
            ret._month--;
            if(ret._month<=0){
                ret._month = 12;
                ret._year--;
            }
            int Day_std = GetMonthDay(ret._year,ret._month);
            ret._day+=Day_std;
        }
        return ret;
    };
//-------------------------------------------------------------"
    Date& operator-=(int Days){
        if(Days < 0){
            return *this += -Days;
        }
       int Day_std = GetMonthDay(_year,_month);
        _day-=Days;
        while(_day<=0){
            _month--;
            if(_month<=0){
                _month = 12;
                _year--;
            }
            int Day_std = GetMonthDay(_year,_month);
            _day+=Day_std;
        }
        return *this;
    }; 
//-------------------------------------------------------------"
    Date& operator+=(int Days){
        if(Days < 0){
            return *this -= -Days;
        }
        int Day_std = GetMonthDay(_year,_month);
        _day += Days;
        while (_day > Day_std)
        {
            _day-=Day_std;
            _month++;
            if(_month>12){
                _month = 1;
                _year++;
            }
            Day_std = GetMonthDay(_year,_month);
        }
        return *this;
    };
//-------------------------------------------------------------"
    Date& operator++(){
        int Day_std = GetMonthDay(_year,_month);
        _day++;
        if(_day>Day_std){
            _day-=Day_std;
            _month++;
            if(_month>12){
                _month = 1;
                _year++;
            }
        }
        return *this;
    };
//-------------------------------------------------------------"
    Date operator++(int) {
        Date ret(*this);  // 保存原始值
        ++(*this);         // 调用前置 -- 逻辑
        return ret;       // 返回原始值
    };
//-------------------------------------------------------------"
    Date& operator--(){
        _day--;
        if(_day<=0){
            _month--;
            if(_month<=0){
                _month = 12;
                _year--;
            }
            int Day_std = GetMonthDay(_year,_month);
            _day+= Day_std;
        }
        return *this;
    }; 
//-------------------------------------------------------------"
    Date operator--(int) {
        Date ret(*this);  // 保存原始值
        --(*this);         // 调用前置 -- 逻辑
        return ret;       // 返回原始值
    };

//-------------------------------------------------------------"
    Date& operator=(const Date& d1){
        if(this != &d1){ //针对自己给自己复制的场景。
            _year = d1._year;
            _month = d1._month;
            _day = d1._day;
        }
        return *this; //自定义类型传参和返回值时，在OK的情形下，尽量使用引用返回，减少拷贝。
    }    //连续复制
    // i = j = k; 运算顺序：j = k; i = k
//--------------------------------------------------------------
private:
    int _year;
    int _month;
    int _day;
};
    


int main(){
    Date d1(2025, 7, 30);
    d1.Print();       // 输出：2025-7-30

    Date d2 = d1++;
    d2.Print();       // 输出：2025-7-30（旧值）
    d1.Print();       // 输出：2025-7-31（加了一天）

    Date d3 = d1++;
    d3.Print();       // 输出：2025-7-31（旧值）
    d1.Print();       // 输出：2025-8-1（跨月）

    Date d4 = --d1;
    d4.Print();       // 输出：2025-7-31
    d1.Print();       // 输出：2025-7-31

    Date d5 = d1--;
    d5.Print();       // 输出：2025-7-31
    d1.Print();       // 输出：2025-7-30

    return 0;
}

// int main(){
//     //构造函数
//     Date d2; 
//     d2.Print();
//     //拷贝构造
//     Date d3(2025,8,16);
//     // if(d3>d2){
//     //     cout<<"True"<<endl;
//     // }
//     // Date d4(1998,7,8);
//     // if(d4<d2){
//     //     cout<<"True"<<endl;
//     // };
//     // Date d4 = d2+10;
//     // d4.Print();
//     // Date d5 = d3-10;
//     // d5.Print();
//     // cout<<"2025,8,16 - 2025,7,30 = "<< d3-d2 <<endl;
//     Date d4 = d2++;
//     d4.Print();
//     Date d5 = d3--;
//     d5.Print();
//     Date d6 = ++d2;
//     d6.Print();
//     Date d7 = --d3;
//     d7.Print();
// }