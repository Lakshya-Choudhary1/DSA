#include <iostream>
#include <vector>

using namespace std;

// for ascending order 
// void firstOccurence(){
//      svector<int> arr = { 10,20,20,30,40,50,60};
//      int index = -1;
//      int target{20};
//      for(int start=0,end=arr.size()-1 ; start<=end ;){
//           int mid  = (start + (end-start)/2);
//           if(arr[mid]==target){
//                index = mid;
//                end = mid-1;
//           }else if(arr[mid]>target){
//                end = mid-1;
//           }else if(arr[mid]<target){
//                start = mid+1;
//           }
//      }    
//      if(index != -1){
//           cout << "First occurence found at index : " << index << endl;
//           return;
//      }
//      cout<< "NO ELEMENT EXISTS!" << endl;
// }

//for descending order
// void firstOccurence(){
//      vector<int> arr = {70,60,30,30,30,20,10,5,3};
//      int index = -1;
//      int target{30};
//      int start{0},end{arr.size()-1};
//      while(start<=end){
//           int mid = start + (end-start)/2 ;
//           if(arr[mid]==target){
//                index = mid;
//                end = mid-1;
//           }else if(arr[mid]>target){
//                start = mid+1;
//           }else if(arr[mid]<target){
//                end = mid-1;
//           }
//      }
//      if(index != -1){
//           cout << "ELEMENT FOUND AT INDEX :  " << index << endl;
//      }else{
//           cout << "NO ELEMENT EXISTS!" << endl;
//      }
// }

//last occurence for ascending order
// void firstOccurence(){
//      vector<int> arr = { 10,20,20,30,40,50,60};
//      int index = -1;
//      int target{20};
//      for(int start=0,end=arr.size()-1 ; start<=end ;){
//           int mid  = (start + (end-start)/2);
//           if(arr[mid]==target){
//                index = mid;
//                start = mid+1;
//           }else if(arr[mid]>target){
//                end = mid-1;
//           }else if(arr[mid]<target){
//                start = mid+1;
//           }
//      }    
//      if(index != -1){
//           cout << "First occurence found at index : " << index << endl;
//           return;
//      }
//      cout<< "NO ELEMENT EXISTS!" << endl;
// }

//last occurence for descending order 
// void lastOccurence(){
//      vector<int> arr = {70,60,30,30,30,20,10,5,3};
//      int index = -1;
//      int target{30};
//      int start{0},end{arr.size()-1};
//      while(start<=end){
//           int mid = start + (end-start)/2 ;
//           if(arr[mid]==target){
//                index = mid;
//                start = mid+1;
//           }else if(arr[mid]>target){
//                start = mid+1;
//           }else if(arr[mid]<target){
//                end = mid-1;
//           }
//      }
//      if(index != -1){
//           cout << "ELEMENT FOUND AT INDEX :  " << index << endl;
//      }else{
//           cout << "NO ELEMENT EXISTS!" << endl;
//      }
// }

int main(){
//   firstOccurence();
//   lastOccurence();

     return 0;
} 