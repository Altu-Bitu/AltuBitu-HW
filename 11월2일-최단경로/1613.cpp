#include <iostream>
#include <vector>

using namespace std;

void floydWarshall(int n, vector<vector<bool>>& graph) {
    for (int k = 1; k <= n; k++) {//������ �� �ִ���
        for (int i = 1; i <= n; i++) {//����
            for (int j = 1; j <= n; j++) {//��
                if (graph[i][k] && graph[k][j]) //i->k, k->j ���İ��� �ִ� ���
                    graph[i][j] = true;//�� �� �ִٰ� ǥ��
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, s, a, b;//��� ��, ��� ����, ���� ���踦 �˰� ���� ����� ��,����

    //�Է�
    cin >> n >> k;
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));//�ش� �������� ���谡 �ִ���
    while (k--) {//k��
        cin >> a >> b;
        graph[a][b] = true; //���İ��� -> �ܹ��� �׷���
    }

    //����
    floydWarshall(n, graph);

    //�Է� & ���
    cin >> s;
    while (s--) {
        cin >> a >> b;
        if (graph[a][b])//���� a,b�� a->b�̸� -1
            cout << "-1";
        else if (graph[b][a])//b->a�̸� 1
            cout << "1";
        else
            cout << "0";//���谡 ������ 0
        cout << '\n';
    }
    return 0;//����
}