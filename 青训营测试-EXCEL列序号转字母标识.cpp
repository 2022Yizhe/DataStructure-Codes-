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
			//递归过程，非头字母 0 为 ‘Z’！
			if (!num)
				str += 90;
			else
				str += num + 64;
		}
	}
	else {
		//递归终点，头字母 0 为 ‘\n’，不能为‘@’！
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