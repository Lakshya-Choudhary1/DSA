#include <iostream>

using namespace std;

//max heap
class MAX_HEAP
{
     private:

          int* container;
          int index , capacity;
     
     public:

          //constructor
          MAX_HEAP(int capacity)
          {
               this->capacity = capacity+1;
               index = 0;
               container = new int[this->capacity];
          }

          //print container data
          void print(){
               if(index == 0 )
               {
                    cout << "<----- MAX HEAP IS EMPTY CANNOT PRINT ----->" << endl;
               }

               for(int i = 1 ; i <= index ; i++)
               {
                    cout << container[i] << "," ;
               }

               cout << endl;
          }

          //insertion in container
          int insert(const int& value)
          {
               //handle overflow
               if(index == capacity-1)
               {
                    cout << "<----- HEAP OVERFLOW ----->" << endl;
                    return -1;
               }

               index++;//increase index
               container[index] = value; //add value to container

               //assigning valid position of data in heap container
               int childIndex = index;
               while(childIndex>1)
               {
                    int parentIndex = childIndex/2; //parent of current element

                    if(container[parentIndex] < container[childIndex])
                    {
                         swap(container[parentIndex] , container[childIndex]);
                         childIndex = parentIndex;
                         continue;
                    }

                    break;
               }

               cout << "ELEMENT INSERTED : " << value << endl;
               cout << "INSERTED AT : " << index << endl;
               cout << "POSITIONED At : " << childIndex << endl;

               return container[childIndex];
          }

          //deletion in container
          bool deletion()
          {
               //handle underflow
               if(index == 0)
               {
                    cout << "<----- HEAP OVERFLOW ----->" << endl;
                    return false;
               }

               //swap top with last element
               swap(container[1],container[index]);

               //delete
               container[index] = 0;
               index--;

               //heapify 

               int i = 1;

               while(true)
               {

                    int leftChildIndex = i*2 , rightChildIndex = i*2 + 1;
                    int largerElementIndex = i ;

                    if(leftChildIndex <= index && container[leftChildIndex] > container[largerElementIndex] )
                    {
                         largerElementIndex = leftChildIndex;
                    }

                    if(rightChildIndex <= index && container[rightChildIndex] > container[largerElementIndex] )
                    {
                         largerElementIndex = rightChildIndex;
                    }

                    if(largerElementIndex == i ) break;

                    //swap i and largerElementIndex
                    swap(container[i] , container[largerElementIndex]);

                    i = largerElementIndex;

               }


               return true;
          }

};


//minHeap
class MIN_HEAP
{
     private:

          int* container;
          int index , capacity;

     public:

          MIN_HEAP(int capacity) : capacity(capacity+1)
          {
               index = 0 ;
               container = new int[capacity+1];
          }

          //print
          void print()
          {
               if(index == 0)
               {
                    cout << "<----- HEAP IS EMPTY CANNOT PRINT ----->" << endl;
                    return;
               }

               for(int i = 1 ; i<=index ; i++)
               {
                    cout << container[i] << "," ;
               }

               cout << endl;

          }

          //insertion 
          int insert(const int& value)
          {
               if(index == capacity-1)
               {
                    cout << "<----- HEAP OVERFLOW ----->" << endl;
                    return -1;
               }

               index++;
               container[index] = value;

               //assign valid index in container

               int child = index;

               while(child>1)
               {
                    int parent = child/2;
                    
                    if(container[child] < container[parent])
                    {
                         swap(container[child],container[parent]);
                         child = parent;
                         continue;
                    }

                    break;
                    
               }

               cout << "ELEMENT INSERTED : " << value << endl;
               cout << "INSERTED AT : " << index << endl;
               cout << "POSITIONED At : " << child << endl;

               return container[child];
          }

          //deletion
          bool deletion()
          {

               if(index == 0 )
               {
                    cout << "<----- HEAP UNDERFLOW ----->" << endl;
                    return false;
               }

               swap(container[1],container[index]);

               container[index] = 0 ;
               index--;

               int i = 1;

               while(true)
               {
                    int leftChildIndex = 2*i;
                    int rightChildIndex = 2*i + 1;
                    int smallestElementIndex = i ;

                    if(leftChildIndex <= index && container[leftChildIndex] < container[smallestElementIndex])
                    {
                         smallestElementIndex = leftChildIndex;
                    }

                    if(rightChildIndex <= index && container[rightChildIndex] < container[smallestElementIndex])
                    {
                         smallestElementIndex  = rightChildIndex; 
                    }

                    if(smallestElementIndex == i ) break;

                    swap(container[i],container[smallestElementIndex]);
                    
                    i = smallestElementIndex;

               }


               return true;
          }

};


int main()
{

     MIN_HEAP hp(6);
     hp.insert(100);
     hp.insert(200);
     hp.insert(300);
     hp.insert(500);
     hp.deletion();
     hp.deletion();
     hp.print();

     return 0;
}