#include <iostream>
using namespace std;

string solution(int num) {
	string str;
	unsigned int jishu = 0;
	if (num / 26) {
		while (num / 26) {
			jishu = num / 26;
			num -= jishu * 26;
			str += solution(jishu);
			//�ݹ���̣���ͷ��ĸ 0 Ϊ ��Z����
			if (!num)
				str += 90;
			else
				str += num + 64;
		}
	}
	else {
		//�ݹ��յ㣬ͷ��ĸ 0 Ϊ ��\n��������Ϊ��@����
		if (!num)
			str += '\0';
		else if (jishu == 0)
			str += num + 64;
	}
	return str;
}

int main() {
	int n;
	cin >> n;
	cout << solution(n) << endl;
	return 0;
}