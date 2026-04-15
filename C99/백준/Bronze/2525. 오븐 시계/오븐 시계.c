#include <stdio.h>
int main(){
    int h,m,n,x,y=0;
    scanf("%d %d",&h,&m);
    scanf("%d",&n);
    if(m+n>=60){
        x=(m+n)/60;
        y=(m+n)%60;
        if(h+x>=24){
            h = h+x-24;
            m = y;
        }
        else{
            h = h+x;
            m=y;
        }
    }
    else{
        m=m+n;
    }
    printf("%d %d",h,m);
    return 0;
}