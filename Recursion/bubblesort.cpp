//****************************************************************************
//***************	BUBBLE SORT USING RECURSION	    *************************
//****************************************************************************
#include<iostream>
#include<conio.h>
using namespace std;
void bblsort(int *ar , int n)
{
    ///base case
    if(n==0 || n==1)
        return ;
    
    //ek case solve kardo
    for(int i = 0; i<n-1 ; i++)
    {
        if(ar[i] > ar[i+1])
            swap(ar[i], ar[i+1]);
    }

    //recursion call
    bblsort(ar , n-1);

}
int main()
{
    system("cls");
    int arr[] = {10,7,6,4,1,9};
    int n = size(arr);
    bblsort(arr,n);
    cout<<"\n the sorted element in an array is :";
    for(int i = 0 ; i< n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
    getch();
}

/*
Time Complexity: O(n*n)
            We are calling the same function recursively for each element of the array and inside the function,
                 we are looping till the given length of the array, So Time complexity is O(n ^ n) = O(n ^ 2).

Space Complexity: O(n)
            We are recursively calling the function for each element of the array, So space complexity is O(n).

*/