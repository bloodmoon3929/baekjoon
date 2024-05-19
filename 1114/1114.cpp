#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
long long L, C, K;

bool possible(int mid) {
    int cut = 0, sum = 0;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] - arr[i - 1] > mid)
            return false;
        if (sum + arr[i] - arr[i - 1] > mid) {
            cut++;
            sum = arr[i] - arr[i - 1];
        } else {
            sum += arr[i] - arr[i - 1];
        }
    }
    return cut <= C;
}

long long binarySearch() {
    long long low = 0, high = L;
    while (low + 1 < high) {
        long long mid = (low + high) / 2;
        if (possible(mid)) 
            high = mid;
        else 
            low = mid;
    }
    return high;
}

int main() {
    cin >> L >> K >> C;
    arr.resize(K + 1);
    for (int i = 1; i <= K; ++i) {
        cin >> arr[i];
    }
    arr.emplace_back(L);
    sort(arr.begin(), arr.end());

    long long max_length = binarySearch();

    int index = K, sum = 0, cuts_left = C;
    for (int i = arr.size() - 1; i > 0; --i) {
        if (sum + arr[i] - arr[i - 1] > max_length) {
            sum = arr[i] - arr[i - 1];
            cuts_left--;
            index = i;
        } else {
            sum += arr[i] - arr[i - 1];
        }
    }
    if (cuts_left > 0) index = 1;

    cout << max_length << " " << arr[index] << endl;

    return 0;
}
