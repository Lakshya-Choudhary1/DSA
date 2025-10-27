#include <iostream>
#include <vector>

using namespace std;

//PRINTING 
void printVector(vector<int>);
void printArray(int [],int);
// BUBBLE SORT
void bubbleSortArray(int [],int &);
void bubbleSortVector(vector<int>&);
//SELECTION SORT
void selectionSortArray(int [],int);
void selectionSortVector(vector<int>&);
//INSERTION SORT
void insertionSortArray(int [],int);
void insertionSortVector(vector<int>&);
int main(){
     int arr[] ={7,4,7,3,3,2,5,6,1}; 
     vector<int> vec = {2,35,6,3,5,23,5,2,5,3,65,76};
     int n = sizeof(arr)/sizeof(arr[0]);

     // insertionSortArray(arr,n);
     // printArray(arr,n);

     insertionSortVector(vec);
     printVector(vec);
     
 
 
     return 0;
}



void printVector(vector<int>vec){
     cout << "--------------------------------" << endl;
     for(unsigned int i{0} ; i<vec.size() ; i++){
          cout << "VEC[" << i+1 << "] = " << vec[i] << endl;
     }
     cout << "--------------------------------" << endl;
}

void printArray(int arr[],int n){
     cout << "--------------------------------" << endl;
     for(int i{0} ; i<n ; i++){
          cout << "ARR[" << i+1 << "] = " << arr[i] << endl;
     }
     cout << "--------------------------------" << endl;
}

void bubbleSortArray(int arr[],int &n){
     for(int i = 0 ; i<n-1 ; i++){
          for(int j = 0 ; j<n-1-i ; j++){
               if(arr[j]>arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
               }
          }
     }
}

void bubbleSortVector(vector<int> &vec){
     for(unsigned int i = 0 ; i < vec.size()-1 ; i++){
          for(unsigned int j = 0 ; j < vec.size()-1 ; j++){
               if(vec[j+1]<vec[j]){
                    int temp = vec[j+1];
                    vec[j+1] = vec[j];
                    vec[j] = temp;
               }
          }
     }
}

void selectionSortArray(int arr[],int n){
     for(int i{0} ; i<n-1 ; i++){
          int smallestValueIndex =i;
          for(int j{i+1} ; j<n ; j++){
               if(arr[j] < arr[smallestValueIndex]){
                    smallestValueIndex = j ;
               }
          }
          swap(arr[i],arr[smallestValueIndex]);
     }
}

void selectionSortVector(vector<int>&vec){
     for(unsigned int i{0} ; i<vec.size()-1 ; i++){
          int smallestValueIndex=i;
          for(unsigned int j {i+1} ; j<vec.size() ;j++){
               if(vec[j] < vec[smallestValueIndex]){
                    smallestValueIndex = j;
               }
          }
          swap(vec[i],vec[smallestValueIndex]);
     }
}

void insertionSortArray(int arr[],int n){
     for(int i {1} ; i<n ; i++){
          int key = arr[i];
          int  j = i-1;
          while(j>=0 && arr[j]>key){
               arr[j+1] = arr[j];
               j--;
          }
          arr[j+1] = key;
     }
}

void insertionSortVector(vector<int> &vec){
     for(unsigned int i{1} ; i<vec.size() ; i++){
          int key = vec[i];
          int j = i-1;
          while(j>=0 && vec[j]>key){
               vec[j+1] = vec[j];
               j--;
          }
          vec[j+1]=key;
     }
}