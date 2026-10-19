#include <iostream>
#include <vector>

using namespace std;

class Undirected_Graph{

     private:
          int vertex;
          vector<vector<int>> g;
     
     public:

     Undirected_Graph(int v): vertex{v}{
          g.resize(v+1,vector<int>(v+1,0));
     }

     void addEdge(int u , int v){
          if(u>vertex || v>vertex) return ;
          g[u][v] = 1;
          g[v][u] = 1;
     }

     void removeEdge(int u , int v){
          if(u>vertex || v>vertex) return ;
          g[u][v] = 0;
          g[v][u] = 0;
     }

     void print(){
          cout << "  " ;
          for(int i=0 ; i<=vertex ; i++){
               cout << i << " " ;
          }
          cout << endl;
          for(int i=0 ; i<=vertex ; i++){
               cout << i << " " ;
               for(int j = 0 ; j<=vertex ; j++){
                    cout << g[i][j] << " " ;
                }
               cout << endl;
          }
     }

};

class Directed_Graph{

     private:
          int vertex;
          vector<vector<int>> g;
     
     public:

     Directed_Graph(int v): vertex{v}{
          g.resize(v+1,vector<int>(v+1,0));
     }

     void addEdge(int u , int v){
          if(u>vertex || v>vertex) return ;
          g[u][v] = 1;
     }

     void removeEdge(int u , int v){
          if(u>vertex || v>vertex) return ;
          g[u][v] = 0;
     }

     void print(){
          cout << "  " ;
          for(int i=0 ; i<=vertex ; i++){
               cout << i << " " ;
          }
          cout << endl;
          for(int i=0 ; i<=vertex ; i++){
               cout << i << " " ;
               for(int j = 0 ; j<=vertex ; j++){
                    cout << g[i][j] << " " ;
                }
               cout << endl;
          }
     }

};

int main(){

     Undirected_Graph ug(3);

     ug.addEdge(0,1);
     ug.addEdge(0,2);
     ug.addEdge(1,2);
     ug.addEdge(2,3);

     ug.print();

     cout << "Directed Graph" << endl;
     Directed_Graph *dg = new Directed_Graph(3);

     dg->addEdge(0,1);
     dg->addEdge(0,2);
     dg->addEdge(1,2);
     dg->addEdge(2,3);

     dg->print();
     
     return 0;
}