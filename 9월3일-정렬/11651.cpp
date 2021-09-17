#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool tid(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int x;
        int y;
        cin >> x >> y;
        a.push_back({ x,y });
    }
    sort(a.begin(), a.end(), tid);
    for (int i = 0; i < n; i++) {
        cout << a[i].first << " " << a[i].second << '\n';
    }




    return 0;

}
