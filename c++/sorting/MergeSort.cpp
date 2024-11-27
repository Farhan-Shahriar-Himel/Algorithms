#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int i, int mid, int j)
{
	int lsize = mid - i + 1;
	int rsize = j - mid;

	int left[lsize + 1], right[rsize + 1];

	for (int k = 0; k < lsize; k++) 
	{
		left[k] = a[i + k];
	}
	left[lsize] = INT_MAX;

	for (int k = 0; k < rsize; k++)
	{
		right[k] = a[mid + k + 1];
	} 
	right[rsize] = INT_MAX;

	int x = 0, y = 0;
	for (int k = i; k <= j; k++)
	{
		if (left[x] <= right[y]) a[k] = left[x++];
		else a[k] = right[y++];
	}
}

void merge_sort(int a[], int start, int end)
{
	int mid = start + ((end - start) / 2);
	
	if (start < end)
	{
		merge_sort(a, start, mid);
		merge_sort(a, mid + 1, end);
		merge(a, start, mid, end);
	}
}

int main()
{
	int n; cin >> n; int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	merge_sort(a, 0, n - 1);
	
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << "\n";
}