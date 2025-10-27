#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <deque>

using namespace std;

int main(){

     // vector<string> vec = {"HELLO","THIS","FRIDD?"};
     // vector<string>::iterator it = vec.begin();
     // while(it!=vec.end()){
     //      cout << *it << "\t" ;
     //      it++;
     // }
     // cout << endl;

     // for(it = vec.begin();it!=vec.end();it++){
     //      cout << *it << "\t";
     // }

     list<int> lst = {1,2,3,4,4};

     list<int>::iterator itr = lst.end();

     while(itr != lst.begin()){
          itr--;
          cout << *itr << "\t" ;
          
     }
     
     return 0;
}