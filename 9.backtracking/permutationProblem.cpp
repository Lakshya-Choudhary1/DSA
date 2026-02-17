#include <iostream>
#include <string>
#include <vector>

using namespace std;

void permutaion(vector<int> vec , int index ,vector<vector<int>> &ans , int &count){
     if(index>=(signed)vec.size()-1){
          ans.push_back(vec);
          count++;
          return;
     }

     for(int i{index} ; i<(signed)vec.size() ; i++){
          swap(vec[index],vec[i]);
          permutaion(vec,index+1,ans,count);
     }
}

int main(){

     vector<int> vec {1,2,3};
     vector<vector<int>> ans;
     int index{0};
     int count{0};

     permutaion(vec,index,ans,count);

     for(int i{0} ; i<(signed)ans.size() ; i++){
          for(int j{0} ; j<(signed)ans[i].size() ; j++){
               cout << ans[i][j] << "," ;
          }
          cout << endl;
     }

     cout << "TOTAL COUNT : " << count << endl;

     return 0;
}