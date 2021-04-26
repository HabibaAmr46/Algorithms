#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i)
{
    int maximum = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[maximum])
        maximum = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[maximum])
        maximum = right;

    // If largest is not root
    if (maximum != i) {
        swap(arr[i], arr[maximum]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, maximum);
    }
}

void BuildHeap(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
}
void HeapSort(int arr[],int n)
{
    BuildHeap(arr,n);
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }

}


int main()
{
    int arr[]={90,10,40,7,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    HeapSort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
