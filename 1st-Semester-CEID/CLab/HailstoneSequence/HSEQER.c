#include <stdio.h>

int sTermHS(int s); //second Term

int main(int argc, char *argv[]){
    int arithmos; 
    printf("Dwse enan thetiko akeraio: ");
    scanf("%d",&arithmos);
    printf("O 2os oros ths akolouthias tou %d einai o %d.",arithmos,sTermHS(arithmos));
return 0;
}

int sTermHS(int s){ 
    if(s%2==0){
        s=s/2;
    }else{
        s=3*s+1;
    }
    return s;
}