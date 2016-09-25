#include <stdio.h>
#define dataStart 6

unsigned int CRC;
char inputStr[100];

//字符转为16进制整数
unsigned int ChangeTo16(char ch) {
  if (ch - '9' <= 0)
    return ch - '0';
  else
    return ch - 'A' + 10;
}

//一轮CRC转化
void CRC_Change(unsigned int data) {
  int i;
  CRC ^= data;
  for (i = 0; i < 8; i++) {
    if (CRC & 0x0001) {
      CRC >>= 1;
      CRC ^= 0xA001;
    } else
      CRC >>= 1;
  }
}

int main() {
  unsigned int slaAddr, func, staAddr, numOfbyte;
  unsigned int temp, tempCRC;
  unsigned int i, len;

  unsigned long floatData;
  unsigned long *longAddr;
  float *floatAddr;

  while (scanf("%u,%u,%u,%u", &slaAddr, &func, &staAddr, &numOfbyte) != EOF) {
    CRC = 0xFFFF;
    CRC_Change(slaAddr);
    CRC_Change(func);
    CRC_Change(staAddr >> 8);
    CRC_Change(staAddr & 0x00ff);
    CRC_Change(numOfbyte >> 8);
    CRC_Change(numOfbyte & 0x00ff);
    temp = CRC & 0x00ff;
    temp <<= 8;
    CRC = (CRC >> 8) | temp;
    printf("%02X%02X%04X%04X%X\n", slaAddr, func, staAddr, numOfbyte, CRC);

    scanf("%s", &inputStr);
    CRC = 0xFFFF;
    CRC_Change(ChangeTo16(inputStr[0]) * 16 + ChangeTo16(inputStr[1]));
    CRC_Change(ChangeTo16(inputStr[2]) * 16 + ChangeTo16(inputStr[3]));
    len = ChangeTo16(inputStr[4]) * 16 + ChangeTo16(inputStr[5]);
    CRC_Change(len);
    for (i = 0; i < len * 2; i += 2)
      CRC_Change(ChangeTo16(inputStr[i + dataStart]) * 16 +
                 ChangeTo16(inputStr[i + 1 + dataStart]));
    temp = CRC & 0x00ff;
    temp <<= 8;
    CRC = (CRC >> 8) | temp;
    tempCRC = ChangeTo16(inputStr[i + dataStart]) * 0x1000 +
              ChangeTo16(inputStr[i + 1 + dataStart]) * 0x0100 +
              ChangeTo16(inputStr[i + 2 + dataStart]) * 0x0010 +
              ChangeTo16(inputStr[i + 3 + dataStart]);
    if (CRC != tempCRC) {
      printf("CRC_ERROR\n");
      continue;
    }
    for (i = 0; i < len * 2; i += 8) {
      floatData = ChangeTo16(inputStr[i + dataStart]) * 0x10000000 +
                  ChangeTo16(inputStr[i + 1 + dataStart]) * 0x01000000 +
                  ChangeTo16(inputStr[i + 2 + dataStart]) * 0x00100000 +
                  ChangeTo16(inputStr[i + 3 + dataStart]) * 0x00010000 +
                  ChangeTo16(inputStr[i + 4 + dataStart]) * 0x00001000 +
                  ChangeTo16(inputStr[i + 5 + dataStart]) * 0x00000100 +
                  ChangeTo16(inputStr[i + 6 + dataStart]) * 0x00000010 +
                  ChangeTo16(inputStr[i + 7 + dataStart]);

      longAddr = &floatData;
      floatAddr = (float *)longAddr;
      if (i > 0) printf(",");
      printf("%.1f", *floatAddr);
    }
    printf("\n");
  }
  return 0;
}
