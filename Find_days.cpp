#include <iostream>
using namespace std;

// int main() {
//     int year, month, day;
//     static int monthdays[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
//     while (cin >> year >> month >> day) { // 注意 while 处理多个 case
//         int num_days = 0;
//         for(int i = 0;i<month;i++){
//             num_days+= monthdays[i];
//         }
//         num_days+=day;
//         if(month>2 && ((year %4 == 0 && year %100 !=0)||(year % 400 == 0))){
//             num_days = num_days+1;
//         }
//         cout<<num_days<<endl;
//     }
// }

// class Stack{
//     public:
//     Stack(){
//         _arr = (int*)malloc(sizeof(int)*_capacity);
//         cout<<"malloc "<<_arr<<endl;
//     };
//     ~Stack(){
//         cout<<"free "<<_arr<<endl;
//         _arr = nullptr;
//         _size = 0;
//         _capacity = 0;
//     };
//     private:
//         int* _arr;
//         int _size;
//         int _capacity;
// };
// Stack C;
// int main(){
//     Stack A;
//     Stack B;
//     static Stack D;
// }
// 先构造全局的类对象，然后再构造局部的类对象（不分静态或是普通）
// 析构顺序：先析构局部的类对象，类对象建立在栈上，栈满足后进先出，所以B->A,然后静态变量比全局变量先释放

class Widget{
public:
    Widget(){
    };
    Widget (const Widget& w){
        cout<<"call the copy_constructor!"<<endl;
    }

};

Widget f(Widget u){
    Widget v(u);
    Widget w = v;
    return w;
}   

int main(){
    Widget x;
    Widget y = f(f(x));
}