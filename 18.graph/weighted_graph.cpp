#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>


using namespace std;



class Undirected_Matrix_Graph{
     private:
          int vertices;
          vector<vector<int>> g;

     public:

          Undirected_Matrix_Graph(int v): vertices{v}{
               g.resize(v,vector<int>(v,0));
          }


          void addEdge(int u, int v, int w){
               g[u][v] = w;
               g[v][u] = w;
          }

          void removeEdge(int u, int v){
               g[u][v] = 0;
               g[v][u] = 0;
          }

          void print(){
               for(vector<int> u : g){
                    for(int v : u){
                         cout << v << "," ;
                    }
                    cout  << endl;
               }
          }

};



class Directed_Matrix_Graph{
     private:
          int vertices;
          vector<vector<int>> g;

     public:

          Directed_Matrix_Graph(int v): vertices{v}{
               g.resize(v,vector<int>(v,0));
          }


          void addEdge(int u, int v, int w){
               g[u][v] = w;
          }

          void removeEdge(int u, int v){
               g[u][v] = 0;
          }

          void print(){
               for(vector<int> u : g){
                    for(int v : u){
                         cout << v << "," ;
                    }
                    cout  << endl;
               }
          }
};

class Undirected_List_Graph{
     private:
          int vertices;
          unordered_map<int,vector<pair<int,int>>> g;

     public:

          Undirected_List_Graph(int v): vertices{v}{
          }


          void addEdge(int u, int v, int w){
               g[u].push_back({v,w});
               g[v].push_back({u,w});
          }

          void print(){
               for(auto u : g){
                    cout << u.first << ": {";
                    for(pair<int,int> p : u.second){
                         cout<< "(" << p.first << "," << p.second <<   "),";
                    }
                    cout << " }" << endl;
               }
          }

};

class Directed_List_Graph{
     private:
          int vertices;
          unordered_map<int,vector<pair<int,int>>> g;

     public:

          Directed_List_Graph(int v): vertices{v}{
          }


          void addEdge(int u, int v, int w){
               g[u].push_back({v,w});
               g[v].push_back({u,w});
          }

          void print(){
               for(auto u : g){
                    cout << u.first << ": {";
                    for(pair<int,int> p : u.second){
                         cout<< "(" << p.first << "," << p.second <<   "),";
                    }
                    cout << " }" << endl;
               }
          }

};


int main(){
     Undirected_List_Graph g(5);
     g.addEdge(1,2,10);
     g.print();
     return 0;
}
