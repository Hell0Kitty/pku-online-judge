#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

void  move_to_other(int deep,bool had, int* n, int op, int pos, int s,int preop, int one = 0);
bool  unchange_add(int pos, int s, int preop, int one = 0);
void  move_to_orgin(int deep, int op, int* n, int pos, int s, int preop, int one = 0);
void print_ans(int mn);

struct Point {
	int x,y;
};

#define BUFSIZE 100010
struct  State {
	int n[3];
	int op;
	bool is_ok;
	State() {
		n[2] = n[1]= n[0] = 0;
		op = -1;
		is_ok = false;
	}

	void reset() {
		n[2] = n[1]= n[0] = 0;
		op = -1;
		is_ok = false;
	}
};

State dp_state[BUFSIZE][4][2];
vector<int> convert_n[10][3];
string num[3];
string ans_num[3];
char buf[BUFSIZE];

void init() {//0->change one stick, remove stick, add stick
	convert_n[0][0].push_back(0);
	convert_n[0][0].push_back(6);
	convert_n[0][0].push_back(9);
	convert_n[0][2].push_back(8);

	convert_n[1][0].push_back(1);
	convert_n[1][2].push_back(7);

	convert_n[2][0].push_back(2);
	convert_n[2][0].push_back(3);

	convert_n[3][0].push_back(3);
	convert_n[3][0].push_back(2);
	convert_n[3][0].push_back(5);
	convert_n[3][2].push_back(9);

	convert_n[4][0].push_back(4);

	convert_n[5][0].push_back(5);
	convert_n[5][0].push_back(3);
	convert_n[5][2].push_back(6);
	convert_n[5][2].push_back(9);

	convert_n[6][0].push_back(6);
	convert_n[6][0].push_back(0);
	convert_n[6][0].push_back(9);
	convert_n[6][1].push_back(5);
	convert_n[6][2].push_back(8);

	convert_n[7][0].push_back(7);
	convert_n[7][1].push_back(1);

	convert_n[8][0].push_back(8);
	convert_n[8][1].push_back(0);
	convert_n[8][1].push_back(6);
	convert_n[8][1].push_back(9);

	convert_n[9][0].push_back(9);
	convert_n[9][0].push_back(0);
	convert_n[9][0].push_back(6);
	convert_n[9][1].push_back(3);
	convert_n[9][1].push_back(5);
	convert_n[9][2].push_back(8);
}

void  move_to_orgin(int deep, int op, int* n, int pos, int s, int preop, int one/* = 0*/) {//op 1有移入matches -1,移走 matches
	if (deep == 3) {
		if (0x03 != op)
				return;

		bool res = (n[2] == ((n[0] + n[1] + one)%10));
		int carry = (n[0]+n[1]+one)/10;
		if (res) {
			dp_state[pos][s][carry].is_ok = true;
			dp_state[pos][s][carry].op = preop;
			memcpy(dp_state[pos][s][carry].n, n, sizeof(int)*3);
		}
		return;

	} else {
		if (pos < num[deep].length()) {
			int v = num[deep][pos] - '0';
			int new_op = 0;
			if ((op&0x1) == 0) {
				for (int i = 0;  i < convert_n[v][1].size(); ++i) {
					n[deep] = convert_n[v][1][i];
					new_op = (op|0x1);
					move_to_orgin(deep + 1, new_op, n, pos, s, preop, one);
				}
			} 

			if ((op&0x2) == 0) {
				for (int i = 0;  i < convert_n[v][2].size(); ++i) {
					n[deep] = convert_n[v][2][i];
					new_op = (op|0x2);
					move_to_orgin(deep + 1, new_op, n, pos, s, preop, one);
				}
			}

			if ((0 == op)) {
				for (int i = 0; i < convert_n[v][0].size(); ++i) {
					n[deep] = convert_n[v][0][i];
					new_op = 0x3;
					move_to_orgin(deep + 1, new_op, n, pos, s,preop, one);
				}
			}
			n[deep] = v;
			move_to_orgin(deep + 1, op, n, pos, s,preop, one);
		} else {
			n[deep] = 0;
			move_to_orgin(deep + 1, op, n, pos, s, preop, one);
		}

	}
}

void  move_to_other(int deep,bool had, int* n, int op, int pos, int s,int preop, int one/* = 0*/) {//op = 1, 2
	if (deep == 3) {
		if (false == had)
				return;
		bool res = (n[2] == (n[0] + n[1] + one)%10);
		int carry = (n[0]+n[1]+one)/10;
		if (res) {
			dp_state[pos][s][carry].is_ok = true;
			dp_state[pos][s][carry].op = preop;
			memcpy(dp_state[pos][s][carry].n, n, sizeof(int)*3);
		}
		return;
	} else {
		if (pos < num[deep].length()) {
			int v = (int)(num[deep][pos] - '0');
			if (!had) {
				for (int i = 0;  i < convert_n[v][op].size(); ++i) {
					n[deep] = convert_n[v][op][i];
					move_to_other(deep + 1, true, n, op, pos, s, preop, one);
				}
			}	
			n[deep] = v;
			move_to_other(deep + 1, had, n, op, pos, s, preop, one);
		} else {
			n[deep] = 0;
			move_to_other(deep + 1, had, n, op, pos, s, preop, one);
		}

	}
	return ;
}

bool  unchange_add(int pos, int s, int preop, int one/* = 0*/) {
	int n[3] = {0};
	for (int i = 0; i < 3; ++i) {
		if (pos < num[i].length())  {
			n[i] = (int)(num[i][pos] - '0');
		}
	}

	bool res = (n[2] == (n[0] + n[1] + one)%10);
	if (res) {
		int carry = (n[0]+n[1] + one)/10;
		dp_state[pos][s][carry].is_ok = true;
		dp_state[pos][s][carry].op = preop;
		memcpy(dp_state[pos][s][carry].n, n, sizeof(int)*3);
	}

	return res;
}

void dp_solve() {
	int mn = 0;
	for (int i = 0; i < 3; ++i) {
		reverse(num[i].begin(), num[i].end());
		if (mn < num[i].length()) {
			mn = num[i].length();
		}
	}
	for (int i = 0; i < mn; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 2; ++k) {
				dp_state[i][j][k].reset();
			}
		}
	}
	for (int i = 0; i < mn; ++i) {
		if (0 == i) {
			unchange_add(0,0, 0);
			int n[3] = {0};
			move_to_other(0, false,n, 1, 0, 1, 0, 0);
			move_to_other(0, false,n, 2, 0, 2, 0, 0);
			move_to_orgin(0, 0, n, 0, 3, 0);
		} else {
			int n[3] = {0};
			//case j ==0
			if (dp_state[i-1][0][0].is_ok) {
				unchange_add(i, 0, 0, 0);
				move_to_other(0, false, n, 1, i, 1, 0, 0);
				move_to_other(0, false, n, 2, i, 2, 0, 0);
				move_to_orgin(0, 0, n, i, 3, 0, 0);
			}
			if (dp_state[i-1][0][1].is_ok) {
				unchange_add(i, 0, 0, 1);
				move_to_other(0, false, n, 1, i, 1, 4, 1);
				move_to_other(0, false, n, 2, i, 2, 4, 1);
				move_to_orgin(0, 0, n, i, 3, 4, 1);
			}

			for (int j = 1; j <= 3; ++j) {
				if (dp_state[i-1][j][0].is_ok) {
					unchange_add(i, j, j, 0);
				}

				if (dp_state[i-1][j][1].is_ok) {
					unchange_add(i, j, 4 + j, 1);
				}
			}

			if (dp_state[i-1][1][0].is_ok) {
				move_to_other(0, false, n, 2, i, 3, 1, 0);
			}

			if (dp_state[i-1][1][1].is_ok) {
				move_to_other(0, false, n, 2, i, 3, 5, 1);
			}

			if (dp_state[i-1][2][0].is_ok) {
				move_to_other(0, false, n, 1, i, 3, 2, 0);
			}

			if (dp_state[i-1][2][1].is_ok) {
				move_to_other(0, false, n, 1, i, 3, 6, 1);
			}
		}
	}
	print_ans(mn);
}

void insert_ans(int pos, int n[]) {
	for (int i = 0; i < 3; ++i) {
		if (pos < num[i].length()) {
			ans_num[i].append(1, n[i] + '0');
		}
	}
}

void print_ans(int mn) {
	int preop = -1;
	for (int i = mn - 1; 0 <= i; --i) {
		if (i == (mn - 1)) {
			preop = dp_state[mn-1][3][0].op;
			insert_ans(mn-1, dp_state[mn-1][3][0].n);
		} else {
			int j = preop%4;
			int k = preop/4;
			preop = dp_state[i][j][k].op;
			insert_ans(i, dp_state[i][j][k].n);
		}
	}
	printf("%s + %s = %s\n", ans_num[0].c_str(), ans_num[1].c_str(), ans_num[2].c_str());
	printf("*****************\n");
}

void reset_init() {
	for (int i = 0; i < 3; ++i) {
		num[i].clear();
		ans_num[i].clear();
	}
}
int main() {
	char c;
	int cur_idx = 0;
	init();
	while (gets(buf)) {
		int len = strlen(buf);
		for (int i = 0; i < len; ++i) {
			char c = buf[i];
			if ('0' <= c && c <= '9') {
				num[cur_idx].append(1,c);
			} else {
				if (' ' == c && num[cur_idx].length() > 0){
					cur_idx = (cur_idx + 1) % 3;
				}
			}
		}
		cur_idx = 0;
		dp_solve();
		reset_init();

	}
}


