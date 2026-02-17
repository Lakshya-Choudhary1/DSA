#include <iostream>
#include <vector>
#include <string>

using namespace std;

void combination(const vector<int>& arr,int length , vector<vector<int>>& ans ,vector<int> temp = {} , int index = 0){

     if(temp.size()>=length){
          ans.push_back(temp);
          return;
     }

     if(index>=arr.size()) return;

     for(int i = index ; i<arr.size() ; i++){
          temp.push_back(arr[i]);
          combination(arr,length,ans,temp,i+1);
          temp.pop_back();
     }


}

int main(){
     vector<int> arr = {0,1,2,3,4,5,6};
     vector<vector<int>> ans;
     int length = 2;

     combination(arr,length,ans);

     for(auto a : ans){
          for(auto b : a){
               cout << b << " " ;
          }
          cout << endl;
     }

     return 0;
}