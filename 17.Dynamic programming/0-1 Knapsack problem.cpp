#include <iostream>
#include <vector>

using namespace std;


int solve(int w ,const int val[] ,const int wt[] ,const int& size, int idx ,vector<vector<int>>& dp ){

     if( w == 0 || idx >= size) return 0;

     int inc{0} , exc{0};

     if(dp[idx][w]!=-1) return dp[idx][w];

     
     if(wt[idx] <= w){
          inc = val[idx] + solve(w-wt[idx],val,wt,size,idx+1,dp);
     }
     

     exc = solve(w,val,wt,size,idx+1,dp);

     int ans = max(inc,exc);

     dp[idx][w] = ans;

     return dp[idx][w];

}


int main()
{
     int w{4};
     int val[] = {1,2,3};
     int wt[] = {4,5,1};

     int size = sizeof(val)/sizeof(val[0]); // size of val and wt is same;

     vector<vector<int>>dp (size+1,vector<int>(w+1,-1));

     int ans = solve(w,val,wt,size,0,dp);

     cout << ans << endl;


     return 0;
}