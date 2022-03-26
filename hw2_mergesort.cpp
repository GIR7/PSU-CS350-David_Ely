#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;


void Merge(int *array,int low, int mid, int high)
{
    int left=low;//left sub array[low,mid]
    int right=mid+1;//right sub array[mid+1,high]
    int k=0;
    int *temp=new int[high-low+1];
    while(left<=mid && right<=high)
    {
        if(array[left]>array[right])
            temp[k++]=array[right++];
        else
            temp[k++]=array[left++];
    }
    while(left<=mid)//finish processing non-complete side(left side)
    {
        temp[k++]=array[left++];
    }
    while(right<=high)//finish processing non-complete side(right side)
    {
        temp[k++]=array[right++];
    }
    for(left=low,k=0;left<=high;left++,k++)//copy sorted array back, certain low-high
    {
        array[left]=temp[k];
    }
    delete []temp;
}

void MergeSort(int *array,int low, int high)
{
    if(low>=high)//base case: only 1 element
        return;
    int mid = (low+high)/2;
    MergeSort(array,low,mid);//recursive call, left subarray
    MergeSort(array,mid+1,high);//recursive call. right subarray
    Merge(array,low,mid,high);
}

int main()
{
    int n;
    cout<<"Please input n: ";
    cin>>n;
    int arr[n];
    srand(time(NULL));//seeds
    for(int i=0;i<n; ++i)
    {
        int num=rand()%(n+1);//[0,n]
        arr[i]=num;//original array
    } 
    cout<<"Original array : "<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    MergeSort(arr,0,n-1);  //function call
    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

