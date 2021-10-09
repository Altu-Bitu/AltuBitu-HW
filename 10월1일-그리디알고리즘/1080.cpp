#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	
	cin >> n >> m;
	vector<vector<int>> a(n,vector<int>(m,0));// a행렬 입력 받음
	vector<vector<int>> b(n, vector<int>(m,0)); //b 행렬 입력받음
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
	int cnt = 0;//연산 횟수
	int end = 3;//연산 한번 할때마다 3x3만 할 수 있으니까 계속 3을 만들 수 있게
	while (true) {
		for (int i = end - 3; i < end; i++) {//맨 처음 3x3 한번씩만 행렬 연산
			for (int j = end - 3; j < end; j++) {
				if (a[i][j] == 0) a[i][j] = 1;//0인경우 1로
				else a[i][j] = 0;//1인경우 0으로
			}
		}
		cnt += 1;//연산 한번 했으니까 cnt 1 더하기
		int sam = 0;//a와 b가 행렬 전체가 같은지 확인하기 위해서
		for (int i = 0; i < n; i++) {//a와b의 행렬이 같은 지 확인하기
			for (int j = 0; j < m; j++) {
				if (a[i][j] == b[i][j]) sam++;//만약 같으면 sam 더하기 연산 해주기
			}
		}// 검사 끝까지 하고
		if (sam == (n * m)) {//만약 sam이 모든 원소? 수랑 같으면 a와 b가 같다는 소리니까
			cout << cnt;//cnt출력하고
			break;//루프 나가기
		}
		else if (end > n || end > m) cout <<  " - 1";//만약 end가 n과m을 넘으면 연산을 계속 해도 a와b가 같아질 수 없다는 소리이니까 -1 출력
		else end += 1;//아니면 end에 1 더해서 다시 처음부터 하기
	}
	
	return 0;
}