#include<iostream>
using namespace std;

int bubble_sort(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-i;j++)
        {
            if(array[j]>array[j+1])
                swap(array[j],array[j+1]);
        }
    }
}

int display_array(int array[],int size)
{
    for(int i=0;i<size;i++)
        cout<<array[i]<<" ";


}

int main()
{
    int array[]={5,4,3,2,1};
    int size=sizeof(array)/sizeof(int);
    cout<<"Array before sorting :\n";
    display_array(array,size);
    cout<<"\n";
    bubble_sort(array,size);
    cout<<"Array after sorting :\n";
    display_array(array,size);
}
