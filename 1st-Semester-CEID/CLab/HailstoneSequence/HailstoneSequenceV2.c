#include <stdio.h>

int hailstoneSeqcalc(int num); //(Hailstone Squence calculator)

int main(int argc, char *argv[]){
    int arithmos; 
    printf("Hailstone Sequence V2 Program\n");
    do{
        printf("Dwse enan thetiko akeraio: ");
        scanf("%d",&arithmos);
        if (arithmos<=0) {
            printf("Mh arnhtiko arithmo parakalo!\n");
        }
    }while(arithmos<=0);
    printf("H akolouthia tou %d einai h exhs: %d",arithmos,arithmos);
    hailstoneSeqcalc(arithmos);
return 0;
}

int hailstoneSeqcalc(int num){
    int i;
    for(i=1;num!=1;i++){
        if(num%2==0){
            num=num/2;
        }else{
            num=3*num+1;
            }
        printf(" --> %d",num);
        }
return num;
}