#include "priority_queue.h"
#include<iostream>
using namespace std;


// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         for(int i = 0;i<nums.size();++i){
//             pq.emplace(nums[i]);
//         }
//         for(int j = 0;j<k-1;++j){
//             pq.pop();   
//         }
//         return pq.top();
//     }
//     priority_queue<int> pq;
// };


// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         for(int i = 0;i<nums.size();++i){
//             pq.emplace(nums[i]);
//             if(pq.size()>k){
//                 pq.pop();
//             }
//         }
//         return pq.top();
//     }
//     priority_queue<int,vector<int>, greater<int>> pq;
// };

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         for(int i = 0;i<k;++i){
//             pq.push(nums[i]);
//         }
//         for(int j = k;j<nums.size();++j){
//             if(nums[j] >= pq.top()){
//                 pq.pop();
//                 pq.push(nums[j]);
//             }
//         }
//         return pq.top();
//     }
//     priority_queue<int,vector<int>, greater<int>> pq;
// };


// int main(){
//     Solution s1;
//     vector<int>nums = {3,2,3,1,2,4,5,5,6};
//     int k =4;
//     cout<< s1.findKthLargest(nums,k) <<endl;
//}

int main(){
    test1();
}