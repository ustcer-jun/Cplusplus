#include<iostream>
#include<assert.h>
using namespace std;

// class Stack{
//     public:
//     Stack(int capacity = 10){
//         _arr = (int*)malloc(sizeof(int)*capacity);
//         cout<<"malloc "<<_arr<<endl;
//         _size = 0;
//         _capacity = capacity;
//     };
//     ~Stack(){
//         cout<<"free "<<_arr<<endl;
//         free(_arr);
//         _arr = nullptr;
//         _size = 0;
//         _capacity =0;
//     };
//     Stack(const Stack& s1){
//         _arr = (int*)malloc(sizeof(int)*s1._capacity);
//         cout<<"malloc"<<_arr<<endl;
//         _size = s1._size;
//         _capacity = s1._capacity;
//     }
//     Stack& operator =(const Stack& s1){
//         if(this != &s1){
//             for(int i = 0;i<s1._size;i++){
//                 _arr[i] = s1._arr[i];
//             }
//             cout<<" copy= "<<endl;
//             _size = s1._size;
//             _capacity = s1._capacity;
//         }
//         return *this;
//     }
//     private:
//     int* _arr;
//     int _size;
//     int _capacity;
// };
// int main(){
//     Stack s1;
//     Stack s2(s1);
//     s2 = s1;
// }

// int main(){
//     stack<int> s1;
//     s1.push(1);
//     s1.push(2);
//     s1.push(3);
//     s1.push(4);
//     while (!s1.empty())
//     {
//         cout<<s1.top()<<" ";
//         s1.pop();
//     }
//     cout<<endl;
// }


#include <iostream>
#include <stack>
#include <string>
using namespace std;

// bool IsValid(string str){
//     stack<char> s1;
//     for(auto ch : str){
//         if((ch == '(') || (ch == '[') || (ch == '{')){
//             s1.push(ch);
//         }
//         else{
//             if(s1.empty()){
//                 return false;
//             }
//             if((ch == ')' && s1.top() != '(') ||
//                 (ch == ']' && s1.top() != '[') ||
//                 (ch == '}' && s1.top() != '{') )
//                 {
//                     return false;
//                 }
//             else{
//                 s1.pop();
//             }
//         }
//     }
//     return s1.empty();
// }
// bool isValid(string s) {
//     stack<char> st;
//     for(char c : s){
//         if(c == '(' || c == '[' || c == '{'){
//             st.push(c);
//         } 
//         else if(c == ')' || c == ']' || c == '}'){
//             if(st.empty()) return false;
//             if((c == ')' && st.top() != '(') ||
//                (c == ']' && st.top() != '[') ||
//                (c == '}' && st.top() != '{')){
//                 return false;
//                }
//             st.pop();
//         }
//         else{
//             return false;
//         }
//     }
//     return st.empty();
// }

// int main() {
//     string s = "{[(555";
//     cout << (isValid(s) ? "匹配成功" : "匹配失败") << endl;
// }
#include <list>

template<typename T, class Container>
class my_stack{
public:
    void push(const T& val){
        _con.push_back(val);
    }
    void pop(){
        _con.pop_back();
    }
    size_t size(){
        return _con.szie();
    }
    T& top(){
        return _con.back();
    }
    bool empty(){
        return _con.empty();
    }

private:
    Container _con;
};

int main(){
    // my_stack<int,vector<int>> s1;
    // my_stack<char,string> s1;
    my_stack<char,list<char>> s1;
    s1.push('a');
    s1.push('b');
    s1.push('c');
    s1.push('d');
    while (!s1.empty())
    {
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
    
}
