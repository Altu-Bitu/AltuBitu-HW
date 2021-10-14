#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> innings;//�� ������ �� �̴׿��� ��� ���
vector<int> order(10, 0); //Ÿ��
vector<bool> check(10, false);//�� �������� Ÿ���� ���������� Ȯ���ϱ� ����
int n, ans;

//���� ��ġ�� ����
int calcScore() {
    int score = 0; //�� ����
    int idx = 1; //Ÿ�� ����� order �ε��� ��ȣ
    for (int i = 0; i < n; i++) { //i: �̴�
        vector<bool> baseman(4, 0); //�� ������� ������ �ִ���
        int out = 0; //�ƿ� ���� ī��Ʈ
        while (out < 3) {//�ƿ� �Ǳ� ������
            int state = innings[i][order[idx++]]; //���� ������ ���� ����
            if (idx == 10)//Ÿ���� 9���� �ۿ� �����Ƿ�
                idx = 1;//�ٽ� 1�� ������ֱ�
            switch (state) {//���� ������ ���� ���¿� ����
            case 0://0�ΰ��
                out++;//�ƿ� �����ְ�
                break;//���� ������
            case 1: //��Ÿ, 1�羿 ����
                score += baseman[3]; //3�翡 �ִ� �����ִٸ� Ȩ ����
                for (int i = 3; i > 0; i--)//�� ������
                    baseman[i] = baseman[i - 1];//�Ű��ֱ�
                baseman[1] = 1; //���ο� ���� 1�翡 ����
                break;//������
            case 2: //2��Ÿ, 2�羿 ����
                score += baseman[3] + baseman[2]; //3��, 2�翡 ���� �ִٸ� Ȩ ����
                baseman[3] = baseman[1]; //1�� -> 3�� �̵�
                baseman[2] = 1; //���ο� ���� 2�翡 ����
                baseman[1] = 0; //�ʱ�ȭ
                break;
            case 3: //3��Ÿ, 3�羿 ����
                for (int i = 3; i > 0; i--) { //3��, 2��, 1�翡 ���� �ִٸ� Ȩ ����
                    score += baseman[i];
                    baseman[i] = 0;// �� Ȩ �����ϴϱ� 0����
                }
                baseman[3] = 1; //���ο� ���� 3�翡 ����
                break;
            case 4: //Ȩ��
                for (int i = 3; i > 0; i--) { //3��, 2��, 1�翡 ���� �ִٸ� Ȩ ����
                    score += baseman[i];
                    baseman[i] = 0;// �� Ȩ �����ϴϱ� 0����
                }
                score++; //���ο� ������ Ȩ �ٷ� ����
                break;
            }
        }
    }

    return score;//���� ��ȯ
}

//������ ��ġ ��� ���ϱ�
void array(int cnt) { //cnt: Ÿ�ڼ���
    if (cnt == 4) { //4�� Ÿ�ڴ� ������ �����Ƿ�
        array(cnt + 1);//5�� Ÿ�ڷ� ������ ��ġ , ��� ȣ��
        return;
    }
    if (cnt == 10) { //9�� Ÿ�ڱ��� ������ (��������)
        int score = calcScore(); //���� ���
        ans = max(ans, score);//�ִ��� ��������
        return;
    }
    for (int i = 2; i <= 9; i++) {
        if (!check[i]) {//���� 2�� �������� 9�� �������� Ÿ���� ������ ���� �ʴٸ�
            order[cnt] = i; //cnt�� Ÿ��: i�� ����
            check[i] = true; //i�� ���� ���� ������
            array(cnt + 1); //���� Ÿ��
            check[i] = false;//������ ��ġ�� �� �غ����ؼ�
        }
    }
    
}

/**
 * ���� + ���Ʈ ����, ��Ʈ��ŷ
 * 1. �켱 ������ Ÿ���� ��� ���Ѵ�. (�̶�, 4�� Ÿ�ڴ� �׻� 1�� �������� ��) (���Ʈ ����, ��Ʈ��ŷ)
 * 2. ���� Ÿ���� ���� ������ ������ ���ϸ� �ִ� ������ �����Ѵ�. (����)
 */

int main() {
    //�Է�
    cin >> n;//�̴� ��
    innings.assign(n, vector<int>(10, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 10; j++) {
            cin >> innings[i][j];//�� ������ �� �̴׿��� ��� ��� �Է� �ޱ�
        }
    }

    //����
    order[4] = 1; //4�� Ÿ�ڴ� 1�� ����
    check[1] = true; //1�� ������ ���� ������
    array(1);

    //���
    cout << ans << '\n';//�ִ� ���� ���

    return 0;//����
}