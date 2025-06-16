#include<stdio.h>

void main(){
    int n;

	printf("Enter Number: ");
    scanf("%d",&n);
    int ans1=factorialRecursion(n);
    int ans2=factorialIterative(n);
    printf("Recursion: %d\n",ans1);
    printf("Iterative: %d",ans2);
}

int factorialIterative(int n){
	int ans=1,i;
    for(i=1;i<=n;i++){
    	ans*=i;
	}
    return ans;
}

int factorialRecursion(int n){
    if (n==0)
    {
        return 1;
    }
    return n*factorialRecursion(n-1);
}
