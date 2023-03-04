#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <array>
#include <set>
#include <numeric>

using namespace std;

int n;
vector<vector<long long> > dist;

int main(){
    string s;
    cin >> n;
    dist.resize(n, vector<long long>(n));
    vector<pair<long, long> > coord(n);
    int node;
    for(int i = 0; i < n; ++i){
        cin >> node >> coord[i].first >> coord[i].second;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            dist[i][j] = abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second);
        }
    }


}