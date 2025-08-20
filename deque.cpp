#include<iostream>
using namespace std;

void Print_deque(const deque<int> dq){
    for(auto e:dq){
        cout<<e<<" ";
    }
    cout<<endl;
}


// int main(){
//     deque<int> d1;
//     d1.push_back(1);
//     d1.push_back(2);
//     d1.push_back(3);
//     d1.push_back(4);
//     Print_deque(d1);
//     d1.pop_back();
//     Print_deque(d1);
//     vector<int>v1 = {4,5,6,7};
//     d1.assign(v1.begin(),v1.begin()+3);
//     Print_deque(d1);
// }

void test_queue(){
    deque<int> dq;
    vector<int> v;
    const int n = 100000;
    srand(time(0));
    for(int i = 0;i<n;++i){
        int x = rand();
        dq.push_back(x);
        v.push_back(x);
    }
    size_t begin1 = clock();
    sort(dq.begin(),dq.end());
    size_t end1 = clock();
    cout<< "Sorting time = "<<end1-begin1<<endl;
    size_t begin2 = clock();
    sort(v.begin(),v.end());
    size_t end2 = clock();
    cout<< "Sorting time = "<<end2-begin2<<endl;
}

int main(){
    test_queue();
}