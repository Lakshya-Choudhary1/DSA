// reverse a string using LL

// #include <iostream>
// #include <string>
// #include <stack>

// using namespace std;

// string reverse(string str){
//      stack<char> s;
//      string newStr;
//      for(auto a : str) s.push(a);
//      while (!s.empty())
//      {
//           newStr.push_back(s.top());
//           s.pop();
//      }
//      return newStr;
// }

// int main(){
//      string s = "LAKSHYA" ;

//      cout << "Reverse : " << reverse(s) << endl;

//      return 0;
// }


//print middle of stack
#include <iostream>
#include <stack>

using namespace std;

int main(){
     stack<int> s;

     s.push(1);
     s.push(2);
     s.push(3);
     s.push(4);
     s.push(5);
     s.push(6);
     s.push(7);

     int mid = s.size()/2;
     int it = s.size()-1;
     stack<int>s2;

     while(it>mid){
          it--;
          s2.push(s.top());
          s.pop();
     }

     cout << "MIDDLE ELEMENT IS : " <<  s.top();


     while(!s2.empty()){
          s.push(s2.top());
          s2.pop();
     }



     return 0;
}