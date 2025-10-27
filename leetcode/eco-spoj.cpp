#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool isPossibleSolution(vector<int> &,int &,int &);

int main(){
     vector<int> trees = {4 ,42 ,40 ,26 ,46};
     sort(trees.begin(),trees.end());

     int reqiredTree {20},height{-1},start{0},end=trees[trees.size()-1];
         
     while(start<=end){
          int mid = start + ((end - start) >> 1 );
          if(isPossibleSolution(trees,reqiredTree,mid)){
              //move right to find max height of sawBlade to get requiredTree
               height = mid;
               start = mid+1;
          }else{
               //move left 
               end = mid-1;
          }
     }
     return 0;
}

bool isPossibleSolution(vector<int> &trees, int &reqiredTree , int &solution){
     int stack{0};
     for(int it : trees){
          if(it > solution){
               stack += it-solution;
               if(stack >= reqiredTree) return true;
          }
     }
     return false;
}