#include <stdio.h>

//V1.2
int main(int argc, char *argv[]){
    int i;
    printf("Hailstone Sequence V1 Program\n");
    int arithmos; 
    do{
        printf("Dwse enan thetiko akeraio: ");
        scanf("%d",&arithmos);
        if (arithmos<=0) {
            printf("Mh arnhtiko arithmo parakalo!\n");
        }
    }while(arithmos<=0);

    printf("H akolouthia tou %d einai h exhs: %d",arithmos,arithmos);
    int res=arithmos;
    for(i=0;res!=1;i++){
        if(res%2==0){
        res=res/2;
        }else{
            res=3*res+1;
            }
        printf(" --> %d",res);
        }
return 0;
}  


//V1.1
// int main(int argc, char *argv[]){
//     int i;
//     int arithmos; 
//     int oros;
//     printf("Dwse enan thetiko akeraio: ");
//     scanf("%d",&arithmos);
//     printf("Dwse ton oro ths akolouthias pou thes: ");
//     scanf("%d",&oros);
//     int res=arithmos;
//     for(i=1;i<oros;i++){
//         if(res%2==0){
//             res=res/2;
//         }else{
//             res=3*res+1;
//             }
//         }

//     printf("O %dos oros ths akolouthias tou %d einai o %d.",oros,arithmos,res);
// return 0;
// }