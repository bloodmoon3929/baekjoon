#include<iostream>
#include<vector>

using namespace std;

pair<int, int> fibonacci(int ans)
{
    if(ans==0)
    {
        return pair<int, int> (1,0);
    }
    else if(ans==1)
    {
        return pair<int, int> (0,1);
    }
    else
    {
        int i=1;
        vector<pair<int, int>> sum;
        sum.push_back(make_pair(1,0));
        sum.push_back(make_pair(0,1));
        for(; i<ans; i++)
        {
            sum.push_back(make_pair(sum[i].first+sum[i-1].first,sum[i].second+sum[i-1].second));
        }
        return sum[i];
    }
}

int main()
{
    int a,b;
    pair<int,int> temp;
    cin>>a;
    for(int i=0; i<a; i++)
    {
        cin>>b;
        temp= fibonacci(b);
        cout<<temp.first<<" "<<temp.second<<endl;
    }

}