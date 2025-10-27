//anagram or not
//means freq of alphabet should be same in two corsponding strings
//anagram == aaangrm same length and same freq of letters
//TimeCom. :O(N+M) ------- SpaceCom. :O(1)
#include <iostream>
#include <string>
using namespace std;
string TEST_CASES[][2]={
     {"anagram","aangram"},
     {"anagrmm","aangram"}
};
bool isAnagram(string &, string &);
int main(){
     int totalTestCases = sizeof(TEST_CASES)/sizeof(TEST_CASES[0]);
     for(int i{0} ; i< totalTestCases ; i++)
          cout << isAnagram(TEST_CASES[i][0],TEST_CASES[i][1]) << endl;; 
     return 0;
}
bool isAnagram(string &s, string &t){
     if(s.length()!=t.length()) return false;
     int freq[256] = {0};
     for(char a : s) freq[int(a)]++;
     for(char a : t) freq[int(a)]--;
     for(int i =0 ; i< 256 ;i++)
          if(freq[i]!=0) return false;
     return true;
}