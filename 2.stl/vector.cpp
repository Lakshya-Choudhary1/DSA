//STL CONTAINERS (VECTOR)
#include <iostream>
#include <vector>

using namespace std;

int main(){
     // vector<int> vec1 = {1,2,3,4,5};
     //iterator
     // vector<int>::iterator it = vec1.begin() + 1 ;
     // while(it != vec1.end()-1){
     //      cout << *it << endl;
     //      it++;
     // }

     //creating 2d vector
     // vector<vector<int>> vec2d(4,vector<int>(4,0));
   
     

     //2d vector with different sizes
     vector<vector<int>> vec(4);
     vec[0] = vector<int>(4, 1);
     vec[1] = vector<int>(3, 2);
     vec[2] = vector<int>(2, 3);
     vec[3] = vector<int>(1, 4);

     
          
                    for(unsigned int i = 0 ; i < vec.size() ; i++){
                         for(unsigned int j = 0 ; j < vec[i].size() ; j++){
                              cout << vec[i][j] << "  " ;
                         }
                         cout << endl;
                    }
                    
     return 0;
}