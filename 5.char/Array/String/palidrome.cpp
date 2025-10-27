#include <iostream>
#include <vector>

using namespace std;

int getLength(char []);
void checkPalidrome(char [] ,int);

int main(){
     char arr1[100] ={'M','O','M',' ','M','O','M','B','\0'};
     int arr1Length = getLength(arr1);
     cout << "LENGTH :" << arr1Length << endl;
     checkPalidrome(arr1,arr1Length);

     return 0;
}

void checkPalidrome(char arr[] ,int n){
     int start{0} , end{n-1};
     while(start <= end){
          if(arr[start]==arr[end]){
               start++;
               end--;
          }else{
               cout << "NOT A VALID PALIDROME"  << endl;
               return;
          }
     }
     cout << "IS A VALID PALIDROME" << endl;
}

int getLength(char arr[]){
     int count{0}, i {0};
     while(arr[i] != '\0'){   count++;     i++;}
     return count ;
}