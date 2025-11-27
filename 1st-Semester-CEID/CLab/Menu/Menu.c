#include <stdio.h>
#include <math.h>

//4.
float getFloat(char message[]);
void printApo(char prajh,float n1,float n2,float apo);
float ypolog(char prajh,float num1,float num2);
void menu();

float num1,num2;

int main(int argc, char *argv[]){
    menu();
}

void  menu(){
    char ch;
    do{
        printf("\n---------------------------MenuV2---------------------------\n");
        printf("A gia eisagwgh arithmwn\n");
        printf("\nB gia prosthesh\n");
        printf("\nC gia afairesh\n");
        printf("\nD gia pollaplasiasmo\n");
        printf("\nE gia diaireshn\n");
        printf("\nF gia ton ypologismo twn 10dikwnlogarithmwn twn arithmwn\n");
        printf("\nG gia ton ypologismo twn dynamewn\n");
        printf("\nX gia exodo\n------------------------------------------------------------\n");
        printf("\nEpeleje apo A-G: ");
        scanf(" %c",&ch);

        switch(ch){
            case 'A':case'a':
                num1=getFloat("Dwse ton 1o arithmo: ");
                num2=getFloat("Dwse ton 2o arithmo: ");
                break;

            case 'B':case'b': 
                printApo('+',num1,num2,ypolog('+',num1,num2));
                break;

            case 'C':case'c':
                printApo('-',num1,num2,ypolog('-',num1,num2));
                break;

            case 'D':case'd':
                printApo('*',num1,num2,ypolog('*',num1,num2));
                break;
        
            case 'E':case'e':
                if(num2!=0)
                    printApo('/',num1,num2,ypolog('/',num1,num2));
                else printf("To num2 einai 0 opote den orizetai diairesh.");
                break;

            case 'F':case'f':
                if(num1>0) 
                    printf("log(%.2f) = %.2f\n",num1,log10(num1));
                else printf("O %f prepei na einai megalyteros tou 0\n",num1);

                if(num2>0) 
                    printf("log(%.2f) = %.2f",num2,log10(num2));
                else printf("O %f prepei na einai megalyteros tou 0",num2);
                break;
        
            case 'G':case'g':
                printf("%.4f ^ %.4f = %.4f\n",num1,num2,pow(num1,num2));
                printf("%.4f ^ %.4f = %.4f\n",num2,num1,pow(num2,num1));
                break;

            default:
                printf("\nEksodos...\n");
                break;

        }
    }while(ch!='X'&ch!='x');
}

float getFloat(char message[]){
    float num;
    printf(message);
    scanf("%f",&num);
    return num;
}

float ypolog(char prajh,float num1,float num2) {
    switch (prajh) {
        case '+':
            return num1+num2;
            break;

        case '-':
            return num1-num2;
            break;

        case '*':
            return num1*num2;
            break;

        case '/':
            return num1/num2;
            break;
        default:
            return 0;
    }
}

void printApo(char prajh,float n1,float n2,float apo) {
    switch (prajh) {
        case '+':
            printf("%.2f + %.2f = %.2f\n",n1,n2,apo);
            break;

        case '-':
            printf("%.2f - %.2f = %.2f\n",n1,n2,apo);
            break;

        case '*':
            printf("%.2f * %.2f = %.2f\n",n1,n2,apo);
            break;

        case '/':
            printf("%.2f / %.2f = %.2f\n",n1,n2,apo);
            break;
    }
}

//3.

#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4
#define LOG 5
#define POW 6

float getFloat(char message[]);
float num1,num2;
int epilogh;
float res;

float add(float n1,float n2);
float sub(float n1,int n2);
float mul(float n1,float n2);
float div(float n1,float n2);


int main(){
    printf("MenuV1\n");
    num1=getFloat("Dwse ton 1o arithmo: ");
    num2=getFloat("Dwse ton 2o arithmo: ");
    printf("\n\n1 gia prosthesh\n");
    printf("\n2 gia afairesh\n");
    printf("\n3 gia pollaplasiasmo\n");
    printf("\n4 gia diairesh\n");
    printf("\n5 gia ton ypologismo twn 10dikwn logarithmwn twn arithmwn\n");
    printf("\n6 gia %.4f ^ %.4f kai %.4f ^ %.4f\n\n",num1,num2,num2,num1);
    epilogh=(int)getFloat("Epeleje apo 1-6: ");

    do{
    switch(epilogh){
    	case ADD: 
            res=add(num1,num2);
            printf("The result is %f",res);
            break;

        case SUB:
            res=sub(num1,num2);
            printf("The result is %f",res);
            break;

        case MUL:
            res=mul(num1,num2);
            printf("The result is %f",res);
            break;
        
        case DIV:
            if(div(num1,num2)==(num1/num2)){
            res=div(num1,num2);
            printf("The result is %f",res);}
            break;

        case LOG:
            if(num1>0) {
                res=log10(num1);
                printf("log(%.2f) = %.2f",num1,res);
                }
            else printf("O %f prepei na einai megalyteros tou 0\n",num1);

            if(num2>0) {
                res=log10(num2);
                printf("log(%.2f) = %.2f",num2,res);
                }
            else printf("O %f prepei na einai megalyteros tou 0",num2);
            break;
     
        case POW:
            res=pow(num1,num2);
            printf("%.4f ^ %.4f = %.4f\n",num1,num2,res);
            res=pow(num2,num1);
            printf("%.4f ^ %.4f = %.4f\n",num2,num1);
            break;

        default:
            epilogh=(int)getFloat("\n\nLathos. Apo 1-6 parakalo: ");
            continue;
        }
    break;
    }while(1);
    return 0;
}

float add(float n1,float n2){
    float result;
    result=n1+n2;
    return result;
}

float sub(float n1,int n2){
    float result;
    result=n1-n2;
    return result;
}

float mul(float n1,float n2){
    float result;
    result=n1*n2;
    return result;
}

float div(float n1,float n2){
    float result;
    if(n2!=0){
        result=n1/n2;
        return result;
    }else printf("O 2os arithmos einai 0");
}

float getFloat(char message[]){
    float num;
    printf(message);
    scanf("%f",&num);
    return num;
}

