#include <iostream>
#include <string>



using namespace std;

int main(){
      string s = "lalalalalad";
     const string part = "la";
     cout << "BEFORE : " << s << endl;
     for(int i{0} ; i+part.length()<s.length() ; i++){
          bool match = true;
          for(int j{0} ; j<part.length() ; j++){
               if(s[i+j] != part[j]){
                    match = false;
                    break;
               }
          }

          if(match){
               s.erase(i,part.length());
               i=-1;
          }
     }

     cout << "AFTER : " << s << endl;

     return 0;
}