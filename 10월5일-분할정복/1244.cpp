#include <iostream>
#include <vector>

using namespace std;

//���л��� ����ġ �ٲٱ�
vector<int> changeSwitchBoy(int n, int number, vector<int> switches) {//����ġ ����,�л��� ������ �ִ� ��, ����ġ�迭
    for (int i = number; i <= n; i += number) //����� �ִ� ����ġ �ٲٱ�
        switches[i] = !switches[i];//����ġ �ٲ��ֱ�

    return switches;//����ġ ��ȯ
}

//���л��� ����ġ �ٲٱ�
vector<int> changeSwitchGirl(int n, int number, vector<int> switches) {//����ġ ����,�л��� ������ �ִ� ��, ����ġ�迭
    switches[number] = !switches[number];//�л��� ������ �ִ� ���� �迭 ����ġ �ٲ��ֱ�
    for (int i = 1; i < number; i++) {
        if ((number + i > n) || (switches[number - i] != switches[number + i])) //����ġ ���� �Ѿ�ų� �¿� ��Ī�� �ƴϸ�
            break;
        switches[number - i] = !switches[number - i];//�ƴϸ� ���� �ٲ��ֱ�
        switches[number + i] = !switches[number + i];//�ƴϸ� ���� �ٲ��ֱ�
    }

    return switches;
}

/**
 * ���л� -> �ش� ��ȣ�� ����� �ش��ϴ� ����ġ ���� �ٲٱ�
 * ���л� -> �ش� ��ȣ�� �߽����� �¿� ��Ī�̸鼭 ���� ���� ����ġ �����ϴ� ������ ���� ��� �ٲٱ�
 *
 * �¿� ��Ī �˻� ��, ����ġ ���� ���� (�־��� ����ġ ���� �Ѿ�� �ʵ���)
 * ����ġ 20���� ����ϴ� �κ� ����
 */
int main() {
    int n, m;//����ġ����, �л� ��
    int student, number;//�л� , �л��� ���� ��

    //�Է�
    cin >> n;
    vector<int> switches(n + 1, 0);//1������ �����̴ϱ� ����� n + 1
    for (int i = 1; i <= n; i++)
        cin >> switches[i];//����ġ ���� �Է�

    //�Է� & ����
    cin >> m;//�л� ��
    while (m--) {//�л� �� ��ŭ �ݺ�
        cin >> student >> number;//�Է�
        if (student == 1)//�����л��̸�
            switches = changeSwitchBoy(n, number, switches);//�ٲ��ֱ�
        else//�ƴϸ� �����л�
            switches = changeSwitchGirl(n, number, switches);//�ٲ��ֱ�
    }

    //���
    for (int i = 1; i <= n; i++) {
        cout << switches[i] << ' ';//����ġ ó������ ������ ���
        if (i % 20 == 0)//20���� �� �ٲ��ֱ�
            cout << '\n';
    }
    return 0;//����
}