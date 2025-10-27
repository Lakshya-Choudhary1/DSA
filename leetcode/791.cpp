#include <iostream>
#include <vector>
using namespace std;

int main(){
     vector<int> nums = {1,2,3,4,5};
     vector<int> arr;
     int x = 3;
     int k= 4;
     int start{0};
     int end = nums.size()-1;
     int index = -1;
     while(start<=end){
          int mid = start + (end-start)/2;
           if(nums[mid]<x){
               index = mid;
               start = mid+1;
          }else{
               end = mid-1;
          }
     }

     int h = index;
     int l = index-1;
     while(h-l<=k){
          if(abs(nums[l]-x)>abs(nums[h]-x)){
               h++;
          }else{
               l--;
          }
     }

     for(int i=l+1 ; i<h  ; i++){
          arr.push_back(nums[i]);
     }

     

     return 0;
}