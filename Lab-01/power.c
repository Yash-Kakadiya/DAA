#include<stdio.h>

void main(){
    int a,b;

	printf("Enter Number a: ");
    scanf("%d",&a);
	printf("Enter Number b: ");
    scanf("%d",&b);
    float ans1=powerRecursion(a,b);
    float ans2=powerIterative(a,b);
    printf("Recursion: %f\n",ans1);
    printf("Iterative: %f",ans2);
}

int powerIterative(int a,int b){
	int ans=1,i;
	for(i=b;i>0;i--){
		ans*=a;
	}
	return ans;
}

int powerRecursion(int a,int b){
    if (b==1)
    {
        return a;
    }
    return a*powerRecursion(a,b-1);
}
