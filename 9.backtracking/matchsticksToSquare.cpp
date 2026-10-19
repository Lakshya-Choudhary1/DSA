#include <iostream>
#include <string>
#include <numeric>
#include <vector>

using namespace std;

//i indicates the index in matchsticks vector initially zero
bool solveProblem(vector<int>&matchsticks, vector<int>&sides , int i ){

     if(i==matchsticks.size()){
          return sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0;
     }

     
     for(int j = 0 ; j<4 ; j++){
          if(sides[j]>=matchsticks[i]){
               sides[j] -= matchsticks[i];
               if(solveProblem(matchsticks,sides,i+1)) return true;
               sides[j] += matchsticks[i];
          }
     }
      
     return false;
}

void solve(vector<int>&matchsticks){
     int sum = accumulate(matchsticks.begin(), matchsticks.end(),0);
     if(sum%4 != 0 || matchsticks.size()<4) return ;
     vector<int> sides(4,sum/4);
     bool ans = solveProblem(matchsticks,sides,0) ;
     
     if(ans)  cout << "IS VALID SOLUTION" << endl;
      
}

int main(){
     vector<int> matchsticks {1,1,2,2,2};
     solve(matchsticks);
     return 0;
}
