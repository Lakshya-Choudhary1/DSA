#include <iostream>
#include <list>

using namespace std;

int main(){
     //creation
     list<int>myList;

     //insertion
     myList.push_back(1);
     myList.push_back(2);
     myList.push_back(3);
     myList.push_back(4);
     myList.insert(myList.begin(),1000);
     //iterator
     list<int>::iterator it = myList.begin();
     for(unsigned int i = 0 ; i<myList.size() ; i++){
          cout << *it << "  " ;
          ++it;
     }
     cout << "\n" ;
     //traversing
     for(auto a : myList)     
          cout << a <<  "  " ;

     return 0;
}