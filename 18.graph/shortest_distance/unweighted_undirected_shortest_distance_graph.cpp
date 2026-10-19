#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(const vector<vector<int>>& edges,const int& V,const int& src){
     //creating adj list
     vector<vector<int>> adj_list(V);
     for(vector<int> edge : edges){
          int u = edge[0] , v = edge[1];
          adj_list[u].push_back(v);
          adj_list[v].push_back(u);
     }

     //storing path
     vector<int> dist(V,-1);
     dist[src] = 0;

     //bfs queue
     queue<int> que;
     que.push(src);

     while(!que.empty()){
          int front = que.front();
          que.pop();

          for(int nbr : adj_list[front]){
               if(dist[nbr] == -1){
                    que.push(nbr);
                    dist[nbr] = 1 + dist[front];
               }
          }
     }
     
     return dist;
}

void dfs_helper(vector<vector<int>>& adj_list,const int& V,vector<int>& dist,const int& src){

     for(int nbr : adj_list[src]){
               if(dist[nbr] == -1 || dist[nbr] > 1 + dist[src] ){
                    dist[nbr] = 1 + dist[src];
                    dfs_helper(adj_list,V,dist,nbr);
               }
          }

}

vector<int> dfs(const vector<vector<int>>& edges,const int& V,const int& src){
     vector<vector<int>> adj_list(V);
     for(vector<int> edge : edges){
          int u = edge[0] , v = edge[1];
          adj_list[u].push_back(v);
          adj_list[v].push_back(u);
     }

     //storing path
     vector<int> dist(V,-1);
     dist[src] = 0;

     dfs_helper(adj_list,V,dist,src);

     return dist;
}

int main(){

    const  vector<vector<int>> edges {{0,1},{1,2},{2,3},{3,7},{7,6},{3,4},{4,6},{3,5}};

     const int V = 8;

     //destination of vertex from src node
     int src_vertex = 0;
     vector<int> ans = bfs(edges,V,src_vertex);

     cout << "SHORTEST PATH OF VERTEX's FROM SRC VERTEX" << endl;
     cout << "SRC VERTEX : " << src_vertex << endl;
     
     for(int i=0 ; i<V ; i++){
          cout << "SOURCE : " << src_vertex << " , DESTINATION : " << i << " , DISTANCE : " << ans[i]  << endl;
     }

     {

     
     int src_vertex = 0;
     vector<int> ans = dfs(edges,V,src_vertex);

     cout << "SHORTEST PATH OF VERTEX's FROM SRC VERTEX" << endl;
     cout << "SRC VERTEX : " << src_vertex << endl;
     
     for(int i=0 ; i<V ; i++){
          cout << "SOURCE : " << src_vertex << " , DESTINATION : " << i << " , DISTANCE : " << ans[i]  << endl;
     }

     }

    

     return 0;
}