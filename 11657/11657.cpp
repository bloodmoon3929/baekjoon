#include<iostream>
#include<vector>
#include<climits>

using namespace std;

struct Edge
{
    int src;
    int dst;
    int weight;
};

const int UNKNOWN = INT_MAX;

bool HasNegativeCycle(const vector<Edge>& edges, vector<long long> distance)
{
    for(auto& e : edges)
    {
        if(distance[e.src]==UNKNOWN)
            continue;
        if(distance[e.src]+e.weight<distance[e.dst])
            return true;
    }
    return false;
}

void BellmanFord(vector<Edge> edges, int V)
{
    vector<long long> distance(V, UNKNOWN);
    distance[0]=0;

    for(int i=0; i<V; i++)
    {
        for(auto& e : edges)
        {
            if(distance[e.src]==UNKNOWN)
                continue;
            if(distance[e.dst]>distance[e.src]+e.weight)
            {
                distance[e.dst]=distance[e.src]+e.weight;
            }
        }
    }
    if(HasNegativeCycle(edges,distance))
    {
        cout<<"-1"<<endl;
        return;
    }
    for(int i=1; i<V; i++)
    {
        if(distance[i]==UNKNOWN)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            cout<<distance[i]<<endl;
        }
    }
}


int main()
{
    int V, E,a,b,c;
    vector<Edge> edges;
    cin>>V>>E;
    for(int i=0; i<E; i++)
    {
        cin>>a>>b>>c;
        Edge tmp;
        tmp.src=a-1;
        tmp.dst=b-1;
        tmp.weight=c;
        edges.emplace_back(tmp);
    }
    BellmanFord(edges, V);
}