#include <iostream>
using namespace std;

int findClosest(int x, int y, int z) {
     int distanceFromX = z-x;
     int distanceFromY = z-y;
     int result {-1};
     if(distanceFromX < 0 ){
          distanceFromX *= -1;
     }
     if(distanceFromY < 0 ){
          distanceFromY *= -1;
     }
     cout << "distance x " << distanceFromX << endl;
     cout << "distance y " << distanceFromY << endl;
     if(distanceFromX == distanceFromY){
          result = 0;
     }else if(distanceFromX < distanceFromY){
          result = 1;
     }else if(distanceFromY < distanceFromX){
          result = 2;
     }
     return result;
}

int main(){
     cout << findClosest(17,19,1) << endl;
     return 0;
}