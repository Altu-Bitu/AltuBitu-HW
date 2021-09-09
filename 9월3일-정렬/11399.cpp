#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> arr;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());


    vector <int> list;
    list.assign(n, 0);
    list[0] = arr[0];
    for (int i = 1; i < n; i++) {
        list[i] = list[i - 1] + arr[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += list[i];
    }

    cout << sum << endl;
    return 0;

}