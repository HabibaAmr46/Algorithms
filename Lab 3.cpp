#include <iostream>

using namespace std;


int partitionn(int arr[],int l,int h)
{
    int pivot=arr[l];
      int i=l;
    int j=h;
    while(i<j)
    {
    do
    {
        i++;
    }while(arr[i]<=pivot);
    do
    {
        j--;
    }while(arr[j]>pivot);
    if(i<j)
        swap(arr[i],arr[j]);
    }
   swap(arr[l],arr[j]);
    return j;
}


int QuickSort(int arr[],int l,int h,int i)
{
    if(l<h){
    int p=partitionn(arr,l,h);
    int k=p-l+1;
    if(i==k)
        return arr[p];

   else if(i<k)
        QuickSort(arr,l,p,i);
    else
        QuickSort(arr,p+1,h,i-k);
    }

}
int main()
{
   int arr[]={12,3,5,7,4,19,26};
    int n=sizeof(arr)/sizeof(arr[0]);
   cout<<QuickSort(arr,0,n,3)<<endl;

    return 0;
}
