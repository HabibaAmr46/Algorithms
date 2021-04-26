#include <iostream>
#include<chrono>
#include<algorithm>
#include<time.h>
#include <stdio.h>
using namespace std;
clock_t tStart ;
clock_t t1;
int seqSearch(int* a , int l , int h , int i)
{
	tStart = clock();
	if (l > h) {
		return -1;
	}
	else if (a[l] == i) {
	return l;
	}
	else if (a[h] == i) {
		return h;
	}
	else {
		return seqSearch(a, l + 1, h - 1, i);
	}
}
int binSearch(int* a, int l, int h, int i)
{
	t1 = clock();
	if (l <= h)
	{
		int mid = (l + h) / 2;
		if (a[mid] > i)  return binSearch(a, l, mid - 1, i);
		if (a[mid] < i)  return binSearch(a, mid + 1, h, i);
		if (a[mid] == i) return mid;
	}
	return -1;
}
void fillArrays(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i+1;
	}
}
int main()
{
	int a[1000];
	int a1[10000];
	int a2[100000];
	fillArrays(a, 1000);
	fillArrays(a1, 10000);
	fillArrays(a2, 100000);

	cout << seqSearch(a, 0, 999, a[999]) << endl;
	printf("Time taken by sequential search: %.2fMs\n", ((double)(clock() - tStart) / CLOCKS_PER_SEC) * 1000000);
	cout << binSearch(a, 0, 999, a[999]) << endl;
	printf("Time taken by binary search: %.2fMs\n", ((double)(clock() - t1) / CLOCKS_PER_SEC) * 1000000);
    cout<<"****************************************************************************************"<<endl;
	cout << seqSearch(a1, 0, 9999, a2[9999]) << endl;
	printf("Time taken sequential search: %.2fMs\n", ((double)(clock() - tStart) / CLOCKS_PER_SEC) * 1000000);
	cout << binSearch(a1, 0, 9999, a2[9999]) << endl;
	printf("Time taken binary search: %.2fMs\n", ((double)(clock() - t1) / CLOCKS_PER_SEC) * 1000000);
    cout<<"****************************************************************************************"<<endl;
	cout << seqSearch(a2, 0, 99999,a2[99999]) << endl;
	printf("Time taken sequential search: %.2fMs\n", ((double)(clock() - tStart) / CLOCKS_PER_SEC)* 1000000);
	cout << binSearch(a2, 0, 99999, a2[99999]) << endl;
	printf("Time taken binary search: %.2fMs\n", ((double)(clock() - t1) / CLOCKS_PER_SEC) * 1000000);
	return 0;
}
