#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M,N;
bool findswan=false;

char map[1500][1500];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

queue<pair<int,int>> Q,NextQ;
pair<int,int> swan;

void input();
void BFS_water();
void BFS_swan();
void SOL();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    SOL();

}

void input()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>map[i][j];
            if(map[i][j]!='X')
            {
                // 처음에는 물과 백조에서 모두 조사해야 하기에 얼음을 제외한 모든 값을 기록
                Q.push(make_pair(i,j));
            }
            
            if(map[i][j]=='L')
            {
                //백조는 어디서 측정하든 상관 없음으로 한 개만 기록
                swan.first = i;
                swan.second =j;
            }
        }
    }
}

void BFS_water()
{
    while(!Q.empty())
    {
        int nx, ny;
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for(int i=0; i<4; i++)
        {
            nx= x+dx[i];
            ny= y+dy[i];
            if(nx>0 && ny>0 && nx<N && ny<<M)
            {
                //범위에 맞게 조사하도록 제한
                if(map[nx][ny]=='X')
                {
                    //얼음 발견시 물로 만들고, 그 물을 다음에 조사할 queue에 집어넣음
                    map[nx][ny]=='.';
                    NextQ.push(make_pair(nx,ny));
                }
            }
            
        }
    }
    Q=NextQ;
}

void BFS_swan()
{
    int nx, ny;
    int x = swan.first;
    int y = swan.second;
    
    for(int i=0; i<4; i++)
    {
        nx= x+dx[i];
        ny= y+dy[i];
        BFS_swan();
        if(map[nx][ny]=='X')
        {
            break;
        }
        if(map[nx][ny]=='L')
        {
            findswan=true;
            return;
        }
    }
}

void SOL()
{
    int count=0;
    while(!findswan)
    {
        BFS_swan();
        if(findswan)
        {
            cout<<count;
            return;
        }
        BFS_water();
    }
}