#include <stdio.h>

// //V2.2
// int getInt(char message[]);
// int ypologFib(int fbNumber[]);

// int numberOfTerms;

// int main(int argc, char *argv[]) {
//     printf("Fibonacci Sequence Program V2\n");
//     numberOfTerms=getInt("Dose arithmo orwn: ");
    
//     int fbNumber[numberOfTerms];
//     ypologFib(fbNumber);
    
//     printf("O ypologismos oloklirothike. Twra tha ektypwthoun oi oroi.\n\n");
//     int i;
//     for(i=0;i<numberOfTerms;i++) 
//         printf("term-%d:%d\n",i+1,fbNumber[i]);

//     return 0;
// }


// int ypologFib(int fbNumber[]) {
//     int i;
//     fbNumber[0] = 0;
//     fbNumber[1] = 1;
    
//     for(i=2;i<=numberOfTerms;i++) {
//         fbNumber[i]=fbNumber[i-2]+fbNumber[i-1];
//     }
//     return 0;
// }

// int getInt(char message[]) {
//     int num;
//     printf(message);
//     scanf("%d",&num);
//     return num;
// }

//V2.1
int getInt(char message[]);

int numberOfTerms;

int main(int argv, char *argc[]){
    int i;
    printf("Fibonacci Sequence Program V2\n");
    numberOfTerms=getInt("Dose arithmo orwn: ");
    int fbNumber[numberOfTerms];
    
    fbNumber[0]=getInt("Dose 1o oro: ");
    fbNumber[1]=getInt("Dose 2o oro: ");

    for(i=2;i<=numberOfTerms;i++){
        fbNumber[i]=fbNumber[i-2]+fbNumber[i-1];
    }
    
    for(i=1;i<=numberOfTerms;i++)
        printf("term-%d:%d\n",i,fbNumber[i-1]);
    return 0;
}
int getInt(char message[]){
	int num;
	printf(message);
	scanf("%d",&num);
	return num;
} 
