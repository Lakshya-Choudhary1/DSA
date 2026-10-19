#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Graph_Interface{
     private:
     
     public:
        virtual  void addEdge(int,int,bool) = 0;
        virtual  void print() = 0;
};

class Graph : public Graph_Interface{
     private:
          unordered_map<int,vector<int>> g;
     public:

     void addEdge(int u, int v, bool directed) override {
         if(directed){
               g[u].push_back(v);
         }else{
               g[u].push_back(v);
               g[v].push_back(u);
         }
     }

     void print() override {
          for(auto r : g){
               cout << r.first << ":  { " ;

               for(auto el : r.second){
                    cout << el << ",";
               }

               cout << " }" << endl;
          }
     }

     virtual ~Graph(){
          cout << "DE-CONSTRUCTOR CALLED." << endl;
     };
};


int main(){

     Graph *g = new Graph();

     g->addEdge(0,1,1);
     g->addEdge(0,2,1);
     g->addEdge(1,2,1);
     g->addEdge(2,3,1);

     g->print();

     delete g;


     return 0;
}