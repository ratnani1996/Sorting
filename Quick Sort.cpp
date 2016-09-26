#include<iostream>
using namespace std;




int swap_function(int *variable1,int *variable2)            //swapping the pivot and the left or right element depending on  the situation
{
    int temp=*variable1;
    *variable1=*variable2;
    *variable2=temp;
}




int find_pivot(int *unsorted,int left , int right)
{
    int  pivot=left;                        //always start pivot location from left in any sub arrays
    while(left<=right)
    {
        if(pivot==left)
        {
            if(unsorted[pivot]>unsorted[right])             //pivot is on the left side and we know that elements on the left side of the pivot should be smaller
            {
                swap_function(&unsorted[pivot],&unsorted[right]);   //since the element on the right of pivot is greater so swap and set the pivot to right element after swapping
                pivot=right;
            }
            else
                right--;
        }
        else if(pivot==right)
        {
            if(unsorted[pivot]<unsorted[left])      //pivot is on the right side and we know that elements on the right side of the pivot should be greater and on the left side should be smaller
            {
                swap_function(&unsorted[pivot],&unsorted[left]);    //since this is not the case swap pivot with left and move the pivot location to the left side
                pivot=left;
            }
            else
                left++;
        }
    }
    return pivot;
}
int quick_sort_function(int *unsorted,int left,int right)
{

    int pivot=find_pivot(unsorted,left,right);
    if(left<=right)
    {
        quick_sort_function(unsorted,left,pivot-1);   //this will sort the left side of the array
        quick_sort_function(unsorted,pivot+1,right);    //this will sort the right side of the array
    }

}
int main()
{
    int *unsorted;
    int n;
    cin>>n;
    unsorted=new int[n];
    for(int i=0;i<n;i++)
        cin>>unsorted[i];
    quick_sort_function(unsorted,0,n-1);
    for(int i=0;i<n;i++)
        cout<<unsorted[i]<<" ";
    delete []unsorted;
}


//End of program
