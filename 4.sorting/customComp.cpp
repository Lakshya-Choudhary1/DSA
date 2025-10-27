#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

void printvv(vector<vector<int>> vec){
     for(unsigned int i{0} ; i<vec.size() ;i++){
          for(unsigned int j{0} ; j<vec[i].size() ; j++){
               cout << vec[i][j] << " ";
          }
          cout << endl;
     }
}

bool myComp(vector<int> &a ,vector<int> &b ){
      return a[1] < b[1] ; //increading order sorting 
}

int main(){
     vector<vector<int>> vec ;
     int size;
     cout << "enter size : " << endl;
     cin >> size ;

     for(int i {0} ; i<size ; i++){
          int a , b;
          vector<int> temp;
          cout << "enter temp a and b : " ;
          cin >> a >> b ;
          temp.push_back(a);
          temp.push_back(b);
          vec.push_back(temp);
          cout << endl;
     }


     sort(vec.begin(),vec.end(),myComp);

     printvv(vec);

     return 0;
}