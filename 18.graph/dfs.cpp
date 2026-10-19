//DFS (DEPTH FIRST SEARCH)

#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>

using namespace std;

class Unweighted_Directed_Graph{
     private:
          map<int,vector<int>> g;
          int src {-1};

     public:

          void addEdge(int u, int v){
               if(src == -1) src = u;
               g[u].push_back(v);
          }

          void print(){
               cout << "Adjancecy List" << endl;
               for( pair<int,vector<int>> n : g ){
                    cout << n.first << " : { " ;
                    for(int e : n.second) cout << e << "," ;
                    cout << " }" << endl;
               }
          }
          
          void traversal(int node,unordered_map<int,bool> &visited){
                    if(visited[node]) return;

                    visited[node] = true;
                    cout << node << " , ";

                    for(auto n : g[node]){
                         if(!visited[n]) traversal(n,visited);
                    }
          }

          void dfs(){

               unordered_map<int,bool> visited;

               cout << "DFS : " ;

               for(pair<int,vector<int>> n : g){
                    if(!visited[n.first]){
                         traversal(n.first,visited);
                    }
               }

               cout << endl;
          }

      
};


int main(){

     Unweighted_Directed_Graph g;
     
     g.addEdge(16,17);

     g.addEdge(3,4);
     g.addEdge(4,6);
     g.addEdge(4,8);
     g.addEdge(8,7);
     g.addEdge(0,1);
     g.addEdge(0,2);
     g.addEdge(1,5);
     g.addEdge(2,3);
     g.addEdge(5,4);
     

     g.print();

     g.dfs();


     return 0;
}