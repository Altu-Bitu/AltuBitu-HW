#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e7 * 2; //�ִ� n-1���� ������ ������ ��

//������ ���� ��� �׷����� ����
vector<vector<int>> fillGraph(int n, vector<vector<int>>& fares) {
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));//ó������ INF�� �ʱ�ȭ
    for (int i = 1; i <= n; i++) //�ڱ� �ڽŰ��� �Ÿ�
        graph[i][i] = 0;//0���� �ʱ�ȭ

    for (int i = 0; i < fares.size(); i++) { //����� �׷���
        graph[fares[i][0]][fares[i][1]] = fares[i][2];//4���� 1�� ���� �Ŷ�
        graph[fares[i][1]][fares[i][0]] = fares[i][2];//1���� 4�� ���� ���� ����� ����
    }
    return graph;//�׷��� ����
}

void floydWarshall(vector<vector<int>>& graph, int n) {
    for (int k = 1; k <= n; k++) {//�����ؼ� ���� �� ���� ����� �� �� �ִ���
        for (int i = 1; i <= n; i++) {//i����
            for (int j = 1; j <= n; j++) {//j�� ���� ��
                int dist = graph[i][k] + graph[k][j]; //�߰��� k�� ���ļ� i���� j�� ��
                graph[i][j] = min(graph[i][j], dist); //i->j�� i->k->j �� �� ª�� ���
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<vector<int>> graph = fillGraph(n, fares);//��� �׷���
    floydWarshall(graph, n);//���� ���

    for (int i = 1; i <= n; i++) { //i��° �������� �ս�
        //���ݱ����� �ִܰŸ��� �ս��� �ִܰŸ� ��
        //�̵� �Ұ����� ���(INF)�� min ���ǿ� ���� �ڵ����� ������� ����
        answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);//s���� ���� ������ �������� ���+ a���� �ɸ��� ���+b���� �ɸ��� ���
    }
    return answer;//�������
}

/**
 * �ս��� �� �ִ� ������ ������ n��
 * 1. s�� ���� �ս��� ���� ���� ��
 * 2. a�� ���� A�� ������ �ս��� ��, B ȥ�� �̵�
 * 3. b�� ���� B�� ������ �ս��� ��, A ȥ�� �̵�
 * 4. ������ ���� Ư�� �������� �ս��� ��, ������ ������ ���� ��
 * -> ���ͽ�Ʈ�� ����ϸ� �ð��ʰ��̹Ƿ� �÷��̵�-���� �˰��� ���
 *
 * 1. �÷��̵�-���� �˰������� ��� ������ ������ �ִ� �Ÿ� ���
 * 2. n���� ������ ���� n�� �������� �ս��� �ϰ� ������ ������ ���� �ִܰŸ� ���
 */
int main() {
    vector<vector<int>> fares = { {4, 1, 10},//���� ,������ ����
                                 {3, 5, 24},
                                 {5, 6, 2},
                                 {3, 1, 41},
                                 {5, 1, 24},
                                 {4, 6, 50},
                                 {2, 4, 66},
                                 {2, 3, 22},
                                 {1, 6, 25} };
    int ans = solution(6, 4, 6, 2, fares);//�������
    cout << ans;//���
}