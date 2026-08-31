#include<stdio.h>

int take(int A[10][10],int R,int C){

	int i,j;

	for(i=0;i<R;i++){

		for(j=0;j<C;j++){

			printf("Element: \n ");

			scanf("%d",&A[i][j]);

			}

		}

		return 0;

	}

int convert(int A[10][10],int R,int C){

	int B[10][10],i,j;

	B[0][0]=R;

	B[0][1]=C;

	int k=1;

	for(i=0;i<R;i++){

		for(j=0;j<C;j++){

			if(A[i][j]!=0){

				B[k][0]=i;

				B[k][1]=j;

				B[k][2]=A[i][j];

				k++;

				}

			}
		}
		B[0][2]=k-1;

	printf("\nTriplet form:\n");

	for(i=0;i<k;i++){
		printf("%d \t %d \t %d \t",B[i][0],B[i][1],B[i][2]);
		printf("\n");
}
		return 0;

	}
int simp(int A[10][10],int R,int C){
	int B[10][10],T[10][10];
	int i,j,k=1;
	B[0][0]=R;
	B[0][1]=C;

	for(i=0;i<R;i++){
		for(j=0;j<C;j++){
			if(A[i][j]!=0){
				B[k][0]=i;
				B[k][1]=j;
				B[k][2]=A[i][j];
				k++;
			}
		}
	}
	B[0][2]=k-1;
	T[0][0]=B[0][1];
	T[0][1]=B[0][0];
	T[0][2]=B[0][2];
	int q=1;
	for(i=0;i<C;i++){
		for(j=1;j<k;j++){
			if(B[j][1]==i){
				T[q][0]=B[j][1];
				T[q][1]=B[j][0];
				T[q][2]=B[j][2];
				q++;
			}
		}
	}
	printf("\nSimple Transpose:\n");
	for(i=0;i<q;i++){
		printf("%d\t%d\t%d\n",T[i][0],T[i][1],T[i][2]);
	}
	return 0;
}
int fast(int A[10][10], int R,int C){
	int B[10][10],T[10][10];
	int i,j,k=1;
	B[0][0]=R;
	B[0][1]=C;

	for(i=0;i<R;i++){
		for(j=0;j<C;j++){
			if(A[i][j]!=0){
				B[k][0]=i;
				B[k][1]=j;
				B[k][2]=A[i][j];
				k++;
			}
		}
	}
	B[0][2]=k-1;

	int Total[10]={0}, Index[10]={0};

	for(i=1;i<k;i++){
		Total[B[i][1]]++;
	}

	Index[0]=1;
	for(i=1;i<C;i++){
		Index[i]=Index[i-1]+Total[i-1];
	}

	T[0][0]=C;
	T[0][1]=R;
	T[0][2]=B[0][2];

	for(i=1;i<k;i++){
		j=Index[B[i][1]];

		T[j][0]=B[i][1];
		T[j][1]=B[i][0];
		T[j][2]=B[i][2];

		Index[B[i][1]]++;
	}

	printf("\nFast Transpose:\n");

	for(i=0;i<k;i++){
		printf("%d\t%d\t%d\n",T[i][0],T[i][1],T[i][2]);
	}

	return 0;
}

int main(){

	int a[10][10],r,c,i,j,ch,press;

	printf("\nEnter the Number of row: ");

	scanf("%d",&r);

	printf("\nEnter the number of columns: ");

	scanf("%d",&c);

	printf("\nEnter the Matrix:\n");

	take(a,r,c);

	printf("Original Matrix:\n");

	for(i=0;i<r;i++){

		for(j=0;j<c;j++){

			printf("\t %d",a[i][j]);

			}

			printf("\n");

		}

	convert(a,r,c);
	do{
		printf("Please Select Type of Transpose you want to perform :\n1.Simple Transpose \n2.Fast Transpose\n3.Exit \nEnter Value(1/2/3): ");
		scanf("%d",&ch);
		switch(ch){
			case 1:simp(a,r,c);
				break;
			case 2:fast(a,r,c);
				break;
			case 3: break;
			default: printf("Enter Valid Input");
				break;
			}
			printf("Press 1 to continue or press 0: ");
			scanf("%d",&press);
			}while(press==1);

	return 0;

	}
