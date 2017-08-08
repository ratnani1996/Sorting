#include<iostream>

using namespace std;

int *insertion_sort(int *unsorted, int size){

    for(int i=0; i<size; i++){
        int j = i+1;
        for(int k = i; k>= 0; k--){
            while(unsorted[k] > unsorted[j] && j!=-1){          //if left element is greater than right element swap the numbers
                swap(unsorted[k], unsorted[j]);
                j--;
            }
        }
    }
    return unsorted;
}


int main(){
    int *unsorted;  //using dynamic arrays
    int n;
    cout<<"Enter the size of the array :";
    cin>>n;
    unsorted = new int[n];
    cout<<"Enter the unsorted array :\n";
    for(int i=0; i<n; i++){
        cin>>unsorted[i];
    }
    unsorted = insertion_sort(unsorted, n); //call to insertion sort function and return the pointer and store it in the variable
    for(int i=0; i<n; i++){
        cout<<unsorted[i];
    }
    delete []unsorted;
}
