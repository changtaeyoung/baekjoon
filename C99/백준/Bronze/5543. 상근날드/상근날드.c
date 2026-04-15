#include <stdio.h>
int main(){
    int a[5]={0};
    int h,d;
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
    }
    if(a[0]<a[1]){
        h=a[0];
    }
    else {
        h=a[1];
    }
    if(h<a[2]){
        h=h;
    }
    else{
        h=a[2];
    }
    if(a[3]<a[4]){
        d=a[3];
    }
    else{
        d=a[4];
    }
    printf("%d",h+d-50);
    return 0;
}