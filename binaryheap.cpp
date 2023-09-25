#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;
class minheap
{
private:
    int size;
    int capacity;
    vector<int> heap;
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }

public:
    minheap(int capacity);
    void insert(int k);
    int deletet();
    void extractkey(int k);
    void extractpos(int i);
    void heapify(int i);
    vector<int> kelements(int k);
    void printheap();
};
vector<int> minheap::kelements(int k)
{
    vector<int> v;
    if (k > size)
    {
        return v;
    }
    for (int i = 0; i < k; i++)
    {
        int x = deletet();
        v.push_back(x);
    }
    return v;
}
void minheap::extractpos(int i)
{
    if (i > size)
    {
        cout << " THERE IS NO POSTION ";
    }
    int key = heap[i];
    for (int i = 0; i < size; i++)
    {
        if (heap[i] == key)
        {
            heap[i] = heap[size - 1];
            size--;
            heapify(0);
            break;
        }
    }
}
void minheap::extractkey(int k)
{
    for (int i = 0; i < size; i++)
    {
        if (heap[i] == k)
        {
            heap[i] = heap[size - 1];
            size--;
            heapify(0);
            break;
        }
    }
}
minheap::minheap(int capacity)
{
    size = 0;
    this->capacity = capacity;
    heap.resize(capacity);
}
void minheap::insert(int k)
{
    if (size == capacity)
    {
        cout << "min heap full" << endl;
        return;
    }
    size++;
    int i = size - 1;
    heap[i] = k;
    while (i != 0 && heap[parent(i)] < heap[i])
    {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}
void minheap::heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if ((l < size) && (heap[l] > heap[smallest]))
    {
        smallest = l;
    }
    if ((r < size) && (heap[r] > heap[smallest]))
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}
int minheap::deletet()
{
    if (size == 0)
    {
        return -1;
    }
    if (size == 1)
    {
        size--;
        return heap[0];
    }
    else
    {
        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(0);
        return root;
    }
}
void minheap::printheap()
{
    /* int power=0;
    int value=1;
    for(int i=0;i<size;i++)
    {
        if(i==value)
        {
            cout<<endl;
            power+=1;
            value+=(1<<power);
        }
            cout<<heap[i]<<" ";
    }
    cout<<endl;*/
    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << " ";
    }
}
int main()
{
    int N = 15;
    int x;
    minheap heap(N);
    for (int i = 0; i < N; i++)
    {
        cout << "inserting elemet" << i + 1;
        cout << endl;
        cin >> x;
        heap.insert(x);
        heap.printheap();
        cout << endl;
    }
    vector<int> v = heap.kelements(5);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    /* heap.extractkey(12);
    heap.printheap();
    cout<<endl;
    heap.extractpos(7);
    heap.printheap();*/
    return 0;
}