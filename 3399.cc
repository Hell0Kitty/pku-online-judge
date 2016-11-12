#include "iostream"
#include "cstdio"
#include "algorithm"
#include "vector"
using namespace std;
int N,K;
vector<int> pos,neg;
vector<int> ans;
void input(){
    scanf("%d%d",&N,&K);
    for(int i = 0 ;i < N; ++i){
        int tmp;
        scanf("%d",&tmp);
        if(tmp >= 0) pos.push_back(tmp);
        else neg.push_back(tmp);
    }
}
void calc(){
    int ret = 1;
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    int i = pos.size()-1;
    int j = 0,cnt = 0;
    if(neg.size() == 0){
        while(cnt < K){
            ans.push_back(pos[i]);
            --i;
            ++cnt;
        }
        return;
    }else if(pos.size() == 0){
        if(K & 1){
            for(int  k = neg.size() -1; cnt < K; --k){
                ans.push_back(neg[k]);
                ++cnt;
            }
        }else{
            for(int k = 0 ; cnt < K; ++k){
                ans.push_back(neg[k]);
                ++cnt;
            }
        }
        return;
    }
    if(K % 2){
        ans.push_back(pos[i]);
        --i;
        cnt = 1;
    }
    while(cnt < K && i >= 1 && j < neg.size() -1){
        if(pos[i] * pos[i-1] >= neg[j] * neg[j +1]){
            ans.push_back(pos[i]);
            ans.push_back(pos[i-1]);
            cnt += 2;
            i-=2;
        }else{
            ans.push_back(neg[j]);
            ans.push_back(neg[j+1]);
            cnt += 2;
            j+=2;
        }
    }
    while(cnt < K){
        while(i == 0){
            if(j < neg.size() -1 && neg[j] * neg[j + 1] >= pos[i]){
                ans.push_back(neg[j]);
                ans.push_back(neg[j + 1]);
                j += 2;
                cnt +=2;
            }else{
                ans.push_back(pos[i]);
                ++cnt;
                --i;
            }
        }
        while(cnt < K){
            ans.push_back(neg[j]);
            ++j;
            ++cnt;
        }
    }
}
int main(){
    input();
    calc();
    for(int i = 0 ;i < ans.size(); ++i){
        if(i == ans.size() -1)
            printf("%d\n",ans[i]);
        else printf("%d ",ans[i]);
    }
    return 0;
}


