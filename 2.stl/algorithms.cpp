#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_double(int a){
     cout << 2*a << " ";
}

bool check_even(int a){
     return a%2==0;
}

bool not_even(int a ){
     return a%2 != 0 ;
}

int main(){
     vector<int> vec = {1,2,3,4,5,5};

     //for_each
     // for_each(vec.begin(),vec.end(),print_double);
     
     //find
     // int target = 5;
     // cout << *(find(vec.begin(),vec.end(),target));
     
     //find_if
     // vector<int>::iterator it = find_if(vec.begin(),vec.end(),check_even);
     // cout << *it << endl;

     //count
     // const int target = 5; 
     // int ans = count(vec.begin(),vec.end(),target);
     // cout << "Element : " << target << " occured "<< ans << " times. " << endl;

     //count_if
     // int ans = count_if(vec.begin(),vec.end(),not_even);
     // cout <<  ans;

     vector<int>::iterator it = partition(vec.begin(),vec.end(),check_even);
     for(auto a : vec){
          cout << a << " " ;
     }
     cout << endl;`
     it--;
     while(it>=vec.begin()){
          cout << *it << " " ;
          it--;
     }
     
     
     return 0;
}