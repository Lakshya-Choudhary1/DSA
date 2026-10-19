#include <iostream>
#include <queue>

using namespace std; 

// find k'th largest integer

int main()
{

     int arr[] {10,5,50,23,17,8,21,57};
     int size = 8;
     long long unsigned int k = 8 ; //find k'th largest number 
     priority_queue<int , vector<int> , greater<int> > h; // min heap

     int i = 0 ;

     while(i<size)
     {
          if(h.size() < k)
          {
               h.push(arr[i]);
          }else
          {
               if(arr[i] > h.top())
               {
                    h.pop();
                    h.push(arr[i]);
               }
          }

          i++;
     }

     cout << "k'th largest number is : " << h.top() << endl;


     return 0;
}