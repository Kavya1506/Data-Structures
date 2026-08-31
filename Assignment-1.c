#include<stdio.h>
void take(int m[10][10],int p,int n){
	int i,j;
	for(i=0;i<p;i++){
		for(j=0;j<n;j++){
			printf("Element: \n ");
			scanf("%d",&m[i][j]);
			}
		}
	}
void disp(int d[10][10],int k,int l){
	int i,j;
	printf("\n Your Matrix is : \n");
	for(i=0;i<k;i++){
		for(j=0;j<l;j++){
			printf("\t %d",d[i][j]);
			}
		printf("\n");
		}		
	}
int add(int A[10][10],int B[10][10],int R,int C,int R1,int C1){
	int X[10][10],i,j;
	if(R==R1 && C==C1){
	for(i=0;i<R;i++){
		for(j=0;j<C;j++){
			X[i][j]=A[i][j]+B[i][j];
			}
		}
	disp(X,R,C);
	}
	else{
		printf("Addition not possible");
	}
	return 0;
	}
int sub(int A[10][10],int B[10][10],int R,int C,int R1,int C1){
	int X[10][10],i,j;
	if(R==R1 && C==C1){
	for(i=0;i<R;i++){
		for(j=0;j<C;j++){
			X[i][j]=A[i][j]-B[i][j];
			}
		}
	disp(X,R,C);
	}
	else{
		printf("Subtraction not possible");
	}
	return 0;
	}
int mult(int A[10][10],int B[10][10],int R,int C,int R1,int C1){
	int X[10][10],i,j,k;
	if(C==R1){
		for(i=0;i<R;i++){
			for(j=0;j<C1;j++){
				X[i][j]=0;
				for(k=0;k<C;k++){
					X[i][j]+=A[i][k]*B[k][j];
					}
				}
			}
	disp(X,R,C1);
	}
	else{
		printf("Multiplication not possible");
	}
	return 0;
}	
int trans(int A[10][10],int R,int C){
	int i,j;
	printf("\n Your Transpose Matrix is : \n");
	for(i=0;i<C;i++){
		for(j=0;j<R;j++){
			printf("\t %d",A[j][i]);
			}
		printf("\n");
		}		
	return 0;
}
int main(){
	int a[10][10],b[10][10];
	int r,c,choice,count,c1,r1;
	printf("Enter the Number of rows for the 1st matrix: ");
	scanf("%d",&r);
	printf("Enter the Number of columns for the 1st matrix: ");
	scanf("%d",&c);
	printf("Enter the Number of rows for the 2nd matrix: ");
	scanf("%d",&r1);
	printf("Enter the Number of columns for the 2nd matrix: ");
	scanf("%d",&c1);
	printf("Enter Elements of 1st matrix:\n");
	take(a,r,c);
	printf("Enter Elements of 2nd matrix:\n");	
	take(b,r1,c1);
	do{
	printf("==========Matrix Methods=========\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Transpose\n5.Display\n6.Exit\n");
	printf("Enter Your Choise(1/2/3/4/5/6)");
	scanf("%d",&choice);
	switch(choice){
		case 1: printf("The Sum of your Matrices is: \n");
			add(a,b,r,c,r1,c1);
			break;
		case 2: printf("The Difference of your Matrices is:\n");
			sub(a,b,r,c,r1,c1);
			break;
		case 3: printf("The multiplication of your matrices is:\n");
			mult(a,b,r,c,r1,c1);
			break;
		case 4: trans(a,r,c);
			trans(b,r1,c1);
			break;
		case 5: disp(a,r,c);
			disp(b,r1,c1);
			break;
		case 6: printf("Thankyou");
			break;
		default:printf("Please enter valid input");
			break;
		}
	printf("Press 1 if you want to continue or press 0 to exit: ");
	scanf("%d",&count);
	}while(count==1);
	printf("Thankyou!!");
	return 0;
	}

