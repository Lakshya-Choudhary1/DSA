#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr){
     for(unsigned int i{0} ; i<arr.size() ; i++)
          for(unsigned int j{0} ; j<arr.size()-1-i ; j++)
               if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
}

int main(){
     vector<int> arr {1,4,2,3,5,6,9,7,8};
     bubbleSort(arr);
     for(auto a: arr) cout << a << " " ;
     return 0;
}