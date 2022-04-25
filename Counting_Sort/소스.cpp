#include <iostream>
#include <vector>
#define MAX 10
using namespace std;

void counting_sort(int list[], int n, int m)
{
	vector<int> v(m + 1, 0);
	vector<int> t(n, 0);
	int i;
	for (i = 0; i < n; i++)
		v[list[i]]++;

	for (i = 1; i <= m; i++)
		v[i] += v[i - 1];

	for (i = 0; i < n; i++)
		t[--v[list[i]]] = list[i];

	for (i = 0; i < n; i++)
		list[i] = t[i];
}
int main()
{
	int arr[MAX] = { 2, 10, 2, 3, 6, 3, 2, 1, 3, 1 };

	for (int i = 0; i < MAX; i++)
		cout << arr[i] << ' ';
	cout << endl;

	counting_sort(arr, MAX, 10);

	for (int i = 0; i < MAX; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}