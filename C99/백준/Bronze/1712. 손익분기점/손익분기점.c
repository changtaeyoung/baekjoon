#include <stdio.h>
int main(){
    long long int a,b,c,i;
    scanf("%lld %lld %lld",&a,&b,&c);
    if(b>=c){
        printf("-1\n");
    }
    else{
        printf("%lld\n",a/(c-b)+1);
    }
    return 0;
}