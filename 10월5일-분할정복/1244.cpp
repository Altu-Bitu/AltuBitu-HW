#include<iostream>
#include <vector>

using namespace std;

void change(int n) {
	if (n == 1) n = 0;
	else n = 1;
}


int main() {
	int n;
	cin >> n;
	
	vector <int> lit (n);
	for (int i = 0; i < n; i++) {
		cin >> lit[i];
	}
	int p;
	cin >> p;
	vector <vector<int>> stu(p, vector<int>(2, 0));
	for (int i = 0; i < p; i++) {
		cin >> stu[i][0] >> stu[i][1];
			}
	for (int i = 0; i < p; i++) {
		if (stu[i][0] == 1) {
			change(lit[stu[i][1]]);
			change(lit[2 * (stu[i][1])]);
		}
		else {
			change(lit[stu[i][1]]);//�ϴ� ���л��� ���� ��ȣ�� �ٲٱ�
			
			int num = stu[i][1];
			int k = 1;//���� ���� ���� �� Ȯ���ϱ� ����
			while (true) {
				
				if ((lit[num - k] == lit[num + k]) && (num - k >= 0 && num + k < n)) {
					change(lit[num - k]);
					change(lit[num + k]);
					k++;
				}
				else  break;
			}
		}

	}
	for (int i = 0; i < n; i++) {
		cout << lit[i] << '  ';
	}
	return 0;
}