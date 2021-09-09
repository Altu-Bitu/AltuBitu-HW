#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int mul(vector<int>a, vector<int>b, vector <int>c) {
    int sum = 0;
    for (int i = 0; i < c.size(); i++) {
        c[i] = a[i] * b[i];
        sum += c[i];
    }
    return sum;
}
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
    

    cout << mul( a, b, c) << endl;

    return 0;

}