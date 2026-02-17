#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> & arr , int start , int end){

     if(start>=end) return;

     int pivot = end;
     int i = start-1;
     int j = start;

     while(j<pivot){
          if(arr[j]<arr[pivot]){
               i++;
               swap(arr[i],arr[j]);
          }
          j++;
     }

     i++;
     swap(arr[i],arr[pivot]);

     quickSort(arr,start,i-1);
     quickSort(arr,i+1,end);
}


int main(){
     vector<int> arr = {1,5,2,3,2,6};
     int start = 0 ;
     int end = arr.size()-1;

     cout << "BEFORE : " ;
     for(auto a : arr){
          cout << a << "\t" ;
     }
     cout << endl;


     quickSort(arr,start,end);

     cout << "AFTER : " ;
     for(auto a : arr){
          cout << a << "\t" ;
     }
     cout << endl;
     

     return 0;
}