#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class device
{
public:
    int profit;
    int price;
    device(int pf,int p)
    {
        profit=pf;
        price=p;
    }
};
int maxx(int x, int y)
{
    if(x>y)
        return x;
    return y;
}


int knapSack(int W, device arr[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (arr[i - 1].price <= w)
                K[i][w] = maxx(arr[i - 1].profit
                               + K[i - 1][w - arr[i - 1].price],
                               K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main()
{
    device arr[] = { {14,8},{5,3},{8,5},{3,1},{6,4},{28,20},{10,7},{27,22} };

    int W = 30;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Maximum Profit= "<<knapSack(W,arr, n)<<"k"<<endl;
    return 0;
}
