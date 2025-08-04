#include <iostream>
using namespace std;

#define SQUARE(x) ((x)*(x))

// int main(){
//     int i = 5;
//     cout << "6*6 = " << SQUARE(++i);
// }


inline int max(int a, int b) {
    return a > b ? a : b;
}

int main(){
    int x = 5;
    int y = max(x++, 10);  // x++ 只执行一次
}