#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  

using namespace std;

int main(){
     vector<int> arr = {10,20,30,40,50};
     //accumulate
     int totalSum = accumulate(arr.begin(),arr.end(),0);
     cout << totalSum ;

     return 0;
}