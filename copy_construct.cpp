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
    Date(int year = 2025,int month = 7, int day = 29){
        if(year>=0 && month>=1 &&month<=12 && day>= 1 && day<= GetMonthDay(year,month)){
           _year = year;
            _month = month;
            _day = day; 
        }
        else{
            cout << "非法日期" << endl;
        }
    }
    void Print(){
        // 普通函数
        cout<< _year<<"-"<<_month<<"-"<<_day<<endl;
    };
    Date(const Date& d1){
        _year = d1._year;
        _month = d1._month;
        _day = d1._day;
    }
    //由于隐藏了this指针，相当于
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
    int operator-(const Date& d2){
        Date tmp = *this;
        int sum = 0;
        if(tmp == d2){
            return 0;
        }
        else if(tmp > d2){
            int year1 = d2._year;
            int month1 = d2._month+1;
            int day1 = d2._day;
            int std_day = GetMonthDay(year1, month1);
            sum = GetMonthDay(year1, month1)-day1;
            day1 = 0;
            while(year1<d2._year ||(year1 == d2._year && month1 < d2._month)){
                std_day = GetMonthDay(year1, month1);
                if(year1 == d2._year){
                    while (month1 < d2._month)
                    {
                        
                        sum+=std_day;
                        month1++;
                    }                
                }
                else{
                    while (month1<=12)
                    {
                        sum+=std_day;
                        month1++;
                    }
                    year1++;
                    month1 =1;
                }
            }
        }
        else{
            int year1 = tmp._year;
            int month1 = tmp._month+1;
            int day1 = tmp._day;
            int std_day = GetMonthDay(year1, month1);
            sum = GetMonthDay(year1, month1)-day1;
            day1 = 0;
            while(year1<d2._year ||(year1 == d2._year && month1 < d2._month)){
                std_day = GetMonthDay(year1, month1);
                if(year1 == d2._year){
                    while (month1 < d2._month)
                    {
                        sum+=std_day;
                        month1++;
                    }                
                }
                else{
                    while (month1<=12)
                    {
                        sum+=std_day;
                        month1++;
                    }
                    year1++;
                    month1 =1;
                }
            }
        }
        return sum;
    }
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
    Date& operator+=(int Days){
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
    Date operator++(int) {
        Date ret(*this);  // 保存原始值
        ++(*this);         // 调用前置 -- 逻辑
        return ret;       // 返回原始值
    };
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
    Date operator--(int) {
        Date ret(*this);  // 保存原始值
        --(*this);         // 调用前置 -- 逻辑
        return ret;       // 返回原始值
    };
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
    Date& operator-=(int Days){
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

private:
    int _year;
    int _month;
    int _day;
};



int main(){
    Date d2(2025,7,31); 
    Date d4 = d2+10;
    //d2-=10;
    --d2;
    d4++;
    d2.Print();
    d4.Print();
}

// bool operator==(const Date& D1,const Date& D2){
//     return D1._year == D2._year && D1._month == D2._month
//         && D1._day == D2._day;
// };

// int main(){
//     //构造一样的类
//     Date d1(2025,7,29);

//     //拷贝构造 构造几乎一样的类
//     // Date d3 = Date(d1);
//     Date d3(2025,7,30);
//     if(d3.operator==(d1)){
//         cout<< "True" << endl;
//     }
//     if(d3.operator>(d1)){
//         cout<< "True" << endl;
//     }
    
// }


// class Stack{
//     public:
//     Stack(int capactity=10){
//         _arr = (int*)malloc(sizeof(int)*capactity);
//         cout<<"malloc"<<_arr<<endl;
//     }
//     ~Stack(){
//         cout<<"free"<<_arr<<endl;
//         free(_arr);
//         _arr = nullptr;
//     }
//     Stack(const Stack& s){
//         _size = s._size;
//         _capacity = s._capacity;
//         _arr = (int*)malloc(sizeof(int)*_capacity);
//         memcpy(_arr,s._arr,_capacity);
//         cout<<"copy construct "<<_arr<<endl;
//     }
//     private:
//     int* _arr;
//     int _size;
//     int _capacity;
// };

// int main(){
//     Stack s1;
//     // Stack s2 = s1;// 默认拷贝构造
//     Stack s2 = Stack(s1);//自定义拷贝构造
// }