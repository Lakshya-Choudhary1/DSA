#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int> &arr,vector<int> &brr , vector<int> &ans){
     int a{0} , b{0} ;
     while(a<arr.size() && b<brr.size() ){
          if(arr[a]<brr[b]){
               ans.push_back(arr[a++]);
          }else{
               ans.push_back(brr[b++]);
          }
     }
     while(a<arr.size()) ans.push_back(arr[a++]);
     while(b<brr.size()) ans.push_back(brr[b++]);
}

int main(){
     vector<int> arr{20,40,60,80,90,100,100} , brr{10,30,50,70,88} , ans;
     mergeSort(arr,brr,ans);

     for(auto a : ans){
          cout << a << "  " ;
     }

     return 0;
}