#include<stdio.h>

#include<math.h>

struct node

{

       double x,y;

};

node a,b,c,d,e,f,g;

double S1,lA,lB,lC,kAC,kAB,dHAB,dAB,sum,lA1,lB1,lC1,kAB1,h;

double dxy(node xx,node yy)

{

       return sqrt((xx.x-yy.x)*(xx.x-yy.x)+(xx.y-yy.y)*(xx.y-yy.y));

}

void CS1()          //面积

{

       double p,a1,b1,c1;

       a1=dxy(d,e);

       b1=dxy(e,f);

       c1=dxy(d,f);

       p=(a1+b1+c1)/2;

       S1=sqrt(p*(p-a1)*(p-b1)*(p-c1));

}

void CL()         //直线

{

       if(b.x-a.x==0)

       {

              lA=(b.y-a.y);

              lC=b.x*(b.y-a.y);

       }

       else if(b.y-a.y==0)

       {

              lB=(a.x-b.x);

              lC=b.y*(b.x-a.x);

       }

       else

       {

              lA=(b.y-a.y);

              lB=(a.x-b.x);

              lC=b.y*(b.x-a.x)-b.x*(b.y-a.y);

       }

}

void CL2()         //直线

{

       if(c.x-a.x==0)

       {

              lA1=(c.y-a.y);

              lC1=c.x*(c.y-a.y);

       }

       else if(c.y-a.y==0)

       {

              lB1=(a.x-c.x);

              lC1=c.y*(c.x-a.x);

       }

       else

       {

              lA1=(c.y-a.y);

              lB1=(a.x-c.x);

              lC1=c.y*(c.x-a.x)-c.x*(c.y-a.y);

       }

}

int main()

{

       node H;

       while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y,&e.x,&e.y,&f.x,&f.y)!=EOF)

       {

              if(!a.x&&!a.y&&!b.x&&!b.y&&!c.x&&!c.y&&!d.x&&!d.y&&!e.x&&!e.y&&!f.x&&!f.y)

                     break;

              CS1();

              CL();

              CL2();

              h=S1/dxy(a,b);

              if(a.x==b.x)

              {

                     if(a.y==c.y)

                     {

                            if(a.x<c.x)

                            {

                                   H.x=a.x+h;

                                   H.y=a.y;

                            }

                            else

                            {

                                   H.x=a.x-h;

                                   H.y=a.y;

                            }

                     }

                     else

                     {

                            if(a.x<c.x)

                            {

                                   H.x=a.x+h;

                                   H.y=(-1)*(lC1+lA1*H.x)/lB1;

                            }

                            else

                            {

                                   H.x=a.x-h;

                                   H.y=(-1)*(lC1+lA1*H.x)/lB1;

                            }

                     }

              }

              else if(a.x==c.x)

              {

                     if(a.y==b.y)

                     {

                            if(a.y<c.y)

                            {

                                   H.x=a.x;

                                   H.y=a.y+h;

                            }

                            else

                            {

                                   H.x=a.x;

                                   H.y=a.y-h;

                            }

                     }

                     else

                     {

                            if(a.y<c.y)

                            {

                                   H.x=a.x;

                                   H.y=(h*sqrt(lA*lA+lB*lB)-lA*H.x-lC)/lB;

                                   if(H.y<a.y)

                                          H.y=((-1)*h*sqrt(lA*lA+lB*lB)-lA*H.x-lC)/lB;
                            }
                            else
                            {
                                   H.x=a.x;
                                   H.y=(h*sqrt(lA*lA+lB*lB)-lA*H.x-lC)/lB;
                                   if(H.y>a.y)
                                          H.y=((-1)*h*sqrt(lA*lA+lB*lB)-lA*H.x-lC)/lB;
                            }
                     }
              }
              else if(a.y==c.y)
              {
                     if(a.x<c.x)

                     {

                            H.y=a.y;

                            H.x=(h*sqrt(lA*lA+lB*lB)-lB*H.y-lC)/lA;

                            if(H.x<a.x)

                                   H.x=((-1)*h*sqrt(lA*lA+lB*lB)-lB*H.y-lC)/lA;

                     }

                     else

                     {

                            H.y=a.y;

                            H.x=(h*sqrt(lA*lA+lB*lB)-lB*H.y-lC)/lA;

                            if(H.x>a.x)

                                   H.x=((-1)*h*sqrt(lA*lA+lB*lB)-lB*H.y-lC)/lA;

                     }

              }

              else if(a.y==b.y)

              {

                     if(a.y<c.y)

                     {

                            H.y=a.y+h;

                            H.x=(-1)*(lC1+lB1*H.y)/lA1;

                     }

                     else

                     {

                            H.y=a.y-h;

                            H.x=(-1)*(lC1+lB1*H.y)/lA1;

                     }

              }

              else

              {

                     if(a.x<c.x)

                     {

                            H.x=(h*sqrt(lA*lA+lB*lB)-lC+(lB*lC1/lB1))/((lA*lB1-lB*lA1)/lB1);

                            if(H.x<a.x)

                                   H.x=((-1)*h*sqrt(lA*lA+lB*lB)-lC+(lB*lC1/lB1))/((lA*lB1-lB*lA1)/lB1);

                            H.y=(-1)*(lC1+lA1*H.x)/lB1;

                     }

                     else

                     {

                            H.x=(h*sqrt(lA*lA+lB*lB)-lC+(lB*lC1/lB1))/((lA*lB1-lB*lA1)/lB1);

                            if(H.x>a.x)

                                   H.x=((-1)*h*sqrt(lA*lA+lB*lB)-lC+(lB*lC1/lB1))/((lA*lB1-lB*lA1)/lB1);

                            H.y=(-1)*(lC1+lA1*H.x)/lB1;

                     }

              }

              printf("%.3f %.3f %.3f %.3f\n",(b.x-a.x)+H.x,(b.y-a.y)+H.y,H.x,H.y);

       }

       return 0;

}



