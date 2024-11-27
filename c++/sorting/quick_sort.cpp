#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int low, int high)
{
	int pivot = a[low];
	int i = low + 1;
	int j = high;

	while (i <= j)
	{
		while (i <= j and a[i] <= pivot) i++;
		while (j >= i and a[j] > pivot) j--;
		
		if (i < j) swap(a[i], a[j]);
	}

	swap(a[low], a[j]);
	return j;
}

void quick_sort(int a[], int low, int high)
{
	if (low >= high) return;

	int pi = partition(a, low, high);
	quick_sort(a, low, pi - 1);
	quick_sort(a, pi + 1, high);

}


int main()
{
	int n; cin >> n; int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	quick_sort(a, 0, n - 1);

	for (int i = 0; i < n; i++) cout << a[i] << " ";

	cout << "\n";

	return 0;
}