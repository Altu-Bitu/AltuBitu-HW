#include <iostream>
#include <vector>

using namespace std;
int snack(int n , vector<int> len ,int m) {
	int mid = len[m-1]/ 2;//�迭���� ���� ū ���� ����
	int cnt = 0;//����� ���� ��
	while (true) {
		for (int i = 0; i < m; i++) {
			cnt += len[i] / mid;//�� ����� ���ڿ��� ���� �� �ִ� ����
		}
		if (cnt >= n) break;//��ī ���� ������ ������
		else mid--;//�ƴϸ� �ϳ��� ���̱�
	}
	return mid;
}
int main() {
	int n, m;//��ī ��, ������� ��
	cin >> n >> m;
	vector<int> len(m, 0);//�迭
	for (int i = 0; i < m; i++) {
		cin >> len[i];
	}
	
	int ans = 0;
	if (n <= m) {//��ī ������ ���� ������ ������ 
		ans = len[m - n];//m-n �ε��� ������
	}
	else if(n>m) ans = snack(n, len, m);

	cout << ans;

	return 0;
	
}