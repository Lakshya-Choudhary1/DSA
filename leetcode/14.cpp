#include <iostream>
#include <string>

using namespace std;

string TEST_CASES [][3] =  {
     {"flower","flow","flight"}
};
//find longest common pre-fix
string longestPrefix(string [],int); 

int main(){
     int length = sizeof(TEST_CASES)/sizeof(TEST_CASES[0]);   
     for(int i{0} ; i < length ; i++){
          int inner_length = sizeof(TEST_CASES[i])/sizeof(TEST_CASES[i][0]);
          string ans = longestPrefix(TEST_CASES[i],inner_length);     
          cout << ans << endl;
     }
     return 0;
}

string longestPrefix(string str[],int size){
     string ans;
     int index {0};
     for(;;){
          char curr_char = 0;

          for(int i{0} ; i< size ; i++){
               int len = sizeof(str[i])/sizeof(str[i][0]);

               if(i >= len){//out of bound
                    curr_char = 0;
                    break;
               }

               if(curr_char==0){
                    curr_char = str[i][index];
               }else if( curr_char != str[i][index]){
                    curr_char=0;
                    break;
               }
          }

          if(curr_char == 0) break;
          ans.push_back(curr_char);
          index++;
     }

     return ans;
} 