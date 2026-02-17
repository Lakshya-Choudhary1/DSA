// #include <iostream>
// #include <vector>

// using namespace std;

// void merge(vector<int> &vec , int s , int e , int mid){
//      //length of both parts leftSub Array and rightSub Array
//      int leftLength = mid-s+1;
//      int rightLength = e-mid;

//      //created new array in heap memory for both parts (DIVIDE)
//      int *leftArr = new int[leftLength];
//      int *rightArr = new int[rightLength];

//      //inserting main array in two subArray
//      int index = s;
//      for (int i = 0; i <leftLength; i++) leftArr[i] = vec[index++];
//      for (int i = 0 ; i<rightLength ; i++) rightArr[i] = vec[index++];   
     
//      //merge Logic
//      int leftStaringIndex = 0;
//      int rightStartingIndex = 0;
//      int mainIndex = s;

//      while(leftStaringIndex < leftLength && rightStartingIndex<rightLength){
//           if(leftArr[leftStaringIndex]<rightArr[rightStartingIndex]){
//                vec[mainIndex] = leftArr[leftStaringIndex++];
//           }else{
//                vec[mainIndex] = rightArr[rightStartingIndex++];
//           }
//           mainIndex++;
//      }

//      while(leftStaringIndex<leftLength){
//           vec[mainIndex++] = leftArr[leftStaringIndex++];
//      } 

//      while(rightStartingIndex<rightLength){
//           vec[mainIndex++] = rightArr[rightStartingIndex++];
//      }
// }

// void mergeSort(vector<int> &vec , int s , int e){
//      if(s>=e) return;  
//      int mid = s+(e-s)/2;
//      mergeSort(vec,s,mid);
//      mergeSort(vec,mid+1,e);
//      merge(vec,s,e,mid);
// }

// int main(){
//      vector<int> vec = {5,1,1,4,6,2,1,5,6};

//      cout << "Before : [" ;
//      for(auto a: vec) {
//           cout << a << ",";
//      }
//      cout << "]" << endl;

//      mergeSort(vec,0,vec.size()-1);

//      cout << "After : [";
//      for(auto a: vec) {
//           cout << a << ",";
//      }
//      cout << "]" << endl;

//      return 0;
// }


#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &vec , int s , int e , int mid){

     //length of both sub array
     int leftLength = mid-s+1;
     int rightLength = e-mid;
     

     //creating heao memory for both subArray
     int *leftArray = new int[leftLength];
     int *rightArray = new int[rightLength];

     //filling valued from main array into two subArray
     int index = s;
     for(int i{0} ; i<leftLength ; i++) leftArray[i] = vec[index++];
     for(int i{0} ; i<rightLength ; i++) rightArray[i] = vec[index++];

     //merge 
     int leftStartingIndex{0};
     int rightStartingIndex{0};
     int mainIndex = s;

     while(leftStartingIndex<leftLength && rightStartingIndex<rightLength){
          if(leftArray[leftStartingIndex] < rightArray[rightStartingIndex]){
               vec[mainIndex++] = leftArray[leftStartingIndex++];
          }else{
               vec[mainIndex++] = rightArray[rightStartingIndex++];
          }
     }

     while(leftStartingIndex<leftLength){
          vec[mainIndex++] = leftArray[leftStartingIndex++];
     }

     while(rightStartingIndex<rightLength){
          vec[mainIndex++] = rightArray[rightStartingIndex++];
     }

     delete[] leftArray;
     delete[] rightArray; 
}

void mergeSort(vector<int> &vec , int s , int e){
     if(s>=e) return;
     int mid = s+((e-s)>>1);
     //leftSubArray
     mergeSort(vec,s,mid);
     //rightSubArray
     mergeSort(vec,mid+1,e);
     //mergeTwoSubArray
     merge(vec,s,e,mid);
}

int main(){
     vector<int> vec = {2,4,6,8,3,5,7,9};
     mergeSort(vec,0,vec.size()-1);
     for(auto a : vec){
          cout << a << "  " ;
     }
     return 0;
}