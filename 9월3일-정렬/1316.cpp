#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	int count = 0;
	string word;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word;
		bool flag = true;
		for (int j = 0; j < word.length(); j++) {
			for (int k = 0; k < j; k++) {
				if (word[j - 1] != word[j] && word[k] == word[j]) {
					flag = false;
					break;
				}
			}
		}
		if (flag) count++;
	}
	cout << count << endl;
	return 0;
}