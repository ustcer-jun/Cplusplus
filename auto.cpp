#include<iostream>
using namespace std;

// int main(){
//     int a = 10;
//     auto b = a;
//     auto c = 'a';
//     auto d = (double) a;
//     auto e = &a;
//     cout << "size of b = " << sizeof(b) << endl;
//     cout << "size of c = " << sizeof(c) << endl;
//     cout << "size of d = " << sizeof(d) << endl;
//     cout << "size of e = " << sizeof(e) << endl;
//     cout << "type of b is " << typeid(b).name() << endl;
//     cout << "type of c is " << typeid(c).name() << endl;
//     cout << "type of d is " << typeid(d).name() << endl;
//     cout << "type of e is " << typeid(e).name() << endl;
// }

// int main(){
//     auto a = 1,b=2;
//     auto c = 3,d = 3.1;
// }

// int main(){
//     const int a = 10;
//     //a = 20; //const修饰的变量只能读
//     auto b = a;
//     b = 20;

//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;
// }

// int main(){
//     int arr[] = {1,2,3,4,5,6,7,8,9,10};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     for(int i = 0; i<size;i++){
//         arr[i] *= 2;
//     }
//     for(int i = 0; i<size;i++){
//         cout << arr[i] <<" ";
//     }
//     cout<< endl;
// }

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(auto& e: arr){
        e *= 2;
    }
    for(auto e: arr){
        cout << e <<" ";
    }
    cout<< endl;
}