/*
     IMPLEMENTATION HEAP USING ARRAY
     1 BASED INDEXING

     HEAP PROPERTYIES :
          1. MAX HEAP (PARENT NODE IS GREATER THAN CHILD)
          2. MIN HEAP (PARENT NODE IS SMALLER THAN CHILD)

     ACCESSING PROPERTY:
          1: IF
               PARENT INDEX = i
                    THEN
                         LEFT CHILD INDEX = 2*i
                         RIGHT CHILD INDEX = 2*i + 1

          2:
               IF CURRNT NODE INDEX = i
                    THEN
                         PARENT INDEX = i/2

*/

#include <iostream>

using namespace std;


class Heap
{
private:
     int index;
     int size;
     int *heap;

public:
     Heap(int size) : size(size + 1)
     {
          this->index = 0;
          this->heap = new int[size + 1];
     }

     void print()
     {
          cout << "<-----PRINTING----->" << endl;
          for (int i = 1; i <= this->index; i++)
          {
               cout << heap[i] << ",";
          }

          cout << endl;
     }

     int insert(int val)
     {
          if (index == size)
          {
               cout << "CANNOT INSERT HEAP IS FULL" << endl;
               return -1;
          }

          heap[++index] = val;

          int i = index;

          while (i > 1)
          {
               int parent = i / 2;

               if (heap[parent] < heap[i])
               {
                    swap(heap[parent], heap[i]);
               }

               i = parent;
          }

          return heap[i];
     }

     int pop()
     {
          if (index == 0)
          {
               cout << "HEAP IS EMPTY" << endl;
               return -1;
          }
          // replace
          swap(heap[1], heap[index]);
          // delete
          int deletedElement = heap[index];
          heap[index] = 0;
          index--;
          // heapify

          int i = 1;

          while (true)
          {
               int leftChildIndex = 2 * i;
               int rightChildIndex = 2 * i + 1;
               int largestElementIndex = i;

               if (i > index)
                    break;

               if (leftChildIndex < size && heap[leftChildIndex] > heap[largestElementIndex])
               {
                    largestElementIndex = leftChildIndex;
               }

               if (rightChildIndex < size && heap[rightChildIndex] > heap[largestElementIndex])
               {
                    largestElementIndex = rightChildIndex;
               }

               if (largestElementIndex == i)
                    break;

               swap(heap[i], heap[largestElementIndex]);
               i = largestElementIndex;
          }

          return deletedElement;
     }
};

int main()
{

     Heap hp(10);

     cout << "INSERTED : " << hp.insert(10) << endl;
     cout << "INSERTED : " << hp.insert(20) << endl;
     cout << "INSERTED : " << hp.insert(30) << endl;
     cout << "INSERTED : " << hp.insert(40) << endl;
     cout << "INSERTED : " << hp.insert(50) << endl;
     hp.print();
     cout << "POPPED : " << hp.pop() << endl;
     hp.print();

     return 0;
}