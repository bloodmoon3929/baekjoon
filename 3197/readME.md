https://www.acmicpc.net/problem/3197

# 3197번 백조의 호수

## 문제
두 마리의 백조가 호수에서 살고 있었다. 그렇지만 두 마리는 호수를 덮고 있는 빙판으로 만나지 못한다.

호수는 행이 R개, 열이 C개인 직사각형 모양이다. 어떤 칸은 얼음으로 덮여있다.

호수는 차례로 녹는데, 매일 물 공간과 접촉한 모든 빙판 공간은 녹는다. 두 개의 공간이 접촉하려면 가로나 세로로 닿아 있는 것만 (대각선은 고려하지 않는다) 생각한다.

백조는 오직 물 공간에서 세로나 가로로만(대각선은 제외한다) 움직일 수 있다.

며칠이 지나야 백조들이 만날 수 있는 지 계산하는 프로그램을 작성하시오.

## 입력
입력의 첫째 줄에는 R과 C가 주어진다. 단, 1 ≤ R, C ≤ 1500.

다음 R개의 줄에는 각각 길이 C의 문자열이 하나씩 주어진다. '.'은 물 공간, 'X'는 빙판 공간, 'L'은 백조가 있는 공간으로 나타낸다.

## 출력
첫째 줄에 문제에서 주어진 걸리는 날을 출력한다.

## 코드
```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M,N;
bool found=false;

char map[1500][1500];
bool visited[1500][1500]={false};
//방문한 정점 기록(방문한 정점에 대해서 조사하지 않기 위해)

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
//상하좌우 이동할 때, 좌표에 더해야 하는 값

queue<pair<int,int>> Q,NQ,SQ,SNQ; 
//Q와 NQ는 BFS_water, SQ와 SNQ는 BFS_swan
//NQ는 얼음이 녹을 때, 기록하기 위함 다음 번에 조사할 Q
//SQ는 백조가 방문 가능한 물에 방문기록 visited를 기록하기 위함
//SNQ는 현재는 얼음이지만 추후 백조가 갈 수 있는 공간을 표시
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
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for(int i = 0; i < 4; i++)//상하좌우 이동
        {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0 && ny>=0 && nx < N && ny <M)//범위가 초과하지 않도록 하기 위함
            {
                if(map[nx][ny]=='X')//얼음을 녹이고, 다음에 녹기 시작할 좌표를 NQ에 저장
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
        //NQ를 재사용하기에 비워줘야 함
        NQ.pop();
    }
}

void BFS_swan()
{
    while(!SQ.empty())
    {
        int x = SQ.front().first;
        int y = SQ.front().second;
        SQ.pop();

        for(int i = 0; i < 4; i++)//상하좌우 이동
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx < N && ny <M)//범위가 초과하지 않도록 하기 위함
            {
                if(visited[nx][ny]==false)//방문한 곳을 다시 방문하지 않기 위해
                {
                    if(map[nx][ny]=='.')//물이라면
                    {
                        visited[nx][ny]=true;//방문 했음
                        SQ.push(make_pair(nx, ny));//해당 위치에서 다시 조사 해야함
                    }
                    else if (map[nx][ny]=='X')//얼음이라면
                    {
                        visited[nx][ny]= true;//방문 했음
                        SNQ.push(make_pair(nx,ny));//다음 번에는 이 얼음은 녹을 것임으로 조사대상임
                    }
                    else if(map[nx][ny]=='L')
                    {
                        found=true;//백조를 찾음
                        break;
                    }
                }
            }
        }
    }
    SQ=SNQ;
    while(!SNQ.empty())
    {
        //SNQ는 재사용해야하기에 비움
        SNQ.pop();
    }
}

void SOL()
{
    int count=0;//만날 날짜
    visited[swan.first][swan.second]=true;//백조의 위치는 방문한 것으로 처리
    SQ.push(make_pair(swan.first, swan.second));//백조 위치부터 조사 시작
    while(!found)//백조가 발견되지 않았다면
    {
        BFS_swan();
        if(!found)
        {
            BFS_water();
            count++;
        }
    }
    cout<<count;

}
```