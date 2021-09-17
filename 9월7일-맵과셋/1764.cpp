#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;

string a[500000];
string b;
vector <string> list;

int main() {
	cin >> n >> m;
	int count = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int j = 0; j < m; j++) {
		cin >> b;
		for (int i = 0; i < n; i++) {
			if (b == a[i]) 
				count++;
				list.push_back(b);
			}
	}
	cout << count << '\n';
	for (int i = 0; i < list.size(); i++) {
		cout << list[i]<<'\n';
	}
}