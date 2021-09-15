#include <iostream>
#include <vector>

using namespace std;

vector <int> arr;

int peo(int n, int a, int b) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int num = arr[i] - a;
        int c = num % b;
        int d = num / b;
        if (arr[i] <= a) count = 1;
        else if (c == 0) count += d + 1;
        else count += d + 2;
    }
    return count;
}
int main()
{
    int n, a, b;
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> a >> b;

    cout << peo(n, a, b) << endl;

}