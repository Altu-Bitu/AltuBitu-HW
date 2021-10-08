#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	
	cin >> n >> m;
	vector<vector<int>> a(n,vector<int>(m,0));
	vector<vector<int>> b(n, vector<int>(m,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}
	int cnt = 0;
	int end = 3;
	while (true) {
		for (int i = end - 3; i < end; i++) {
			for (int j = end - 3; j < end; j++) {
				if (a[i][j] == 0) a[i][j] = 1;
				else a[i][j] = 0;
			}
		}
		cnt += 1;
		int sam = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == b[i][j]) sam++;
			}
		}
		if (sam == (n * m)) {
			cout << cnt;
			break;
		}
		else if (end > n || end > m) cout <<  " - 1";
		else end += 1;
	}
	
	return 0;
}