#include <iostream>
#include <vector>

using namespace std;
int snack(int n , vector<int> len ,int m) {
	int mid = len[m-1]/ 2;
	int cnt = 0;
	while (true) {
		for (int i = 0; i < m; i++) {
			cnt += len[i] / mid;
		}
		if (cnt >= n) break;
		else mid--;
	}
	return mid;
}
int main() {
	int n, m;//조카 수, 막대과자 수
	cin >> n >> m;
	vector<int> len(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> len[i];
	}
	
	int ans = 0;
	if (n <= m) {
		ans = len[m - 3];
	}
	else if(n>m) ans = snack(n, len, m);

	cout << ans;

	return 0;
	
}