#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    /// freopen("output.txt", "w", stdout);
    int V, E;
    cin >> V >> E; /// scanf("%d%d", &V, &E);

    int Graph[V][V];

    memset(Graph, 0, sizeof(Graph));

    for(int i=1; i<=E; i++)
    {
        int from, to;
        cin >> from >> to; /// scanf("%d%d", &from, &to);
        Graph[from][to] = 1;
    }

    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
            cout << Graph[i][j] << " ";
        cout << "\n"; /// printf("\n");
    }

    return 0;
}