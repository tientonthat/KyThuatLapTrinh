#include <iostream>
#include <iomanip>

using namespace std;

int a[10][10];

void Print(int n)
{
	cout << "----------------------------"
		<< "\n Mang ket qua: \n";
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
			cout << setw(4) << a[i][j] << "  ";
		cout << "\n";
	}
	cin >> n;
}

void XoanOc(int k, int b, int n)
{
	if (n % 2 ==1 )
		if (b == (n / 2)) { a[n / 2][n / 2] = k; return; }
	if (b > n) { return; }

	for (int i = b; i < n - b; i++) a[b][i] = k++;
	for (int i = b + 1; i < n - b; i++) a[i][n-b-1] = k++;
	for (int i = (n - b - 1); i > b; i--) a[n-b-1][i-1] = k++;
	for (int i = (n - b - 1); i > b+1; i--) a[i-1][b] = k++;
	
	b++;
	XoanOc(k, b, n);

}

void main()
{
	XoanOc(1, 0, 10);
	Print(10);
}