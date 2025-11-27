#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num);
void displayDivisors(int num);
void getIntV2(char *message,int *numPtr);

int main(){
    int num;
    int *numPtr=&num;
    getIntV2("Dwse arithmo: ",numPtr);
    if(isPrime(num)) 
        printf("The number %d is prime.\n",num);
    else 
        displayDivisors(num);
    return 0;
}

bool isPrime(int num){
    for (int i=2;i*i<=num;i++) {
        if (num%i==0) return false;
    }
    return true;
}

void displayDivisors(int num){
    int i;
    int count=0;
    printf("\nThe divisors of %d except 1 and itself are:\n\n",num);

    for(i=2;i<num;i++){
        if(num%i==0){
            printf("|%d|\t",i);
            count++;
        }    
    }
    printf("\nThe numbers of divisors are: %d\n",count); 
}

void getIntV2(char *message,int *numPtr){
    printf(message);
    scanf("%d",numPtr);
}