#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class item
{
public:
    int value;
    int weight;
    item(int v,int w)
    {
        value=v;
        weight=w;
    }
};

bool compare(item a,item b)
{
    double ratio1 = (double)a.value / (double)a.weight;
    double ratio2 = (double)b.value / (double)b.weight;
    return ratio1 > ratio2;
}

double FractionalKnapsack(int W,item arr[],int sizeOfItems)
{
    sort(arr, arr + sizeOfItems, compare);
    double totalWeight=0.0;
    double Result=0.0;

    double x[sizeOfItems];
    for(int i=0; i<sizeOfItems; i++)
        x[i]=0;
    for(int i=0; i<sizeOfItems; i++)
    {
        if((totalWeight+arr[i].weight)<=W)
        {
            x[i]=1;
            totalWeight+=arr[i].weight;
        }
        else
        {
            int r=W-totalWeight;
            x[i]=(double) r/ (double) arr[i].weight;
            break;
        }
    }
    for(int i=0; i<sizeOfItems; i++)
    {
        Result+=x[i]*arr[i].value;
    }
    return Result;
}



int main()
{

    int W1 = 60;
    item arr[] = { { 280,40 }, { 100, 10 }, { 120, 20 },{ 120, 24 }};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum Total Value="<< FractionalKnapsack(W1, arr, n);





    return 0;
}
