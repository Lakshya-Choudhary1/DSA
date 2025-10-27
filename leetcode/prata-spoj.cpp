#include <iostream>
#include <vector>

using namespace std;

bool isPossibleSolution(vector<int> & , int & , int & );

int main(){
     int prata {10};
     vector<int> cooks = {1,2,3,4};
     int ans{-1};
     int start{0};
     int end = cooks[cooks.size()-1] * (prata*(prata+1)/2);

     while(start<=end){
          int mid = start + ((end-start) >> 1) ;

          if(isPossibleSolution(cooks,prata,mid)){
               ans = mid;
               end = mid-1;
          }else{
               start = mid+1;
          }
     }

     cout << "------------------------" << endl;
     cout << cooks[cooks.size()-1] * (prata * (prata+1)/2) << endl;
     cout << "ANS : " << ans << endl;

     return 0;
}

bool isPossibleSolution(vector<int> &cooks , int  &prata , int &sol){
     int currP{0};
     for(int i =  0 ; i<cooks.size() ; i++){
          int cookTime {0};
          int r = cooks[i];
          int j = 1;

          while(true){
               if(cookTime + j*r <= sol){
                    cookTime += j*r;
                    currP++;
                    j++;
               }else{
                    break;
               }
               if(currP >= prata) return true;
          }
     }
     return false;
}