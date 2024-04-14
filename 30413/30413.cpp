#include <iostream>

using namespace std;

#define MOD 1000000007

long long power(long long base, long long exp);

int main() {
    long long N, M, A, B;
    cin >> N >> M;

    A=(power(N,M)-1)%MOD;
    B=(power(N-1, MOD-2))%MOD;

    cout << (A*B)%MOD << endl;



    return 0;
}


long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) 
    {
        if (exp % 2 == 1) 
        {
            result = (result%MOD * base%MOD) % MOD;
        }
        base = (base%MOD * base%MOD) % MOD;
        exp /= 2;
    }
    return result;
}