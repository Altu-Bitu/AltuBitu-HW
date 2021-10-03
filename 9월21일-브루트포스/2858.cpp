#include <iostream>

using namespace std;
int main() {
	int a, b;
	
	cin >> a >> b;
	int sum = a + b;
	for (int i = 1; i <= a + b; i++) {
		if ((a + b) % i == 0) {
			int c = i;
			int d = (a + b) / i;
			if ((c - 2) * (d - 2) == b) {
				cout << max(c, d) << ' ' << min(c, d);
				break;
			}
		}
	}
	return 0;
 }