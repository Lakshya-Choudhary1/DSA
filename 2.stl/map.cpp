#include <iostream>
#include <map>
#include <unordered_map>
 
using namespace std;

int main(){

          //creation
          unordered_map<string,string> table;
          
          //insertion
               //method 1
               table["in"] = "india";
               //method 2
               table.insert(make_pair("en","England"));
               //method 3 
               pair<string,string> p;
               p.first = "br";
               p.second = "Brazil";
               table.insert(p);


     return 0;
}