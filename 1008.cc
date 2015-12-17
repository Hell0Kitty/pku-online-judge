nclude <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int ncase;
/*19 months. Each of the first 18 months was 20 days long
pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen,
yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu*/

/*Tzolkin 
The year was divided into 13 periods, each 20 days long
20 names: imix, ik, akbal, kan, chicchan, cimi, manik, lamat, muluk, ok, 
chuen, eb, ben, ix, mem, cib, caban, eznab, canac, ahau
*/
int daysOfTheMonth(char monthName[]){
    if (strcmp(monthName,"uayet") ==0)
    {
        return 5;
    }
    return 20;
}

int indexOfTheMonth(char monthName[]){
    if (strcmp(monthName,"pop") ==0) return 0;
    if (strcmp(monthName,"no") ==0) return 1;
    if (strcmp(monthName,"zip") ==0) return 2;
    if (strcmp(monthName,"zotz") ==0) return 3;
    if (strcmp(monthName,"tzec") ==0) return 4;
    if (strcmp(monthName,"xul") ==0) return 5;
    if (strcmp(monthName,"yoxkin") ==0) return 6;
    if (strcmp(monthName,"mol") ==0) return 7;
    if (strcmp(monthName,"chen") ==0) return 8;
    if (strcmp(monthName,"yax") ==0) return 9;
    if (strcmp(monthName,"zac") ==0) return 10;
    if (strcmp(monthName,"ceh") ==0) return 11;
    if (strcmp(monthName,"mac") ==0) return 12;
    if (strcmp(monthName,"kankin") ==0) return 13;
    if (strcmp(monthName,"muan") ==0) return 14;
    if (strcmp(monthName,"pax") ==0) return 15;
    if (strcmp(monthName,"koyab") ==0) return 16;
    if (strcmp(monthName,"cumhu") ==0) return 17;
    if (strcmp(monthName,"uayet") ==0) return 18;
}

char * indexTostring(int index){
    char* name[20]={ "imix", "ik", "akbal", "kan", 
        "chicchan", "cimi", "manik", "lamat", "muluk", "ok", 
        "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", 
        "canac", "ahau"};
    return name[index];
}
int main(){
    scanf("%d", &ncase);
    int i;
    printf("%d\n",ncase);
    for (i= 0 ;i<ncase;i++)
    {
        int numberoftheday, year;
        char month[10];
        scanf("%d.%s%d", &numberoftheday, month, &year);

        //cout<<"The numberoftheday is "<<numberoftheday<<endl;
        //cout<<"The month is "<<month<<endl;
        //cout<<"The year is "<<year<<endl;
        //puts("before die");
        long int sumdays = numberoftheday +1 + indexOfTheMonth(month)*20+ year*365;


        long int anotherYear = (long int) sumdays / 260;
        long int remainderDays = sumdays % 260;
        if (!remainderDays)
        {
            anotherYear --;
        }
        long int printDay = remainderDays % 13;
        long int stringIndex = remainderDays % 20;
        //cout<<"The month index is "<<stringIndex<<endl;
        if (stringIndex == 0)
        {
            stringIndex = 20;
            
        }
        if (printDay == 0)
        {
            printDay = 13;
        }
        printf("%d %s %d\n",printDay, indexTostring(stringIndex-1), anotherYear);
        //cout<<"Output day is "<< printDay<<endl;
        //cout<<"Month name is "<< indexTostring(stringIndex-1)<<endl;
        //cout<<"Another year is "<<anotherYear <<endl;


    }

}
