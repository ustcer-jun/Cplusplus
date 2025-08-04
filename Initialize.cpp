#include<iostream>
using namespace std;

class Date{
    public:
        Date(int year = 2025,int month = 7,int day = 31)
            : _year(year)
            , _month(month)
            , _day(day)
        {}
        void Print(){
            cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
        }
    private:
        int _year;
        int _month;
        int _day;
};

int main(){
    Date d1;
    d1.Print();
    Date d2(1,2,3);
    Date d3 = 1;
    Date d4 = {1,2};
    Date d5 = {1,2,3};
    d2.Print();
    d3.Print();
    d4.Print();
    d5.Print();
}