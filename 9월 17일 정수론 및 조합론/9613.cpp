#include <iostream>

using namespace std;
int gcdRecursion(int a, int b) {
	if (b == 0)
		return a;
	
	return gcdRecursion(b, a % b);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int count;
	cin >> count;
	while (count--) {
		int arr[101];
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		long long sum = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) sum += gcdRecursion(arr[i], arr[j]);
		}
		cout << sum <<'\n';
	}
	return 0;
}