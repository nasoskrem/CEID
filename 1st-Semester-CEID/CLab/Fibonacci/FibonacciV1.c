#include <stdio.h>

//V1.2
int getInt(char message[]);

const int fTerm=0; 
const int sTerm=1;

int cTerm(int term);

int main(int argc, char *argv[]) {
    int numberOfTerms;
    printf("Fibonacci Sequence Program V1\n");
    numberOfTerms = getInt("Dose ton arithmo twn orwn: ");

    for (int i=0;i<numberOfTerms;i++) {
        printf("%d  ",cTerm(i));
    }
    return 0;
}

int cTerm(int term){
    if (term == 0) 
        return fTerm;
    if (term == 1) 
        return sTerm;

    return cTerm(term - 1) + cTerm(term - 2);
}

int getInt(char message[]){
	int num;
	printf(message);
	scanf("%d",&num);
	return num;
}

// V1.1
// int getInt(char message[]);

// int fTerm=0; 
// int sTerm=1;
// int cTerm,numberOfTerms;
// int pTerm,ppTerm;

// int main(int argv, char *argc[]){
//     int i;
//     printf("Fibonacci Sequence Program V1\n");
//     numberOfTerms=getInt("Dose ton arithmo twn orwn: ");
//     printf("term-0:%d\n",fTerm);
//     printf("term-1:%d\n",sTerm);
//     ppTerm=fTerm;
//     pTerm=sTerm;
//     for(i=3;i<=numberOfTerms;i++){
//         cTerm=pTerm+ppTerm;
//         printf("term-%d:%d\n",i,cTerm);
//         ppTerm=pTerm;
//         pTerm=cTerm;
//     }
// return 0;
// }

// int getInt(char message[]){
// 	int num;
// 	printf(message);
// 	scanf("%d",&num);
// 	return num;
// } 