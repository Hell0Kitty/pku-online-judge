#include <iostream>
#include <cstring>
using namespace std;
const int N = 1300000; //第10万个数为1299709
int prime[N];
bool notPrime[N];

int main() {

  memset(prime, 0, sizeof(prime));
  memset(notPrime, 0, sizeof(notPrime));
  int count = 0;
  for (int i = 2; i < N; i++) //求素数表
  {
    if (!notPrime[i]) {
      prime[count++] = i;
    }

    for (int j = 0; j < count && (i * prime[j] < N); j++) {
      notPrime[i * prime[j]] = true;
      if (!(i % prime[j]))
        break;
    }
  }

  int test;
  while (cin >> test && test != 0) {
    for (int i = 0; i < 100000; i++) {
      if (prime[i] == test) //输入的是素数
      {
        cout << "0" << endl;
        break;
      } else {
        if (test < prime[i] && i != 0) {
          cout << prime[i] - prime[i - 1] << endl;
          break;
        }
      }
    }
  }
  return 0;
}