#include<iostream>

int main()
{
    using namespace std;
    int n,count=0;
    char ch;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>ch;
        if(ch=='L')
        {
            count++;
        }   
    }
    count/=2;
    if(count==0)
    {
        cout<<n<<endl;
    }
    else
    {
        cout<<n-(count-1)<<endl;
    }
    
    return 0;
}