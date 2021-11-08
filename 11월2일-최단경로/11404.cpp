//
// Created by iw040 on 2021-11-02.
//

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e7; //�ִ� n-1���� ������ ������ ��

//�÷��̵�-����
void floydWarshall(int n, vector<vector<int>>& graph) {
    for (int k = 1; k <= n; k++) {//i���� j�� ���� �� �߿� �ִ� k
        for (int i = 1; i <= n; i++) {//i����
            for (int j = 1; j <= n; j++) {//j�� ���� ��
                int dist = graph[i][k] + graph[k][j]; //�߰��� k�� ���ļ� i���� j�� ��
                graph[i][j] = min(graph[i][j], dist); //i->j�� i->k->j �� �� ª�� ���
            }
        }
    }
}

int main() {
    int n, m, a, b, c;//n���� ����,m���� ����

    //�Է�
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));//ó������ INF�� �ʱ�ȭ
    for (int i = 1; i <= n; i++) //�ڱ� �ڽŰ��� �Ÿ�
        graph[i][i] = 0;//0���� �ʱ�ȭ

    while (m--) {//������ ����ŭ �Է� �ޱ�
        cin >> a >> b >> c;//��� ����,���� ���� , ���
        graph[a][b] = min(graph[a][b], c); //�ߺ� ������ ���� �� �����Ƿ� �ּڰ� ���
    }

    //����
    floydWarshall(n, graph);

    //���
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << ((graph[i][j] == INF) ? 0 : graph[i][j]) << ' ';//inf�̸� ��ΰ� ���� 0���� ��� �ƴϸ� �ּҺ�� ���
        cout << '\n';//�� n���� �ٷ� ����ؾ��ϱ⶧����
    }
}