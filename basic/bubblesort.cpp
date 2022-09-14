//****************************************************************************
//********************* BUBBLE SORT VIA ARRAY********************************
//****************************************************************************
#include<iostream>
#include<conio.h>
#include<algorithm>
using namespace std;

void bubble(int *arr, int z){               //receive array in pointer as actual argument by reference
        int minindex;
        for (int i = 0; i < z-1; i++)
        {   
            minindex=i;
            for(int j=i ; j<z-1 ; j++ ){
            if(arr[minindex]>arr[j+1])
                swap(arr[minindex], arr[j+1]);
            }
        }
        
}

int main()
{
    system("cls"); 
    int ar[]{10,1,7,6,14,9,89,65,12,30,54,75,99,11};
    int s = size(ar);
    cout<<"\n after sorting an array via bubble sort:"<<endl;
    bubble(ar, s);
    for (int i = 0; i < s; i++)
    {
        cout<<ar[i]<<"\t";
    }
    
    return 0;
    getch();
}

/*
COMPLEXITY-----
    space       -   O(1)
    time        -   O(n^2)
    best case   -   already sorted O(n)     , if no swapping done
    worse case  -   reverse sorted O(n^2)  
*/