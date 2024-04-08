#include <iostream>
#include <vector>
#include <algorithm>

class Friend
{
public:
    int happy = 0;
    int stress = 0;
    double stress_per_happy = 0;
    bool is_used=true;

    Friend(int s, int h)
    {
        happy = h;
        stress = s;
        stress_per_happy = (double)h / s;
    }
};

int main()
{
    int n, sum_happy = 0, sum_stress=0;
    using namespace std;
    cin >> n;
    vector<Friend> f;
    vector<pair<int, int>> pa(n);

    for (int i = 0; i < n; i++)
        cin >> pa[i].first;

    for (int i = 0; i < n; i++)
        cin >> pa[i].second;

    for (int i = 0; i < n; i++)
    {
        Friend tmp = Friend(pa[i].first, pa[i].second);
        f.push_back(tmp);
    }

    sort(f.begin(), f.end(), [](const Friend &a, const Friend &b) { return a.stress_per_happy > b.stress_per_happy; });
    
    int i = 0;
    
    while (sum_stress < 100 && i < n)
    {
        sum_happy += f[i].happy;
        f[i].is_used=false;
        sum_stress += f[i++].stress;
    }
    if(sum_stress>=100)
    {
        sum_stress-=f[--i].stress;
        f[i].is_used=true;
        sum_happy-=f[i].happy;
    }
    vector<Friend> ne;
    for(int i=0; i<n; i++)
    {
        if(100-sum_stress>f[i].stress&&f[i].is_used)
            ne.push_back(f[i]);
    }
    i=0;
    while(sum_stress<100&&i<ne.size())
    {
        sum_happy += ne[i].happy;
        sum_stress += ne[i++].stress;
    }
    if(sum_stress>=100)
    {
        sum_stress-=ne[--i].stress;
        sum_happy-=ne[i].happy;
    }

    cout << sum_happy << endl;

    return 0;
}