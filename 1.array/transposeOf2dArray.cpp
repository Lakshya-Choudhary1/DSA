#include <iostream>
using namespace std;

int main(){
     int arr[3][3] = {{10,11,12},{20,21,22},{30,31,32}};
     int transposeArr [3][3] = {0};
     int original[3][3] = {0};
     int rowSize = sizeof(arr)/sizeof(arr[0]);
     int colSize =  sizeof(arr[0])/sizeof(arr[0][0]);

     for(int row{0};row<rowSize;row++){
          for(int col{0};col<colSize;col++){
               transposeArr[row][col] = arr[col][row];
          }
     }

     cout << "ORIGINAL ARRAY" << endl;
     for(int row{0};row<rowSize;row++){
          for(int col{0};col<colSize;col++){
               cout << arr[row][col] << "  " ; 
          }
          cout << endl;
     }
     
     cout << "TRANSPOSE OF ORIGINAL ARRAY" << endl;
     for(int row{0};row<rowSize;row++){
          for(int col{0};col<colSize;col++){
               cout << transposeArr[row][col] << "  " ; 
          }
          cout << endl;
     }

     for(int col{0};col<colSize;col++){
          for(int row{0};row<rowSize;row++){
              original[row][col] = transposeArr[col][row];
          }
     }
     cout << "TRANSPOSE OF TRANSPOSE OF ORIGINAL ARRAY" << endl;
     for(int row{0};row<rowSize;row++){
          for(int col{0};col<colSize;col++){
               cout << original[row][col] << "  " ; 
          }
          cout << endl;
     }


     return 0;
}