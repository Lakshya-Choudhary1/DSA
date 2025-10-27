#include <iostream>
using namespace std;

int  findFirstOccurence(int [],int,int);
int findLastOccurence(int [],int,int);
int findTotalOccurence(int [],int,int);
int findMissingIndex(int [],int);
int findPeakElementInMountainArray(int [],int);
int findPivetIndex(int [],int);

int main(){

     return 0;
}

int findPivetIndex(int arr[],int size){
     for(int start{0},end=size-1 ; start<=end ; ){
          int mid = start + (end-start)/2;
          if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
               return mid;
          }else if(arr[mid]<arr[0]){
               end = mid-1;
          }else{
               start = mid+1;
          }
     }
     return -1;
}
int  findFirstOccurence(int arr[],int size,int target){
     int start{0};
     int end{size-1};
     int ans = -1;
     while(start<=end){
          int mid = start + (end-start)/2;
          if(arr[mid]==target){
               ans = mid;
               end = mid-1;
          }else if(arr[mid]>target){
               end = mid-1;
          }else{
               start = mid+1;
          }
     }

     return ans;
}
int findLastOccurence(int arr[],int size,int target){
     int start{0},end{size-1};
     int ans = -1;
     while(start<=end){
          int mid = start + (end-start)/2;
          if(arr[mid]==target){
               ans=mid;
               start = mid+1;
          }else if(arr[mid]<target){
               start=mid+1;
          }else{
               end = mid-1;
          }
     }
     return ans;
}
int findTotalOccurence(int arr[],int size,int target){
     int startingIndex = findFirstOccurence(arr,size,target);
     int endingIndex = findLastOccurence(arr,size,target);

     int totalOccurence = endingIndex-startingIndex+1;

     return totalOccurence;
}
int findMissingIndex(int arr[],int size){
     int start{0},end{size-1};
     int missingIndex{-1};

     while(start<=end){
          int mid = start +(end-start)/2;
          if(mid-arr[mid] == 0){
               //move right
               start = mid+1;
          }else {
               //store and move left
               missingIndex = mid;
               end = mid-1;
          }
     }

     if(missingIndex != -1){
          return missingIndex;
     }else {
          return size;
     }
}
int findPeakElementInMountainArray(int arr[],int size){
     int start{0},end=size-1;

     while (start<=end){
          int mid = start + (end-start)/2;
          if(arr[mid] > arr[mid-1] && arr[mid]>arr[mid+1]){
               return arr[mid];
          }else if(arr[mid]>arr[mid+1]){
               //we are in rigtht ---> move left
               end = mid-1;
          }else if(arr[mid]<arr[mid+1]){
               //we are in left ---> move right
               start = mid+1;
          }
     }
     return -1;
}