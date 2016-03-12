/* 
  Name:poj 2410 Simple Computers 
  Author:Unimen 
  Date: 25/04/11 20:39 
  Description:模拟题  
*/  
/* 
解题报告：模拟题 
1、运用位运算模拟执行过程 
2、注意枚举，位运算的运用 
3、注意模拟时用的数据类型，尤其是unsigned char memory[32];为什么开成unsigned类型的  
*/  
#include <iostream>  
#include <cstring>  
using namespace std;  
enum semantics{STA, LDA, BEQ, NOP, DEC, INC, JMP, HLT};  
char szInput[32][9];  
unsigned char memory[32];  
unsigned char accu;  
unsigned char pc;  
void execute()  
{  
    while(true)  
    {  
        switch(memory[pc]>>5)  
        {  
            case STA :  
                memory[memory[pc] & 0x1f] = accu;  
                pc = ++pc & 0x1f;  
            break;  
            case LDA :  
                accu = memory[memory[pc] & 0x1f];  
                pc = ++pc & 0x1f;  
            break;  
            case BEQ :  
                if(0 == accu)  
                {  
                    pc = memory[pc] & 0x1f;  
                }  
                else  
                    pc = ++pc & 0x1f;  
            break;  
            case NOP :  
                pc = ++pc & 0x1f;  
            break;  
            case DEC :  
                --accu;  
                pc = ++pc & 0x1f;  
            break;  
            case INC :  
                ++accu;  
                pc = ++pc & 0x1f;  
            break;  
            case JMP :  
                pc = memory[pc] & 0x1f;  
            break;  
            case HLT :  
                for(int i=7; i>=0; --i)  
                {  
                    cout<<((accu>>i)&1);  
                }  
                cout<<endl;  
                return ;  
            break;  
        }  
    }  
}  
int main()  
{  
    int i, j;  
    while(cin>>szInput[0])  
    {  
        for(i=1; i<32; ++i)  
            cin>>szInput[i];  
        memset(memory, 0, sizeof(memory));  
        for(i=0; i<32; ++i)  
        {  
            for(j=0; j<8; ++j)  
            {  
                memory[i] = (memory[i]<<1) | (szInput[i][j] - '0');  
            }  
        }  
        accu = 0x0;  
        pc = 0x0;  
        execute();        
    }     
    return 0;  
}  
