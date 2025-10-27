#include <iostream>
#include <vector>
using namespace std;


void convertLowerCase(char arr[] , int n){
     for(int i{0} ; i<n ;i++){
          if(arr[i]>= 'A' && arr[i]<='Z'){
                arr[i] += -'A' + 'a';
          }
     }
}

int getLength(char arr[] , int n){
     int count{0};
     int i = 0;
     while(i<n){
          if(arr[i] != '\0'){
               count++;
               i++;
          }else{
               break;
          }
     }
     return count;
}


int main(){
     char arr[80];
     cout << "enter : " ;
     cin.getline(arr,80);
     cout << endl;
     int length = getLength(arr,80); 
     
     cout << length << endl;

     //METHOD ONE --------------------->
     // int s{0} , e{length-1};
     // while(s<e){
     //      swap(arr[s],arr[e]);
     //      s++;
     //      e--;
     // }

     //MeTHOD TWO --------------------->
     char newArr[length];
     int i{0} , j{length-1};
     while(j>=0 && i<=length){
          newArr[i] = arr[j];
          j--;
          i++;
     }


     cout << newArr << endl;
     return 0;
}