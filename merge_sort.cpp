#include<iostream>
using namespace std;

int merge(int unsorted[],int left,int middle,int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 =  right - middle;

    /* create temp unsortedays */
    int L[n1], R[n2];

    /* Copy data to temp unsortedays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = unsorted[left + i];
    for (j = 0; j < n2; j++)
        R[j] = unsorted[middle + 1+ j];

    /* Merge the temp unsortedays back into unsorted[l..r]*/
    i = 0; // Initial index of first subunsorteday
    j = 0; // Initial index of second subunsorteday
    k = left; // Initial index of merged subunsorteday
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            unsorted[k] = L[i];
            i++;
        }
        else
        {
            unsorted[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        unsorted[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        unsorted[k] = R[j];
        j++;
        k++;
    }
}
int merge_sort(int unsorted[],int left,int right)
{
    if(left<right)
    {
        int middle=(left+right)/2;
        merge_sort(unsorted,left,middle);       //sort left side of the array
        merge_sort(unsorted,middle+1,right);    //sort right side of the array
        merge(unsorted,left,middle,right);      //simply merge the two arrays
    }
}

int print_function(int unsorted[],int size)
{
    for(int i=0;i<size;i++)
        cout<<unsorted[i]<<" ";
    cout<<endl;
}

int main()
{
    int unsorted[100];
    int number_of_elements;
    cout<<"Enter total number of elements ";
    cin>>number_of_elements;
    for(int i=0;i<number_of_elements;i++)
        cin>>unsorted[i];
    merge_sort(unsorted,0,number_of_elements-1);
    print_function(unsorted,number_of_elements);

}
