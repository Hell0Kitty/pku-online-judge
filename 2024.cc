#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const char num[15] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
const char col[5] = {'*', 'c', 'd', 'h', 's'};

inline int get_num(char c)
{
	if (c == 'A')
		return 14;
	if (c == 'K')
		return 13;
	if (c == 'Q')
		return 12;
	if (c == 'J')
		return 11;
	if (c == 'T')
		return 10;
	return c - '0';
}

inline int get_col(char c)
{
	if (c == 'c')
		return 1;
	if (c == 'd')
		return 2;
	if (c == 'h')
		return 3;
	return 4;
}

struct card
{
	int num, col;

	inline card(int num, int col) : num(num), col(col) {}

	inline card() {}

	inline bool operator < (const card &b) const
	{
		if (num != b.num)
			return num < b.num;
		return col < b.col;
	}

	inline void read()
	{
		char s[10];
		scanf("%s", s);
		num = get_num(s[0]);
		col = get_col(s[1]);
	}
}need[10];

struct hand
{
	card a[5];
	int type;

	inline void pre()
	{
		sort(a, a + 5);
	}

	inline void change()
	{
		for (int i = 0; i < 5; i ++)
			if (a[i].num == 14)
				a[i].num = 1;
		pre();
	}

	inline void reset()
	{
		for (int i = 0; i < 5; i ++)
			if (a[i].num == 1)
				a[i].num = 14;
		pre();
	}

	inline bool is_royal_flush()
	{
		pre();
		for (int i = 1; i < 5; i ++)
		{
			if (a[i].col != a[0].col)
				return 0;
			if (a[i].num != a[i - 1].num + 1)
				return 0;
		}
		if (a[4].num == 14)
			return 1;
		return 0;
	}

	inline bool is_straight_flush()
	{
		pre();
		for (int i = 1; i < 5; i ++)
			if (a[i].col != a[0].col)
				return 0;
		bool flag = 1;
		for (int i = 1; i < 5; i ++)
			if (a[i].num != a[i - 1].num + 1)
				flag = 0;
		if (flag)
			return 1;
		change();
		flag = 1;
		for (int i = 1; i < 5; i ++)
			if (a[i].num != a[i - 1].num + 1)
				flag = 0;
		reset();
		return flag;
	}

	inline bool is_four_of_a_kind()
	{
		pre();
		bool flag = 1;
		for (int i = 1; i < 4; i ++)
			if (a[i].num != a[0].num)
				flag = 0;
		if (flag)
			return 1;
		flag = 1;
		for (int i = 1; i < 4; i ++)
			if (a[i].num != a[4].num)
				flag = 0;
		return flag;
	}

	inline bool is_full_house()
	{
		pre();
		bool flag = a[1].num == a[0].num && a[2].num == a[0].num && a[3].num == a[4].num;
		if (flag)
			return 1;
		flag = a[0].num == a[1].num && a[2].num == a[3].num && a[2].num == a[4].num;
		return flag;
	}

	inline bool is_flush()
	{
		pre();
		bool flag = 1;
		for (int i = 1; i < 5; i ++)
			if (a[i].col != a[0].col)
				flag = 0;
		return flag;
	}

	inline bool is_straight()
	{
		pre();
		bool flag = 1;
		for (int i = 1; i < 5; i ++)
			if (a[i].num != a[i - 1].num + 1)
				flag = 0;
		if (flag)
			return 1;
		change();
		flag = 1;
		for (int i = 1; i < 5; i ++)
			if (a[i].num != a[i - 1].num + 1)
				flag = 0;
		reset();
		return flag;
	}

	inline bool is_three_of_a_kind()
	{
		pre();
		if (a[0].num == a[1].num && a[1].num == a[2].num)
			return 1;
		if (a[1].num == a[2].num && a[2].num == a[3].num)
			return 1;
		if (a[2].num == a[3].num && a[3].num == a[4].num)
			return 1;
		return 0;
	}

	inline void get_type()
	{
		if (is_royal_flush())
			type = 7;
		else if (is_straight_flush())
			type = 6;
		else if (is_four_of_a_kind())
			type = 5;
		else if (is_full_house())
			type = 4;
		else if (is_flush())
			type = 3;
		else if (is_straight())
			type = 2;
		else if (is_three_of_a_kind())
			type = 1;
		else
			type = 0;
	}	

	inline bool operator < (hand &b)
	{
		if (type != b.type)
			return type < b.type;
		pre();
		b.pre();
		if (type == 7)
			return 0;
		if (type == 6)
			return a[0].num < b.a[0].num;
		if (type == 5)
		{
			if (a[0].num != a[1].num)
				swap(a[0], a[4]);
			if (b.a[0].num != b.a[1].num)
				swap(b.a[0], b.a[4]);
			if (a[0].num != b.a[0].num)
				return a[0].num < b.a[0].num;
			return a[4].num < b.a[4].num;
		}
		if (type == 4)
		{
			if (a[1].num != a[2].num)
			{
				swap(a[0], a[4]);
				swap(a[1], a[3]);
			}
			if (b.a[1].num != b.a[2].num)
			{
				swap(b.a[0], b.a[4]);
				swap(b.a[1], b.a[3]);
			}
			if (a[0].num != b.a[0].num)
				return a[0].num < b.a[0].num;
			return a[4].num < b.a[4].num;
		}
		if (type == 3)
		{
			for (int i = 4; i >= 0; i --)
				if (a[i].num != b.a[i].num)
					return a[i].num < b.a[i].num;
			return 0;
		}
		if (type == 2)
			return a[0].num < b.a[0].num;
		if (type == 1)
		{
			if (a[1].num != a[2].num)
			{
				swap(a[0], a[3]);
				swap(a[1], a[4]);
			}
			else if (a[2].num == a[3].num)
				swap(a[0], a[3]);
			if (b.a[1].num != b.a[2].num)
			{
				swap(b.a[0], b.a[3]);
				swap(b.a[1], b.a[4]);
			}
			else if (b.a[2].num == b.a[3].num)
				swap(b.a[0], b.a[3]);
			if (a[0].num != b.a[0].num)
				return a[0].num < b.a[0].num;
			if (a[4].num != b.a[4].num)
				return a[4].num < b.a[4].num;
			if (a[3].num != b.a[3].num)
				return a[3].num < b.a[3].num;
			return 0;
		}
		return 0;
	}
}best;

bool flag[100][100];

inline void print_type(int x)
{
	if (x == 7)
		puts("ROYAL FLUSH");
	if (x == 6)
		puts("STRAIGHT FLUSH");
	if (x == 5)
		puts("FOUR OF A KIND");
	if (x == 4)
		puts("FULL HOUSE");
	if (x == 3)
		puts("FLUSH");
	if (x == 2)
		puts("STRAIGHT");
	if (x == 1)
		puts("THREE OF A KIND");
}

int main()
{
	int _;
	scanf("%d", &_);
	while (_ --)
	{
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i < 5; i ++)
		{
			need[i].read();
			flag[need[i].num][need[i].col] = 1;
		}
		for (int i = 0; i < 2; i ++)
		{
			card tmp;
			tmp.read();
			flag[tmp.num][tmp.col] = 1;
		}
		for (int i = 0; i < 5; i ++)
			best.a[i] = need[i];
		best.get_type();
		for (int del = 0; del < 5; del ++)
		{
			hand base;
			int cnt = 0;
			for (int i = 0; i < 5; i ++)
				if (i != del)
					base.a[cnt ++] = need[i];
			for (int i = 2; i <= 14; i ++)
				for (int j = 1; j <= 4; j ++)
					if (!flag[i][j])
					{
						base.a[4] = card(i, j);
						hand now = base;
						now.get_type();
						if (best < now)
							best = now;
						else if (!(now < best))
						{
							now.pre();
							best.pre();
							for (int k = 0; k < 5; k ++)
								if (best.a[k].num == now.a[k].num && best.a[k].col != now.a[k].col)
									best.a[k].col = 0;
						}
					}
		}
		for (int del1 = 0; del1 < 4; del1 ++)
			for (int del2 = del1 + 1; del2 < 5; del2 ++)
			{
				hand base;
				int cnt = 0;
				for (int i = 0; i < 5; i ++)
					if (i != del1 && i != del2)
						base.a[cnt ++] = need[i];
				for (int i = 2; i <= 14; i ++)
					for (int j = 1; j <= 4; j ++)
						if (!flag[i][j])
						{
							flag[i][j] = 1;
							base.a[3] = card(i, j);
							for (int x = i; x <= 14; x ++)
								for (int y = 1; y <= 4; y ++)
									if (!flag[x][y])
									{
										if (i == x && j > y)
											continue;
										base.a[4] = card(x, y);
										hand now = base;
										now.get_type();
										if (best < now)
											best = now;
										else if (!(now < best))
										{
											now.pre();
											best.pre();
											for (int k = 0; k < 5; k ++)
												if (best.a[k].num == now.a[k].num && best.a[k].col != now.a[k].col)
													best.a[k].col = 0;
										}
									}
							flag[i][j] = 0;
						}
			}
		best.pre();
		for (int i = 4; i >= 0; i --)
			printf("%c%c ", num[best.a[i].num], col[best.a[i].col]);
		print_type(best.type);
	}
	return 0;
}



