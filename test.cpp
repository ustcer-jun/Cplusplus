#include<iostream>
using namespace std;


class Solution {
public:
    int Sum_Solution(int n) {
        int Sum = n;
        bool ContinueAdd = n>1 && (Sum += Sum_Solution(n-1));
        return Sum;
    }
};

int main(){
    Solution s;
    cout<<"Sum(5) = "<<Solution().Sum_Solution(5)<<endl;//利用匿名对象
    //cout<<"Sum(5) = "<<s.Sum_Solution(5)<<endl;
}



// class Sum{
//     public:
//         static void Init_Sum(){
//             i = 0;
//             sum = 0;
//         }
//         Sum(){
//             ++i;
//             sum+= i;
//         }
//         int Get_Sum(){

//             return sum;
//         }
//     private:
//     static int i;
//     static int sum;

// };
// int Sum::i = 0;
// int Sum::sum = 0;

// class Solution {
// public:
//     int Sum_Solution(int n) {
//         Sum::Init_Sum();
//         //Sum A[n];
//         //动态开辟
//         Sum* Pa = new Sum[n];
//         return Pa->Get_Sum();
//     }
// };


// int main(){
//     Solution S1;
//     cout<<"sum(5) = "<<S1.Sum_Solution(5)<<endl;
// }
