#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool po[21] = {false};


int main() {
	//����� �ӵ� ���
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
				cout << "1" << '\n';
			else
				cout << "0" << '\n';
		}
		else if (order == "toggle") {
			cin >> num;
			if (po[num]) po[num] = false;
			else  po[num] = true;
		}
		else if (order == "all") {
			memset(po, true, sizeof(po));
		}
		else if (order=="empty") {
			memset(po, false, sizeof(po));
		}
	}
	return 0;
}