#include <stdio.h>
#include<string.h>
#define MAX 50

//V3
void getStringV2(char message[], char str[],int numOfChars);
char fname[MAX];
char lname[MAX];
char odos[MAX];

int main(int argc, char *argv[]){
    getStringV2("Dwse onoma: ",lname,sizeof(lname));
    getStringV2("Dwse epitheto: ",fname,sizeof(fname));    
    getStringV2("Dwse odo: ",odos,sizeof(odos));
    printf("Onoma: %s\tEpitheto: %s\tOdos: %s",lname,fname,odos);
    return 0;
}

void getStringV2(char message[], char str[], int numOfChars) {
    int i;
    char ch;
    printf(message);
    for(i=0;i<numOfChars&&(ch=getchar())!='\n';i++) {
        str[i]=ch;
    }
    str[i] = '\0';
    while(ch!='\n'){
        ch=getchar();
    }
}


// StringHandlingV2 getStringV2

// #define MAX_LENGTH 100
//
// void getStringV2(char leksi[], int maxLength);
// int main(int argc, char *argv[]) {
//     printf("Antikeimeno D2 Program\n\n");
//  
//     char name[MAX_LENGTH];
//     printf("Dwse epwnymo: ");
//     getStringV2(name, MAX_LENGTH);
//     printf("To epwnymo einai %s\n", name);
//     char surname[MAX_LENGTH];
//     printf("\nDwse 2o epwnymo: ");
//     getStringV2(surname, MAX_LENGTH);
//     printf("To 2o epwnymo einai %s\n", surname);
//     return 0;}
//
//     void getStringV2(char leksi[], int maxLength) {
//     int i=0;
//     char ch;
//     while ((ch=getchar())!='\n' && i<maxLength-1) {
//         leksi[i]=ch;
//         i++;
//     }
//     leksi[i]='\0';
//     while (ch!='\n') {
//         ch=getchar(); 
//     }
// }


// StringHandlingV2 getStringV1

// void getString(char leksi[]);
// int main(int argc, char *argv[]){
//    printf("Antikeimeno D2 Program\n\n");
//    char name[10];
//    printf("Dwse epwnumo: ");
//    getString(name);
//    printf("To epwnyumo einai %s\n",name);
//    char surname[10];
//    printf("\nDwse 2o epwnumo: ");
//    getString(surname);
//    printf("To 2o epwnyumo einai %s\n",surname);
// return 0;
// }
//
// void getString(char leksi[]){
//     scanf("%s",leksi);
// }


//StringHandlingV3
// int main(int argc, char *argv[]){
//     printf("Antikeimeno D2 Program\n\n");
//     int len;
//     int i;
//     char name[10];
//     printf("Dwse epwnumo: ");
//     scanf("%s",name);
//     len=strlen(name);
//     printf("To epwnyumo einai %s kai to mhkos tou einai %d\n",name,len);
//     int len2;
//     char surname[10];
//     printf("\nDwse 2o epwnumo: ");
//     scanf("%s",surname);
//     len2=strlen(surname);
//     printf("To 2o epwnyumo einai %s kai to mhkos tou einai %d\n\n",surname,len2);
//     int cmp=strcmp(name,surname);
//     if (cmp > 0) {
//         printf("To %s einai megalytero apo to %s sumfwna me ton ASCII\n\n",name,surname);
//     } else if (cmp < 0) {
//        printf("To %s einai megalytero apo to %s sumfwna me ton ASCII\n\n",surname,name);
//     } else {
//        printf("To %s einai iso me to %s sumfwna me ton ASCII\n\n",name,surname);
//     }
//     for(i=0;i<len;i++){
//        printf("%c\n",name[i]);}
//     for(i=0;i<len;i++){
//        printf("%s\n",name+i);}
//     for(i=len;i>0;i--){
//        name[i]='\0';
//        printf("%s\n", name);}
// return 0;
// }

//StringHandlingV1
// int main(){
//     int i;
//     char name[10]="NIKOY";
//     printf("%s\n\n",name);
//     for(i=0;i<5;i++){
//         printf("%c",name[i]);
//     }
//     printf("\n\n");
//     for(i=0;i<5;i++){
//         printf("%c\n",name[i]);
//     }
//     printf("\n");
//     for(i=0;i<5;i++){
//         printf("%s\n",name+i);
//     }
//     printf("\n");
//     for(i=5;i>0;i--){
//         name[i]=0;
//         printf("%s\n", name);}
//     return 0;
// }
