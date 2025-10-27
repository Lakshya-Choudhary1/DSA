#include <iostream>
using namespace std;


void printRowSum(int arr[][3],int rowSize,int colSize){
     for(int row = 0 ; row<rowSize ; row++){
          int rowSum = 0 ;
          for(int col = 0 ; col < colSize ; col++){
               rowSum += arr[row][col];
          }
          cout << "SUM OF ROW:" << row << " IS " << rowSum << endl;
     }
}

void printColSum(int arr[][3],int rowSize,int colSize){
     for(int col = 0 ; col<colSize ; col++){
          int colSum = 0 ;
          for(int row = 0 ; row < rowSize ; row++){
               colSum += arr[row][col];
          }
          cout << "SUM OF ROW:" << col << " IS " << colSum << endl;
     }
}

void printDigSum(int arr[][3],int rowSize , int colSize){
     int sum = 0;
     for(int row = 0 ; row < rowSize ; row++){
          for(int col=0 ; col <colSize ; col++){
               if(row==col){
                    sum+= arr[row][col];
               }
          }
     }
     cout << "DIGIONAL SUM IS " << sum << endl;
}

int main(){

     int arr[3][3]={
          {1,2,3},
          {5,6,7},
          {9,10,11}
     };

     int rowSize =  sizeof(arr)/sizeof(arr[0]) ;
     int colSize = sizeof(arr[0])/sizeof(arr[0][0]);

     cout << rowSize << " " << colSize << endl;
     
     // printRowSum(arr,rowSize,colSize);
     // printColSum(arr,rowSize,colSize);
     printDigSum(arr,rowSize,colSize);

     return 0;
}