#include<iostream>
using namespace std;

int tran[ 10 ][ 20 ], N, M;

struct Command
{
 int command;
 int pre;
};
const int MAX = 200000;
Command cmdList[ MAX ]; int cCount;
int queue[ MAX ][ 8 ], front, rear;

int cmds[ MAX ], cmdSize;

char xx[ 17 ] = "0123456789abcdef";

void read()
{
 scanf( "%d %d", &N, &M );
 int i, j;
 for ( i = 0; i < N; i ++ )
 {
  for ( j = 0; j < M; j ++ )
   scanf( "%d", &tran[ i ][ j ] );
  queue[ 0 ][ i ] = i;
 }
}

bool checkCurState( int front, int size )
{
 for ( int i = 0; i < size; i ++ )
  if ( queue[ front ][ i ] != 0 )
   return false;
 return true;
}

bool checkHaveUsed( int cur, int curState[], int size )
{
 for ( int x = cur; x != 0; x = cmdList[ x ].pre )
 {
  bool flag = false;
  for ( int i = 0; i < size; i ++ )
   if ( curState[ i ] != queue[ x ][ i ] )
    flag = true;
  if ( !flag )
   return true;
 }
 return false;
}

void getPath( int front )
{
 cmdSize = 0;
 for ( int x = front; x != 0; x = cmdList[ x ].pre )
  cmds[ cmdSize ++ ] = cmdList[ x ].command;
}

bool bfs()
{
 front = 0; rear = 1;

 while( front < rear )
 {
   if ( checkCurState( front, N ) ) 
   {
    getPath( front );
    return true;
   }

   for ( int i = 0; i < M; i ++ )
   {
    for ( int j = 0; j < N; j ++ )
     queue[ rear ][ j ] = tran[ queue[ front ][ j ] ][ i ];
    if ( !checkHaveUsed( front, queue[ rear ], N ) )
    {
     cmdList[ rear ].command = i;
     cmdList[ rear ].pre = front;
     rear ++;
    }  
   }

   front ++;
 }

 return false;
}

void print( int size )
{
 for ( int i = size - 1; i >= 0; i -- )
  printf( "%c", xx[ cmds[ i ] ]);
 putchar( '\n' );
}

int main()
{
 read();
 if ( bfs() )
  print( cmdSize );
 else
  printf( "*\n" );
 return 0;
}




