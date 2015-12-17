
#include <stdio.h>
#include <string.h>

int degree[10000];
char directive[500];
char discard[50];
char inputs[1000];
int startRoom, rooms;

void answer() {
  if (startRoom == 0) {
    int i;
    int sumDoors = 0;
    for (i = 0; i < rooms; i++) {
      if (degree[i] % 2 != 0) {
        break;
      }
      sumDoors += degree[i];
    }
    if (i < rooms) {
      puts("NO");
      return;
    } else {
      printf("YES %d\n", sumDoors / 2);
    }
  } else {
    if (degree[startRoom] % 2 != 0 && degree[0] % 2 != 0) {
      int i;
      int sumDoors = degree[0];
      for (i = 1; i < rooms; i++) {
        if (i != startRoom) {
          if (degree[i] % 2 != 0) {
            break;
          }
        }

        sumDoors += degree[i];
      }
      if (i < rooms) {
        puts("NO");
        return;
      } else {
        printf("YES %d\n", sumDoors / 2);
      }

    } else {
      puts("NO");
    }
  }
}

int main() {
  gets(directive);
  do {
    // printf("The input directive is %s\n", directive);
    char* p = strtok(directive, " ");
    // printf("P is %s\n", p);
    p = strtok(NULL, " ");
    sscanf(p, "%d", &startRoom);
    //  printf("P is %s\n", p);
    p = strtok(NULL, " ");
    sscanf(p, "%d", &rooms);
    memset(degree, 0, 10000 * sizeof(int));
    // printf("The startRoom is %d, The rooms is %d\n", startRoom, rooms);
    // sscanf(directive ,"START %d %d", &startRoom, &rooms );
    //    printf("The room is %d %d\n", startRoom, rooms);

    for (int i = 0; i < rooms; i++) {
      gets(inputs);
      char* _tokens = strtok(inputs, " ");
      while (_tokens) {
        int doorNo;
        sscanf(_tokens, "%d", &doorNo);
        degree[i]++;
        degree[doorNo]++;

        _tokens = strtok(NULL, " ");
      }
      // token
    }
    answer();
    gets(directive);  // input the END
    gets(directive);
  } while (strcmp(directive, "ENDOFINPUT") != 0);

  return 0;
}