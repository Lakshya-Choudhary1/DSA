#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> vec)
{
     for(int i{0}  ; i < int(vec.size()) ; i++) cout << vec[i] << "," ;
     cout << endl;
}

void maxHeap(vector<int>& vec , int index){
     int size = vec.size();
     while(true){
          int largest = index;
          int left = 2*index + 1;
          int right = 2*index + 2;

          if(left < size && vec[left] > vec[largest]){
               largest = left;
          }

          if(right < size && vec[right] > vec[largest]){
               largest = right;
          }

          if(largest == index){
               break;
          }

          swap(vec[index],vec[largest]);

          index = largest;
     }

}

void buildHeap(vector<int>& vec){
     for(int i = vec.size()/2 - 1 ; i>=0 ; i-- ){
          maxHeap(vec,i);
     }
}

void heapSort(vector<int> vec , vector<int>& ans){
     while(!vec.empty()){

          ans.push_back(vec.front());
          swap(vec[0],vec[int(vec.size()-1)]);

          vec.pop_back();

          maxHeap(vec,0);

     }
}

int main(){
     vector<int> vec {10,40,50,60,30,20};

     cout << "Before Heap" << endl;
     print(vec);

     cout << "After Heap" << endl;
     buildHeap(vec);
     print(vec);

     cout << "Heap Sort" << endl;
     vector<int> ans;
     heapSort(vec,ans);
     print(ans);

     return 0;
}