#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M,N;

char map[1500][1500];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

queue<pair<int,int>> Q;
pair<int,int> swan;

void input();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();


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
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for(int i=0; i<4; i++)
        {
            
        }
    }
}

void BFS_swan()
{

}