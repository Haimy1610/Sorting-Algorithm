#include <stdio.h>

enum bool {FALSE, TRUE};
#define MAX 5000
//Function display the array
void display(int num[], int low, int up)
{
    int i;
    for(i=low;i<=up;i++)
    {
        printf ("%d ",num[i]);
    }
}

//Function of Quick sort algorithm
void quickSort(int num[],int low,int up)
{
    int piv,temp,left,right;
    enum bool pivot_placed=FALSE;
    left=low;
    right=up;
    piv=low; //First element is pivot
    if(low>up)
        return;
    printf("low = %d\n",low);
    printf("up = %d\n",up);
    printf("Sublist: ");
    display(num,low,up);
    
    while(pivot_placed==FALSE)
    {
        //Compare from right to left
        while(num[piv]<=num[right] && piv!=right)
            right=right-1;
        if (piv==right)
            pivot_placed=TRUE;
        if (num[piv] > num[right])
        {
            temp=num[piv];
            num[piv]=num[right];
            num[right]=temp;
            piv=right;
        }
        //Compare from left to right
        while(num[piv]>=num[left] && left!=piv)
            left=left+1;
        if (piv==left)
            pivot_placed=TRUE;
        if (num[piv] < num[left])
        {
            temp=num[piv];
            num[piv]=num[left];
            num[left]=temp;
            piv=left;
        }
        printf (" -> Pivot Placed is %d -> ",num[piv]);
        display(num,low,up);
        printf ("\n");
        quickSort(num,low,piv-1);
        quickSort(num,piv+1,up);
    }
}
int main()
{
    int num[MAX],n,i;
    printf(" \nHow many numbers in the list? ");
    scanf ("%d", &n);
    for (i=0;i<n;i++)
    {
        printf ("\nAdd number %d: ",i+1);
        scanf ("%d",&num[i]);
    }
    printf (" \nNow the list you wanna sort is: ");
    display(num,0,n-1);
    printf ("\n");
               
    quickSort (num,0,n-1);
    printf ("\nSorted list in increasing is: ");
    display(num,0,n-1);
    printf ("\n");
}
