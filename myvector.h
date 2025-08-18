#include<iostream>
#include<assert.h>
using namespace std;
template <typename T>
class my_vector{
public:
    typedef T* iterator;
    typedef T* const_iterator;

    iterator begin(){
        return _start;
    }
    iterator end(){
        return _finish;
    }

    const_iterator begin()const{
        return _start;
    }
    const_iterator end()const{
        return _finish;
    }

    my_vector()
    :_start(nullptr)
    ,_finish(nullptr)
    ,_endofstorage(nullptr)
    {}
    ~my_vector()
    {
        delete[] _start;
        _start = nullptr;
        _finish = nullptr;
        _endofstorage = nullptr;
    }
    my_vector(const my_vector<T>& v){
        if(this != &v){
            size_t new_capacity = v.capacity();
            T* tmp = new T[v.capacity()];
            ::copy(v._start,v._finish,tmp);
            _start = tmp;
            _finish = _start + v.size();
            _endofstorage = _start+new_capacity;
        };
    }
    void swap(my_vector<T>& v){
        ::swap(_start,v._start);
        ::swap(_finish,v._finish);
        ::swap(_endofstorage,v._endofstorage);
    }
    my_vector<T>& operator = (my_vector<T> v){
        swap(v);
        return *this;
    }

    size_t size()const {
        return _finish - _start;
    }

    size_t capacity()const {
        return _endofstorage - _start;
    }
    bool empty(){
        if(_start == _finish){
            return true;
        }
        return false;
    }
    void reserve(size_t n){
        size_t sz = size();
        if(n > capacity()){
            T* tmp = new T[n];
            if(_start){
                std::copy(_start,_finish,tmp);
                delete[] _start;
            }
            _start = tmp;
            _finish = _start +sz;
            _endofstorage = _start + n;
        }
    }
    void resize(size_t n, const T& val){
        size_t sz = size();
        if(n <= sz){
            _finish  = _start + n;
        }
        else{
            if(n > capacity()){
                reserve(n);
            }
            while (_finish != _endofstorage)
            {
                *_finish = val;
                ++_finish;
            }
        }
    }
    void push_back(const T& x){
        // if(_finish == _endofstorage){
        //     //增容
        //     size_t new_capacity = (capacity() == 0)? 2 : 2* capacity();
        //     reserve(new_capacity);
        // }
        // *_finish = x;
        // ++_finish;
        insert(_finish,x);
    }
    void pop_back(){
        erase(_finish-1);
    }

    iterator insert (iterator position, const T& val){
        assert(position <= _finish && _start <= position);
        if(_finish == _endofstorage){
            size_t num = position - _start;
            size_t new_capacity = (capacity() == 0) ? 2 : 2*capacity();
            reserve(new_capacity);
            position = _start + num;
        }
        for(T* end = _finish; end > position; --end){
            *end = *(end-1);
        };
        *position = val;
        ++_finish;
        return position;
    }
    iterator erase (iterator pos){
        assert(pos < _finish && _start <= pos);
        if(_start != _finish){
            T* _init = pos;
            for(T* _init = pos;_init < _finish-1;++_init){
                *(_init) = *(_init + 1);
            } 
            --_finish;
        }
        return pos;
    }
    iterator erase (iterator first, iterator last){
        assert(first >= _start && last <= _finish && _start);
        size_t num = last - first;
        size_t res = _finish - last;
        T* end = last;
        T* begin = first;
        while (res--)
        {
            *begin = *end;
            ++end;
            ++begin;
        }
        _finish -= num;
        return first;
    }


private:
    T* _start;
    T* _finish;
    T* _endofstorage; 
};
template <typename T>
void Print_vector(const my_vector<T> & v){
    typename my_vector<T>::const_iterator it = v.begin();
    while (it != v.end())
    {
        cout<< *it <<" ";
        ++it;
    }
    cout<< endl;
}

//---------------- "Test function ----------------" 

void test1(){
    my_vector<int> v;
    v.push_back(1);
    cout<< v.capacity()<<endl;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    cout<< v.capacity()<<endl;
    if(!v.empty()){
        cout<< "Vector is not empty!"<<endl;
    }
    Print_vector(v);
}

// void test2(){
//     my_vector<int> v;
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(3);
//     v.push_back(4);
//     v.resize(2,5);
//     Print_vector(v);
// }
void test2(){
    my_vector<int> v;
    v.push_back(1);
    v.reserve(10);
    cout<<"capacity is "<<v.capacity()<<endl;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.resize(12,5);
    Print_vector(v);
}

void test3(){
    my_vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.insert(v.begin(),0);
    Print_vector(v);
    v.insert(v.end(),5);
    Print_vector(v);
    v.erase(v.begin());
    Print_vector(v);
    v.erase(v.begin(),v.end());
    Print_vector(v);
}

void test4(){
    my_vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    my_vector<int> v2;
    v2 = v;
    Print_vector(v2);
}
