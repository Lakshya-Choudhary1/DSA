// #include <iostream>

// using namespace std;

// int main(){
//      int a=21;
//      cout << "----------------------------" << endl;
//      cout << "a = " << a << endl;
//      cout << "address = " << &a << endl;

//      //simple pointer
//      int *simple_ptr = nullptr; 
//      simple_ptr = &a;
//      *simple_ptr = 22;
//      cout << "--------SIMPLE_POINTER-------------" << endl;
//      cout << "*simple_ptr =  " << *simple_ptr << endl;
//      cout << "simple_ptr = " << simple_ptr << endl;
//      cout << "&simple_ptr = " << &simple_ptr << endl;

//      //pointer to a const integers
//      const int *ptr1 {nullptr};
//      ptr1 = &a;
//      cout << "-----POINTER TO A CONSTANT INTEGER----" << endl;
//      cout << "*ptr1 = " << *ptr1 << endl;
//      cout << "ptr1 = " << ptr1 << endl;
//      cout << "&ptr1 = " << &ptr1 << endl;

//      //const ptr to an integer
//      int b = 89;
//      int *const ptr2 {&b}; // *ptr1 = 32 = valid // ptr = &a = error
//      cout << "---------const pointer to an int ------------" << endl;
//      *ptr2 = 32;
//      cout << "*ptr2 = " << *ptr2 << endl;
//      cout << "ptr2 = " << ptr2 << endl;

//      //const ptr to a const int
//      int c = 3234;
//      const int* const ptr3 {&c};
//      cout << "---------const pointer to an const int ------------" << endl;
   
//      cout << "*ptr3 = " << *ptr3 << endl;
//      cout << "ptr3 = " << ptr3 << endl;

//      //dynamic memory allocation
//      const int *ptr4{nullptr};
//      ptr4 = new int(543);
//      cout << "----dynamic memory allocation-----" << endl;
//      cout << "*ptr4 = " << *ptr4 << endl;
//      cout << "ptr4 = " << ptr4 << endl;

//      // pointer to an array
//      int arr[]{1,2,3,4,5};
//      int *ptr5 = arr;
//      cout << "---pointer to an array-----" << endl;
//      cout << "*(arr+1) : " << *(arr+1) << endl;
//      cout << "*ptr5 : " << *ptr5 << endl;
//      cout << "*(ptr5+2 ): " << *(ptr5+2) << endl;
//      return 0;
// }

// #include <iostream>

// using namespace std;

// int main(){

     // int *ptr = new int[2];

     // for(int i = 0 ; i < 2 ; i++){
     //      *(ptr+i) = i+1;
     // }

     // cout << "print --->" << endl;
     // cout << "*(ptr+0) : " << *ptr << endl;
     // cout << "*(ptr+1) : " << *(ptr+1) << endl;

     //double pointer
//      int c = 12;
//      int *a;
//      int *b;
//      a = new int(21);
//      b = new int(12);
//      int **main_ptr[2];
//      main_ptr[0] = &a ;
//      main_ptr[1] = &b ;

//      return 0;
// }

#include <iostream>
using namespace std;

int *largest(int *ptr1 , int  *ptr2){
     if(*ptr1>*ptr2) return ptr1;
     return ptr2;
}

int main(){

     cout << (12*13)%5 << endl;

     return 0;
}