#include <iostream>

using namespace std;

int factor(int n) {
	if (n == 0) return 1;
	else return n* factor(n - 1);
}
int main() {
	int n, k;
	cin >> n >> k;
	int num;
	if (k == 0) num = 1;
	else num = factor(n) / (factor(k) * factor(n - k));

	cout << num ;
}