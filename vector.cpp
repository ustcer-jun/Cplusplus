#include <iostream>
// #include <vector>
#include "vecotor.h"
#include <algorithm>
using namespace std;


// int main() {
//     // 创建一个空的int类型vector
//     vector<int> v1;
//     v1.assign({1,2,3,4});
//     v1.push_back(8);
//     v1.push_back(7);
//     v1.push_back(6);
//     for(int i = 0;i<v1.size();i++){
//         printf("%d\n",v1[i]);
//     }
//     return 0;
// }

// void test1(){
//     vector<int> v1;
//     v1.assign({1,2,3,4,5,6,7,8,9});
//     //遍历修改数据
//     for(int i = 0;i<v1.size();i++){
//         cout<< v1[i]<<" ";
//     }
//     cout<<endl;

//     /// 
//     for(auto num :v1){
//         cout<< num<<" ";
//     }
//     cout<<endl;

//     ///
//     vector<int>::iterator it ;
//     // 或者使用while
//     for(it = v1.begin();it<v1.end(); it++){
//         cout<<*it<<" ";
//     }
//     cout<<endl;
// }

// void Print_Vector(const vector<int>& v){
//     vector<int>::const_iterator it = v.begin();
//     while (it != v.end())
//     {
//         (*it) += 1;
//         cout<< *it<<" ";
//         it++;
//     }
//     cout<<endl; 
// }
// void test3(){
//     vector<int> v1;
//     v1.assign({1,2,3,4,5,6,7,8,9});
//     Print_Vector(v1);
// }

// void test2(){
//     //const 迭代器无法修改内容
//     vector<int> v1;
//     v1.assign({1,2,3,4,5,6,7,8,9});
//     vector<int>::const_iterator it = v1.begin();
//     while (it != v1.end())
//     {
//         cout<< *it<<" ";
//         it++;
//     }
//     cout<<endl;     
// }

// void test4(){
//     //const 迭代器无法修改内容
//     vector<int> v1;
//     v1.assign({1,2,3,4,5,6,7,8,9});
//     vector<int>::reverse_iterator it = v1.rbegin();
//     while (it != v1.rend())
//     {
//         cout<< *it<<" ";
//         it++;
//     }
//     cout<<endl;     
// }

// 查看容量的变化
// void test5(){
//     vector<int> v1;
//     v1.assign({1,2,3,4,5,6,7,8,9});
//     // int arr[] = {1,2,3,4,5,6,7,8,9};
//     for(int i =10;i<100;i++){
//         v1.push_back(i);
//         if (i%10 == 0)
//         {
//             cout<< v1.capacity()<<endl;
//         }
//     }
//     v1.reserve(20);
//     cout<<v1.capacity()<<endl;
// }

// void test5(){
    // vector<int> v1;
    // v1.assign({1,2,3,4,5,6,7,8,9});
    // v1.insert(v1.begin(),10);
//     v1.insert(v1.begin()+3,20);
//     for(auto num:v1){
//         cout<< num<<" ";
//     }
//     cout<<endl;
//     v1.erase(v1.begin());
//     v1.erase(v1.end()-1);
//     for(auto num:v1){
//         cout<< num<<" ";
//     }
//     cout<<endl;
// }
// template<class Inputiterator, class T>
// Inputiterator find(Inputiterator begin, Inputiterator end, T val){
//     while (begin!=end)
//     {   
//         if(*begin == val){
//             return begin;
//         }
//         begin++;
//     }
    
// }

// void test6(){
//     vector<int> v1;
//     v1.assign({1,2,3,4,5,6,7,8,9});
//     vector<int>::iterator pos = find(v1.begin(),v1.end(),5);
//     for(auto num:v1){
//         cout<<num<<" ";
//     }
//     cout<<endl; 
// }

// void test7(){
//     vector<int> v1 = {1,2,3,4,5,6,7,8};
//     //删除所有元素中的偶数元素
//     std::vector<int>::iterator it = v1.begin();
//     while (it!=v1.end())
//     {
//         if(*it %2 ==0){
//             it = v1.erase(it);
//         }
//         else{
//             it++;
//         }
//     }
//     for(auto num :v1){
//         cout<<num<<" ";
//     }
//     cout<<endl;
// }

// int main(){
//     // test1();
//     test7();
// }

// int main(){
//     Vector<int> v1;
//     v1.push_back(1);
//     v1.push_back(2);
//     v1.push_back(3);
//     v1.push_back(4);
//     cout<<v1.capacity()<<endl;
//     v1.insert(1,5); 
//     Print_vector(v1);
// }
// int main() {
    // Vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);
    // v.push_back(6);
    // v.resize(12,1);
    // Print_vector(v);
    // Test1();
    // // v.erase(v.begin()+3);
    // // v.erase(v.begin()+1);
    // // v.insert(1, 100); // 插到最前
    // // v.insert(3, 200); // 插到中间
    // // v.insert(v.size(), 300); // 插到末尾

    // for (auto it = v.begin(); it != v.end(); ++it) {
    //     cout << *it << " ";
    // }
// }

int main(){
    test6();
}