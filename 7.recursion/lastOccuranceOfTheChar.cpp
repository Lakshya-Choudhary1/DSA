#include <iostream>
using namespace std;

//METHOD 1 BASIC LOOP
int method1(char arr[],int len,char targetChar){
     int lastIndex{-1};
     for(int i{0} ; i<len ; i++) 
          if(arr[i] == targetChar) lastIndex = i ;
     return lastIndex;
}

//METHOD2 
int method2(char arr[],int len,char targetChar){
     for(int i = len-1 ; i>=0 ; i++){
          if(arr[i] == targetChar) return i;
     }
     return -1;
}

//METHOD 3 usingRE
//l-->r
void RE(char arr[] , int len , char targetChar , int index,int &ans){
     if(index>=len) return ;
     if(arr[index]==targetChar) ans=index;
     RE(arr,len,targetChar,index+1,ans);
}

//METHOD 4 
//r-->l
void RER(char arr[] , int len , char targetChar , int index , int &ans){
     if(index==-1) return;
     if(arr[index]==targetChar){
          ans = index;
          return;
     }
     RER(arr,len,targetChar,index-1,ans);
}

int main(){
     char arr[]{'a','b','c','d','c','b','a'};
     int len = sizeof(arr)/sizeof(arr[0]);
     int ans{-1};
     char targetChar = 'a';
     cout << "METHOD 1 : " << method1(arr,len,targetChar) << endl;
     cout << "METHOD 2 : " << method2(arr,len,targetChar) << endl;
     RE(arr,len,targetChar,0,ans);
     cout << "METHOD 3 : " << ans << endl;
     ans=-1;
     RER(arr,len,targetChar,len-1,ans);
     cout << "METHOD 4 : " << ans << endl;

     return 0;
}