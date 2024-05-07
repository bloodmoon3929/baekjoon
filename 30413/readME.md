https://www.acmicpc.net/problem/30413

# 양 한마리... 양 A마리... 양 A제곱마리...

## 문제
춘배는 오늘도 열심히 활동을 마친 후 자려 하지만 도저히 잠이 안 온다. 춘배는 잠을 자기 위해 자신만의 방법으로 양을 세려는데 한 마리씩 세지 않고 여러 마리를 한꺼번에 세면서 자려 한다.

춘배는 일단 양의 정수 
$A$를 정한다. 그 후 양을 셀 때 첫 번째에 센 양의 수는 항상 
$1$로 두고, 그 뒤 두 번째에 센 양의 수는 
$A$, 세 번째에 센 양의 수는 
$A^{2}$ 이렇게 점점 양의 수를 세어 간다. 즉, 
$n$번째에 센 양의 수는 
$A^{n-1}$ 가 된다.

춘배는 이러한 방식으로 양을 세다 문득 자신이 첫 번째부터 
$B$번째까지 센 모든 양의 수가 얼마나 될지 궁금해졌다. 춘배를 위해 첫 번째부터 마지막 
$B$번째까지 센 모든 양의 수가 몇 마리인지 구해보자! 하지만 수가 너무 커질 수 있기에 
$1\,000\,000\,007(= 10^{9} + 7)$로 나눈 나머지를 구하자.

## 임력
첫 번째 줄에 양의 정수 
$A$, 
$B$ 가 공백으로 구분되어 주어진다. 
$(1 \le A \le 1\,000$, 
$ 1 \le B \le 10^{12})$ 

## 출력
첫 번째부터 
$B$번째까지 센 모든 양의 수를 
$1\,000\,000\,007$로 나눈 나머지를 출력한다.

# 해답
해당 문제는 등비수열을 활용하는 문제로 수식은 다음과 같습니다.

$\frac{(첫쩨 항)(1-N^M)}{(1-N)}$

여기서 N은 등비, M은 항수입니다.

이 문제에서 첫째항은 항상 1이라 하였기에 이를 활용하여 코드를 작성하면

```cpp
#include <iostream>

using namespace std;

#define MOD 1000000007

long long power(long long base, long long exp);

int main() {
    long long N, M, A, B;
    cin >> N >> M;

    A=(power(N,M)-1)%MOD;
    B=(power(N-1, MOD-2))%MOD;


    if(N==1)
        cout<<(N*M)%MOD;
    else
        cout<< (A*B)%MOD << endl;



    return 0;
}


long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) 
    {
        if (exp % 2 == 1) 
        {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}
```

### long long power(long long base, long long exp)
제곱을 구하기 위해 사용

### if문

N이 1일 경우 수식이 0이 되어 오답이 됨