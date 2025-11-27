#include <stdio.h>
#include<string.h>

#define MAX 30
#define MAXmhk 50
#define TERMINATE 0
#define ADD_WORDS 1
#define DISPLAY_WORDS 2
#define INC_SORT 3
#define DEC_DORT 4
#define WORD_STATS 5
#define CHAR_STATS 6
#define SEARCH_WORD 7

char lekseis[MAX][MAXmhk];
int wordsnumber=0;

int getInt(char message[]);
void getString(char str[], int numOfChars);

void addwords();
void displaywords();
void incsort();
void decsort();
void wordstats();
void charstats();
void searchword();

int main(){
    int choice=-1;
    while(choice!=TERMINATE){
    	printf("\n|-----------------------------Menou-------------------------------|");
    	printf("\n|1 - Eisagwgh lekshs/leksewn                                      |");
    	printf("\n|2 - Emfanish listas leksewn                                      |");
    	printf("\n|3 - Taksinomhsh leksewn kata auksoysa seira symfwna me ton ASCII |");
    	printf("\n|4 - Taksinomhsh leksewn kata fthinousa seira symfwna me ton ASCII|");
    	printf("\n|5 - Emfanish statistikwn stoieiwn leksewn                        |");
    	printf("\n|6 - Eyresh xarakthra                                             |");
    	printf("\n|7 - Eisagwgh lekshs                                              |");
    	printf("\n|0 - Termatismos programmatos                                     |\n");
    	printf("|------------------------------------------WordsHandling-Program--|\n\n");

    	choice=getInt("Epeleje apo to menou: ");

    	switch (choice){

            case TERMINATE: printf("Eksodos..."); break;

        	case ADD_WORDS: addwords(); break;
        
        	case DISPLAY_WORDS: displaywords(); break;
        
        	case INC_SORT: incsort(); break;

        	case DEC_DORT: decsort(); break;
        
        	case WORD_STATS: wordstats(); break;

        	case CHAR_STATS: charstats(); break;

        	case SEARCH_WORD: searchword(); break;

        	default: printf("Mh yposthrizomenh epilogh!\n"); break;
    	}
    }
    return 0;
}

void addwords(){
    if (wordsnumber>MAX){
        printf("H lista einai gemath.\n");
        return;
    }
    int i;
    int num;

    printf("Poses lekseis theleis na eisageis (mexri %d): ",MAX-wordsnumber);
    scanf("%d",&num);

    getchar();

    for(i=0;i<num&&wordsnumber<MAX;i++){
        printf("Eishgage thn %dh leksh: ",i+1);
        getString(lekseis[wordsnumber],MAXmhk-1);
        wordsnumber++;
    }
}

void displaywords(){
    if(wordsnumber>0){
        int i;
        printf("Lista leksewn:\n");
        for(i=0;i<wordsnumber;i++){
            printf("%dh leksh: %s.\n",i+1,lekseis[i]);
        }
    }else printf("\nDen yparxoun lekseis.\n");
}

void incsort(){
    int i;
    int k;
    if(wordsnumber>0){
        for(i=0;i<wordsnumber-1;i++){
            for(k=i+1;k<wordsnumber;k++){
                if(strcmp(lekseis[i],lekseis[k])>0){
                    char cur[MAXmhk];
                    strcpy(cur,lekseis[i]);
                    strcpy(lekseis[i],lekseis[k]);
                    strcpy(lekseis[k],cur);
                }
            }
        }   
    printf("\nTaksinomish epityxhs.\n"); 
    }else printf("\nDen yparxoun lekseis gia taksinomhsh.\n");
}

void decsort(){
    int i;
    int k;
    if(wordsnumber>0){
        for(i=0;i<wordsnumber-1;i++){
            for(k=i+1;k<wordsnumber;k++){
                if(strcmp(lekseis[i],lekseis[k])<0){
                    char cur[MAXmhk];
                    strcpy(cur,lekseis[i]);
                    strcpy(lekseis[i],lekseis[k]);
                    strcpy(lekseis[k],cur);
                }
            }    
        }
    printf("\nTaksinomish epityxhs.\n");
    }else printf("\nDen yparxoun lekseis gia taksinomhsh.\n");
}

void wordstats(){
    int i,k;
    float meso=0;
    if(wordsnumber>0){
        int min=strlen(lekseis[0]);
        int max=strlen(lekseis[0]);

        for(i=0;i<wordsnumber;i++){
            (strlen(lekseis[i]));
            if((int)strlen(lekseis[i])<min){
                min=strlen(lekseis[i]);
            }
            if((int)strlen(lekseis[i])>max){
                max=strlen(lekseis[i]);
            }
        } 
        printf("\n--> Megisto mhkos lekshs: %d.\n--> Elaxisto mhkos lekshs: %d.\n",max,min);

        for(k=0;k<wordsnumber;k++){
            meso+=strlen(lekseis[k]);
        }
        printf("--> Meso mhkos lekshs einai: %.2f.\n",meso/(float)wordsnumber);
    }else printf("\nDen yparxoun lekseis.\n");
}
    
void charstats(){
    int i,k,min=MAXmhk,max=0;
    char ch;
    int count=0;
    int total=0;
    float meso;
    int indexmax=-1,indexmin=-1;
    if(wordsnumber>0){
        printf("Dwse xarakthra: ");
        scanf(" %c",&ch);
        for(k=0;k<wordsnumber;k++){
            count=0;
            for(i=0;lekseis[k][i]!='\0';i++){
                if(lekseis[k][i]==ch)
                    count++;
            }
            total+=count;
            if(count>max){
                max=count;
                indexmax=k;
            }
            if(count<min&&count>0){
                min=count;
                indexmin=k;
            }
        }
        printf("\n\n--> O xarakthras %c emfanizetai %d fores sthn lista.\n",ch,total);

        meso=(float)total/(float)wordsnumber;
        printf("\n--> O mesos oros emfanishs tou xarakthra %c sthn lista einai %.4f\n",ch,meso);

        if(indexmax!=-1)
            printf("\nLeksh pou periexei ton megisto arithmo tou xarakthra: |%s| kai %d fores\n",lekseis[indexmax],max);
        if(indexmin!=-1)
            printf("Leksh pou periexei ton elaxisto arithmo tou xarakthra: |%s| kai %d fores\n",lekseis[indexmin],min);
    
    }else printf("\nDen yparxoun lekseis.\n");
}

void searchword(){
    int i;
    char leksh[MAXmhk];
    printf("\nEishgage leksh: ");
    getchar();
    getString(leksh,MAXmhk);

    for(i=0;i<wordsnumber;i++){
        if(strcmp(lekseis[i],leksh)==0){
            printf("H leksh %s yparxei hdh ston pinaka sthn thesh %d",leksh,i+1);
            return;
        }
    }

    if (wordsnumber>MAX){
        printf("H lista einai gemath.\n");
        return;}

    char choice;
    printf("\nH leksh den yparxei. Thes na thn prostheseis (Y/N): ");
    scanf(" %c",&choice);
    switch(choice){
        case 'Y': case'y':
            strcpy(lekseis[wordsnumber++],leksh);
            printf("\nH leksh prostethike.\n");
            break;
        default:
            printf("Ok");
            break;
    }
}

int getInt(char message[]){
	int num;
	printf("%s",message);
	scanf("%d",&num);
	return num;
}

void getString(char str[], int numOfChars) {
    int i;
    char ch;
    for(i=0;i<numOfChars&&(ch=getchar())!='\n';i++) {
        str[i]=ch;
    }
    str[i] = '\0';
    while(ch!='\n'){
        ch=getchar();
    }
}
