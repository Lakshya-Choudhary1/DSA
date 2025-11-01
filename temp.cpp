#include <iostream>
#include <string>

using namespace std;

int main(){
     string s = "laKshYa";
     int l=2,r=5;//kshy
     cout << s.substr(l,r-l+1) << endl;

     return 0;
}