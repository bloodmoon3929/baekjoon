#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int arr[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N, M;
    cin >> N >> M;

    arr[0] = 0;
    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    int result = INT_MAX;
    for(int start = 0; start <= N; start++)
    {
        int end = lower_bound(arr + start, arr + N + 1, M + arr[start]) - arr;
        if (end <= N)
            result = min(result, end - start);
    }

    cout << (result == INT_MAX ? 0 : result) << endl;

    return 0;
}
