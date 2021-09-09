#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> a;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector <int> b;
    b.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    vector <int> c;
    c.assign(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        c[i] = a[i] * b[i];
        sum += c[i];
    }

    cout << sum << endl;

    return 0;

}