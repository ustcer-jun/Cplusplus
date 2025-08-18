#include<iostream>
#include<assert.h>
using namespace std;
    
template<class T>
struct  __list_node  //双向链表
{
    __list_node<T>* _prev;
    __list_node<T>* _next;
    T _data;
    
    __list_node(const T& data = T())
    :_data(data)
    ,_prev(nullptr)
    ,_next(nullptr)
    {}
};

// __list_iterator<T,T&,T*>  -> iterator
// __list_iterator<T,const T&,const T*>  -> const_iterator
 
template<class T, class Ref, class Ptr>
struct __list_iterator
{
    typedef __list_node<T> Node;
    typedef __list_iterator<T,Ref,Ptr> Self;
    Node* _node;
    
    __list_iterator(Node* node = nullptr)
    :_node(node) 
    {}
    Ref operator*(){
        return _node->_data;
    }
    Self& operator++(){
        _node= _node->_next;
        return *this;
    }
    Self operator++(int){
        Node* tmp = *this;
        ++(*this);
        return tmp;
    }
    Self& operator--(){
        _node= _node->_prev;
        return *this;
    }
    Self operator--(int){
        Node* tmp = *this;
        --(*this);
        return tmp;
    }
    Ptr operator->(){
        return &_node->_data;
    }
    bool operator!=(const Self& it){
        return _node!= (it._node);
    }
    bool operator==(const Self& it){
        return _node == (it._node);
    }

};

template<class T>
class mylist{
public:
    typedef __list_node<T> Node;
    typedef __list_iterator<T,T&,T*> iterator;
    typedef __list_iterator<T,const T&,const T*> const_iterator;
    iterator begin(){
        return iterator(head->_next);
    }
    iterator end(){
        return iterator(head);
    }
    const_iterator begin()const{
        return const_iterator(head->_next);
    }
    const_iterator end()const{
        return const_iterator(head);
    }
    mylist(){
        head = new Node();
        head->_next = head;
        head->_prev = head;
    }
    // mylist(const mylist<T>& l1){
    //     head = new Node();
    //     head->_next = head;
    //     head->_prev = head;
    //     const_iterator start = l1.begin();
    //     Node* Cur = head;
    //     while (start!= l1.end())
    //     {
    //         Node* newnode = new Node;
    //         newnode->_data = start._node->_data;
    //         Cur->_next = newnode;
    //         newnode->_next = head;
    //         head->_prev = newnode;
    //         newnode->_prev = Cur;
    //         Cur = Cur->_next;
    //         ++start;
    //     }
    //     Cur->_next = head;
    //     head->_prev = Cur;
        
    // }
    mylist(const mylist<T>& l1){
        head = new Node();
        head->_next = head;
        head->_prev = head;
        const_iterator start = l1.begin();
        while (start!= l1.end())
        {
            push_back(start._node->_data);
            ++start;
        }        
    }
    void clear(){
        Node* cur = head->_next;
        while (cur!= head)
        {
            Node* next = cur->_next;
            delete cur;
            cur = next;
        }
    }
    ~mylist(){
        Node* cur = head->_next;
        while (cur!= head)
        {
            Node* next = cur->_next;
            delete cur;
            cur = next;
        }
        delete head;
        head = nullptr;
    }
    // mylist<T>& operator =(const mylist<T>l1){
    //     if(this != &l1){
    //         clear();
    //         for(auto e: l1){
    //             push_back(e);
    //         }
    //     }
    //     return *this;
    // }
    void swap(Node*& head2){
        assert(head2);
        Node* tmp = head;
        head = head2;
        head2 = tmp;
    }
    mylist<T>& operator =(mylist<T>l1){
        swap(l1.head);
        return *this;
    }
    void insert(iterator pos,const T& data){
        Node* cur = pos._node;
        Node* prev = cur->_prev;
        Node* newnode = new Node;
        newnode->_data = data;

        prev->_next = newnode;
        newnode->_prev = prev;
        newnode->_next = cur;
        cur->_prev = newnode; 
    }
    void push_front(const T& data){
        insert(begin(),data);
    }
    void push_back(const T& data){
        // Node* newnode = new Node;
        // newnode->_data = data;
        // Node* tail = head->_prev;
        // tail->_next = newnode;
        // newnode->_prev = tail;
        // newnode->_next = head;
        // head->_prev = newnode;
        insert(end(),data);
    };
    iterator erase(iterator pos){
        assert(pos != end()); 
        Node* Del = pos._node;
        Node* prev = Del->_prev;
        Node* next = Del->_next;
        prev->_next = next;
        next->_prev = prev;
        delete Del;
        Del = nullptr;
        return next;
    }
    void pop_back(){
        // erase(iterator(head->_prev));
        erase(--end());
    }
    void pop_front(){
        erase(begin());
    } 


private:
    Node* head;
};
template<class T>
void Print_list(const mylist<T>& l){
    typename mylist<T>::const_iterator it = l.begin();
    while (it != l.end())
    {
        // *it = 1;
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
}

void test1(){
    mylist<int>l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(6);
    // mylist<int>::iterator it =--(l1.end());
    // l1.erase(it);
    mylist<int>l2(l1);
    mylist<int>l3;
    l3 = l1;
    Print_list(l3);

}
// struct Date
// {
//     Date(int year = 2025,int month = 8,int day = 14)
//     :_year(year)
//     ,_month(month)
//     ,_day(day)
//     {}
//     int _year;
//     int _month;
//     int _day;
// };

// void test2(){
//     mylist<Date> l1;
//     l1.push_back(Date());
//     l1.push_back(Date());
//     l1.push_back(Date());
//     // Print_list(l1);
//     typename mylist<Date>::iterator it = l1.begin();
//     while (it != l1.end())
//     {
//         cout<<(*it)._year<<"-"<<(*it)._month<<"-"<<(*it)._day<<endl;
//         ++it;
//     }
// }
