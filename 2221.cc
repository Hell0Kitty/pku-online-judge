#include<string.h>
#include<stdio.h>
int mat[ 12 ][ 12 ],temp[ 12 ][ 12 ];
bool flag[ 12 ];

void solve(){
    memset( temp,0,sizeof( temp ) );
    for( int i=0;i<4;i++ ){
        for( int j=0;j<10;j++ ){
            if( mat[i][j]!=0 )
                temp[i][ (j-mat[i][j]+10)%10 ] = mat[i][j];
        }
    }
    for( int i=4;i<8;i++ ){
        for( int j=0;j<10;j++ ){
            if( mat[i][j]!=0 )
                temp[i][ (j+mat[i][j])%10 ] = mat[i][j];
        }
    }
    for( int i=0;i<8;i++ ){
        for( int j=0;j<10;j++ ){
            mat[i][j] = temp[i][j];
        }
    }
}

int main(){
    char s[ 12 ];
    while( scanf("%s",s)!=EOF ){
        for( int i=0;i<8;i++ )
            for( int j=0;j<10;j++ )
                scanf("%d",&mat[i][j]);
        scanf("%s",s);
        memset( flag,true,sizeof( flag ) );
        for( int i=0;i<4;i++ ){
            for( int j=0;j<10;j++ ){
                for( int k=0;k<=mat[i][j]&&mat[i][j]!=0;k++ ){
                    flag[ (j-k+10)%10 ] = false;
                }
            }
            solve( );
        }
        for( int i=4;i<8;i++ ){
            for( int j=0;j<10;j++ ){
                for( int k=0;k<=mat[i][j]&&mat[i][j]!=0;k++ ){
                    flag[ (j+k)%10 ] = false;
                }
            }
            solve( );
        }
        int i;
        for( i=0;i<10;i++ )
            if( flag[i]==true )
                break;
        if( i==10 )
            printf("FROGGER\n");
        else
            printf("LEFTOVER POSSUM\n");
    }
    return 0;
}



