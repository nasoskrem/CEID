#include <stdio.h>
#include <stdlib.h>

const float mik=0.08;
const float meg=0.2;
int getBottles(char *message);

int main(int argc, char *argv[]) {
	int plithosmik=getBottles("Posa mikra boukalia exei h paraggelia: ");
	int plithosmeg=getBottles("Posa megala boukalia exei h paraggelia: ");
	int synolikoplithos=plithosmik+plithosmeg;
	
	float kostosmik=plithosmik*mik;
	float kostosmeg=plithosmeg*meg;
	float synolikokostos=kostosmik+kostosmeg;

	if (synolikokostos>600)
		synolikokostos*=0.76;
	else if ((synolikokostos>300&&synolikokostos<=600)||synolikoplithos>1000)
		synolikokostos*=0.88;

	printf("To synoliko kostos einai %.3f$",synolikokostos);
	return 0;
}

int getBottles(char *message){
	int bottle;
	printf("%s",message);
	scanf("%d",&bottle);
	return bottle;
}