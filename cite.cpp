#include <iostream>
#include <vector>
#include <chrono>
#include<time.h>
using namespace std;

//测试 以值为函数的返回类型，和引用，以及指针的效率

struct A
{
    int a[100000];
};

// A a;

// A Testfunc1(){
//     return a;
// }
// A& Testfunc2(){
//     return a;
// }

// void TestReturnForValue(){
//     //以值为函数返回值的类型
    // size_t begin1 = clock();
    // for(int i =0;i<100000;i++){
    //     Testfunc1();   
    // }
    // size_t end1 = clock();

//     //以引用为函数返回值的类型
//     size_t begin2 = clock();
//     for(int i = 0;i<100000;i++){
//         Testfunc2();  
//     }
//     size_t end2 = clock();

    // cout << "Testfunc1 time:" << end1-begin1 <<" ms\n";
    // cout << "Testfunc2 time:" << end2-begin2 <<" ms\n";
// }
// int main(){
//     TestReturnForValue();
// }

void testfunc1(A a){
    return;
}

void testfunc2(A& a){
    return;
}
void testfunc3(A* a){
    return;
}

int main(){
    A a;
    size_t begin1 = clock();
    for(int i =0;i<100000;i++){
        testfunc1(a);   
    }
    size_t end1 = clock();

    size_t begin2 = clock();
    for(int i = 0;i<100000;i++){
        testfunc2(a);   
    }
    size_t end2 = clock();

    size_t begin3 = clock();
    for(int i = 0;i<100000;i++){
        testfunc3(&a);   
    }
    size_t end3 = clock();
    cout << "Testfunc1 time:" << end1-begin1 <<" ms\n";
    cout << "Testfunc2 time:" << end2-begin2 <<" ms\n";
    cout << "Testfunc3 time:" << end3-begin3 <<" ms\n";
}
//测试传址，传值，传引用的效率；
 

