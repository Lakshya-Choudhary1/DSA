#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>

using namespace std;

class Undirected_Weighted_List_Graph{
     private:
          unordered_map<int,vector<pair<int,int>>> g;
          int src = -1;

     public:

          void addEdge(int u, int v,int w){
               if(src == -1) src = u;
               g[u].push_back({v,w});
               g[v].push_back({u,w});
          }

          Undirected_Weighted_List_Graph(){
               cout << "Created Undirected Adjencey List graph" << endl;
          }

          void print(){

               for(pair<int,vector<pair<int,int>> node: g){
                    cout << "{" ;

                    cout << node.first << " : " ;

                    for(pair<int,int> i : node.second){
                         cout << "(" << i.first << "," << i.second << ")," ;
                    }

                    cout << "}" << endl;
               }

          }


          void level_order_traversal(){
               unordered_map<int,bool> visited;
               deque<int> q;
               cout << "LEVEL ORDER TRAVERSAL : " ;
               
               visited[src] = true;
               q.push_back(src);
               
               while(!q.empty()){
                    //fetch front element form queue
                    int node = q.front();
                    //pop from queue
                    q.pop_front();

                    for(auto n : g[node]){
                         if(visited[n]) continue;
                         visited[n] = true;
                         q.push_back(n);
                    }
                    cout << node << "," ;
               }
               cout << endl;
          }    

          void depth_first_search(){

          }

};



int main(){

     Undirected_Weighted_List_Graph g;
     g.addEdge(1,2,2);
     g.addEdge(2,3,8);
     g.addEdge(1,3,9);
     g.print();
     g.level_order_traversal();


     return 0;
}