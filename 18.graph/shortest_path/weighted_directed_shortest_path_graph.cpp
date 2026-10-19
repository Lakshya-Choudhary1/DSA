//shortest path in weighted and directed graph using dijkastra algorithm

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;

// u : {{v,w},{v,w}}
void dfs(const vector<vector<pair<int,int>>>& adj,vector<bool>& visited,   stack <int>& stk,int src){

     visited[src] = true;

     for(pair<int,int> nbr : adj[src]){
          if(!visited[nbr.first]){
               dfs(adj,visited,stk,nbr.first);
          }
     }

     stk.push(src);
     
}

void shortest_path_and_distance(const vector<vector<int>>& edges,const int& V){

     vector<bool> visited(V,false);
     stack<int> stk;
     vector<vector<pair<int,int>>> adj(V);

     for(vector<int> edge : edges){
          int u = edge[0] ,
              v = edge[1],
              w = edge[2];
          adj[u].push_back({v,w});
     }

     for(int i = 0 ; i<V ; i++){
          if(!visited[i]){
               dfs(adj,visited,stk,i);
          }
     }

     vector<int> parent(V,-1);
     vector<int> dist(V,INT_MAX);

     int src = 0;

     dist[src] = 0;


     while(!stk.empty()){

          int u = stk.top();
          stk.pop();

          for(pair<int,int> nbr : adj[u]){
               int v = nbr.first;
               int w = nbr.second;

               if(dist[u] == INT_MAX) continue;

               if(dist[u] + w < dist[v]){
                    parent[v] = u;
                    dist[v] = dist[u] + w;
               }
          }

     }
     

     cout << "DISTANCE : "; 
     for(auto d : dist){
          cout << d << " , " ;
     }
     cout << endl;


     cout << "PARENT : "; 
     for(auto p : parent){
          cout << p << " , " ;
     }
     cout << endl;

     vector<int> path;
     for(int i = 2 ; i != -1 ;  ){
          path.push_back(i);
          i = parent[i];
     }

     cout << "path from 0,2 : " ;
     reverse(path.begin(),path.end());
     for(int i : path){
          cout << i << " , " ;
     }
     cout << endl;


}

int main(){

     vector<vector<int>> edges {
          {0,2,13},
          {0,1,5},
          {1,2,7},
          {0,4,3},
          {1,4,1},
          {4,3,6},
          {3,2,2}
     };
     int V =5;

     shortest_path_and_distance(edges,V);
     

     return 0;
}