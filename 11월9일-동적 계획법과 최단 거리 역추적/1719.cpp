#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e5 * 2; //�ִ� n-1���� ������ ������ ��

void floydWarshall(int n, vector<vector<int>>& graph, vector<vector<int>>& table) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int new_dist = graph[i][k] + graph[k][j]; //�߰��� k�� ���ļ� i���� j�� ��
                if (new_dist < graph[i][j]) { //i->k->j�� i->j���� ���� ��ζ��
                    graph[i][j] = new_dist;//����ġ ����
                    table[i][j] = table[i][k];//��� ����
                }
            }
        }
    }
}

/**
 * graph : �÷��̵�-���� ��� ��� �׷���
 * table : ���ǥ. table[i][j] = i->j�� ���� ���� ���� ���� ���ľ� �ϴ� ����
 *
 * 1. i->j�� �߰� ��θ� i�� �ʱ�ȭ
 * 2. i->k->j�� i->j���� ª�ٸ� i->j�� �߰� ��θ� i->k�� �߰� ���(table[i][k])�� ����
 *    k�� �����ϴ°� �ƴ϶� table[i][k]�� �����ϴ� ������?
 *    ���� i->k�� ��ΰ� i->t->k��� ���� ��δ� i->t->k->j
 *    �ٷ� k�� �����ϸ� t�� ��ĥ �� �ֱ� ������ table[i][k]�� ����
 *    line 16�� table[i][j] = k�� �ٲٸ� ����� ��� �Ǵ��� Ȯ���غ�����
 */
int main() {
    int n, m, s, d, c;

    //�Է�
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));//����ġ
    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));//���
    for (int i = 1; i <= n; i++)
        graph[i][i] = 0;//�ڱ� �ڽŰ��� ���� ����ġ 0���� �ʱ�ȭ

    while (m--) { //������ �׷���
        cin >> s >> d >> c;
        //���� ����
        graph[s][d] = graph[d][s] = c;//��������� ����ġ�� �Ȱ����ϱ�

        //��� ����
        table[s][d] = d;//�߰���θ� �ϴ� ���������� ����
        table[d][s] = s;//���� ����
    }

    //����
    floydWarshall(n, graph, table);

    //���
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                cout << "- ";//�ڱ� �ڽŰ��� ���
            else
                cout << table[i][j] << ' ';//��� ���
        }
        cout << '\n';
    }
}