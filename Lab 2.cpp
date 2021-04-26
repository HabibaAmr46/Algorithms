#include <iostream>

using namespace std;
//using Powering
void multiply(int F[2][2], int M[2][2]);
void power(int F[2][2], int n);

int fibPowering(int n)
{
    int F[2][2] = { { 1, 1 }, { 1, 0 } };

    if (n == 0)
        return 0;

    power(F, n - 1);

    return F[0][0];
}

void multiply(int F[2][2], int M[2][2])
{
    int x = F[0][0] * M[0][0] +
            F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] +
            F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] +
            F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] +
            F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(int F[2][2], int n)
{
    int i;
    int M[2][2] = { { 1, 1 }, { 1, 0 } };

    for(i = 2; i <= n; i++)
        multiply(F, M);
}
// using recursion

int fibRecursion(int n)
{
    if(n<=1)
        return n;
    return fibRecursion(n-1)+fibRecursion(n-2);
}

// using DynamicProgramming
int fibDynamic(int n)
{
    int F[n+2];
    F[0]=0;
    F[1]=1;
    for(int i=2;i<=n;i++)
    {
        F[i]=F[i-1]+F[i-2];
    }
    return F[n];
}

int main()
{
  cout<<fibRecursion(6)<<endl;
   cout<<fibDynamic(6)<<endl;
    cout<<fibPowering(6)<<endl;
    return 0;
}
