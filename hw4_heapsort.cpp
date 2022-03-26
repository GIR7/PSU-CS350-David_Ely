#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;


void adjust(int arr[],int length,int index)
{
    int left=2*index+1;
    int right=2*index+2;
    int max=index;
    if(left<length && arr[left]>arr[max])
        max=left;
    if(right<length && arr[right]>arr[max])
        max=right;
    
    if(max != index)
    {
        swap(arr[max],arr[index]);
        adjust(arr,length,max);
    }
}
void heapsort(int arr[],int size)
{
    for(int i=size/2 - 1 ; i>=0; i--)//build the heap
    {
        adjust(arr,size,i);//i:parent of last data
    }

    for(int i=size-1;i>=1; i--)
    {
        swap(arr[0],arr[i]);//swap root and last,(prune last 
        adjust(arr,i,0);//re-heaped
    }
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
    heapsort(arr,n);  //function call
    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

