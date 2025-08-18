#include<iostream>
#include<assert.h>
using namespace std;

template<typename T>
struct ListNode
{
    ListNode* prev;
    ListNode* next;
    T data;
    ListNode(const T& val = T())
    :prev(nullptr)
    ,next(nullptr)
    ,data(val)
    {}
};
template<class T, class Ref, class Ptr>
struct list_iterator
{
    typedef ListNode<T> Node;
    Node* _node;
    typedef list_iterator<T,Ref,Ptr> Self;
    list_iterator(Node* node = nullptr)
    :_node(node)
    {}
    
    Ref operator *()
    {
        return _node->data;
    }

    Ptr operator->()
    {
        return &(_node->data);
    }
    Self& operator++(){
        _node = _node->next;
        return *this;
    }
    Self operator++(int){
        list_iterator tmp = *this;
        ++(*this);
        return tmp;
    }
    Self& operator--(){
        _node = _node ->prev;
        return *this;
    }
    Self operator--(int){
        list_iterator tmp = _node;
        --(*this);
        return tmp;
    }
    bool operator ==(const Self& it){
        return(_node == it._node);
    }
    bool operator !=(const Self& it){
        return !(_node == it._node);
    }
};





template<typename T>
class mylist
{
    typedef ListNode<T> Node;
public:
    typedef list_iterator<T,T&,T*> iterator;
    typedef list_iterator<T,const T&,const T*> const_iterator;
    iterator begin(){
        return head->next;
    }
    iterator end(){
        return head;
    }
    const_iterator begin()const{
        return head->next;
    }
    const_iterator end()const{
        return head;
    }
    mylist()
    :head(new ListNode<T>()) //自动调用构造函数
    {   
        cout<<"Using Constructor!"<<endl;
        head->next = head;
        head->prev = head;
    }
    void clear(){
        Node* cur = head->next;
        while (cur != head)
        {
            Node* Next = cur->next;
            delete cur;
            cur = Next;
        }
        head->prev = head;
        head->next = head;
    }
    ~mylist(){
        cout<<"Using Destructor!"<<endl;
        clear();
        delete head;
        head = nullptr;
    }
    mylist(const mylist& l){
        
    }
    size_t size(){
        size_t num = 0;
        Node* cur = head->next;
        while (cur != head)
        {
            ++num;
            cur = cur -> next;
        }
        return num;
    }
    bool empty(){
        return(head == head->next &&head == head->prev);
    }
    T& front(){
        return (head->next)->data;
    }
    T& back(){
        return (head->prev)->data;
    }
    void push_front(const T& val){
        Node* newnode = new Node(val);
        Node* cur = head->next;
        head->next = newnode;
        newnode->prev = head;
        cur->prev = newnode;
        newnode->next = cur;
    }
    void push_back(const T& val){
        Node* newnode = new Node(val);
        Node* last = head->prev;
        head->prev = newnode;
        newnode->next = head;
        last->next = newnode;
        newnode->prev = last;
    }
    iterator insert(iterator position, const T& val) {
    Node* cur = position._node;  // 要插入的位置
    Node* newnode = new Node(val);

    Node* Prev = cur->prev;
    newnode->next = cur;
    newnode->prev = Prev;
    Prev->next = newnode;
    cur->prev = newnode;

    return iterator(newnode); // 返回新节点的迭代器
}

iterator erase(iterator position) {
    assert(position != end());
    Node* cur = position._node;

    Node* Prev = cur->prev;
    Node* Next = cur->next;

    Prev->next = Next;
    Next->prev = Prev;
    delete cur;

    return iterator(Next); // 返回删除节点之后的位置
}
void splice (iterator position, mylist& x){
    if(x.empty()) return;
    Node* cur = position._node;
    Node* Prev = cur->prev;
    Prev->next = x.head->next;
    (x.head->next)->prev = Prev;
    cur->prev = x.head->next;
    (x.head->prev)->next = cur;

    x.head->next = x.head;
    x.head->prev = x.head;

}

private:
    Node* head;
};

template<typename T>
void Print_List(const mylist<T>& l1){   
    typename mylist<T>::const_iterator it = l1.begin();
    while (it != l1.end())
    {
        cout<< *it << " ";
        ++it;
    }
    cout<<endl;
}

//%% ------------------ Test Function-----------------%%

// void test1(){
//     mylist<string> l1;
// }

void test1(){
    mylist<string> l1;
    cout<<"size = "<<l1.size()<<endl;
    if(l1.empty()){
        cout<<"List l1 is empty!"<<endl;
    }

}

void test2(){
    mylist<string> l1;
    l1.push_front("def");
    l1.push_front("abc");
    l1.push_back("ghi");
    Print_List(l1);
}

void test3(){
    mylist<string> l1;
    l1.insert(l1.begin(),"abc");
    l1.insert(l1.end(),"def");
    Print_List(l1);
}

