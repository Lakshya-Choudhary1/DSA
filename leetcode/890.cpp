#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> func(vector<string> &words,string &pattern){
     vector<string> mapArr;
     vector<string> result;
     for(string word : words){
          char newChar {'a'};
          string mapString {""};
          for(unsigned int i{0} ; i<word.length() ; i++){
               if(word[i]==word[i+1] || word[i]==word[i-1]){
                    mapString.push_back(newChar);
               }else{
                    newChar++;
                    mapString.push_back(newChar);
               }
          }
          mapArr.push_back(mapString);
     }

     for(unsigned int i{0} ; i<mapArr.size() ; i++){
          if(mapArr[i]== pattern)
               result.push_back(words[i]);        
     }
      
     return result;
}

int main(){
     vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
     string pattern {"abb"};
     vector<string>ans =  func(words,pattern);

     for(string s : ans){
          cout << s << endl;
     }
     return 0;
}