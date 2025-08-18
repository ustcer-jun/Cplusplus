#include<iostream>
#include<assert.h>
using namespace std;

// template<typename T>
// void Swap(T& a,T& b){
//     T tmp = a;
//     a = b;
//     b =tmp;
// };

// int main(){
//     double a = 12.1;
//     double b = 2;
//     Swap(a,b);
//     cout<<"a = "<<a<<" b = "<<b<<endl;
// }

// template<typename T>
// void Swap(T& a, T& b){
//     T tmp = a;
//     a = b;
//     b = tmp;
// }
// int main(){
//     int a = 2;
//     int b = 3;
//     Swap(a,b);
//     cout<<"a = "<<a<<", b = "<<b<<endl;
// };

// template<class T>
// class Stack{
//     public:
//         Stack(int capacity = 10){
//         _capacity = 10;
//         _top = 0;
//         _arr = new T[capacity];
//     }
//     ~Stack(){
//         delete[] _arr;
//         _arr = nullptr;
//         _top =0;
//         _capacity =0;
//         cout <<"delet Stack "<< endl;
//     }
//     private:
//     T* _arr;
//     size_t _top;
//     size_t _capacity;
// };

// int main(){
//      Stack<int> s1;
// }

// c语言来构建栈
// typedef int DataType;
// struct Stack
// {
//     DataType* _data;
//     size_t _size;
//     size_t _capacity;
// };

// void StackInit(Stack* ps){
// };
// void StackDestroy(Stack* ps){
// }; 
// void StackPush(Stack* ps){
// };
// void StackPop(Stack* ps){
// };

// template<class T>
// class Stack{
//     public:
//     Stack(){

//     };
//     ~Stack(){

//     };
//     private:
//     T* _data;
//     size_t _size;
//     size_t _capacity;
// };
// int main(){

// }


// template<class T>
// class Vector{
//     public:
//         Vector()
//         :_top(0)
//         ,_capacity(10)
//         {
//             _a = new T[_capacity];
//         };
//         ~Vector(){
//             delete[] _a;
//             _top = 0;
//             _capacity =0;
//         };
//         //类内函数声明
//         void push_back(const T& x);

//         void pop_back(); 
//         // []的读数据用法
//         T& operator[](size_t i){
//             assert(i<_top);
//             return _a[i];
//         }

//         size_t size(){
//             return _top;
//         }
//     private:
//         T* _a;
//         size_t _top;
//         size_t _capacity;
// };
// template<class T>
// //类外的函数定义
// void Vector<T>::push_back(const T& x){
//     //空间不够
//     if(_top == _capacity){
//         size_t new_capacity = 2*_capacity;
//         T* tmp = new T[new_capacity];
//         if(_a){
//             memcpy(tmp,_a,sizeof(T)*_top);
//             delete [] _a;
//         }
//         _a = tmp;
//         _capacity = new_capacity;
//     }
//     else{ 
//         _a[_top++] = x;
//     }
// };

// template<class T>
// void Vector<T>::pop_back(){
//     assert(_top>0);
//     _top--;
// };

// int main(){
//     Vector<int> v;
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(3);
//     for(int i =0;i<v.size();i++){
//         v[i]*=2;
//     };
//     for(int i =0;i<v.size();i++){
//         cout<<v[i]<<" ";
//     };
//     cout<< endl;
    
// }


// // 类外面定义函数
// template<class T>
// void push_pop(){
// };
// void pop_back(){
// };
// int main(){

// } 

//隐氏实例化

template<typename T>
T add(T& a,T& b){
    return a+b;
};

int main(){
    int a = 1;int b =2;
    double c = 2.1;double d = 1.2;
    cout<<"a + b = "<< add(a,b)<<endl;
    cout<<"c + d = "<< add(c,d)<<endl;
    // 显示实例化 （指定 T 的类型）
    cout<<"a + b = "<<add<int>(a,b);
}