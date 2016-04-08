#include <stdio.h>

#include <string.h>

#define len 251

char post[len], s[len];  // post 为后缀表达式的栈

int priority[len], n;  // priority 为运算符优先级

void postfix() {
  int p, ep, i;

  char expresion[len];

  for (i = p = ep = 0; i < n; i++) {
    switch (s[i]) {
      //左括号直接进栈

      case '(':
        expresion[ep++] = s[i];

        break;

      // + - * /
      // 按照优先级入栈，//即如果表达式栈expresion中的栈顶的运算符的优先级高于s[i]的运算符的优先级，

      // expresion中栈顶的元素压入post的后缀表达式的栈中，如果不满足条件则是s[i]压入expresion栈中作为新的栈顶元素

      case '+':

      case '-':
        for (; ep && expresion[ep - 1] != '('; post[p++] = expresion[--ep])
          ;

        expresion[ep++] = s[i];

        break;

      case '*':

      case '/':
        for (; ep && (expresion[ep - 1] == '*' || expresion[ep - 1] == '/');
             post[p++] = expresion[--ep])
          ;

        expresion[ep++] = s[i];

        break;

      //右括号与左括号之间的元素全部进入后缀表达式的栈

      case ')':
        for (; ep && expresion[--ep] != '('; post[p++] = expresion[ep])
          ;

        break;

      default:
        post[p++] = s[i];

        break;
    }
  }

  while (ep) post[p++] = expresion[--ep];

  post[p] = '\0';
}

void infix() {
  int k, p, i, tem;  // p为栈顶指针

  bool c;

  char stack[len][len], s1[len],
      s2[len];  // s1,s2分别是参与运算的前面和后面的表达式，可以想想一下 M*K
                // 这里的M和K为表达式 //stack下面有介绍

  for (i = p = 0; i < n; i++) {
    switch (post[i]) {
      case '+':

      case '-':

      case '*':

      case '/':
        k = (post[i] == '*' || post[i] == '/') ? 2 : 1;  // k记录优先级

        c = (post[i] == '-' || post[i] == '/') ? true
                                               : false;  //记录是否需要括号

        //判断是不是需要（） 设想一下: 表达式 ： m L h
        //这里的小写字母代表表达式，L代表运算符，如果m中有运算符，

        //那么m中的运算符的优先级必然大于或者等于L不然的话就要加（），例如:(a+b)*c，同理h中如果有运算符的话那么该运算符的优先级必然大于L，

        //或者当L的优先级和h中的运算符的优先级相同时L为‘+’或‘*’，不然也要加（），例如:
        // a-(b+c) ; a/(b*c) ;

        if (priority[p - 1] &&
            (priority[p - 1] < k || (priority[p - 1] == k && c))) {
          s2[0] = '(';

          s2[1] = '\0';

          strcat(s2, stack[p - 1]);

          strcat(s2, ")");

        }

        else {
          s2[0] = '\0';

          strcat(s2, stack[p - 1]);
        }

        --p;

        if (priority[p - 1] && priority[p - 1] < k) {
          s1[0] = '(';

          s1[1] = '\0';

          strcat(s1, stack[p - 1]);

          strcat(s1, ")");

        }

        else {
          s1[0] = '\0';

          strcat(s1, stack[p - 1]);
        }

        //进行字符串的拼接处理，可以看到stack只是作为容器来存储post[i]运算符下的表达式，

        //从中可以看到当执行完最后一次时p也就是栈顶指针为0

        strcpy(stack[p - 1], s1);

        tem = (int)strlen(stack[p - 1]);

        stack[p - 1][tem] = post[i];

        stack[p - 1][tem + 1] = '\0';

        strcat(stack[p - 1], s2);

        priority[p - 1] = k;

        break;

      //如果post[i]是操作数的话就入栈，由于每两个操作数之间都有一个操作符，所以此时的stack[i]就成了第i个表达式的内容

      default:
        stack[p][0] = post[i];

        stack[p][1] = '\0';

        priority[p++] = 0;

        break;
    }
  }

  strcpy(post, stack[0]);
}

int main(void) {
  int t;

  scanf("%d", &t);

  while (t--) {
    scanf("%s", s);

    n = (int)strlen(s);

    memset(post, 0, sizeof(post));

    postfix();

    infix();

    puts(post);
  }

  return 0;
}
