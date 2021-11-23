#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

ci dfs(int node, int parent, vector<vector<ci>>& graph) {
    int pos = node, len = 0; //������ �����ϴ� ��� �� �ϳ�, �� �������� �Ÿ�
    for (int i = 0; i < graph[node].size(); i++) {//�׷����� �����ŭ
        int next_node = graph[node][i].first;//��� ����
        if (next_node == parent)//���� �θ�����
            continue;//�׳� ��������

        ci dfs_search = dfs(next_node, node, graph); //�ڽ� ��忡 ���� dfs Ž��
        if (graph[node][i].second + dfs_search.first > len) { //���� �Ÿ����� ��ٸ� ����
            len = graph[node][i].second + dfs_search.first;//�Ÿ� �����ֱ�
            pos = dfs_search.second;//�ش� ��带 ������ �����ϴ� ���� �ٲ��ֱ�
        }
    }
    return { len, pos };//������ �����ϴ� ���� �������� �Ÿ�
}

/**
 * 1. ������ �̷�� �� ���� ��� ���� ���
 * 2. ������ �� ��忡�� ���� �ָ� �ִ� ���(���� ���)�� ������ �̷�� ��� �� �ϳ�
 * 3. ������ �̷�� ��忡�� ���� �ָ� �ִ� ���� ������ �̷�� �ٸ� ���
 *
 * �θ�->�ڽ��� ���⸸ �����ϸ� ���� ��忡�� �ٸ� ���� ���� Ž���� �� �����Ƿ� ������ �׷����� ����
 */
int main() {
    int n, p, c, w;

    //�Է�
    cin >> n;
    vector<vector<ci>> graph(n + 1, vector<ci>(0));//�׷��� 1������
    for (int i = 1; i < n; i++) { //������ �׷����� �����
        cin >> p >> c >> w;//�θ� ��� , �ڽ� ��� , ����ġ
        graph[p].emplace_back(c, w);//�׷����� �־��ֱ�
        graph[c].emplace_back(p, w);//�׷����� �־��ֱ�
    }

    //����
    ci first_node = dfs(1, -1, graph); //������ �����ϴ� ��� �ϳ� ã��
    ci second_node = dfs(first_node.second, -1, graph); //������ �����ϴ� �ٸ� ��� ã��

    //���
    cout << second_node.first;//�Ÿ�
}