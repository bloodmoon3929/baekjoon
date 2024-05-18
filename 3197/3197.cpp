#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M,N;
<<<<<<< HEAD
bool found=false;
=======
bool findswan=false;
>>>>>>> c95bb75735e5a5e15162cb93718114918c65a81a

char map[1500][1500];
bool visited[1500][1500]={false};
//방문한 정점 기록(방문한 정점에 대해서 조사하지 않기 위해)

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

<<<<<<< HEAD
queue<pair<int,int>> Q,NQ,SQ,SNQ; //Q와 NQ는 BFS_water, SQ와 SNQ는 BFS_swan
=======
queue<pair<int,int>> Q,NextQ;
>>>>>>> c95bb75735e5a5e15162cb93718114918c65a81a
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
<<<<<<< HEAD
=======

>>>>>>> c95bb75735e5a5e15162cb93718114918c65a81a
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

        for(int i = 0; i < 4; i++)
        {
<<<<<<< HEAD
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0 && ny>=0 && nx < N && ny <M)
            {
                if(map[nx][ny]=='X')
                {
                    map[nx][ny]='.';
                    NQ.push(make_pair(nx,ny));
                }
            }
        }
    }
    Q=NQ;
    while(!NQ.empty())
    {
        NQ.pop();
    }
=======
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
>>>>>>> c95bb75735e5a5e15162cb93718114918c65a81a
}

void BFS_swan()
{
<<<<<<< HEAD
    while(!SQ.empty())
    {
        int x = SQ.front().first;
        int y = SQ.front().second;
        SQ.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx < N && ny <M)
            {
                if(visited[nx][ny]==false)
                {
                    if(map[nx][ny]=='.')
                    {
                        visited[nx][ny]=true;
                        SQ.push(make_pair(nx, ny));
                    }
                    else if (map[nx][ny]=='X')
                    {
                        visited[nx][ny]= true;
                        SNQ.push(make_pair(nx,ny));
                    }
                    else if(map[nx][ny]=='L')
                    {
                        found=true;
                        break;
                    }
                }
            }
        }
    }
    SQ=SNQ;
    while(!SNQ.empty())
    {
        SNQ.pop();
    }
}

void SOL()
{
    int count=0;
    visited[swan.first][swan.second]=true;
    SQ.push(make_pair(swan.first, swan.second));
    while(!found)
    {
        BFS_swan();
        if(!found)
        {
            BFS_water();
            count++;
        }
    }
    cout<<count;
=======
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
>>>>>>> c95bb75735e5a5e15162cb93718114918c65a81a

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