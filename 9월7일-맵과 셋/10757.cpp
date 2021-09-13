#include<iostream>
#include<vector>
#include<string>

using namespace std;



int main() {
	string number1;
	string number2;
	string temp;
	cin >> number1 >> number2;

	if (number1.size() < number2.size()) {
		temp = number1;
		number1 = number2;
		number2 = temp;
	}
	int a[1000];
	int b[1000];
	

	for (int i = 0; i < number1.size(); i++) {
		a[i + 1] = number1[i] - '0';
	}
	for (int i = 0; i < number2.size(); i++) {
		b[i + 1 + (number1.size() - number2.size())] = number2[i] - '0';
	}

	int sum;
	vector<int> fin;

	for (int i = number1.size(); i > 0; i--) {
		sum = a[i] + b[i];
		if (sum >= 10) {
			a[i - 1]++;
			sum -= 10;
		}
		fin.push_back(sum);
	}


	if (a[0] != 0) cout << 1;
	
    for (int i = fin.size() - 1; i >= 0; i--) {
		cout << fin[i];
	}
	

}



