#include <stdio.h>
#include <memory.h>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct ff
{
	vector<string> mmap;
	int h,w;
};

vector<ff> file;
map<string,int> fmap;

struct mm
{
	int x,y;
	int jud;
	int which;
	int num;
	int layer;
	string rs;
};

vector<mm> css;
map<string,int> cmap;

int n,m;
char s[1005];

int lay[1010][1010];
char maps[1010][1010];
int xmax,ymax;

void find(const int &i)
{
	if (css[i].jud)
	{
		find(css[i].which);
		css[i].x += css[css[i].which].x;
		css[i].y += css[css[i].which].y;
		css[i].jud = 0;
	}
}

int main()
{
	int t,o;
	int i,j,k,num,p,q;
	scanf("%d",&t);
	for (o = 1;o <= t;++o)
	{
		scanf("%d",&n);
		fmap.clear();
		file.clear();
		for (i = 0;i < n;++i)
		{
			ff temp;
			scanf("%s%d%d",s,&temp.h,&temp.w);
			fmap[s] = i;
			temp.mmap.clear();
			gets(s);
			for (j = 0;j < temp.h;++j)
			{
				gets(s);
				temp.mmap.push_back(s);
			}
			file.push_back(temp);
		}
		scanf("%d",&m);
		gets(s);
		num = 0;
		cmap.clear();
		css.clear();
		map<string,int>::iterator iter;
		for (i = 0;i < m;++i)
		{
			gets(s);
			j = 0;
			while(s[j] != '#')
				++j;
			++j;
			while(s[j] == ' ') 
				++j;
			k = j;
			while(s[k] != ' '&& s[k] != '{')
				++k;
			s[k] = 0;
			iter = cmap.find(s+j);
			if (iter == cmap.end())
			{
				cmap[s+j] = num;
				++num;
			}
			mm temp;
			gets(s);
			j = 0;
			while (s[j] != ':')
				++j;
			++j;
			sscanf(s + j,"%d",&temp.y);
			gets(s);
			j = 0;
			while (s[j] != ':') 
				++j;
			++j;
			sscanf(s + j,"%d",&temp.x);
			gets(s);
			j = 0;
			while (s[j] != ':')
				++j;
			++j;
			while (s[j] == ' ') 
				++j;
			if (s[j] == 'a') 
				temp.jud = 0;
			else
			{
				temp.jud=1;
				while (s[j] != '=')
					++j;
				++j;
				while (s[j] == ' ')
					++j;
				k = j;
				while (s[k] != ';'&&s[k] != ' ') 
					++k;
				s[k] = 0;
				temp.rs.assign(s + j);
			}
			gets(s);
			j = 0;
			while (s[j] != ':') 
				++j;
			++j;
			while (s[j] == ' ')
				++j;
			k = j;
			while (s[k] != ' '&&s[k] != ';')
				++k;
			s[k] = 0;
			temp.num = fmap[s + j];
			gets(s);
			j = 0;
			while (s[j] != ':') 
				++j;
			++j;
			sscanf(s + j,"%d",&temp.layer);
			gets(s);
			css.push_back(temp);
		}
		for (i = 0;i < m;++i)
			css[i].which = cmap[css[i].rs];
		printf("Scenario #%d:\n",o);
		memset(maps,' ',sizeof(maps));
		memset(lay,0,sizeof(lay));
		xmax = ymax = 0;
		for (i = 0;i < m;++i)
		{
			find(i);
			if (file[css[i].num].h == 0 || file[css[i].num].w == 0)
				continue;
			if (xmax < css[i].x + file[css[i].num].h)
				xmax = css[i].x + file[css[i].num].h;
			if (ymax < css[i].y + file[css[i].num].w)
				ymax = css[i].y + file[css[i].num].w;
			for (p = 0;p < file[css[i].num].h;++p)
			{
				for (q = 0;q < file[css[i].num].w;++q)
				{
					if (lay[css[i].x+p][css[i].y+q] <= css[i].layer)
					{
						if (file[css[i].num].mmap[p][q] != '.')
						{
							maps[css[i].x+p][css[i].y+q] = file[css[i].num].mmap[p][q];
							lay[css[i].x+p][css[i].y+q] = css[i].layer;
						}
					}
				}
			}
		}
		for (i = 0;i < xmax;++i)
		{
			for (j = 0;j < ymax;++j)
				printf("%c",maps[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}



