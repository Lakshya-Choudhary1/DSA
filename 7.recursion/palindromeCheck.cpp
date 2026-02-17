#include <iostream>
#include <string>

using namespace std;

bool checkPalindromeRE(string str, int startingIndex , int endingIndex){
     if(startingIndex>endingIndex) return true;
     if(str[startingIndex] != str[endingIndex]) return false;
     return  checkPalindromeRE(str,startingIndex+1,endingIndex-1);
}

int main(){
     string str {"abeba"};
     int startingIndex{0};
     int endingIndex = str.length()-1;

     if(checkPalindromeRE(str,startingIndex,endingIndex)){
          cout << checkPalindromeRE(str,startingIndex,endingIndex) << endl;
          cout << str << " is palindrome!" << endl;
     }else{
          cout << str << " not a valid palindrome!" << endl;
     }
     
     return 0;
}