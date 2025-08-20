#include<iostream>
#include<assert.h>
using namespace std;
#include <list>

template<typename T, class Container>
class my_queue{
public:
    void push(const T& val){
        _con.push_back(val);
    }
    void pop(){
        _con.pop_front();
    }
    size_t size(){
        return _con.szie();
    }
    T& top(){
        return _con.front();
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
    my_queue<char,list<char>> s1;
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