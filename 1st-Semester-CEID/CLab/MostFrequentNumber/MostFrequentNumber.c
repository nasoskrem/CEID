#include <stdio.h>

int getInt(char message[]);

int main(int argc, char *argv[]) {
    int i;
    int numofterms=getInt("\nDwse plithos arithmwn: ");
    int currentterm,count=1;
    int maxcount=1;
    int mostfreqterm;
    currentterm=getInt("\nDwse ton 1o arithmo: ");
    mostfreqterm=currentterm;
    int prevterm=currentterm;
    for(i=2;i<=numofterms;i++){
        printf("Dwse ton %do arithmo: ",i);
        scanf("%d",&currentterm);
        if(currentterm==prevterm){
            count++;
            if(count>maxcount){
                maxcount=count;
                mostfreqterm=currentterm;
            }
        } else count=1;
        prevterm=currentterm;
    }
    printf("\nPerissoteres fores synexomena emfanizetai o: %d kai |%d| fores synolika",mostfreqterm,maxcount);  
    return 0;
}

int getInt(char message[]){
    int num;
    printf(message);
    scanf("%d",&num);
    return num;
}