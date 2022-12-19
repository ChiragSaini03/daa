// Matrix chain multiplication
// Lab Assignment 7
// Chirag Saini
// 2021UCS1564

#include <iostream>
using namespace std;

void orderpar(int i, int j, int n, int* bckt,char& nm){		// printing the required order for matrix multiplication
	if (i == j) {
		cout << nm++;
		return;
	}
	cout << "(";
	orderpar(i, *((bckt + i * n) + j), n,bckt, nm);
	orderpar(*((bckt + i * n) + j) + 1, j, n,bckt, nm);
	cout << ")";
}
void matrixChainMultiplication(int arr[], int n){
	int m[n][n];
	int bckt[n][n];
	for (int i = 1; i < n; i++)
		m[i][i] = 0;
	for (int L = 2; L < n; L++)
	{
		for (int i = 1; i < n - L + 1; i++)
		{
			int j = i + L - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++)
			{
				int q = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
				if (q < m[i][j])
				{
					m[i][j] = q;
					bckt[i][j] = k;
				}
			}
		}
	}
	char nm = 'A';
	cout << "Best Multiplication with optimal solution is : ";
	orderpar(1, n - 1, n, (int*)bckt, nm);
	cout << "Optimal Cost for the given problem is : " << m[1][n - 1];
}

int main()
{
    int n;
    cin>>n;
    int arr1[n][2];
    for (int i=0;i<n;i++){
        cin>>arr1[i][0];
        cin>>arr1[i][1];
    }
    int arr[n+1];
    for (int i=0;i<n;i++){
        arr[i]=arr1[i][0];
    }
    arr[n]=arr1[n-1][1]; // --> arr contain the arr containing the element of arr1 once
	matrixChainMultiplication(arr, n+1);
	return 0;
}