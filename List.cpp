#include"List.h"
#include<iostream>
#include<assert.h>
#include<list>
using namespace std;


void Print_list(const list<int>& l1){
    list<int>::const_iterator it = l1.begin();
    while(it != l1.end()){
        cout<< *it <<" ";
        ++it;
    }
    cout<<endl;
}

// int main(){
//     list<int> l1;
//     l1.push_back(1);
//     l1.push_back(2);
//     l1.push_back(3);
//     l1.push_back(4);
//     list<int>::iterator it = l1.begin();
//     while (it != l1.end())
//     {
//         cout<< *it <<" ";
//         ++it;
//     }
//     cout<<endl;
//     Print_list(l1);
// }

// int main() {
//     list<int> L1;                // 空
//     list<int> L2(5, 42);         // 5 个 42
//     list<int> L3 = {1, 2, 3};    // 列表初始化
//     list<int> L4(L3);            // 拷贝构造
//     list<int> L5(::move(L3));      // 移动构造（L3 被掏空）

//     cout << L2.size() << endl;   // 通常 O(1)
//     cout << boolalpha << L1.empty() << endl;
//     for(auto e:L3){
//         cout << e <<" " ;
//     }
//     cout << endl;
//     for(auto e:L4){
//         cout << e <<" " ;
//     }
//     cout << endl;
//     for(auto e:L5){
//         cout << e <<" " ;
//     }
//     cout << endl;

//     return 0;
// }

// void test1(){
//     list<int> v1= {1,2,3,4,5};
//     v1.push_front(0);
//     Print_list(v1);
//     v1.pop_back();
//     Print_list(v1);
//     v1.insert(++v1.begin(),3,6);
//     Print_list(v1);

// }
// void test2(){
//     list<int> L = {1, 3, 5};
//     L.push_front(0);   // 0 1 3 5
//     L.push_back(7);    // 0 1 3 5 7
//     L.pop_front();     // 1 3 5 7
//     L.pop_back();      // 1 3 5
//     Print_list(L);
// }

// void test3(){
//     list<int> L = {1, 3, 5};
//     list<int>::iterator it = L.begin();
//     it++;
//     L.insert(it,2);   // 0 1 3 5
//     Print_list(L);
//     L.insert(L.end(),3,6);
//     Print_list(L);
// }
// //find的实现
// template<class Inputiterator, class T>
// Inputiterator Find(Inputiterator first, Inputiterator last,const T& val){
//     while(first != last){
//         if(*first == val){
//             return first;
//         }
//         ++first;
//     }
//     return last;
// }

// void test4(){
//     list<int> L = {1,2,3,4,5,6};
//     list<int>::iterator it = Find(L.begin(),L.end(),3);
//     L.insert(it,8);   // 0 1 3 5
//     Print_list(L);
//     // L.insert(L.end(),3,6);
// }

// void test5(){
//     list<int> L = {1,2,3,4,5,6};
//     list<int>::iterator it = Find(L.begin(),L.end(),3);
//     L.insert(it,8);   // 0 1 3 5
//     Print_list(L);
//     // L.insert(L.end(),3,6);
// }

// void test6(){
//     list<int> L = {1,2,3,4,5,6};
//     list<int>::iterator pos = find(L.begin(),L.end(),3);
//     pos = L.erase(pos);
//     L.insert(pos,3);
//     Print_list(L);
// }

// void test7(){
//     list<int> L1 = {1,2,3,4,5,6};
//     list<int> L2 = {1,2,3,4,5,6};
//     L1.splice(L1.end(),L2);
//     Print_list(L1);
//     Print_list(L2);
// }
// void test8(){
//     list<int> L1 = {1,2,3,4,5,6};
//     list<int> L2 = {1,2,3,4,5,6};
//     L1.splice(L1.end(),L2,++L2.begin(),--L2.end());
//     Print_list(L1);
//     Print_list(L2);
// }


// int main(){
//     test7();
//     test8();
// }

int main(){
    test1();
    return 0;
}
