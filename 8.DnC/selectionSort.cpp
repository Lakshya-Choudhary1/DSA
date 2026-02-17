#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr){
     int smallestIndex;
     for(unsigned int i{0} ; i<arr.size() ; i++){
          smallestIndex = i ;
          for(unsigned int j = i+1 ; j<arr.size() ; j++)
               if(arr[j]<arr[smallestIndex]) smallestIndex = j ;
          swap(arr[i],arr[smallestIndex]);
     }
}

int main(){
     vector<int> arr{1,3,5,2,6,4,9,8,7,8};
     selectionSort(arr);
     for(auto a: arr) cout << a << " " ;
     return 0;
}