#include <cstdio>
#include <cstring>
#include <cstdlib>

char WDAY[7][4]  = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
char MON[12][4]  = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
char MON_DAY[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char ZONE[6][4]   = { "UT", "GMT", "EDT", "CDT", "MDT", "PDT" };
int ZONE_TIME[6] = { 0, 0, -400, -500, -600, -700 };
struct mydate{
	int sec, min, hour;
	int mday, mon, year, wday;
	int zone;
	void changezone(int zone2) {
		int zonehh = zone/100, zonemm = zone%100;
		int zone2hh = zone2/100, zone2mm = zone2%100;
		zone = zone2;
		if( zone2mm<zonemm ) zone2hh--, zone2mm+=60;
		hour += zone2hh-zonehh, min += zone2mm-zonemm;
		if( min>=60 ) min%=60, ++hour;
		if( hour>=24 ) ++mday, ++wday, hour-=24;
		else if( hour<0 ) hour+=24, --mday, --wday;
		if( wday>=7 ) wday-=7;
		else if( wday<0 ) wday+=7;

		if( mday<=0 ) {
			--mon;
			if( mon<0 ) mon+=12, --year;
			bool leap = false;
			if( (year%4==0 && year%100!=0) || (year%400==0 ) ) leap = true;
			int thismon = MON_DAY[mon]+(int)(mon==1&&leap);
			mday += thismon;
		}
		else {
			bool leap = false;
			if( (year%4==0 && year%100!=0) || (year%400==0 ) ) leap = true;
			int thismon = MON_DAY[mon]+(int)(mon==1&&leap);
			if( mday>thismon ) mday-=thismon, ++mon;
			if( mon>=12 ) mon-=12, ++year;
		}
	}
	void print() {
		printf("%s, %02d %s %04d %02d:%02d:%02d %+05d\r\n", WDAY[wday], mday, MON[mon], year, hour, min, sec, zone);
	}
} xd;
int main() {
	char s[10];
	while( ~scanf("%s", s) ) {
		s[3] = '\0';
		for(int i=0; i<7; ++i)
			if( !strcmp(s, WDAY[i]) ) { xd.wday = i; break; }
		scanf("%d", &xd.mday);
		scanf("%s", s);
		for(int i=0; i<12; ++i)
			if( !strcmp(s, MON[i]) ) { xd.mon = i; break; }
		scanf("%s", s);
		xd.year = atoi(s);
		if( strlen(s)<=2 ) xd.year+=1900;
		scanf("%2d:%2d:%2d", &xd.hour, &xd.min, &xd.sec);
		scanf("%s", s);
		if( s[0]=='+' || s[0]=='-' )
			sscanf(s, "%d", &xd.zone);
		else {
			for(int i=0; i<6; ++i)
				if( !strcmp(s, ZONE[i]) ) { xd.zone = ZONE_TIME[i]; break; }
		}
		xd.changezone(300);
		xd.print();
	}

	return 0;
}



