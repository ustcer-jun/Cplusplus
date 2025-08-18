#include<iostream>
using namespace std; 
#include<assert.h>
#include<string.h>
  
//实现增删查改的string类。
namespace zyj{
    class string
    {
        public:
            typedef char* iterator;
            iterator begin(){
                return _str;
            }
            iterator end(){
                return _str+_size;
            }

            string(const char* str = "",size_t size = 0,size_t capacity = 10) //两个构造函数
            :_str(new char[capacity])
            {
                if(capacity<(strlen(str)+1)){
                    _str = new char[strlen(str)+1];
                    _capacity = strlen(str);
                }
                else{
                    _str = new char[capacity];
                    _capacity = capacity;
                }
                _size = strlen(str);
                strcpy(_str,str);
            }
            string(const string& str){
                _str = new char[strlen(str._str)+1];
                _capacity = str._capacity;
                _size = str._size;
                strcpy(_str,str._str);
            }
            void swap(string& s){
                ::swap(_str,s._str);
                ::swap(_capacity,s._capacity);
                ::swap(_size,s._size);
            }
            // string& operator=(const string& str){
            //     if(this != &str){
                
            //         _size = str._size;
            //         _capacity = str._capacity;
            //         char* newstr = new char[str._capacity+1];
            //         strcmp(str._str,newstr);
            //         delete[] _str;
            //         _str = newstr;
            //         return *this;
            //     }
            // }
            ~string(){
                delete [] _str;
                _str = nullptr;
                _capacity = 0;
                _size = 0;
            }
            size_t size() const{
                return _size;
            }
            size_t capacity() const {
                return _capacity;
            }
            bool isempty(){
                if(_size != 0){
                    return false;
                }
                return true;
            }
                        //增删查改
            void reserve(size_t n){
                assert(n > _capacity);
                char* new_str = new char[n+1];
                strcpy(new_str,_str);
                delete[] _str;
                _str = new_str;
                _capacity = n;
            };
            void resize(size_t size,char ch = '\0'){
                if(size < _size){
                    _str[size] = '\0';
                }
                else{
                    if(size > _capacity){
                        reserve(size);
                    }
                    for(size_t i = _size ;i < size; i++){
                        _str[i] = ch;
                    }
                    _str[size] = '\0';
                }
                _size = size;
            }

            char* c_str(){
                char* str = new char[_size];
                strcpy(str, _str);
                return str;
            }

        void push_back(char ch){
            if(_size == _capacity){
                size_t new_capacity = 2*_capacity;
                reserve(new_capacity);
            }
            _str[_size] = ch;
            ++_size;
            _str[_size] = '\0';
        }
        void append(const char* str){
            size_t len = strlen(str);
            // while (len+_size > _capacity)
            // {
            //     _capacity *= 2;
            // }
            if(len+_size > _capacity){
                _capacity = len+_size;
            }
            reserve(_capacity);
            // strcat(newstr,_str);
            // strcat(newstr,str);
            strcpy(_str+_size,str);
            _size += len;
        };
        void Delete(){
            if(_size == 0){
                cout<< "void string!"<<endl;
                return;
            }
            _size --;
        }

        string& insert(size_t pos, char ch){
            assert(pos <= _size);
            if(_size == _capacity){
                reserve(2*_capacity);
            }
            int end = _size;
            while(end >= (int) pos){
                _str[end+1] = _str[end];
            }
            _str[pos] = ch;
            _size++;
            return *this;
        }
        string& insert(size_t pos, const char* str){
            assert(pos <= _size);
            size_t len = strlen(str);
            if(_size+len > _capacity){
                reserve(_size+len);
            }
            int end = _size;
            while (end >= (int) pos)
            {
                _str[end+len] = _str[end];
                end--;
            };
            strncpy(_str+pos,str,len);
            _size += len;
            return *this;
        }
        string& erase(size_t pos, size_t len = npos){
            assert(pos<_size);
            if(pos+len >= _size){
                _size = pos;
                _str[_size] = '\0';
            }
            else{
                int res = _size - len - pos;
                size_t end = _size;
                while (res >= 0)
                {
                    _str[pos+res] = _str[end--];
                    res--;
               }
               _size = _size-len;
            }
            return *this;
        }
        size_t find(char ch, size_t pos = 0){
            assert(pos >= 0 && pos<_size);
            while (pos < _size)
            {
                if(_str[pos] == ch){
                    return pos;
                }
                pos ++;
            }
            return npos;
        }
        size_t find(const char* str, size_t pos = 0){
            assert(pos<_size);
            // if(pos + len > _size){
            //     return npos;
            // }
            // for(size_t begin = pos; begin <=_size-len;begin++){
            //     size_t i = 0;
            //     while ( i < len && _str[begin+i] == str[i])
            //     {
            //         ++i;
            //     }
            //     if(i == len){
            //         return begin;
            //     }
                
            // }
            // return npos;
            char* ps = strstr(_str+pos,str);
            if(!ps){
                return npos;
            }
            else{
                return ps -_str;
            }
        }
        string& operator=  (const string& str){
            if(&str == this){
                return *this;
            }
            delete [] _str;
            if(str._str){
                _str = new char[strlen(str._str)+1];
                strcpy(_str,str._str);
            }
            else{
                _str = nullptr;
            }
            _capacity = str._capacity;
            _size = str._size;
            return *this;
        }
        string& operator+=(char ch){
            this->push_back(ch);
            return *this;
        }
        string& operator+=(const char * str){
            this->append(str);
            return *this;
        }
        char& operator[](size_t i){
            assert(i<_size);
            return _str[i];
        }
        const char& operator[](size_t i) const{
            assert(i<_size);
            return _str[i];
        }
        bool operator<(const string& s){
            int ret = strcmp(_str,s._str);
            return ret<0;
        }
        bool operator>(const string& s){
            int ret = strcmp(_str,s._str);
            return ret > 0;
        }
        bool operator==(const string& s){
            int ret = strcmp(_str,s._str);
            return ret == 0;
        }
        bool operator<=(const string& s){
            return !(*this > s);
        }
        bool operator!=(const string& s){
            return !(*this == s);
        }
        bool operator>=(const string& s){
            return !(*this < s);
        }
        private:
            char* _str;
            size_t _size;
            size_t _capacity;
            static size_t npos;
    };
    size_t zyj::string::npos = (size_t) -1;
    std::ostream& operator <<(std::ostream& out, const string& s){
        for(size_t i =0;i<s.size();i++){
            out<<s[i];
        }
        return out;
    }
    // getline的实现。
    std::istream& operator >>(std::istream& in, string& s){
        char ch;
        while (in.get(ch))
        {
            if (ch == ' ' || ch =='\n'){
                break;
            }
            else{
                s += ch;
            }
        } 
        return in;
    }

};
template<typename T>
void swap(T a, T b){
    T tmp = a;
    a =  b;
    b = tmp;
}


