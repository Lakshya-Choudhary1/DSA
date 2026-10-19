#include <iostream>
#include <vector>

using namespace std;

// Min Heapify
void minHeapify(vector<int>& vec, int i, int n)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && vec[left] < vec[smallest])
        smallest = left;

    if (right < n && vec[right] < vec[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(vec[i], vec[smallest]);
        minHeapify(vec, smallest, n);
    }
}

// Build Min Heap
void buildMinHeap(vector<int>& vec)
{
    int n = vec.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minHeapify(vec, i, n);
    }
}

// Max Heapify
void maxHeapify(vector<int>& vec, int i, int n)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && vec[left] > vec[largest])
        largest = left;

    if (right < n && vec[right] > vec[largest])
        largest = right;

    if (largest != i)
    {
        swap(vec[i], vec[largest]);
        maxHeapify(vec, largest, n);
    }
}

// Build Max Heap
void buildMaxHeap(vector<int>& vec)
{
    int n = vec.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(vec, i, n);
    }
}
    
int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60};

    vector<int> minHeap = arr;
    buildMinHeap(minHeap);

    cout << "Min Heap: ";
    for (int x : minHeap)
        cout << x << " ";
    cout << endl;

    vector<int> maxHeap = arr;
    buildMaxHeap(maxHeap);

    cout << "Max Heap: ";
    for (int x : maxHeap)
        cout << x << " ";
    cout << endl;

    return 0;
}