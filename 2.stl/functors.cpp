// #include <iostream>
// using namespace std;

// class Student{
//      public:
//           int mark{0};
//      Student(){}
//      Student(int init_mark):mark{init_mark}{}
// };

// class StudentComperator{
//      public:
//           //accending order
//           bool operator()(Student a , Student b){
//                return a.mark>b.mark;
//           }
// };



// int main(){
//      Student s1(100);
//      Student s2(10);
//      StudentComperator cmp;
//      cout << "S1 And S2 : " << s1.mark << "\t" << s2.mark << endl;
//      if(cmp(s1,s2)==true){
//           cout << "s1 has greater marks" << endl;
//      }else{
//           cout << "s2 has greater marks" << endl;
//      }
//      return 0;
// }


//custom sort
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
     vector<int> arr ;
     arr.push_back(100);
     arr.push_back(20);
     arr.push_back(15);

     sort(arr.begin(),arr.end());

     for(unsigned int a = 0 ; a<arr.size() ; a++){
          cout << arr[a] << "\t" ;
     }

     return 0;
}