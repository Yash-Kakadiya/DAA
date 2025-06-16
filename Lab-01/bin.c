#include<stdio.h>

void main(){
    int n;

	printf("Enter Number: ");
    scanf("%d",&n);
    int ans1=sumRecursion(n);
    int ans2=sumIterative(n);
    printf("Recursion: %d\n",ans1);
    printf("Iterative: %d",ans2);
}

int sumIterative(int n){
	int ans=0,i;
    for(i=1;i<=n;i++){
    	ans+=i;
	}
    return ans;
}

int sumRecursion(int n){
    if (n==1)
    {
        return 1;
    }
    return n+sumRecursion(n-1);
}
