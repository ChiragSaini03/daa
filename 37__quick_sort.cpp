#include <iostream>
using namespace std;

int partition(int input[],int si,int ei){
    if (si>=ei) return si;
    int pivot=input[si], ind=si;
    for (int i=si+1;i<=ei;i++){
        if (input[i]<pivot) ind++;
    }
    for (int i=si;i<ind;i++){
        input[i]=input[i+1];
    }
    input[ind]=pivot;
    int indPoint=ind+1;
    for (int i=si;i<ind;i++){
        if (input[i]>pivot){
            int temp=input[i];
            while(input[indPoint]>pivot) indPoint++;
            input[i]=input[indPoint];
            input[indPoint]=temp;
            indPoint++;
        }
    }
    indPoint=si;
    for (int i=ind+1;i<=ei;i++){
        if (input[i]<pivot){
            int temp=input[i];
            while(input[indPoint]<pivot) indPoint++;
            input[i]=input[indPoint];
            input[indPoint]=temp;
            indPoint++;
        }
    }
    return ind;
}
void quickSortHelper(int input[], int start, int end)
{
    if (start>=end) return;
    // for (int i=start;i<=end;i++) cout<<input[i]<<" ";
    // cout<<endl;
    int c=partition(input,start,end);
    quickSortHelper(input,start,c-1);
    quickSortHelper(input,c+1,end);
}
void quickSort(int input[], int size)
{
    return quickSortHelper(input,0,size-1);
}

int main(){
    int arr[10]={9, 7, 4, 8, 6, 8, 3, 1, 7, 10};
    // -->       2 3 4 5 7 8 9 10 13 15
    quickSort(arr,10);
    for (int i=0;i<10;i++) cout<<arr[i]<<" ";
    return 0;
}

// --> ind should be the index but here is the number of elements less than pivot