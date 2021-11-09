#include <iostream>
#include <map>

using namespace std;
typedef pair<int, int> ci;
const int SIZE = 8;//8*8 ü����

map<string, int> direction = { {"L",  0},  //��
                              {"R",  1},  //��
                              {"B",  2},  //��
                              {"T",  3},  //��
                              {"LT", 4},  //�����
                              {"LB", 5},  //�»���
                              {"RT", 6},  //������
                              {"RB", 7} }; //������

string pointToString(ci point) {
    string ans;//��������  ŷ, ���� �ִ� �ڸ�
    ans = (point.first + 'A');//��
    ans += (point.second + '1');//��
    return ans;//�ڸ� ��ȯ
}

pair<ci, ci> moveKing(string move, ci point_k, ci point_r) {//����,ŷ �ڸ�,�� �ڸ�
    //��, ��, ��, ��, �����, �»���, ������, ������
    int dr[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
    int dc[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };
    int d = direction[move]; //���� �ε��� ����

    int king_nr = point_k.first + dr[d];//ŷ ��ġ �Ű���,��
    int king_nc = point_k.second + dc[d];//ŷ ��ġ �Ű���,��
    if (king_nr < 0 || king_nr >= SIZE || king_nc < 0 || king_nc >= SIZE) //ŷ�� ������ ����� ���
        return { point_k, point_r };//�̵� �ǳʶٰ� ���� �̵�

    if (king_nr != point_r.first || king_nc != point_r.second) //ŷ�� �����̴� ���⿡ ���� ���� ���
        return { {king_nr, king_nc}, point_r };//ŷ�� �̵�,���� �̵����� ����

    //���� �ִٸ�
    int rock_nr = point_r.first + dr[d];//�� ��ġ �Ű���,��
    int rock_nc = point_r.second + dc[d];//�� ��ġ �Ű��� ,��
    if (rock_nr < 0 || rock_nr >= SIZE || rock_nc < 0 || rock_nc >= SIZE) //������ �����
        return { point_k, point_r };//�̵� �ǳʶٰ� ���� �̵�

    return { {king_nr, king_nc}, {rock_nr, rock_nc} };//ŷ ��ġ�� �� ��ġ 
}

/**
 * ü������ ���ϰ� �����ϱ� ���� ���� �Ʒ��� �ð�������� 90�� ȸ���� ü�������� ����
 * [���� �ٲ㼭 ����]
 *  T:�� -> ��       B:�� -> ��       L:��->��         R:��->��
 * RT:���� -> ����   LT:���� -> ����   RB:���� -> �޾�   LB:�޾� -> ����
 *
 * => �ٲ� ������ �Է¿� ���� ŷ�� ���� ������
 * ���� ������ ȿ�������� �ϱ� ���� Ž�� �ð����⵵�� logN�� map ���
 *
 * [����� ��]
 * 1. ŷ�� ������ ����� ���
 * 2. ŷ�� �����̴� ���⿡ ���� ���� ���
 * 3. ŷ�� �����̴� ���⿡ ���� �ְ�, ���� ������ ����� ���
 * 4. ŷ�� �����̴� ���⿡ ���� �ְ�, �� �� ������ ����� �ʴ� ���
 *
 */

int main() {
    string king, rock, move;
    int n;

    //�Է� & ����
    cin >> king >> rock >> n;
    ci point_k = { king[0] - 'A', king[1] - '1' }; //�ʱ� ŷ ��ġ
    ci point_r = { rock[0] - 'A', rock[1] - '1' }; //�ʱ� �� ��ġ
    pair<ci, ci> point = { point_k, point_r };//�ʱ� ŷ ��ġ, �� ��ġ
    while (n--) {
        cin >> move;//���� �Է� �ޱ�
        point = moveKing(move, point.first, point.second);//�Լ� ȣ��
    }

    //���
    cout << pointToString(point.first) << '\n' << pointToString(point.second) << '\n';//ŷ ��ġ, �� ��ġ
    return 0;//����
}