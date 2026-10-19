#include <iostream>

using namespace std;

//RECURSION

int febRec(int n)
{
     if(n<=1) return n;
     return febRec(n-1) + febRec(n-2);
}

//MEMORISATION 

int febMemo(int n)
{
     return 0;
}

//TABULATION

int febTab(int n)
{
        return 0;
}

//SPACE OPTIMISATION

int febSO(int n)
{
        return 0;
}

int main()
{
     cout << febRec(6) << endl;
     return 0;
}