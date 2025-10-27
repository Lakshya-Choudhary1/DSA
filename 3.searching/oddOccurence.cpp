#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int,int>findOddOccurence(vector<int>);

int main(){
     vector<int> arr = {1,1,2,2,3,3,4,4,5,5,3,3,8};
     pair<int,int> ans = findOddOccurence(arr);
     cout << "INDEX: " << ans.first << " AND ELEMENT: " << ans.second << endl;
     return 0;
}

pair<int,int>findOddOccurence(vector<int> arr){
     int size = arr.size() - 1;
     for(int start{0},end=size;start<=end;){
          int mid = start + (end-start)/2;
          if ((mid == 0 || arr[mid] != arr[mid - 1]) &&
            ((mid == size) || arr[mid] != arr[mid + 1])) {
            return {mid, arr[mid]};
        }
           if(arr[mid]==arr[mid-1]){
               if(((mid-1)&1) == 0){ //we are in left part so move right
                    start = mid+1;
               }else{//we are in right part so move left
                    end = mid-2;
               }
          }else if(arr[mid]==arr[mid+1]){
               if((mid&1)==0){ //we are in left part move right
                    start = mid+2;
               }else{//we are in right part move left
                    end = mid-1;
               }
          }
     }
     return {-1,-1};
}