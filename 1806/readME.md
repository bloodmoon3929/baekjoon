https://www.acmicpc.net/problem/1806

# 부분합
|시간제한|메모리 제한|정답비율|
|--|--|--|
|0.5초|128 MB|25.895%|

자바의 경우 1초까지 허용

## 문제
10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다. 이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.

## 입력
첫째 줄에 N (10 ≤ N < 100,000)과 S (0 < S ≤ 100,000,000)가 주어진다. 둘째 줄에는 수열이 주어진다. 수열의 각 원소는 공백으로 구분되어져 있으며, 10,000이하의 자연수이다.

## 출력
첫째 줄에 구하고자 하는 최소의 길이를 출력한다. 만일 그러한 합을 만드는 것이 불가능하다면 0을 출력하면 된다.

# 코드
```cpp
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
```

### 문제의 핵심
다른 문제와 달리 시간 제한이 0.5 초이기에, 최대한 빠른 시간내에 문제를 풀수 있어야함.

### 시간 단축을 위한 코드
```cpp
int arr[100001];
```
```cpp
ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
```
### 누적합의 입력
```cpp
 arr[0] = 0;
    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
```
arr의 인덱스의 0번을 0으로 저장한 이유는, 누적합 입력을 편하게 받기 위해 사용

### 출력
```cpp
    int result = INT_MAX;
```
```cpp
    cout << (result == INT_MAX ? 0 : result) << endl;
```
 result의 초기값은 INT_MAX로 초기화 되어있고, 다음 소개할 코드에서 값이 변하지 않았다면 0을 출력, 변하였다면 result를 출력하게 되어있습니다.

 ### 누적합 비교
 ```cpp
 for(int start = 0; start <= N; start++)
    {
        int end = lower_bound(arr + start, arr + N + 1, M + arr[start]) - arr;
        if (end <= N)
            result = min(result, end - start);
    }
 ```

 * lower_bound<br>
  전달인자로 3가지를 받는 데,
  1. 배열의 시작 주소
  2. 배열의 끝 주소
  3. 찾고자 하는 값<br>
만일 찾고자 하는 값보다 큰 값을 찾았다면, 해당 값의 주소를 반환합니다.<br>
만일 찾지 못하였다면, 2번째 전달인자의 다음 위치를 반환합니다.


다음 반복문은 끝 위치는 고정한채 시작위치를 변경하여 시작점과 끝 점의 길이가 가장 짧은 위치를 찾는 코드입니다. 문제의 예시를 기준으로 다음과 같이 작동할 것입니다.<br>

|0|5|6|9|14|24|31|35|44|46|54|
|-|-|-|-|-|-|-|-|-|-|-|

|반복 횟수|값 발견(arr[find]>=M+arr[start])|반환값(arr[end]-arr[start])|
|--|-|-|
|1|24>=15+0|5-1=5|
|2|24>=15+5|5-1=4|
|3|24>=15+6|5-2=3|
|4|24>=15+9|5-3=2|
|5|31>=15+14|6-4=2|
|6|44>=15+24|7-4=3|
|7|46>=15+31|8-5=3|
|8|54>=15+35|9-6=3|
|9|값을 찾을수 없음|11-7=4|
|10|값을 찾을수 없음|11-8=3|
|11|값을 찾을수 없음|11-9=2|
|12|값을 찾을수 없음|11-10=1|

if문 조건에 따라 N보다 큰 값은 포함하지 않음으로 값을 찾을 수 있는 범위에서 동작할 것입니다.<br>
만일 if문이 존재하지 않는다면 결과는 항상 1이 출력될 것입니다.