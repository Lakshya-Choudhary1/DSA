#include <iostream>
#include <vector>

using namespace std;

int main(){
     vector<int> a = {1,2,3,5,7};
     vector<int> b = {1,2,3,4,6};
     vector<int> ans;

     int a_index{0};
     int b_index{0};

     while(a_index<a.size() && b_index<b.size()){
          if(a[a_index]<=b[b_index]){
               ans.push_back(a[a_index++]);
          }else{
               ans.push_back(b[b_index++]);
          }
     }

     while(a_index<a.size()){
          ans.push_back(a[a_index++]);
     }

     while(b_index<b.size()){
          ans.push_back(b[b_index++]);
     }    

     for(auto it : ans ){
          cout << it << "  " ;
     }

     return 0;
}