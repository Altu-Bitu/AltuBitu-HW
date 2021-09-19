#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool po[21] = {false};


int main() {
	//입출력 속도 향상
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m,num ;
	string order;
	
	cin >> m;
	while (m--) {
		cin >> order;
		if (order == "add") {
			cin >> num;
            po[num] = true;
		}
		else if (order == "remove") {
			cin >> num;
			po[num] = false;
		}
		else if (order == "check") {
			cin >> num;
			if (po[num])
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (order == "toggle") {
			cin >> num;
			if (po[num]) po[num] = false;
			else  po[num] = true;
		}
		else if (order == "all") {
			for (int i = 1; i < 21; i++) {
				po[i] = true;
			}
		}
		else if (order=="empty") {
			po[21] = {false};
		}
	}
}