#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
using namespace std;

void tamato(tuple<int,int,int> par, vector<vector<int>>& box,queue<tuple<int,int,int>>& Q,int n, int m)
{
    int N=get<0>(par), M=get<1>(par), count=get<2>(par);
    if(N-1>=0&&box[N-1][M]==0)
    {
        box[N-1][M]=1;
        Q.push(tuple<int,int, int>(N-1,M,count+1));
    }
    if(N+1<m&&box[N+1][M]==0)
    {
        box[N+1][M]=1;
        Q.push(tuple<int, int, int>(N+1,M,count+1));
    }
    if(M-1>=0&&box[N][M-1]==0)
    {
        box[N][M-1]=1;
        Q.push(tuple<int, int, int>(N,M-1,count+1));
    }
    if(M+1<n&&box[N][M+1]==0)
    {
        box[N][M+1]=1;
        Q.push(tuple<int, int, int>(N,M+1, count+1));
    }
}
bool is_complete(int n, int m, vector<vector<int>> box)
{
    for(int i=0; i<m;i++)
        for(int j=0; j<n;j++)
            if(box[i][j]==0)
                return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n,input,temp;
    queue<tuple<int, int, int>> Q;
    cin>>n>>m;
    vector<vector<int>> box(m, vector<int>(n));
    for(int i=0; i<m;i++)
    {
        for(int j=0; j<n;j++)
        {
            cin>>input;
            if(input==1)
            {
                Q.push(tuple<int, int,int>(i,j,0));
            }
            box[i][j]=input;
        }
    }
    while(!Q.empty())
    {
        tamato(Q.front(),box,Q,n,m);
        temp=get<2>(Q.front());
        Q.pop();
    }
    if(is_complete(n,m,box))
        cout<<temp<<'\n';
    else
        cout<<"-1\n";
    return 0;
}