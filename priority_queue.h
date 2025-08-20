#include<iostream>
#include<assert.h>
using namespace std;

// 比较器仿函数
template<typename T>
struct Less
{
    bool operator()(const T& t1, const T& t2){
        return t1<t2; // 小于 => 大顶堆
    };
};

template<typename T>
struct Greater
{
    bool operator()(const T& t1, const T& t2){
        return t1 > t2;// 大于 => 小顶堆
    };
};

template<typename T,class Container = vector<T>, typename Compare =Less<T>>
class my_priority_queue{
private:
    Container _con;
public:
     // 向上调整（插入时）
    void Adjust_up(int child){
        Compare com;
        int parent = (child-1)/2;
        while (child>0)
        {
            // if(_con[child] > _con[parent]){
            if(com(_con[parent],_con[child])){// 父比子小 => 交换
                ::swap(_con[child],_con[parent]);
                child = parent;
                parent = (child-1)/2;
            }
            else{
                break;
            }
        }
    }
    // 向下调整（删除堆顶时）
    void Adjust_down(int root){
        Compare com;
        int parent =root;
        int child = 2*parent+1;
        while (child<_con.size())
        {
            // if(child+1 < _con.size() && _con[child+1] > _con[child]){
            if(child+1 < _con.size() && com(_con[child],_con[child+1])){
                ++child;// 选更优的孩子
            }
            if(com(_con[parent],_con[child])){
               ::swap(_con[child],_con[parent]);
                parent = child;
                child = 2*parent+1;
            }
            else{
                break;
            }
        }
        
    }
    void push(const T&x){
        _con.push_back(x);
        Adjust_up(_con.size()-1);
    }
    void pop(){
        swap(_con[0],_con[_con.size()-1]);
       _con.pop_back();
       Adjust_down(0);
    }
    T& top(){
        return _con.front();
    }
    size_t size(){
        return _con.size();
    }
    bool empty(){
        return _con.empty();
    }
};


void test1(){
    my_priority_queue<int,vector<int>,Greater<int>> pq;
    pq.push(6);
    pq.push(3);
    pq.push(9);
    pq.push(2);
    pq.push(12);
    while(!pq.empty()){
        cout << pq.top()<<" ";
        pq.pop();
    } 
    cout<< endl;  
}
