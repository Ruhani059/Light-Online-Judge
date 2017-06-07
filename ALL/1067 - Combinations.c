#include<stdio.h>
#define size 100001
#define mod_m % 1000003
#define modulo 1000003
long long int pseudo_factorial[size];
long long int inverse (long long int b, long long int m);    //b*x=1(mod m), find x
long long int nCr (long long int n, long long int r);
long long int factorial (long long int n);
int main ()
{
    long long int i,j,fact=1,T,t=1;
    pseudo_factorial[0]=1;
    for (i=1;i<size;i++)
    {
        for(j=10*(i-1)+1;j<=10*i;j++)
        {
            fact=((fact mod_m)*(j mod_m)) mod_m;
        }
        pseudo_factorial[i]=fact;
    }
    scanf("%lld",&T);
    while(T--)
    {
        long long int n,r;
        scanf("%lld %lld",&n,&r);
        printf("Case %lld: %lld\n",t++,nCr(n,r));
    }
    return 0;
}
long long int factorial (long long int n)
{
    long long int i,ans,k;
    i=n/10;
    ans=pseudo_factorial[i];
    for(k=i*10+1;k<=n;k++)
    {
        ans=(ans mod_m)*(k mod_m) mod_m;
    }
    return ans;
}
long long int inverse (long long int b, long long int m)//b*x=1(mod m), find x
{
    long long int i1,i2,x,y;
    for(x=1,y=-1;x<m;x++,y--)
    {
        i1=((b mod_m) *(x  mod_m)) mod_m;
        i2=((b mod_m) *(y  mod_m)) mod_m;
        if(i1 == 1)
        {
            return x;
            break;
        }
        if (i2==1)
        {
            return y;
            break;
        }
    }
}
long long int nCr (long long int n, long long int r)
{
    long long int a,b,c,ans;
    a=factorial(n) mod_m;
    b=factorial(r) mod_m;
    c=factorial(n-r) mod_m;
    b=((b mod_m) * (c mod_m)) mod_m;
    c=inverse(b,modulo);
    ans=((a mod_m)*(c mod_m)) mod_m;
    return ans;
}
