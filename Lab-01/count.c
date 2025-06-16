#include<stdio.h>

void main(){
    int n;

	printf("Enter Number: ");
    scanf("%d",&n);
    int ans1=countRecursion(n);
    int ans2=countIterative(n);
    printf("Recursion: %d\n",ans1);
    printf("Iterative: %d",ans2);
}

int countIterative(int n){
	int ans=0;
	while(n>0){
		n/=10;
		ans++;
	}
    return ans;
}

int countRecursion(int n){
    if (n==0)
    {
        return 0;
    }
    return 1+countRecursion(n/10);
}
