#include <iostream>
#include <vector>

using namespace std;

void pattern_util(vector<int> &vec , int start , int end){
     if(end>=vec.size()) return;

     for(int i{start} ; i<=end ; i++)
          cout << vec[i] << " " ; 
     
     cout << endl;
     pattern_util(vec,start,end+1);
}

void pattern(vector<int>& vec){
     for(int start{0} ; start<vec.size() ;start++){
          int end = start;
          pattern_util(vec,start,end);
     }
}

int main(){
     vector<int> vec = {1,2,3,4,5};

     pattern(vec);
     
     return 0;
}