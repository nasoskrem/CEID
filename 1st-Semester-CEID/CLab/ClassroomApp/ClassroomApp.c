#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 40
#define A 8
#define MAX_STUDENTS 72
#define ZONES 4
#define SEATS 18

#define ADD_STUDENT 1
#define ADD_ZONE 2
#define DISPLAY_ALL 3
#define DISPLAY_ZONE 4
#define NAME_ID_SEARCH 5
#define POSITION_SEARCH 6

#define TERMINATE 0

void getString(char str[], int numOfChars, char *message);
int getInt(char *message);

typedef struct{
	char name[M];
	int am;
	char date[M];
	char zone[A],seat[A];
}Student;

void displayMenu();
void getStudent();
void getZone();
void displayStudents();
void displayZoneStudents();
void nameIDsearch();
void positionsearch();

Student* getStudentByID_ErwthmaC(Student students[ZONES][SEATS], int studentCountInZone[], int am);

void saveStudentsToFile();
void loadStudentsFromFile();

int studentsCount=0;
int studentCountInZone[ZONES] = {0};
Student students[ZONES][SEATS];

int main() {
    printf("Note that every student is saved in a binary file with his/her data for privacy!\n");
    loadStudentsFromFile();
	int choice=-1;
	while(choice!=TERMINATE){
		displayMenu();
		choice=getInt("Choose from the Menu: ");

			switch(choice){
				
				case TERMINATE:
                    saveStudentsToFile();
					printf("Terminating...");
				break;
				
				case ADD_STUDENT:
					getStudent();
                    saveStudentsToFile();
				break;	
				
				case ADD_ZONE:
					getZone();
                    saveStudentsToFile();
				break;
				
				case DISPLAY_ALL:
					displayStudents();
                    saveStudentsToFile();
				break;
				
				case DISPLAY_ZONE:
					displayZoneStudents();
                    saveStudentsToFile();
				break;
				
				case NAME_ID_SEARCH:
					nameIDsearch();
                    saveStudentsToFile();
				break;
				
				case POSITION_SEARCH:
					positionsearch();
                    saveStudentsToFile();
                break;
                
				default:
					printf("\nInvalid choice\n");
                break;
		}
	}
	return 0;
}

void displayMenu() {
    printf("\n-------COMPUTERS-LAB-ROOM--------\n");
    printf("|0. Exit                        |\n");
    printf("|1. Register Individual Student |\n");
    printf("|2. Register Student Group      |\n");
    printf("|3. Display All Students        |\n");
    printf("|4. Display Zone Students       |\n");
    printf("|5. Search Student by ID/Name   |\n");
    printf("|6. Search Student by Position  |\n");
}

void getStudent() {
    if (studentsCount >= MAX_STUDENTS) {
        printf("Maximum student limit reached.\n");
        return;
    }

    Student newStudent;
    getString(newStudent.name, M, "Enter Student Name: ");
    newStudent.am = getInt("Enter Registration Number: ");
    getString(newStudent.date, M, "Enter Registration Date: ");
    getString(newStudent.zone, A, "Enter Zone (Z1-Z4): ");
    getString(newStudent.seat, A, "Enter Seat (S1-S18): ");

    int seatTaken = 0;
    int zoneIndex = newStudent.zone[1] - '1';

    do {
        seatTaken = 0;
        for (int j = 0; j < studentCountInZone[zoneIndex]; j++) {
            if (strcmp(newStudent.seat, students[zoneIndex][j].seat) == 0) {
                printf("The seat %s in zone %s is already taken\n", newStudent.seat, newStudent.zone);
                getString(newStudent.zone, A, "Enter Zone again (Z1-Z4): ");
                getString(newStudent.seat, A, "Enter Seat again (S1-S18): ");
                zoneIndex = newStudent.zone[1] - '1';
                seatTaken = 1;
            break;
            }
        }
    } while (seatTaken);

    if (zoneIndex < 0 || zoneIndex >= ZONES) {
        printf("Invalid zone.\n");
        return;
    }

    if (studentCountInZone[zoneIndex] >= SEATS) {
        printf("No more seats available in this zone.\n");
        return;
    }

    students[zoneIndex][studentCountInZone[zoneIndex]++] = newStudent;
    studentsCount++;

    printf("Student registered successfully.\n");
}

void getZone(){
	char zone[A];
    int startSeat, groupSize;
    
    getString(zone,A,"Enter Zone (Z1-Z4): ");
    int zoneIndex=zone[1]-'1';
    
     if (zoneIndex < 0 || zoneIndex >= ZONES) {
        printf("Invalid zone.\n");
        return;
    }

    startSeat=getInt("Enter starting seat number (1-18): ");
    groupSize=getInt("Enter number of students in group: ");
    
    if (startSeat<1||startSeat+groupSize>19) {
        printf("Invalid seat range.\n");
        return;
    }

    int currentSeat=startSeat;
    int studentsRegistered=0;
    
    while (studentsRegistered<groupSize&&currentSeat<=18) {
        char tempSeat[A];
        sprintf(tempSeat,"S%d",currentSeat);
      
        int seatOccupied = 0;
        for (int j=0;j<studentCountInZone[zoneIndex];j++) {
            if (strcmp(students[zoneIndex][j].seat, tempSeat) == 0) {
                printf("\nSeat %s is occupied, skipping to next seat.\n", tempSeat);
                seatOccupied=1;
                break;
            }
        }
        
        if (!seatOccupied) {
            Student *newStudent = &students[zoneIndex][studentCountInZone[zoneIndex]];
            
            printf("\nStudent %d details (Seat %s):\n", studentsRegistered + 1, tempSeat);
            getString(newStudent->name, M, "Enter Name: ");
            newStudent->am = getInt("Enter Registration Number: ");
            getString(newStudent->date, M, "Enter Registration Date: ");
            
            strcpy(newStudent->zone, zone);
            strcpy(newStudent->seat, tempSeat);
            
            studentCountInZone[zoneIndex]++;
            studentsCount++;
            studentsRegistered++;
        }
        
        currentSeat++;
    }
    
    if (studentsRegistered < groupSize) {
        printf("\nWarning: Only %d out of %d students could be registered due to seat availability.\n", 
               studentsRegistered, groupSize);
    } else {
        printf("\nGroup registration completed successfully.\n");
    }
}

void displayStudents(){
	if (studentsCount == 0) {
        printf("No students registered.\n");
        return;
    }
    
    for (int i = 0; i < ZONES; i++) {
    	for (int j = 0; j < studentCountInZone[i]; j++) {
        	printf("\nStudent's Data:\n");
        	printf("Name: %s\n", students[i][j].name);
        	printf("Reg Number: %d\n", students[i][j].am);
        	printf("Date: %s\n", students[i][j].date);
       		printf("Zone: %s\n", students[i][j].zone);
        	printf("Seat: %s\n", students[i][j].seat);
    	}
	}
    printf("\nTotal Number of Students: %d\n",studentsCount);
}

void displayZoneStudents() {
    char zone[A];
    getString(zone, A, "\nEnter Zone to display (Z1-Z4): ");
    
    int zoneIndex = zone[1] - '1';
    int found=0;
    
    for (int i=0;i<studentCountInZone[zoneIndex]; i++) {
            printf("\nSeat: %s\nName: %s\nID: %d\n", students[zoneIndex][i].seat, students[zoneIndex][i].name,students[zoneIndex][i].am);
        	found=1;
        }
    
    if (!found){
        printf("No students found in zone %s\n", zone);
        return;
    }

    printf("\nNumber of Students in Zone Z%d: %d\n",studentCountInZone[zoneIndex],studentsCount);

}

void nameIDsearch() {
    char input[M];
    getString(input,M,"Search by 'id' or 'name': ");

    if (strcmp(input,"id")==0) {
        int ID=getInt("Enter Student's ID: ");
        Student* student = getStudentByID_ErwthmaC(students, studentCountInZone, ID);
        if (student != NULL) {
        printf("\nStudent Found:\n");
        printf("Name: %s\n", student->name);
        printf("ID: %d\n", student->am);
        printf("Date: %s\n", student->date);
        printf("Zone: %s\n", student->zone);
        printf("Seat: %s\n", student->seat);
    } else printf("No student found with ID '%d'\n", ID);

    } else if (strcmp(input,"name")==0) {
        char name[M];
        getString(name, M, "Enter Student's Name: ");
        int found=0;
        for (int i=0;i<ZONES;i++) {
            for (int j = 0; j < studentCountInZone[i]; j++) {
                if (strcmp(name, students[i][j].name) == 0) {
                    printf("\nStudent: %s\nZone: %s\nSeat: %s\nId: %d\nRegistration Date: %s\n", 
                            students[i][j].name, students[i][j].zone, students[i][j].seat,students[i][j].am,students[i][j].date);
                    found = 1;
                    break;
                }
        	}
        }
        if (!found) 
            printf("No student found with name '%s'\n", name);
            
    } else printf("Invalid choice. Please enter 'ID' or 'name'.\n");
}

void positionsearch() {
    char zone[A], seat[A];
    getString(zone, A, "Enter Zone (Z1-Z4): ");
    getString(seat, A, "Enter Seat (S1-S18): ");

    int zoneIndex = zone[1] - '1'; 
    if (zoneIndex < 0 || zoneIndex >= ZONES) {
        printf("Invalid zone.\n");
        return;
    }

    int found = 0;
    for (int j = 0; j < studentCountInZone[zoneIndex]; j++) {
        if (strcmp(seat, students[zoneIndex][j].seat) == 0) {
            printf("\nStudent Found:\n");
            printf("Name: %s\n", students[zoneIndex][j].name);
            printf("ID: %d\n", students[zoneIndex][j].am);
            printf("Date: %s\n", students[zoneIndex][j].date);
            printf("Zone: %s\n", students[zoneIndex][j].zone);
            printf("Seat: %s\n", students[zoneIndex][j].seat);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No student found in Zone %s, Seat %s\n", zone, seat);
    }
}

void saveStudentsToFile() {
    FILE *file = fopen("students_data.bin", "wb");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return;
    }

    fwrite(&studentsCount, sizeof(int), 1, file);
    fwrite(studentCountInZone, sizeof(int), ZONES, file);

    for (int i = 0; i < ZONES; i++) {
        fwrite(students[i], sizeof(Student), studentCountInZone[i], file);
    }
    
    fclose(file);
}

void loadStudentsFromFile() {
    FILE *file = fopen("students_data.bin", "rb");
    if (file == NULL) {
        return;
    }
    fread(&studentsCount, sizeof(int), 1, file);
    fread(studentCountInZone, sizeof(int), ZONES, file);

    for (int i = 0; i < ZONES; i++) {
        fread(students[i], sizeof(Student), studentCountInZone[i], file);
    }
    
    fclose(file);
}

Student* getStudentByID_ErwthmaC(Student students[ZONES][SEATS], int studentCountInZone[], int am) {
    for (int i=0;i<ZONES;i++) 
        for (int j=0;j<studentCountInZone[i];j++) 
            if (students[i][j].am==am) 
                return &students[i][j];
    return NULL; 
}

void getString(char str[], int numOfChars, char *message) {
	printf("%s",message);
	
    int i;
    char ch;
    for(i=0;i<numOfChars&&(ch=getchar())!='\n';i++) 
        str[i]=ch;
    str[i] = '\0';
    while(ch!='\n'){
        ch=getchar();
    }
}

int getInt(char *message){
	int n;
	printf("%s",message);
	scanf("%d",&n);
	getchar();
	return n;
}