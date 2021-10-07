#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n , k;
	cin >> n >> k;
	vector <int> roll (n);
	for (int i = 0; i < n; i++) {
		cin >> roll[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
			    if (roll[i] == 10) {
					cnt += 1;
					roll[i] = 0;
				}
				else if ((roll[i] % 10) == 0 && k >= ((roll[i] / 10) - 1)){
					    cnt += (roll[i] / 10);
						k = k - ((roll[i] / 10) - 1);
						roll[i] = 0;
			    }
				else {
				while (roll[i] > 10 && k > 0) {
					cnt += 1;
					k -= 1;
					roll[i] -= 10;
				}
			}
			}
        
        cout << cnt;
		return 0;

}