#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<string>
#include<iostream>
using namespace std ;

map<int,int> mp ;
char s[111] ;
char s1[111] , s2[111] , f[1111] ;

void reverse ( char *s , int len ) {
    int i ;
    for ( i = 0 ; i < (len+1) / 2 ; i ++ )
        swap ( s[i] , s[len-i-1] ) ;
}

void jion ( char *s , char *s1 , char *s2 , int l1 , int l2 ) {
    int len = 0 ;
    int i ;
    for ( i = 0 ; i < l1 ; i ++ ) s[len++] = s1[i] ;
    for ( i = 0 ; i < l2 ; i ++ ) s[len++] = s2[i] ;
    s[len] = 0 ;
}

int hash ( char *s ) {
    int ret = 0 ;
    while ( *s ) {
        ret = ret * 1000000007 + ( *s ) ;
        s ++ ;
    }
    return ret ;
}

int main () {
    int t , i , k ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        scanf ( "%s" , s ) ;
        int len = strlen ( s ) ;
        mp.clear () ;
        int ans = 0 ;
        for ( i = 0 ; i < len - 1 ; i ++ ) {
            s1[i] = s[i] , s1[i+1] = 0 ;
            strcpy ( s2 , s + i + 1  ) ;
            int l1 = i + 1 , l2 = len - l1 ;
            jion ( f , s1 , s2 , l1 , l2 ) ;
            k = hash ( f ) ;
            if ( !mp.count ( k ) ) ans ++ , mp[k] = 1 ;
            jion ( f , s2 , s1 , l2 , l1 ) ;
            k = hash ( f ) ;
            if ( !mp.count ( k ) ) ans ++ , mp[k] = 1 ;
            reverse ( s2 , l2 ) ;
            jion ( f , s1 , s2 , l1 , l2 ) ;
            k = hash ( f ) ;
            if ( !mp.count ( k ) ) ans ++ , mp[k] = 1 ;
            jion ( f , s2 , s1 , l2 , l1 ) ;
            k = hash ( f ) ;
            if ( !mp.count ( k ) ) ans ++ , mp[k] = 1 ;
            reverse ( s1 , l1 ) ;
            jion ( f , s1 , s2 , l1 , l2 ) ;
            k = hash ( f ) ;
            if ( !mp.count ( k ) ) ans ++ , mp[k] = 1 ;
            jion ( f , s2 , s1 , l2 , l1 ) ;
            k = hash ( f ) ;
            if ( !mp.count ( k ) ) ans ++ , mp[k] = 1 ;
            reverse ( s2 , l2 ) ;
            jion ( f , s1 , s2 , l1 , l2 ) ;
            k = hash ( f ) ;
            if ( !mp.count ( k ) ) ans ++ , mp[k] = 1 ;
            jion ( f , s2 , s1 , l2 , l1 ) ;
            k = hash ( f ) ;
            if ( !mp.count ( k ) ) ans ++ , mp[k] = 1 ;
            reverse ( s1 ,  l1 ) ;
        }
        printf ( "%d\n" , ans ) ;
    }
}



