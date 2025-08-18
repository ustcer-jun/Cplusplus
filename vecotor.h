#include<iostream>
#include<assert.h>
using namespace std;


// template<class T>
// // 为什么需要使用模版呢？因为vector里面放入的类型可以是任何。
// class Vector{

// public:
//     typedef T* iterator;
//     friend void swap(Vector<T>& v1,Vector<T>& v2);
//     typedef const T* const_iterator;
//     iterator begin(){
//         return _start;
//     }
//     iterator end(){
//         return _finish;
//     }
//     const_iterator begin() const{
//         return _start;
//     }
//     const_iterator  end() const{
//         return _finish;
//     }
//     Vector()
//     :_start(nullptr)
//     ,_finish(nullptr)
//     ,_endofstorage(nullptr) 
//     {};
//     //初始化列表
//     //拷贝构造函数
//     // Vector(const Vector& v){
//     //     size_t sz = v.size();
//     //     size_t capa = v.capacity();
//     //     _start = new T[capa];
//     //     if(_start){
//     //         memcpy(_start,v._start,sz*sizeof(T));
//     //     };  
//     //     _finish = _start + sz;
//     //     _endofstorage = _start + capa;

//     // }
//     Vector(const Vector<T>& v)
//     :_start(nullptr),
//     _finish(nullptr),
//     _endofstorage(nullptr){
//         reserve(v.capacity());
//         for(auto& num:v){
//             push_back(num);
//         }
//     }
    
//     //析构函数
//     ~Vector(){
//         delete[] _start;
//         _start = nullptr;
//         _finish = nullptr;
//         _endofstorage = nullptr;
//     }

//     //size和capacity
//     size_t size()const{
//         return _finish - _start;
//     }
//     size_t capacity()const{
//         return _endofstorage - _start;
//     }
//     void reserve(size_t n){
//         size_t sz = size();
//         if(n > capacity()){
//             T* tmp = new T[n];
//             if(_start){
//                 memcpy(tmp,_start, sz * sizeof(T));
//                 // std::copy(_start, _finish, tmp);
//                 delete[] _start;
//             }
//             _start = tmp;
//             _finish = _start + sz;
//             _endofstorage = _start + n;
//         }   
//     }
//     void push_back(const T& x){
//         size_t new_capacity = (capacity() == 0 ? 2 :capacity()*2);
//         if(_finish == _endofstorage){
//             reserve(new_capacity);
//         }
//         *_finish = x;
//         _finish ++;
//     }
//     void pop_back(){
//         assert(_start);
//         _finish --;
//     };
//     iterator insert(iterator pos,const T& x){
//         size_t num = pos - _start;
//         assert(num <=size());
//         size_t Capacity = capacity();
//         if(_finish == _endofstorage){
//             size_t new_capacity = (Capacity == 0 ? 2 :Capacity*2);
//             reserve(new_capacity);
//         }
//         pos = _start + num;
//         iterator end = _finish-1; 
//         while (end >= pos)
//         {
//             *(end+1) = *end;
//             end--;
//         }
//         *(pos) = x;
//         _finish++;
//         return _start;
//     }
//     void erase(iterator pos){
//         size_t num = pos - _start;
//         assert(num < size());
//         iterator end = _finish;
//         while(pos < end-1){
//             *pos = *(pos+1);
//             pos++;
//         }
//         _finish --;
//         // return _start;
//     }
//     void resize(size_t n,const T& x = T()){
//         if(n<size()){
//             _finish = _start +n;
//         }
//         else{
//             if(n > capacity()){
//                 reserve(n);   
//             }
//             while (_finish < _start + n)
//                 {
//                     *_finish = x;
//                     ++_finish; 
//                 } 
//         }
//     }
//     // 运算符重载
//     T& operator[](size_t n){
//         assert(n<size());
//         return (*(_start+n));
//     }
//     const T& operator[](size_t n)const{
//         assert(n<size());
//         return (*(_start+n));
//     }
//     // Vector<T>& operator=(const Vector<T>& v){
//     //     if(this != &v){
//     //         resize(v.capacity());
//     //         if(_start){
//     //             memcpy(_start,v._start,sizeof(T)*v.size());
//     //         }
//     //     }
//     //     return *this;
//     // }
//     // Vector<T>& operator=(const Vector& v){
//     //     if(this != &v){
//     //         delete[] _start;
//     //         T* tmp = new T[v.capacity()];
//     //         memcpy(tmp,v._start,size_t(T)*v.size());
//     //         _start = tmp;
//     //         _finish = _start+v.size();
//     //         _endofstorage = _start+v.capacity();
//     //     }
//     //     return *this;
//     // }
//     void swap(Vector<T>& v){
//         ::swap(_start,v._start);
//         ::swap(_finish,v._finish);
//         ::swap(_endofstorage,v._endofstorage);
//     } 
//     Vector<T>& operator=(Vector<T> v){
//         swap(v);
//         return *this;
//     }


// private:
//     T* _start;
//     T* _finish;
//     T* _endofstorage;
// };
// template<class T>
// void Print_vector(const Vector<T>& v){
//     typename Vector<T>::const_iterator it = v.begin();
//     while (it != v.end())
//     {
//         cout<<*it<<" ";
//         it++;
//     }
//     cout<<endl;
// }
// template<class T>
// void swap(Vector<T>& v1,Vector<T>& v2)noexcept{
//     using ::swap;
//     swap(v1._start, v2._start);
//     swap(v1._finish, v2._finish);
//     swap(v1._endofstorage, v2._endofstorage);

// }

// void Test1(){
//     Vector<int> v1;
//     v1.push_back(1);
//     v1.push_back(2);
//     v1.push_back(3);
//     v1.push_back(4);
//     Vector<int>v2;
//     v2.push_back(5);
//     v2.push_back(6);
//     v2.push_back(7);
//     v2.push_back(8);
//     v2.swap(v1);
//     Print_vector(v2);
// }



template<typename T>
class myvector{

public:
    typedef T* iterator;
    typedef  T* const_iterator;
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
    myvector()
    :_start(nullptr)
    ,_finish(nullptr)
    ,_endofstorage(nullptr)
    {};
    ~myvector(){
        delete[] _start;
        _start = nullptr;
        _finish = nullptr;
        _endofstorage = nullptr;
    }
    //拷贝构造和赋值运算符
    myvector(const myvector<T>& v){
        size_t capa = v.capacity();
        size_t sz = v.size();
        T* tmp = new T[capa];
        std::copy(v._start,v._finish,tmp);
        _start = tmp;
        _finish = _start+sz;
        _endofstorage = _start + capa;
    }

    size_t size(){
        return _finish - _start;
    }

    size_t capacity(){
        return _endofstorage - _start;
    }

    size_t size()const{
        return _finish - _start;
    }

    size_t capacity()const{
        return _endofstorage - _start;
    }
    void reserve(size_t n){
        size_t sz = size();
        if(n>capacity()){
            T* tmp = new T[n];
            if(_start){
                std::copy(_start,_finish,tmp);
                delete[] _start;
            }
            _start = tmp;
            _finish = _start + sz;
            _endofstorage = _start + n;
        }
        return;
    }
    void resize(size_t n,const T& val = T()){
        if(n <= size()){
            _finish = _start + n;
        }
        else{
            if(n > capacity()){
                reserve(n);
                
            }
            while (_finish < _start +n)
            {
                *_finish = val;
                _finish++;
            }
        }
    }
    void push_back(const T& val){
        if(_finish == _endofstorage){
            size_t Capa = (capacity() == 0)? 2 : capacity()*2;
            reserve(Capa);
        }
        *_finish = val;
        _finish++;
    }
    void pop_back(){
        assert(_start != _finish);
        _finish--;
    }
    
    iterator erase (iterator pos, iterator first, iterator last){
        assert(pos<last && pos>=first);
        // iterator end = _finish-1;
        while (pos != _finish-1)
        {
            *(pos) = *(pos+1);
            pos++;
        }
        --_finish;
        return _start;
    }
    void insert(iterator pos,const T& val){
        assert(pos<=_finish);
        size_t num = pos - _start;
        if(_finish == _endofstorage){
            size_t newcapacity = (capacity() == 0)?2:2*capacity();
            reserve(newcapacity);
        }
        iterator end = _finish;
        pos = _start+num;
        while (end > pos)
        {
            *end = *(end-1);
            end--;
        }
        *pos = val;
        ++_finish;
    }   
    //运算符重载
    T& operator [](size_t pos){
        return *(_start+pos);
    }
    const T& operator [](size_t pos)const{
        return *(_start+pos);
    }
    T& at(size_t index) {
        if (index >= size()) throw std::out_of_range("Index out of range");
        return _start+index;
    };
    void swap(myvector<T>& v){
        ::swap(_start,v._start);
        ::swap(_finish,v._finish);
        ::swap(_endofstorage,v._endofstorage);
    }
    myvector<T>& operator=(myvector<T> v){
        swap(v);
        return *this;
    }

private:
    T* _start;
    T* _finish;
    T* _endofstorage;    
};

template<class T>
void Print_vector(const myvector<T>& v){
    typename myvector<T>::const_iterator it = v.begin();
    while (it != v.end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
}

void test1(){
    myvector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(4);

    myvector<int>:: iterator it = v1.begin();
    while (it != v1.end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
    
}

void test2(){
    myvector<string> v1;
    v1.reserve(8);
    cout<<"capacity = "<<v1.capacity()<<endl;
    v1.push_back("aaa");
    v1.push_back("bbb");
    v1.push_back("cccc");
    v1.resize(8,"d");
    Print_vector(v1);
}
    // myvector<int>:: iterator it = v1.begin();
    // while (it != v1.end())
    // {
    //     cout<<*it<<" ";
    //     it++;
    // }
    // cout<<endl;

void test3(){
    myvector<string> v1;
    v1.push_back("aaa");
    v1.push_back("bbb");
    v1.push_back("cccc");
    v1.resize(8,"d");
    v1.erase(v1.begin(),v1.begin(),v1.end());
    Print_vector(v1);
}

void test4(){
    myvector<string> v1;
    v1.push_back("aaa");
    v1.push_back("bbb");
    v1.push_back("cccc");
    v1.resize(8,"d");
    for(size_t i = 0; i<v1.size();i++){
        cout<< v1[i]<<" ";
    }
    cout<< endl;
}

void test5(){
    myvector<string> v1;
    v1.push_back("aaa");
    v1.push_back("bbb");
    v1.push_back("cccc");
    Print_vector(v1);
    v1.pop_back();
    Print_vector(v1);
    v1.insert(v1.begin()+2,"e");
    Print_vector(v1);
    v1.insert(v1.begin(),"hello");
    Print_vector(v1);
    v1.erase(v1.begin(),v1.begin(),v1.end());
    Print_vector(v1);
}

void test6(){
    myvector<string> v1;
    v1.push_back("aaa");
    v1.push_back("bbb");
    v1.push_back("cccc");
    Print_vector(v1);
    myvector<string> v2(v1);
    Print_vector(v2);
    myvector<string> v3;
    v3 = v2;
    Print_vector(v3);
}