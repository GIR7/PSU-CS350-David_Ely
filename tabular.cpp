#include <iostream>

using namespace std;

int main()
{
    int r,c;
    cout<<"Input number of rows and columns."<<endl;
    cin>>r;
    
    cin.ignore(100,'\n');
    cin>>c;
    cin.ignore(100,'\n');

    //allocate the 2d array
    int **arr = new int*[r];//rows
    for(int i=0;i<r;++i)
    {
        arr[i] = new int[c];//columns
    }

    cout<<"Input data"<<endl;
    for(int i=0;i<r;++i)
    {
        for(int j=0;j<c;++j)
        {
            cin>>arr[i][j];
        }
    }



    return 0;

}


