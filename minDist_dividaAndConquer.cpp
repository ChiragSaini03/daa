#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <algorithm>
using namespace std;

float dist2pts(int *p1, int *p2)    // function to calculate the distance between two points
{
	return  abs(p1[0] - p2[0]) +
				abs(p1[1]-p2[1]); // manhatten distance
}
float getMin(int **arr, int n)
{   // function to find the minimum distance from any 2 pair of points
    // this is a bruteforce approach for solving the problem
    // but it will increase complexity thus it is only being used for a maximum of 3 points
	float min = FLT_MAX;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			if (dist2pts(arr[i], arr[j]) < min)
				min = dist2pts(arr[i], arr[j]);
	return min;
}
float stripClosest(int** strip, int size, float d)
{
    // this returns the minmum distance taking the strip which divides the 2 blocks in divide and conquer
	float min = d; 
	sort(strip,strip+size,[](int *arr1,int *arr2){return arr1[1]<arr2[1];});
	for (int i = 0; i < size; ++i)
		for (int j = i+1; j < size && (strip[j][1]- strip[i][1]) < min; ++j)
			if (dist2pts(strip[i],strip[j]) < min)
				min = dist2pts(strip[i], strip[j]);

	return min;
}
float manhattenDist(int** arr,int n)
{   // this is the main function for divide and conquer approach 
    if (n<=3){
        return getMin(arr,n);
    }
	int mid = n/2;
	int* midPoint = arr[mid];
	float dl = manhattenDist(arr, mid);
	float dr = manhattenDist(arr + mid, n-mid);
	float d = min(dl, dr);
    // now the minimum for the left, right and the strip is to be found
	int** strip=new int*[n];
    for (int i=0;i<n;i++) strip[i]=new int[2];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (abs(arr[i][0] - midPoint[0]) < d)
			strip[j][0] = arr[i][0],strip[j][1]=arr[i][1], j++;
	return min(d, stripClosest(strip, j, d) );
}
float closest(int **arr, int n)
{
    sort(arr,arr+n,[](int *arr1,int *arr2){return arr1[0]>arr2[0];}); // creating a custon comparison func for sorting
	return manhattenDist(arr, n);
}
int main(){
    int n;
    cout<<"Enter number of boats: ";
    cin>>n;
    int **arr=new int*[n]; // 2-D array to store the points in the plane arr(nx2)
    for (int i=0;i<n;i++){
        arr[i]=new int[2];
    }
    for (int i=0;i<n;i++){
        cin>>arr[i][0];
        cin>>arr[i][1];
    }
    cout<<"Minimum Distance is: "<<closest(arr,n);
    return 0;
}