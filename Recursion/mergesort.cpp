//****************************************************************************
//**********	MERGE SORT USING RECURSION 	******************** VERY IMPORTANT
//****************************************************************************
#include<iostream>
#include<conio.h>
using namespace std;
void merge(int *ar, int s, int e)
{
    int mid = s + (e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values to first array
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = ar[mainArrayIndex];
        mainArrayIndex++;
    }
    
    //copy values to second array
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = ar[mainArrayIndex];
        mainArrayIndex++;
    }
    
    //************now all values are copied to new two array so we can make changes to original array

    //now merging two array in single
        //create three variable
    int index1 = 0 ;
    int index2 = 0 ;
    mainArrayIndex = s; //intialize value to mainindex of array with start

    while(index1 < len1 && index2 < len2)
    {
        if(first[index1] < second[index2])
        {
            ar[mainArrayIndex] = first[index1];
            mainArrayIndex++;
            index1++;
        }
        else
        {
            ar[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1 < len1)
    {
        ar[mainArrayIndex] = first[index1];
            mainArrayIndex++;
            index1++;
    }
    while(index2 < len2)
    {
        ar[mainArrayIndex++] = second[index2++];
    }
    
    delete []first;
    delete []second;
}
void mergesort(int *ar, int s, int e)
{
    //base case
    if(s>=e)
        return ;
    
    //ek case solve kardo
    int mid = s + (e-s)/2;

        //left part sort karna hai
    mergesort(ar , s , mid);

        //RIGHT PART SORT KARNA HAI
    mergesort(ar, mid+1, e);

    merge(ar, s, e);

}
int main()
{
    system("cls");
    int ar[]={2,6,8,4,10};
    int n=size(ar);
    
    mergesort(ar, 0, n-1);

    cout<<"\n the sorted array using recursion :";
    for(int i=0;i<n ; i++)
    {
        cout<<ar[i]<<" ";
    }
    return 0;
    getch();
}

/*
SC - O(N)
TC -  O( n log n)

merge operation of merge sort can be implemented without extra space for linked lists

merge sort extra space leta hai isliye 
-prefered for linkedlist
-not prefered for array

it is not an in-place sorting technique

h.w - inversion count
*/