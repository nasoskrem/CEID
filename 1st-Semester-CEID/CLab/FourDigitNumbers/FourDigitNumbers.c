#include <stdio.h>
#include <math.h>

//Πολυ πιο γρηγορη εκτελεση

int SumOfDigitsTo4(int num);
int digit4Pow[10];

int main(){
	printf("4-digit Armstrong numbers:\n");
	
	for (int i=0;i<10;i++)
		digit4Pow[i]=pow(i, 4);
		
	for (int num=1000;num<=9999;num++)
		if (num==SumOfDigitsTo4(num))
			printf("\n|%d|\n",num);
	return 0;
}
	
int SumOfDigitsTo4(int num){
	int sum=0;
	while (num>0) {
		int digit=num%10;
		sum += digit4Pow[digit];
		num/=10;
	}
	return sum;
}

// Χωρις πινακα/συναρτηση
// int main(){
// 	printf("4-digit Armstrong numbers:\n");
//	
// 	for (int num = 1000; num <= 9999; num++){
// 		int originalNum = num;
// 		int sum = 0;
// 		while (num > 0) {
// 			int digit = num % 10;
// 			sum += pow(digit, 4);
// 			num/=10;
// 		}
// 		if (sum == originalNum){
// 			printf("%d\n", originalNum);
// 		}
// 		num = originalNum;
// 	}	
// 	return 0;
// }