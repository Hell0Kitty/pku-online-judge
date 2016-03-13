#include <string.h>
#include <iostream>
#include <stdio.h>

#define MAX_INT 0x7FFFFFFF
#define MAX_NUMS 101
#define MAX_N 5 * 60 * 60
using namespace std;

int signals[MAX_NUMS], signals_size, zeros, start, end, value;

int check(int start, int end, int index) {
  if (index == signals_size) {
    if (end >= start) return start;

    return 0;
  }

  int mul = start / (signals[index] << 1);

  int tmp_start = (signals[index] << 1) * mul;
  int tmp_end = tmp_start + signals[index] - 6;

  while (tmp_start <= end) {
    if (tmp_start < start) tmp_start = start;

    if (tmp_end > end) tmp_end = end;

    int value;
    if (tmp_end >= start)
      if ((value = check(tmp_start, tmp_end, index + 1))) return value;

    mul++;
    tmp_start = (signals[index] << 1) * mul;
    tmp_end = tmp_start + signals[index] - 6;
  }

  return 0;
}

int main() {
  zeros = 0;
  while (zeros != 3) {
    signals_size = 0, value = MAX_INT, start = 0;
    while (cin >> signals[signals_size], signals[signals_size]) {
      if (value > signals[signals_size])
        value = signals[signals_size], start = signals_size;
      signals_size++, zeros = 0;
    }

    signals[start] = signals[0], signals[0] = value;

    if (signals_size) {
      start = signals[0] << 1, value = 0;
      while (start <= MAX_N) {
        if (start + signals[0] - 6 > MAX_N)
          value = check(start, MAX_N, 1);
        else
          value = check(start, start + signals[0] - 6, 1);

        if (value) {
          printf("%02d:%02d:%02d\n", value / 3600, (value % 3600) / 60,
                 value % 60);
          break;
        }

        start += (signals[0] << 1);
      }

      if (!value)
        std::cout << "Signals fail to synchronise in 5 hours" << std::endl;

      signals_size = 0;
    } else if (!signals_size)
      zeros++;
  }
  return 0;
}
