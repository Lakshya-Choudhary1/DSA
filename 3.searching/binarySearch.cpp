#include <iostream>
using namespace std;

// for ascending order array date
void binarySearch1(int arr[],int length , int target){
     int start{0},end{length-1};
     while(start<=end){
          int mid=(start+end)/2;
          if(arr[mid]==target){
               cout << "ELEMENT FOUND :" << arr[mid] << " AT INDEX : " << mid << endl;
               return;
          }else if(arr[mid]<target){
               start = mid+1;
          }else{
               end=mid-1;
          }
     }
     cout << "ELEMENT NOT FOUND";
}


//for descending order array data
void binarySearch2(int arr[],int length , int target){
     for(int start{0},end{length-1};start<=end;){
          int mid = (start+end)/2;
          if(arr[mid]==target){
               cout << "ELEMENT FOUND :" << arr[mid] << " AT INDEX : " << mid << endl;
               return;
          }else if(arr[mid]>target){
               start = mid+1;
          }else if(arr[mid]<target){
               end = mid-1;
          }
     }
     cout << "ELEMENT NOT FOUND" << endl;
}

int main(){

     int arr1[]={2,8,10,20,30,34,46,78,100};    //ascending order
     int arr2[]={100,78,46,34,30,20,10,8,2};  //decending order
     
     int size1 = sizeof(arr1)/sizeof(arr1[0]);
     int size2 = sizeof(arr2)/sizeof(arr2[0]);
     int target = 2;
     binarySearch1(arr1,size1,target);
     binarySearch2(arr2,size2,target);

     return 0;
}