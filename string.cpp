// #include<iostream>
// #include<assert.h>
// using namespace std;

// int main(){
//     string s1;
//     string s2("Yajun very handsome!");
//     string s3(s2);
//     string s4(5,'h');
//     string s5("hello world",5);
//     string s6(s5.begin(),s5.end());
//     cout<<s1<<endl;
//     cout<<s2<<endl;
//     cout<<s3<<endl;
//     cout<<s4<<endl;
//     cout<<s5<<endl;
//     cout<<s6<<endl;

// }

// int main(){
//     string s1("Yajun very handsome!");
//     s1.push_back('y');
//     s1.append(" That is right!");
//     cout << s1 <<endl;

// }

// int main(){
//     string s("123456789");
//     // for(int i = 0;i<s.size();i++){
//     //     cout << s[i];
//     // }
//     // cout<<endl;

//     // string::iterator it = s.begin();
//     // while (it<s.end())
//     // {
//     //     cout<< *it;
//     //     it++;
//     // }
//     // cout<<endl;
//     // for(string::iterator it = s.begin();it<s.end();it++){
//     //     cout<< *it;
//     // }
//     // cout<<endl;

//     for(auto it = s.begin();it < s.end();it++){
//          cout<< *it;
//     }
//     cout<<endl;
//     for(size_t i = 0;i<s.size();i++){
//         cout<<s.at(i);
//     }
//     cout<<endl;

//     for(string::reverse_iterator rit = s.rbegin();rit < s.rend();rit++){
//         cout<<*rit;
//     }
//     cout<<endl;
// }

// int main(){
//     string s1("hello world!");
//     string s2("hello!");
//     cout<< s1.length()<<endl;
//     cout<< s2.length()<<endl;
//     cout<< s1.capacity()<<endl;
//     cout<< s2.capacity()<<endl;
//     s1.clear();
//     cout<<s1<<endl;
//     cout<<s1.capacity()<<endl;
// }

// int main(){
//     string s1;
//     s1.reserve(100);
//     size_t sz =0;
//     for(int i =0;i<100;i++){
//         s1.push_back('h');
//         if(sz != s1.capacity()){
//             sz = s1.capacity();
//             cout<< "capacity changed:" << sz<<'\n';
//         }
//     }
//     cout<<endl;
// }
// int main(){
//     string s1;
//     s1.resize(100);
//     size_t string_capa = s1.capacity();
//     for(size_t i =0;i<100;i++){
//         s1.push_back('a');
//         if(string_capa != s1.capacity()){
//             string_capa = s1.capacity();
//             cout<< "string capacity = "<< string_capa;
//         }
//     }
//     cout<<endl;
// }

// int main() {
//     string s = "hello";

//     s.resize(8, 'x'); // 扩展长度，填充 'x'
//     cout << "resize(8, 'x'): " << s << endl; // helloxxx

//     s.resize(3); // 缩短长度
//     cout << "resize(3): " << s << endl; // hel

//     return 0;
// }
// int main(){
//     string s("12345");
//     s.insert(s.begin(),0);
//     s.insert(6,"7");
//     s.insert(7,3,'8');
//     cout<<s<<endl;
// }

// #include<assert.h>
// #include<string.h>
// #include<ctype.h>
// char* reverse_str(char* pc){
//     assert(pc);
//     int len = strlen(pc);
//     int left = 0;int right = len-1;
//     while(left<right){
//         if(!isalpha((unsigned char)pc[left]) && isalpha((unsigned char)pc[right])){
//             left++;
//         }   
//         else if(!isalpha((unsigned char)pc[right]) && isalpha((unsigned char)pc[left])){
//             right--;
//         }
//         else if(!isalpha((unsigned char)pc[right]) && !isalpha((unsigned char)pc[left])){
//             right--;
//             left++;
//         }
//         else{
//             char tmp = pc[left];
//             pc[left] = pc[right];
//             pc[right] = tmp;
//             right--;
//             left++;
//         }
//     }
//     return pc;
// }
// int main(){
//     char str[] = {"a-bC-dEf-ghIj"};
//     char str1[] ={"7_28]"};
//     printf("%s\n",str1);
//     reverse_str(str1);
//     printf("%s\n",str1);
// }

// class Solution {
// public:
//     int firstUniqChar(string s) {
//         int size = s.size();
//         int This = 0;
//         int target =0;
//         while(target<size){
//             char ch = s[target];
//             This = 0;
//             int flag = 0;
//             while(This < size){
//                 if(s[This] == ch){
//                     flag = 1;
//                     break;
//                 }
//                 This++;
//             }
//             if(flag == 0){
//                 return target;
//             }
//             target++;
//         }
//         return -1;
//     }
// };

// class Solution {
// public:
//     int firstUniqChar(string s) {
//         int count[26]={0};
//         int size = s.size();
//         for(auto ch : s){
//             count[ch - 'a']++;
//         };
//         for(int i = 0;i<size;i++){
//             if(count[s[i]-'a'] == 1){
//                 return i;
//             }
//         }
//         return -1;

//     }
// };

// int main(){
//     Solution s;
//     string s1("aabb");
//     cout<< s.firstUniqChar(s1)<<endl;
    
// }

// int main(){
//     string s("Hello world!\n");
//     // const char* ps = s.c_str();
//     // // printf("%s\n",ps);
//     // while(*ps){
//     //     cout<< *ps << ' ';
//     //     ps++;
//     // }
//     // cout << endl;
//     s += '\0';
//     s += "world";
//     cout << s << endl;
//     cout << s.c_str()<<endl;
// }

// int main(){
//     for (unsigned char ch = 0; ch<256;ch++){
//         cout << ch << " ";
//     }
//     cout << endl;
// }
// int main(){
//     string s("hello.cpp");
//     size_t pos = s.find('.');
//     if(pos != string::npos){
//         string s2 = s.substr(pos);
//         cout<< s2 <<endl;
//     }
//     else{
//         cout<< "There is no suffix!"<<endl;
//     }
// }
// int main(){
//     string s("Hello world! Welcome to C++.");
//     size_t pos = s.find("world!");
//     if(pos != string::npos){
//         string s1 = s.substr(pos,5);
//         cout<< s1 <<endl;
//     }
//     else{
//         cout<< "Not Found!" << endl;
//     }
// }

// void split_url(const string& str){
//     size_t pos1 = str.find(':');
//     if(pos1 != string::npos){
//         cout<<str.substr(0,pos1)<<endl;
//     }
//     else{
//         cout<<"wrong url"<<endl;
//     }
//     size_t pos2 = str.find('/',pos1+3);
//     if(pos2 != string::npos){
//         cout<<str.substr(pos1+3,pos2-pos1-3)<<endl;
//     }
//     else{
//         cout<<"wrong url"<<endl;
//     }
//     cout<<str.substr(pos2)<<endl;
// };


// int main(){
//     string s("https://cplusplus.com/reference/string/string/?kw=string#google_vignette");
//     split_url(s);
// }


// #include <iostream>
// using namespace std;

// size_t get_length(const string& str){
//     size_t pos =  str.rfind(' ');
//     if(pos != 0){
//         return str.size()-pos-1;
//     }
//     else{
//         return str.size();
//     }
// }

// int main() {
//     string s1("ABSIB T");
//     cout<< "the length of last word is "<< get_length(s1)<<endl;
//     return 0;
// }

// 64 位输出请用 printf("%lld")

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>
// #include <assert.h>

// void reverse(char* str) {
//     assert(str);
//     int num = strlen(str);
//     int left = 0;
//     int right = num - 1;
//     while (right > left) {
//         char ch = str[left];
//         str[left] = str[right];
//         str[right] = ch;
//         right--;
//         left++;
//     }
// }

// char* get_alpha(const char* str) {
//     char* str_copy = (char*)malloc(200000 * sizeof(char));
//     int j = 0;
//     for (int i = 0; str[i]; i++) {
//         if ((str[i] >= '0' && str[i] <= '9') || 
//             (str[i] >= 'A' && str[i] <= 'Z') || 
//             (str[i] >= 'a' && str[i] <= 'z')) {
//             char ch = str[i];
//             if (ch >= 'A' && ch <= 'Z') {
//                 ch += 32; // 转小写
//             }
//             str_copy[j++] = ch;
//         }
//     }
//     str_copy[j] = '\0'; // ✅ 记得添加终止符
//     return str_copy;
// }

// bool issame(const char* str1, const char* str2) {
//     int size1 = strlen(str1);
//     int size2 = strlen(str2);
//     if (size1 != size2) return false;
//     for (int i = 0; i < size1; i++) {
//         if (str1[i] != str2[i]) return false;
//     }
//     return true;
// }

// bool isPalindrome(char* s) {
//     char* s1 = get_alpha(s);
//     char* s2 = get_alpha(s);
//     reverse(s2);
//     bool result = issame(s1, s2);
//     free(s1); // ✅ 别忘了释放内存
//     free(s2);
//     return result;
// }

// class Solution {
// public:
//     void lower2upper(string& s){
//         for(auto& ch : s){
//             if(ch >= 'a' && ch <= 'z'){
//                 ch -= 32;
//             }
//         }
//     };
//     bool isalpha_number(char ch){
//         if((ch>='0' && ch<='9')||(ch>='A' && ch<='Z')){
//             return true;
//         }
//         else{
//             return false;
//         }
//     };

//     bool isPalindrome(string s){
//         lower2upper(s);
//         int begin = 0;
//         int end = s.size()-1;
//         while (begin < end)
//         {
//             while(begin < end && !isalpha_number(s[begin])){
//                 begin++;
//             }
//             while(begin < end && !isalpha_number(s[end])){
//                 end--;
//             }
//             if(s[end]!=s[begin]){
//                 return false;
//             }
//             else{
//                 begin++;
//                 end--;
//             }
//         }
//         return true;       
//     }
// };

// int main(){
//     char str1[] = "A man, a plan, a canal: Panama";
//      if(isPalindrome(str1)){
//         cout<<"True"<<endl;
//     }
//     else{
//         cout<<"False"<<endl;
//     }
// }

// int main(){
//     char str1[] = "A man, a plan, a canal: Panama";
//     char* str2 = get_alpha(str1);
//     cout<<str2<<endl;
//     char* str3 = get_alpha(str1);
//     reverse(str3);
//     cout<<str3<<endl;
//     if(issame(str3,str2)){
//         cout<<"True"<<endl;
//     }
//     else{
//         cout<<"False"<<endl;
//     }
// }

//字符串的实现

#include "string.h"
using namespace zyj;
// using namespace std;
int main(){
    zyj::string s1; 
    zyj::string s2("zyj");
//     cout<<s2<<endl;
//     zyj::string::iterator it = s2.begin();
//     while (it != s2.end())
//     {
//         *it -= 1;
//         cout<<*it<<" ";
//         it++;
//     }
//     cout<<endl;
// //只需要实现迭代器，范围for直接可以使用，因为范围for 的实现基于我们的迭代器，
//     for(auto ch : s2){
//         cout<<ch<<" ";
//     }
//     cout<<endl;
    s2.insert(0,"ab");
    cout<<s2<<endl;
    // zyj::string s3("abcdaabdeabcde");
    // size_t index = s3.find("abcd",2);
    // cout<<index<<endl;

}

