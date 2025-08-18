#include<iostream>
#include<assert.h>
using namespace std;


class my_string{
public:
    //迭代器
    typedef char* iterator;
    typedef char* const_iterator;
    friend void Print_string(const my_string& s);
    iterator begin(){
        return _str;
    }
    iterator end(){
        return _str+(_size);
    }
    const_iterator begin()const{
        return _str;
    }
    const_iterator end()const{
        return _str+(_size);
    }
    //列表的初始化，析构函数
    my_string()
    :_str(nullptr)
    ,_size(0)
    ,_capacity(0)
    {
        cout<<"using Constructor: "<<endl;
    }
    my_string(const my_string& s1)
    {
        if(this != &s1){
            char* tmp = new char[s1._capacity+1];
            memcpy(tmp,s1._str,s1._size);
            _str = tmp;
            _capacity = s1._capacity;
            _size = s1._size;
        }
    };
    my_string& operator = (my_string s1){
        ::swap(_str,s1._str);
        _size = s1._size;
        _capacity = s1._capacity;
        return *this;
    }

    // my_string& operator=  (const my_string& str){
    //     if(&str == this){
    //         return *this;
    //     }
    //     delete [] _str;
    //     if(str._str){
    //         _str = new char[str._capacity+1];
    //         strcpy(_str,str._str);
    //     }
    //     else{
    //         _str = nullptr;
    //     }
    //     _capacity = str._capacity;
    //     _size = str._size;
    //     return *this;
    // }
    // my_string& operator = (const my_string& s1){
    //     ::swap(_str,s1._str);
    //     _size = s1._size;
    //     _capacity = s1._capacity;
    //     return *this;
    // }
    void clean(){
        delete _str;
        _size = 0;
        _capacity = 0;
    }
    ~my_string(){
        clean();
        _str = nullptr;
        cout<<"using Deonstructor: "<<endl;
    }
    size_t size()const{
        return _size;
    }
    size_t capacity()const{
        return _capacity;
    }
    bool empty(){
        return bool(_size== 0);
    }
    //内存管理函数
    void reserve(size_t n){
        if(n > capacity()){
            char* tmp =  new char[n+1]; 
            // memcpy(tmp,_str,size());
            if(_str){
                strcpy(tmp,_str);
                delete[] _str;
            }
            _str = tmp;
            _capacity = n;
        }
    }
    void resize (size_t n, char c = '\0'){
        size_t sz = size();
        if(n > size()){
            if(n>capacity()){
                reserve(n);
            }
            while (sz!= n)
            {
                _str[sz++] = c;
            }
        }
        _str[n] = '\0';
        _size = n;
    }
    //增删查改
    void push_back (char c){
        if(_size == _capacity){
            //增容
            size_t new_capacity = (_capacity == 0)?2: 2*_capacity;
            reserve(new_capacity);
        }
        _str[_size] = c;
        ++_size;
    }
    my_string& insert (size_t pos, const char c){
        assert(pos <= size());
        if(_size == _capacity){
            //增容
            size_t new_capacity = (_capacity == 0)?2: 2*_capacity;
            reserve(new_capacity);
        }
        size_t end = size();
        while (end >= pos)
        {
            _str[end+1] = _str[end];
            if(end == 0){
                break;
            }
            --end;
        };
        ++_size;
        _str[pos] = c;
        _str[_size] = '\0';
        return *this;
    };
    my_string&  insert(size_t pos, const char* str){
        assert(pos <= size());
        size_t len  = strlen(str);
        size_t sz = len + size();
        if(sz > capacity()){
            reserve(sz);
        }
        size_t end = size();
        while (end >= pos)
        {
            _str[end+len] = _str[end];
            if(end == 0){
                break;
            }
            --end;
        };
        // strncpy()
        for(size_t i = 0;i< len;i++){
            _str[pos+i] = str[i];
        };
        _size = sz;
        _str[_size] = '\0';
        return *this;
    }
    // void insert(size_t pos, const my_string& str);
    my_string& append (const char* s){
        size_t sz = strlen(s);
        size_t num = sz + size();
        if(num > capacity()){
            reserve(num);
        }
        strcat(_str,s);
        _size = num;
        return *this;
    }
    my_string& erase (size_t pos = 0, size_t len = npos){
        assert(pos < size());
        size_t sz = size();
        if(pos + len >= sz){
            _size = pos;
        }
        else{
            size_t write = pos;
            size_t read = pos + len;
            while ( _str[read] != '\0')
            {
                _str[write++] = _str[read++];
            }
            _size = sz-len;
            _str[_size] = '\0';
        }
        return *this;
    }
    size_t find(char ch, size_t pos = 0){
        assert(pos < size());
        while (pos < size())
        {
            if(_str[pos] == ch){
                return pos;
            }
            ++pos;
        }
        return npos;
    };
    size_t find(const char* str, size_t pos = 0){
        assert(pos < size());
        while (pos < size())
        {
            if(_str[pos] == str[0]){
                size_t len = strlen(str);
                size_t index;
                for(index = 1;index<len;index++)
                {
                    if(str[index] != _str[pos+index]){
                        break;
                    } 
                }
                if(index == len){
                    return pos;
                }
                
            }
            ++pos;
        }
        return npos;
    }

    char& operator[](size_t i){
        assert(i<_size);
        return _str[i];
    }
    const char& operator[](size_t i) const{
        assert(i<_size);
        return _str[i];
    }
private:
        char* _str;
        size_t _size;
        size_t _capacity;
        static size_t npos;
};
size_t my_string::npos = static_cast<size_t>(-1);

void Print_string(const my_string& s){
    my_string::const_iterator it = s.begin();
    while (it != s.end())
    {
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
    
}



//"----------------Test function ------------"

void test1(){
    my_string s1;
}


void test2(){
    my_string s1;
    cout<<s1.capacity()<<endl;
    cout<<s1.size()<<endl;
    cout<<s1.empty()<<endl;
}
void test3(){
    my_string s1;
    s1.reserve(4);
    cout<<s1.capacity()<<endl;
    s1.resize(10,'g');
    Print_string(s1);
}

void test4(){
    my_string s1;

    s1.push_back('a');
    s1.push_back('b');
    s1.push_back('c');
    s1.append("def");
    s1.insert(0,'x');
    Print_string(s1);
    s1.erase(3,2);
    Print_string(s1);
    size_t ind = s1.find("xa");
    cout<< "index = " << ind<<endl;
}

void test5(){
    my_string s1;

    s1.push_back('a');
    s1.push_back('b');
    s1.push_back('c');
    my_string s2(s1);
    Print_string(s2);
    my_string s3;
    s3 = s2;
    Print_string(s3);
}

void test6(){
    my_string s1;

    s1.append("abcdef");
    for(size_t i = 0; i<s1.size();i++){
        cout<< s1[i]<<" ";
    }
    cout<<endl;
}