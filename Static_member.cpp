#include<iostream>
using namespace std;

// class Student{
//     public:
//     Student(){
//         ++_count;
//     }
//     int Get_count_student(){
//         cout<<"The total number of Students is "<<_count<<endl;
//         return _count;
//     }
//     private:
//         static int _count;
// };

// int Student::_count = 0; 

// int main(){
//     Student s1;
//     Student s2;
//     Student s3;
//     s3.Get_count_student();
// } 
        //cout<<"调用非静态成员函数\n"<<endl;
class Test{
    public:
    static void Static_fun(){
        cout<<"调用静态成员函数\n"<<endl;
    }
    void non_Static_fun(){
        Static_fun();

    }

};

int main(){
    Test t1;
    t1.non_Static_fun();
}

class Test{
    public:
    static void Static_fun(const Test& t){
        t.non_Static_fun();
    }
    void non_Static_fun(){
        cout<<"调用非静态成员函数\n"<<endl;
    }

};

int main(){
    Test t1;
    Test::Static_fun(t1);
}