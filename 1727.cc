#include<stdio.h>
#include<algorithm>
typedef struct event
{
  int x;
  int t;
} event;

event e[100000];

int cmp(const void *a, const void *b)
{
  event *e1, *e2;
  e1 = (event *)a;
  e2 = (event *)b;
  if(e1->x != e2->x)
     return e1->x - e2->x;
  else return e1->t - e2->t;
}

int check(int t, int n, int m)
{
  int last_b,last_e,begin,end,count,i;
  last_b = e[0].x - (e[0].t-t);
  last_e = e[0].x + (e[0].t-t);
  count=1;
  for(i=1; i<n; i++)
  {
    begin= e[i].x - (e[i].t-t);
    end= e[i].x + (e[i].t-t);
    if(last_e < begin)
    {
      count++;
      if(count > m) return 0;
      last_b = begin;
      last_e = end;
    }
    else 
    {
      if(last_b <= begin) last_b = begin;
      if(end <= last_e) last_e = end;
      }
  }
  return 1;
}

int main()
{
  int cases, n, m, i, j;
  int t_max, t_min, mid, ans;
  scanf("%d", &cases);
  for(i=0; i<cases; i++)
  {
    scanf("%d%d", &n, &m);
    t_max=1000000;
    t_min=-2000000;
    for(j=0; j<n; j++)
    {
      scanf("%d%d", &e[j].t, &e[j].x);
      if(e[j].t < t_max) t_max=e[j].t;
    }

    qsort(e, n, sizeof(event), cmp);

    while(t_min <= t_max)
    {
      mid=(t_min + t_max) >> 1;
      if(check(mid, n, m))
      {
        ans = mid;
        //继续往上找 
        t_min=mid+1;
      }
      else t_max=mid-1;
    }

    printf("Case %d: %d\n", i+1, ans);
  }

  return 0; 
}