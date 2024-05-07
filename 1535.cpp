#include<iostream>

using namespace std;

int main()
{
    int N, temp = 0;
    int arr[21][100] = {-1};
    int memory[2][20];

    cin >> N;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < N; j++)
            cin >> memory[i][j];
    for (int i = 0; i < 21; i++)
        arr[i][0] = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= 99; j++)
            if (j - memory[0][i - 1] >= 0)
                arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - memory[0][i - 1]] + memory[1][i - 1]);
            else
                arr[i][j] = arr[i - 1][j];
    for (int i = 0; i <= 99; i++)
        if (temp < arr[N][i])
            temp = arr[N][i];
        
    cout << temp;
}
