#include<iostream>
using namespace std;

class Stack{
    public:
    Stack(int capacity = 10){
        _arr = (int*)malloc(sizeof(int)*capacity);
        cout<<"malloc "<<_arr<<endl;
        _size = 0;
        _capacity = capacity;
    };
    ~Stack(){
        cout<<"free "<<_arr<<endl;
        free(_arr);
        _arr = nullptr;
        _size = 0;
        _capacity =0;
    };
    Stack(const Stack& s1){
        _arr = (int*)malloc(sizeof(int)*s1._capacity);
        cout<<"malloc"<<_arr<<endl;
        _size = s1._size;
        _capacity = s1._capacity;
    }
    Stack& operator =(const Stack& s1){
        if(this != &s1){
            for(int i = 0;i<s1._size;i++){
                _arr[i] = s1._arr[i];
            }
            cout<<" copy= "<<endl;
            _size = s1._size;
            _capacity = s1._capacity;
        }
        return *this;
    }
    private:
    int* _arr;
    int _size;
    int _capacity;
};
int main(){
    Stack s1;
    Stack s2(s1);
    s2 = s1;
}