#include <iostream>
#include <vector>
#include <string>

using namespace std;

void findSolution(vector<vector<int>> &vec, int row , int col , int n , vector<string> &ans , string dir = ""){

    if(row<0 || row>=n || col<0 || col>=n || vec[row][col]==0) return ;

    if( row==(n-1) && col==(n-1) ){
        ans.push_back(dir);
        return ;
    }
    vec[row][col] = 0 ;

    findSolution(vec,row+1,col,n,ans,dir+"D"); //down
    findSolution(vec,row,col-1,n,ans,dir+"L"); //left
    findSolution(vec,row,col+1,n,ans,dir+"R"); //right
    findSolution(vec,row-1,col,n,ans,dir+"U"); //up

    vec[row][col] =  1 ;
}

int main(){
    vector<vector<int>> vec = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };
    vector<string>ans;
    int n = vec.size();

    findSolution(vec,0,0,n,ans);

    for(auto a : ans){
        cout << a << "\t" ;
    }

    return 0;
}