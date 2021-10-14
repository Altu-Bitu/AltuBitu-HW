#include <iostream>
#include <vector>

using namespace std;
int snack(int n , vector<int> len ,int m) {
	int mid = len[m-1]/ 2;//배열에서 가장 큰 값의 절반
	int cnt = 0;//막대기 과자 수
	while (true) {
		for (int i = 0; i < m; i++) {
			cnt += len[i] / mid;//한 막대기 과자에서 나올 수 있는 개수
		}
		if (cnt >= n) break;//조카 수랑 같으면 나가기
		else mid--;//아니면 하나씩 줄이기
	}
	return mid;
}
int main() {
	int n, m;//조카 수, 막대과자 수
	cin >> n >> m;
	vector<int> len(m, 0);//배열
	for (int i = 0; i < m; i++) {
		cin >> len[i];
	}
	
	int ans = 0;
	if (n <= m) {//조카 수보다 과자 개수가 많으면 
		ans = len[m - n];//m-n 인덱스 값으로
	}
	else if(n>m) ans = snack(n, len, m);

	cout << ans;

	return 0;
	
}