#include <cstdio>

#include <algorithm>

using namespace std;

float ratio[100];

int f, r;

float front[10], rear[10];

float max_ratio;

int index;

int main()

{
  while (scanf("%d", &f) != EOF && f)

  {
    scanf("%d", &r);

    for (int i = 0; i < f; i++) scanf("%f", &front[i]);

    for (int i = 0; i < r; i++) scanf("%f", &rear[i]);

    index = 0;

    for (int i = 0; i < r; i++)

    {
      for (int j = 0; j < f; j++)

      {
        ratio[index++] = rear[i] / front[j];
      }
    }

    sort(ratio, ratio + index);

    for (int i = 0; i < index - 1; i++) ratio[i] = ratio[i + 1] / ratio[i];

    max_ratio = 0.0;

    for (int i = 0; i < index - 1; i++)

    {
      if (max_ratio < ratio[i]) max_ratio = ratio[i];
    }

    printf("%.2f\n", max_ratio);
  }

  return 0;
}
