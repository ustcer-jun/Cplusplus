#include<iostream>

//using namespace std //c++库中的所用东西都是放在std命名空间中的
// 展开常用库里面的一下对象。
using std::cout;
using std::endl;
void Print_Hello(int num = 1){
    for(int i = 0;i<num;i++){
        cout << "hello world!\n" << endl;
    }
    return;
}

// int main(){
//     Print_Hello(5);
// }

// int main(){
//     //自动识别类型
//     cout <<"hello world!\n" << endl;
//     int i = 1;
//     double d = 1.11;
//     std::cin >> i >> d; 
//     cout << i << " " << d << endl;

// }

//全缺省
// void Func1(int a = 10,int b = 20,int c = 30){
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;
//     cout << "c = " << c << endl;
// }

// int main(){
//     Func1(); 
//     Func1(1);
//     Func1(1,2);
//     Func1(1,2,3);
// }


//半缺省（缺省部分参数）
// void Func2(int a,int b, int c = 30){
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;
//     cout << "c = " << c << endl;
// }

// int main(){

//     Func2(1,2);
//     Func2(1,2,3);
// }

int Add(int left,int right){
    return left+right;
}

double Add(double left,double right){
    return left+right;
}

long Add(long left,long right){
    return left+right;
}
int Add(int left,int mid,int right){
    return left+mid+right;
}


// int main(){
//     printf("%d\n",Add(10,20));
//     printf("%d\n",Add(10,20));
//     printf("%ld\n",Add(10L,20L));
//     printf("%d\n",Add(10,30,20));
//     return 0;
// }
// int main(){
//     int a = 10;
//     int& ref = a;  // ref 是 a 的引用，即别名
//     int& c = ref;

//     ref = 20;      // 实际修改的是 a
//     int d = 100;
//     ref = d;
//     cout << a <<"\n";     // 输出 20
//     cout << c; 
// }

// int main(){
//     //权限的放大，不能把const给到非const
//     const int a = 10;
//     // int& b  = a; 错误，权限不能放大
//     int b = 10;
//     const int& c  = b; //权限可以缩小
//     cout << "c = " << c;
// }

// int main(){
//     const int x = 10;
//     int y = x;

//     int z = 20;
//     const int r = z;

//     const int* cp = &z;
//     int* p = cp;
// }

// void swap_cpp(int& a,int& b){
//     int tmp = a;
//     a = b;
//     b = tmp;
// }

// int main(){
//     int x = 10;
//     int y = 20;
//     swap_cpp(x,y);
//     cout <<"x = "<< x << "\ny = " << y << "\n";
// }

// int& foo() {
//     int x = 10;   // 局部变量，函数结束后内存释放
//     return x;     // ❌ 返回无效引用
// }

// int main() {
//     int& ref = foo();  // 未定义行为！
//     cout << ref;       // 很可能是垃圾值或崩溃
// }

int& Add2(int a,int b){
    static int c;
    c = a+b;
    return c;
}

int main(){
    Add2(3,4);
    int& ret = Add2(1,2);
    printf("hello world!\n");
    cout << "Add2(1,2) is :" <<ret <<endl;
}