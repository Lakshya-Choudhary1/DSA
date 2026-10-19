//unweighted and undirected graph

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>


using namespace std;

class Graph{
     private:

          unordered_map<int,vector<int>> g;

     public:
          void addEdge(int u , int v){
               g[u].push_back(v);
               g[v].push_back(u);
          }

          void print(){
               for(pair<int,vector<int>> m : g){
                    cout << m.first << ": { ";
                    
                    for(int vertex : m.second){
                         cout << vertex << " , " ;
                    }

                    cout << " } " << endl;
               }
          }

          void bfs_helper(queue<int>& que, unordered_map<int,bool>& visited){

               while(!que.empty()){

                    for(int vertex : g[que.front()]){
                         if(!visited[vertex]){
                              que.push(vertex);
                              visited[vertex] = true;
                         }
                    }

                    cout << que.front() << " , " ;
                    que.pop();
               }

          }

          void bfs(){

               queue<int> que;
               unordered_map<int,bool> visited;


               cout << "BFS : { " ;

               for(pair<int,vector<int>> m : g){
                    if(!visited[m.first]){
                         que.push(m.first);
                         visited[m.first] = true;
                         bfs_helper(que,visited);
                    }
               }
    
               cout << " } " << endl;

          }

          void dfs_helper(unordered_map<int,bool>& visited , int vertex){
                
               cout << vertex << " , " ;
               visited[vertex] = true;

               for(int node : g[vertex]){
                    if(!visited[node]){
                         dfs_helper(visited,node);
                    }
               }

          }

          void dfs(){
               unordered_map<int,bool> visited;

               cout << "DFS : { " ;
               for(pair<int,vector<int>> m : g){
                    if(!visited[m.first]){
                         int vertex = m.first;
                         dfs_helper(visited,vertex);
                    }
               }
               cout << " } " ;
          }

          bool detect_cycle_using_bfs_helper(unordered_map<int,bool>& visited,
               unordered_map<int,int>& parent, queue<int>& q){

                    bool ans = false;
                    while (!q.empty())
                    {
                         int front = q.front();

                         for(int vertex : g[front]){

                              if(!visited[vertex]){
                                   parent[vertex] = front;
                                   visited[vertex] = true;
                                   q.push(vertex);
                              }else if(parent[front] != vertex){
                                   ans = true;
                                   break;
                              }

                         }
                         
                         q.pop();
                    }

               return ans;
          }

          void detect_cycle_using_bfs(){
               unordered_map<int,bool> visited;
               unordered_map<int,int> parent;
               queue<int> q;

               int ans = false;
               for(pair<int,vector<int>> n : g ){
                    if(!visited[n.first]){
                         q.push(n.first);
                         parent[n.first] = -1;
                         visited[n.first] = true;
                         ans = detect_cycle_using_bfs_helper(visited,parent,q);
                         if(ans)break;
                    }
               }

               cout <<  endl;
               if(ans){
                    cout << "CYCLE  PRESENT" << endl;
               }else{
                    cout << "CYCLE NOT PRESENT" << endl;
               }

          }

          bool detect_cycle_using_dfs_helper(unordered_map<int,bool>& visited,
               unordered_map<int,int>& parent,int node){

                    for(int child : g[node]){
                         if(!visited[child]){
                              parent[child] = node;
                              visited[child] = true;
                            bool ans =  detect_cycle_using_dfs_helper(visited,parent,child);

                             if(ans) return true;

                         }else if( child != parent[node] ){
                              return true;
                         }
                    }

                    return false;
          }

          void detect_cycle_using_dfs(){

               unordered_map<int,bool> visited;
               unordered_map<int,int> parent;

               bool ans{false};

               for(pair<int,vector<int>> m : g ){
                    if(!visited[m.first]){
                         visited[m.first] = true;
                         parent[m.first] = -1;

                         ans = detect_cycle_using_dfs_helper(visited,parent,m.first);

                         if(ans) break;
                    }
                    
               }

               if(ans){
                    cout << "CYCLE PRESENT" << endl;
               }else{
                    cout << "CYCLE NOT PRESENT" << endl;
               }    

          }

};

int main(){

     Graph g;

     
     g.addEdge(1,0);
     g.addEdge(2,1);
     g.addEdge(0,2);

     g.print();

     g.bfs(); //level order traversal
     g.dfs(); //depth first traversal

     g.detect_cycle_using_bfs();
     g.detect_cycle_using_dfs();

     return 0;
}