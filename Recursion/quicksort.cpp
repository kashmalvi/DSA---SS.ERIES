//****************************************************************************
//**********	QUICK SORT USING RECURSION	********************SHANDAAR PROGRAM
//****************************************************************************
#include <iostream>
#include <conio.h>
using namespace std;
int partition(int *ar, int s, int e)
{
    // take pivot
    int pivot = ar[s]; // element present in pivot

    // count all element smaller than pivot
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (pivot >= ar[i])
            count++;
    }

    // swap pivot to its right place
    int pivotIndex = s + count;
    swap(ar[s], ar[pivotIndex]);

    // left and right wala part arrange karenge
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        // already less than pivot in left wala part
        while (ar[i] <= pivot)  //here need to include '='
            i++;

        // already greater than pivot in right wala part
        while (ar[j] > pivot)   //here do not include '='
            j--;

        if (i < pivotIndex && j > pivotIndex)
        { // swaping ith and jth element
            swap(ar[i], ar[j]);
            // increment decrement
            i++;
            j--;
        }
    }

    return pivotIndex;
}
void quickSort(int *ar, int s, int e)
{
    // base case
    if (s >= e)
        return;

    // partition
    int p = partition(ar, s, e);

    // less than p wala part
    quickSort(ar, s, p - 1);

    // greater than p wala part
    quickSort(ar, p + 1, e);
}
int main()
{
    system("cls");
    int ar[] = {2, 4, 1, 6, 9,9,9,9,8,8,7,5,4,2,3,1,2,10,5,54,65,98,7,78};
    int n = size(ar);

    quickSort(ar, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    return 0;
    getch();
}

/*

SC - O(n)
TC - O(n log n) -for best and average case
    - O(n^2)    -for worst case
{ where n is the size of array }


quick sort extra space nahi leta hai isliye 
-not prefered for linkedlist
-prefered for array

-it is in-place sorting technique

-Quick Sort is also tail recursive, therefore tail call optimizations is done.

*/