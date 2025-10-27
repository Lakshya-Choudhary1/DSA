#include <iostream>

using namespace std;

//return index 
int exponentialRange(int arr[],int &size , int &target){
     if(arr[0]==target) return 0;
     int i{1};
     while(i<size && arr[i]<=target) i*=2;
     return i;
}
int binarySearch(int arr[],int &size , int &target){
     //finding min subarray
     int i = exponentialRange(arr,size,target);
     if(i==0) return 0;
     int start = i/2 , end = min(size-1,i);
     while(start<=end){
          int mid = start + (end-start)/2;
          if(arr[mid] == target){
               cout << "TARGET FOUND!!!" << endl;
               return mid;
          }else if(arr[mid]<target){//arr[mid] is less than target so move start moves to right
               start = mid+1;
          }else{
               end = mid-1;
          }
     }
     cout << "TARGET NOT FOUND!!!" << endl;
     return -1;
}
int main(){
     int arr[] = {1,2,3,4,5,6,7,8,9,10};
     int arrSize = sizeof(arr)/sizeof(arr[0]);
     int target = 10;
     int index = binarySearch(arr,arrSize,target);
     cout << "INDEX AND ELEMENT : " << index << "|||" << arr[index] << endl;
     return 0;
}