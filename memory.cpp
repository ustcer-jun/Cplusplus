#include<iostream>
#include<assert.h>
using namespace std;

// int globalVar = 1;
// static int staticGlobar var = 1;
// void Test()
// {
//     static int staticVar = 1;
//     int localVar = 1;
//     int num1[10] = { 1, 2, 3, 4 };
//     char char2[] = "abcd";
//     const char* pChar3 = "abcd";
//     int* ptr1 = (int*)malloc(sizeof(int) * 4);
//     int* ptr2 = (int*)calloc(4, sizeof(int));
//     int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//     free(ptr1);
//     free(ptr3);
// }

// int main(){
//     // c语言;
//     int* p1 = (int*)malloc(sizeof(int)); //开辟一个整形内存空间
//     int* p2 = (int*)malloc(sizeof(int)*10);//开辟一个整形数组
//     free(p1);free(p2);
//     // c++;
//     int* p3 = new int(10); //申请一个整型字节空间，初始化为10；
//     int* p4 = new int[10]; //申请10个int的字节空间。
//     delete p3;
//     delete[] p4;
//     return 0;
// }


// int main(){
//     int* pa = new int(9);
//     int* pb = new int[3];
//     cout << *pa <<endl;
//     delete pa;
//     delete [] pb; 
// }


//c语言链表的创建 --> malloc，free
// typedef struct ListNode_c{
//     int _val;
//     struct ListNode_c* _next;
//     struct ListNode_c* _prev;
// }ListNode_c;

// ListNode_c* Buy_NewNode(){
//     ListNode_c* node  =(ListNode_c*)malloc(sizeof(ListNode_c));
//     node->_next = NULL;node->_prev = NULL;
//     node->_val = 0;
//     return node;
// }

// void ListDestroy(ListNode_c* phead){
//     assert(phead);
//     ListNode_c* cur = phead->_next;
//     while (cur)
//     {
//         ListNode_c* tmp = cur->_next;
//         free(cur);
//         cur = tmp;
//     };
//     free(phead);
//     phead = NULL;  
// }

// // c++如何使用new，delete进行动态内存管理

// struct ListNode_cpp
// {
//     ListNode_cpp(int val = 6)
//     :_val(val)
//     ,_prev(nullptr)
//     ,_next(nullptr)
//     {};
//     void ListDestroy_cpp(ListNode_cpp* phead) {
//         ListNode_cpp* cur = phead;
//         while (cur) {
//             ListNode_cpp* tmp = cur->_next;
//             delete cur;
//             cur = tmp;
//         }
//     };

//     int _val;
//     ListNode_cpp* _prev;
//     ListNode_cpp* _next;
// };





// int main(){
//     ListNode_c* node1 = Buy_NewNode();
//     ListDestroy(node1);
//     ListNode_cpp* D1 = new ListNode_cpp;
//     delete D1;
//     ListNode_cpp a[10];
// }

class A{
    public:
    A(){
        cout<<"A()"<<endl;
    };
    ~A(){
        cout<<"~A()"<<endl;
    };
    public:
    int _val;
};
// int main(){
//     // size_t size = 2;
//     // A* a1 =(A*) malloc((size*1024*1024*1024*1024*1024)*sizeof(A));
//     // cout<< a1 <<endl;
//     // A* a2 = new A;
//     // A* a3 = (A*) operator new((size*1024*1024*1024*1024*1024)*sizeof(A));
//     // cout<<a3<<endl;
//     A* a = (A*)malloc(sizeof(A));
//     // a = NULL;
//     // free(a);
//     A* a1 = (A*)operator new(sizeof(A));


// }
// int main(){
//     // A* a1 = new A;
//     // delete a1;
//     A* a1 = (A*)malloc(sizeof(A));
//     new(a1)A();
//     a1->~A();
//     operator delete(a1);
// }