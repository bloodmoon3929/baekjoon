#include<algorithm>
#include<map>
#include<string>
#include <iostream>
using namespace std;

int main()
{

    int num,num1;
    string tmp;
    scanf("%d",&num);
    
    multimap<int, string> m_map;
    for(int i =0; i<num; i++)
    {
        cin >> num1 >> tmp;
        
        m_map.insert(pair<int, string>(num1, tmp));
    }

    multimap<int, string>::iterator iter;

    for(iter = m_map.begin(); iter != m_map.end(); iter++)
        cout << iter->first << " " << iter ->second << '\n';

    return 0;
}