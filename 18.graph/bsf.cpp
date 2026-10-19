#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Weighted_Unordered_Graph{

     private:
          unordered_map<int,vector<pair<int,int>>> g;
          int src = -1;

     public:

          void addEdge(int u,int v , int w){
               if(src == -1) src = u;
               g[u].push_back(make_pair(v,w));
               g[v].push_back(make_pair(u,w));
          }

          void print(){

               cout << "ADJACENCY LIST" << endl;
               for(pair<int,vector<pair<int,int>>> n : g){
                    cout << n.first << " : { ";

                    for(pair<int,int> node : n.second){
                         cout << "(" << node.first << "," << node.second << ")," ;
                    }

                    cout << " } " << endl;
               }
          }

          void level_order_traversal(){

               queue<int> q;
               unordered_map<int,bool> visited;

               q.push(src);
               visited[src] = true;

               cout << "Level order traversal : {" ;

               while (!q.empty()){
                    
                    int edge = q.front();
                    q.pop();

                    cout << edge << "," ;

                    for(pair<int,int> p : g[edge]){
                         if(!visited[p.first]){
                              q.push(p.first);
                              visited[p.first] = true;
                         }
                    }

               }
               cout << "}";
               
          }


};

int main(){

     Weighted_Unordered_Graph g;

     g.addEdge(1,2,3);
     g.addEdge(1,3,4);
     g.addEdge(2,3,5);
     g.addEdge(3,4,7);

     g.print();

     g.level_order_traversal();
     

     return 0;
}