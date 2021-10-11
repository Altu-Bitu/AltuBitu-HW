#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
    int source, dest, amount;//�ù� �ø��� ��,�ù� ������ ��, �ù跮
};

int greedyBox(int n, int m, int c, vector<info>& box) {
    vector<int> truck(n, 0);
    int ans = 0; //�ưԵǴ� �ڽ��� �� ����

    for (int i = 0; i < m; i++) {
        int max_loaded = 0;
        //���� �ڽ��� �̵� �������� ���� ���� �Ǹ� �ڽ��� ��
        for (int j = box[i].source; j < box[i].dest; j++)//�ù� ����ϴ� �������� ���� ��������
            max_loaded = max(max_loaded, truck[j]);//��� �ư� �Ǵ� �ڼ� ���� ���ؼ� �� ū ���� max_loaded�� �ֱ�

        //�̹��� ���� �� �ִ� �ڽ��� ���� Ʈ���� �뷮���� max_loaded�� �� ����, �̹� �ڽ��� ���� �� �ּڰ�
        int loaded = min(box[i].amount, c - max_loaded);
        ans += loaded;//�̹��� �ƴ� �ڽ� �� ���ϱ�

        //Ʈ���� �ڽ� ����
        for (int j = box[i].source; j < box[i].dest; j++)
            truck[j] += loaded;//�ڽ� �� ���ϱ�
    }
    return ans;//�ִ� ��ȯ
}

/**
 * �׸��� �˰����� ����
 * ���� 3: �ڽ��� �� '�Ϻ�'�� ����� ���� �ִ�.
 *
 * 1. Ʈ���� 1�� �������� ���
 * 2. Ʈ���� ���� ������ ���ƾ� �ڽ��� ���� ���� �� ����
 * -> �������� 1�� �������� ����� �ڽ� ���� �ƴ´�
 * -> ������ ���� �������� ����
 *
 * ������ ���� �������� ������ �ؾ� �ϴ� ����
 * 1. ������ ���� �������� ������ �� ���, ������ ������ �־����� Ʈ���� ���� �ڽ��� �ư� �Ǿ� ��ȿ����
 * 2. ������ ���� �������� ������ �� ���, �ڽ��� ���� ������ �Ǿ� ȿ����
 * 3. ������-�������� �Ÿ��� �������� ������ �� ���, ���� �Ÿ��� ª���� �������� �� ��츦 ó������ ����
 */
int main() {
    int n, c, m;

    //�Է�
    cin >> n >> c >> m;//���� ��, Ʈ�� �뷮 ���� ,������ �ù�ǥ �� 
    vector<info> box(m);
    for (int i = 0; i < m; i++)//ǥ ���� m����
        cin >> box[i].source >> box[i].dest >> box[i].amount;//�Է�

    //����
    sort(box.begin(), box.end(),//�������� ����
        [](const info& i1, const info& i2) { //�͸� �Լ��� compare ����
            return i1.dest < i2.dest;//�� �� �������� ���� ���ʿ� �ְ�
        });

    //���� & ���
    cout << greedyBox(n, m, c, box);//�ִ� �ڽ� ��
}