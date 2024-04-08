#include<iostream>
#include<map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num, temp, n1, n2, n3;
    map<int, bool> ma;

    cin >> num;
    for(int i = 0; i < num; i++)
    {
        cin >> temp;
        ma[temp] = true;
    }

    cin >> num;
    for(int i = 0; i < num; i++)
    {
        cin >> temp;
        cout << ma[temp] << " ";
    }

    return 0;
}