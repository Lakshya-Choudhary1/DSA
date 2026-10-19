//topological sort 

//used to sort a graph vertex based on dependency(least to most) = traverse the graph then backtrack and put vertex into stack

//method 1 : using dfs (recurion + visited + stack)
//method 2 : using bfs (indegree + queue)

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <stack>

using namespace std;
 
class Unordered_Graph{
     private:

          //using Adjanency List
          unordered_map<int,vector<int>> graph;
          vector<int> topological_ordering;
          
     public:

          //print graph
          void print_graph(){

               cout << "----------GRAPH----------" << endl;

               for(pair<int,vector<int>> i : graph){
                    cout << i.first ;

                    cout << " : [ " ;

                    for(int j{0} ; j < int(i.second.size()) ; j++){
                         cout << i.second[j] ;

                         if(j != int(i.second.size()-1)){
                              cout << " , " ;
                         }

                    }

                    cout << " ]" << endl;
               }

          }
          //print topological ordering
          void print_topological_ordering(){
               cout << "-----------Topological ordering----------" << endl;
               for(int i : topological_ordering){
                    cout << i << "\t" ;
               }
               cout << endl;

               if(topological_ordering.size() == 0){
                    cout << "Detected Cycle So Topological Ordering Fail OR Graph Is Empty" << endl;
               }
          }

          //add Edge
          void add_edge(int u, int v){
               graph[u].push_back(v);
          }    
          
          //dfs
          bool dfs(unordered_map<int,bool>& visited,unordered_map<int,bool>& path,stack<int>& stk,int node){

               visited[node] = true;
               path[node] = true;

               for(int nbrs : graph[node]){
                    if(!visited[nbrs]){
                         if(dfs(visited,path,stk,nbrs)){
                              return true;
                         }
                    }else if(path[nbrs]){
                         return true;
                    }
               }

               path[node] = false;
               stk.push(node);
               return false;
          }

          //topological Sort
          void topological_sort(){

               unordered_map<int,bool> visited;
               unordered_map<int,bool> path;
               stack<int> stk;


               for(pair<int,vector<int>> i : graph){
                    if(!visited[i.first]){
                         bool cycle_detect = dfs(visited,path,stk,i.first);
1
                         if(cycle_detect){
                              cout << "Cycle Detected In Graph(Topological sort only work on DAG)" << endl;
                              return ;
                         }
                    }
               }
               
               while(!stk.empty()){
                    topological_ordering.push_back(stk.top());
                    stk.pop();
               }

               this->print_topological_ordering();
          }

     Unordered_Graph(){
          cout << "Unordered Graph Created." << endl;
     }


};

int main(){

     Unordered_Graph g;

     g.add_edge(0,1);
     g.add_edge(1,2);
     g.add_edge(2,3);

     g.print_graph();

     g.topological_sort();


     g.print_topological_ordering();

     return 0;
}