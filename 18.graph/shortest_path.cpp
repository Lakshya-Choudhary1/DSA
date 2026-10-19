#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<vector<int>>& adjList,int u,int v,bool directed){

     adjList[u].push_back(v);

     if(!directed){
          adjList[v].push_back(u); 
     }

}

void print(const vector<vector<int>>& adjList){
     int v = adjList.size();

     for(int i{0} ; i<v ; i++){

          cout << i << " : [ " ;

          for(int j : adjList[i]){
               cout << j << " , " ;
          }

          cout << " ] " << endl;
     }

}

int main(){

     int v = 5;
     vector<vector<int>> adjList(v);

     addEdge(adjList,0,1,true);

     print(adjList);



     return 0;
}