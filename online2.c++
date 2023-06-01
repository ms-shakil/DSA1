#include <iostream>
#include <vector>

#define MAX_CITIES 100

using namespace std;

void depth_first_search(int city, bool visited[], vector<vector<int>> adj_list) {
    visited[city] = true;
    for (int i = 0; i < adj_list[city].size(); i++) {
        int neighbor = adj_list[city][i];
        if (visited[neighbor] == false) {
            depth_first_search(neighbor, visited, adj_list);
        }
    }
}

bool can_visit_all_cities(int num_v, int num_e, vector<vector<int>> adj_list, int num_cities, int cities[]) {
    bool visited[MAX_CITIES] = {false};
    for (int i = 0; i < num_cities; i++) {
        visited[cities[i]] = true;
    }
    depth_first_search(cities[0], visited, adj_list);
    for (int i = 0; i < num_v; i++) {
        if (visited[i] == false) {
            return false;
        }
    }
    return true;
}

int main() {
    int num_v, num_edges, num_cities;
        cin >> num_v >> num_edges;
    vector<vector<int>> adjacency_list(num_v);
    for (int i = 0; i < num_edges; i++) {
        int s, d;
        cin >> s >> d;
        adjacency_list[s].push_back(d);
    }
    cin >> num_cities;
    int cities[MAX_CITIES];
    for (int i = 0; i < num_cities; i++) {
        cin >> cities[i];
    }
    if (can_visit_all_cities(num_v, num_edges, adjacency_list, num_cities, cities)) {
        cout << "exist" << endl;
    } else {
        cout << "no exist" << endl;
    }
    return 0;
}