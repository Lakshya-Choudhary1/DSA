#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

void shortest_path_using_bfs(vector<vector<int>>& edges , int& V , int& src , int& dist){

     vector<int> parent(V,-1); //used to find path
     vector<int> visited(V,false); //mark visited
     vector<vector<int>> adj_list(V); // adjenecy list

     //making adj_list
     for(int i{0} ; i< int(edges.size()) ; i++){
          int u = edges[i][0] , v = edges[i][1];
          adj_list[u].push_back(v);
          adj_list[v].push_back(u);
     }
     
     queue<int> que;
     que.push(src);

     visited[src] = true;

     while(!que.empty()){
          int front = que.front();
          que.pop();
          for(int nbr : adj_list[front]){
               if(!visited[nbr]){
                    visited[nbr] = true;
                    parent[nbr] = front;
                    que.push(nbr);
               }
          }
     }

     //loop front dest to src and reverse to get shortest path

     int d = dist;
     vector<int> path;

     while(d!=-1){
          path.push_back(d);
          d = parent[d];
     }

     reverse(path.begin(),path.end());

     for(auto p : path){
          cout << p << "->" ;
     }

}

int main(){

     vector<vector<int>> edges {{0,1},{1,2},{2,3},{2,4},{4,5},{3,5}};
     
     int V = 6;
     int src = 0;
     int dist = 3;

     shortest_path_using_bfs(edges,V,src,dist);

     return 0;
}