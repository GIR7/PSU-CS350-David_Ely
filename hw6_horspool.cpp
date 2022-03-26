#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int horspool(char text[], char pattern[])
{
    int count =0;
    int k =0;
    int table[128];
    int m = strlen(pattern);
    int n = strlen(text);
    printf("The pattern has %d characters and the text has %d characters.\n",m,n);
    for (int i = 0;i<128;++i)
        table[i] = m;
    for(int i=0; i< m-1;++i)
        table[pattern[i]] = m-i-1;

    int i = m-1;
    int check = m-1;
    while ( i<= n-1)
    {
        ++count;
        k=0;
        while(k<= m-1 && pattern[m-1-k] == text [i-k] )
        {
            if(check != m-1)
            {
                count++;
            }
            k++;
            check--;
        }
        if(k == m)
        {
           printf("%d times comparisons\n ",count);
           return i-m+1;
        }
        else
            i = i+table[text[i]];//slides
    }
    printf("%d times comparisons\n ",count);
    return -1;

}
    
int main()
{
    char text[10000];
    char pattern[200];
    printf("enter text :");
    scanf("%s",text);
    printf("enter pattern you are searching for : ");
    scanf("%s",pattern);
    int i=horspool(text,pattern);
    printf("The position is : %d\n", i);
    return 0;
}


/*
void table(string & pattern,int ascii[])
{
    int len = pattern.length();//get the length of pattern:m
    for(int i=0; i<128;++i)
    {
        ascii[i] = len;//initialize the table to the m
    }
    for(int i=0;i<len-1;++i)
    {
        ascii[pattern[i]] = len - i -1;//set the specific value in the ascii
    }
}

void horspool(string & text, string & pattern , int ascii[])
{
    int j{0};
    int pos{0};//index of the string
    bool flag{false};
    int plen = pattern.length();
    int tlen = text.length();
    while (pos <= tlen - plen)
    {
        j = plen -1;
        while ( j>= 0 && pattern[j] == text[pos+j] )
        {
            --j;
            if(j == -1)
            {
                flag = true;
                cout<< " Position of the text:"<<pos+1<<endl;
            }
            else
                pos += ascii[ text[pos+plen-1] ];//slides
        }
        if(!flag)
            cout<<"Position of the text : -1"<<endl;
    }
}

int main()
{
    int ascii[128];
    string t, p;
    cout<<"Pattern"<<endl;
    cin>>p;
    cout<<"Text :"<<endl;
    cin>>t;

    table(p,ascii);
    horspool(t,p,ascii);

    return 0;
}

*/

