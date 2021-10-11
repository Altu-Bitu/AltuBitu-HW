#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	
	cin >> n >> m;
	vector<vector<int>> a(n,vector<int>(m,0));// a��� �Է� ����
	vector<vector<int>> b(n, vector<int>(m,0)); //b ��� �Է¹���
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
	int cnt = 0;//���� Ƚ��
	int end = 3;//���� �ѹ� �Ҷ����� 3x3�� �� �� �����ϱ� ��� 3�� ���� �� �ְ�
	while (true) {
		for (int i = end - 3; i < end; i++) {//�� ó�� 3x3 �ѹ����� ��� ����
			for (int j = end - 3; j < end; j++) {
				if (a[i][j] == 0) a[i][j] = 1;//0�ΰ�� 1��
				else a[i][j] = 0;//1�ΰ�� 0����
			}
		}
		cnt += 1;//���� �ѹ� �����ϱ� cnt 1 ���ϱ�
		int sam = 0;//a�� b�� ��� ��ü�� ������ Ȯ���ϱ� ���ؼ�
		for (int i = 0; i < n; i++) {//a��b�� ����� ���� �� Ȯ���ϱ�
			for (int j = 0; j < m; j++) {
				if (a[i][j] == b[i][j]) sam++;//���� ������ sam ���ϱ� ���� ���ֱ�
			}
		}// �˻� ������ �ϰ�
		if (sam == (n * m)) {//���� sam�� ��� ����? ���� ������ a�� b�� ���ٴ� �Ҹ��ϱ�
			cout << cnt;//cnt����ϰ�
			break;//���� ������
		}
		else if (end > n || end > m) cout <<  " - 1";//���� end�� n��m�� ������ ������ ��� �ص� a��b�� ������ �� ���ٴ� �Ҹ��̴ϱ� -1 ���
		else end += 1;//�ƴϸ� end�� 1 ���ؼ� �ٽ� ó������ �ϱ�
	}
	
	return 0;
}