#include <iostream>
#include <deque>

using namespace std;

int main(){
     deque<int> dq;
     dq.push_back(1);
     dq.push_front(2);
     //front
     //back
     //pop_back()
     //pop_front()
     //push_front()
     //push_back()
     //clear() all element clear
     //erase(iterator first , iterator second)
     //erase(iteraetor index)
     //empty()
     //size()
     //begin()
     //end()
     //swap(dequeue &dq)
     //at()
     //operator[]
     //insert(iterator posn , const t& value)

     for(auto a : dq){
          cout << a << "  " ;
     }

     return 0;
}