#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <list>

using namespace std;

//directed unweighted graph
class Graph{

     private : 
          vector<vector<int>> g;

     public:
     
     void addEdge(int u, int v){
          g[u].push_back(v);
     };

     //helper function for dfs 
     void dfs_helper(int node, unordered_map<int,bool>& visited){

          visited[node] = true;
          cout << node << " , " ;

          vector<int> nbrs = g[node];
          
          for(int nbr : nbrs) {
               if(!visited[nbr]){
                    dfs_helper(nbr,visited);
               }
          }
          
     };

     //main dfs member function
     void dfs(){
          //maintain visited
          unordered_map<int,bool> visited;

          int n = g.size();

          cout << "DFS TRAVERSAL : " ;

          for(int i{0} ; i<n ; i++){
               if(!visited[i] && !g[i].empty()){
                    dfs_helper(i,visited);
               }
          }

          cout << endl;

     };

     //helper function for bfs
     void bfs_helper(unordered_map<int,bool>& visited, queue<int>& que){


          while(!que.empty()){

               int front = que.front();
               que.pop();

               cout << front << " , " ;

               for(int nbr : g[front]){
                    if(!visited[nbr]){
                         que.push(nbr);
                         visited[nbr] = true;
                    }
               }

          }

     };
     
     //main bfs member function
     void bfs(){
          
          unordered_map<int,bool>visited;
          queue<int> que;

          cout << " BFS TRAVERSAL : " ;

          for(int i{0} ; i< int(g.size()); i++){
               if(!g[i].empty() && !visited[i]){
                    que.push(i);
                    visited[i] = true;
                    bfs_helper(visited,que);
               }
          }

          cout << endl;


     };

     //helper function for cycle detection using dfs
     bool cycle_detection_using_dfs_helper(unordered_map<int,bool>& visited,
          unordered_map<int,bool>& path,int node){

               visited[node] = true;
               path[node] = true;

               for(int nbrs : g[node]){
                    if(!visited[nbrs]){
                         if(cycle_detection_using_dfs_helper(visited,path,nbrs)){
                              return true;
                         }
                    }else if(path[nbrs]){
                         return true;
                    }
               }

               path[node] = false;

          return false;
     };

     //main cycle detection function using dfs
     void cycle_detection_using_dfs(){
          //track visited and path
          unordered_map<int,bool> visited;
          unordered_map<int,bool> path;

          for(int i{0} ; i< int(g.size()) ; i++){
               if(!visited[i]){
                    if(cycle_detection_using_dfs_helper(visited,path,i)){
                         cout << "CYCLE DETECTED IN DIRECTED ADJ LIST GRAPH USING DFS." << endl;
                         return;
                    }
               }
          }
 
          cout << "NO CYCLE DETECTED IN DIRECTED ADJ LIST GRAPH USING DFS." << endl; 
     };

     //helper function for cycle detection using bfs
     bool cycle_detection_using_bfs_helper(queue<int>& que,
          unordered_map<int,bool>& visited,
          unordered_map<int,bool>& path, int node){

               que.push(node);
               visited[node] = true;
               path[node] = true;

               while (!que.empty())
               {
                    int current = que.front();
                    que.pop();

                    for(auto nbrs : g[current]){
                         if(!visited[nbrs]){
                              que.push(nbrs);
                              visited[nbrs] = true;
                              path[nbrs] = true;
                         }else if(path[nbrs]){
                              return true;
                         }
                    }  
                    
               }
               path[node] = false;
               return false;
     };

     //main cycle detection function using bfs
     void cycle_detection_using_bfs(){
          //maintain queue , visited and path

          queue<int> que;
          unordered_map<int,bool> visited;
          unordered_map<int,bool> path;

          for(int i{0} ; i< int(g.size()) ; i++){
               if(!visited[i]){
                    if(cycle_detection_using_bfs_helper(que,visited,path,i)){
                         cout << "CYCLE DETECTED IN DIRECTED ADJ LIST GRAPH USING BFS." << endl;
                         return ;
                    }
               }
          }
               
          cout << "NO CYCLE DETECTED IN DIRECTED ADJ LIST GRAPH USING BFS." << endl;
     }; 

     friend void print(const Graph& graph);

     Graph(int v) : g(v) {}

};

void print(const Graph& graph){
     int n = graph.g.size();

     for(int i{0} ; i<n ; i++){
          cout << i << " : [ " ; 

          for(int nbr : graph.g[i]){
               cout << nbr << "," ;
          }

          cout <<  " ] " << endl;
     }

}


int main(){

     Graph g{5};

     g.addEdge(0,1);
     g.addEdge(1,2);
     g.addEdge(2,3);
     g.addEdge(3,4);
     

     print(g);

     g.dfs();
     g.bfs();

     g.cycle_detection_using_dfs();
     g.cycle_detection_using_bfs();

     return 0;
}