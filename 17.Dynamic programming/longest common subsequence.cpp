// //text1 = "abcde", text2 = "ace" 

// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// vector<vector<int>> dp;

// int solve(int i , int j ,const string& text1, const string& text2 ){

//      if(i == int(text1.length()) || j == int(text2.length()) )
//      {
//           return 0;
//      }

//      if(dp[i][j] != -1){
//           return dp[i][j];
//      }

//      if(text1[i] == text2[j]){
//           return 1 + solve(i+1,j+1,text1,text2);
//      }

//      return max(
//           solve(i+1,j,text1,text2),
//           solve(i,j+1,text1,text2)
//      );
// }

// int main()
// {
//      string text1{"abcee"},text2{"acee"};
//      int n = text1.length() , m = text2.length();

//      dp.assign(n,vector<int>(m,-1));

//      int ans = solve(0,0,text1,text2);
//      cout << "LONGEST COMMON SUBSEQUENCE : " << ans << endl;

//      return 0;
// }


#include <iostream>
#include <string>

using namespace std;

int main(){
     string s = "abcde";

     cout << "Before : " << s << endl;
     s.erase(s.begin());
     cout << "After : " << s << endl;

     return 0;
}