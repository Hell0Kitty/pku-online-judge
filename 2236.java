
        l=arr[l];
       if(l==u) continue;
       int x=ax[w]-ax[j];
       int y=ay[w]-ay[j];
       if(x*x+y*y<=max)
        {
        if(u>l) arr[j]=arr[w]=arr[u]=l;
        else arr[j]=arr[w]=arr[l]=u;
        }
      }
    bool[w]=1;
     }
     else
     {
    int r=in.nextInt(),w=r;
    while(arr[w]!=w)
       w=arr[w];
    int t=in.nextInt(),u=t;
    while(arr[u]!=u)
       u=arr[u];
    arr[r]=w;
    arr[t]=u;
    if(arr[w]==arr[u]&&bool[w]==1) System.out.println("SUCCESS");
    else System.out.println("FAIL");
      }
   }
 }
}
