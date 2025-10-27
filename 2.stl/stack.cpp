#include <iostream>
#include <stack>
using namespace std;

int main(){
     //creation
     stack<int> st;

     //insertion
     st.push(10);
     st.push(20);
     st.push(30);

     //size 
     cout << st.size() << endl;

     //empty
     cout << st.empty() << endl;
     
     //deletion
     st.pop();

     //top of stack
     cout << st.top()  << endl;




     return 0;
}