#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);

    int V, E;
    cin >> V >> E;
    vector< int > Graph[V];
    for(int i=1;i<=E;i++)
    {
        int from, to;
        cin >> from >> to;
        Graph[from].push_back(to);
    }


    for(int i=0; i<V; i++)
    {
        cout << i << " --> ";
        for(int j=0; j<Graph[i].size(); j++)
        {
            printf("%d ", Graph[i][j]);
        }
        cout << endl;
    }
    return 0;
}