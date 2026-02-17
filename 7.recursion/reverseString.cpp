#include <iostream>
#include <string>

using namespace std;

void RE(string &str , int startingIndex , int endingIndex){
     if(startingIndex>endingIndex) return;
     swap(str[startingIndex],str[endingIndex]);
     RE(str,startingIndex+1,endingIndex-1);
}

int main(){
     string str {"abcdef"};
     int startingIndex{0} , endingIndex = str.length()-1;
     cout << "STIRNG BEFORE : " << str << endl;
     RE(str,startingIndex,endingIndex);
     cout << "STRING AFTER : " << str << endl;
     return 0;
}