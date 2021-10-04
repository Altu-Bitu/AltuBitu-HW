#include <iostream>
#include <vector>

using namespace std;
const int MAX_CHANNEL = 1000000;

vector<bool> broken(11); //��ư�� ���忩��

//�������� ��ư��� �� ä���� ���� �� �ִ��� �˻�. ���� ���� �� �ִٸ� ������ �ϴ� Ƚ�� ����
int canPress(int channel) {
    int cnt = 0; //��ư�� ������ �ϴ� Ƚ��
    if (channel == 0) //0�� ä���� ��
        return !broken[0];//ä�� ������ ����
    while (channel != 0) { //���� ä���� ��� �ڸ����� ����
        if (broken[channel % 10]) //�ϳ��� �μ����ٸ� ���� �� ����
            return 0;
        channel /= 10;//1�� �ڸ� ���ڸ� ���� �� �ְ�
        cnt++;//�ش� �ڸ� �� �Է� 
    }
    return cnt;
}

/**
 * 0�� ä�κ��� MAX_CHANNEL���� ��� ä�ο� ���� �̵� ���� ���θ� üũ
 * 1,000,000������ ����ϸ� �Ǳ� ������ �����ϰ� Ǯ� �ð��ȿ� Ǯ �� ����
 */
int main() {
    int n, m, button;

    //�Է�
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> button;//���峭 ��ư ���� �Է�
        broken[button] = true;//���峵�ٰ� ǥ��
    }

    //����
    int min_click = abs(n - 100); //+ �Ǵ� - ��ư ��� ������
    if (m == 10) { //��ư�� ���� �μ����ٸ� ���ڸ� ���� �̵��� �� ����
        cout << min_click;//���� ä���� 100���̶�� �����Ƿ�
        return 0;
    }
    for (int i = 0; i < MAX_CHANNEL; i++) { //i�� ä�ο� ����
        int press_cnt = canPress(i); //i�� ä�ο� ���� ���� ��ư�� ������ �ϴ� Ƚ��
        if (press_cnt != 0) //0�� �ƴ϶�� i�� ä�η� �̵��� �� ����
            min_click = min(min_click, abs(n - i) + press_cnt); //i�� ä�� �̵� ��, i������ n������ + / - ��ư ���� ���� �ּڰ� ��
    }

    //���
    cout << min_click;
}