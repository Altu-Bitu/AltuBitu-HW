#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int avg(vector <int> a) {
	double sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum +=(double)a[i];
	}
	return round(sum / a.size());
}
int mid(vector <int> a) {
	sort(a.begin(), a.end());
	int k = a.size() / 2 ;
	return a[k];

}
//ÃÖºó°ª
int fre(vector <int> a) {
	int count[8001] = { 0 };
	int max = 0;
	for (int i = 0; i < a.size(); i++) {
		int b = a[i] + 4000;
		count[b]++;
		if (count[b] > max)
			max = count[b];
	}
	int cnt = 0, ans = 0;
	for (int i = 0; i < 8001; i++) {
		
		if (count[i] == max) {
			ans = i - 4000;
			cnt++;
			}
		if (cnt == 2) break;
	}
	return ans;

	
}
int range(vector <int> a) {
	sort(a.begin(), a.end());
	return a[a.size() - 1] - a[0];

}
int main() {
	int n , k;
	cin >> n;
	vector <int> num;
	for (int i = 0; i < n; i++) {
		cin >> k;
		num.push_back(k);
	}
	cout << avg(num) << '\n';
	cout << mid(num) << '\n';
	cout << fre(num) << '\n';
	cout << range(num) << '\n';


	return 0;
}