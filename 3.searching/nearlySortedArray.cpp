#include <iostream>
#include <algorithm>
using namespace std;

pair<bool,int> applyBinarySearch(int arr[],int &size,int &target){
     int start = 0;
     int end = size-1;

     while(start<=end){
          int mid = start + (end-start)/2;
          if(arr[mid]==target){
               return {true,mid};
          }
          if(arr[mid-1]==target){
               return {true,mid-1};
          }
          if(arr[mid+1]==target){
               return {true,mid+1};
          }
          if(arr[mid]>target){
               //move left
               end = mid-2;
          }else if(arr[mid]<target){
               //move right
               start = mid+2;
          }
     }
     
     return {false,-1};
}

int main(){
     int arr[] = {10,3,40,20,50,80,70};
     int size = sizeof(arr)/sizeof(arr[0]);
     int target = 70;

     pair<bool,int> found = applyBinarySearch( arr,size,target);
     
     if(found.first){
          cout << "FOUND AT INDEX : " << found.second << endl;
     }else if(!found.first){
          cout << "NOT FOUND" << endl;
     }


     return 0;
}