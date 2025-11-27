#include <stdio.h>
#include <stdlib.h>

#define M 50
#define MAX_ORDERS 100

#define TERMINATE 0
#define ADD_ORDER 1
#define SHOW_ORDERS 2
#define SHOW_PENDING 3
#define SAVE_PENDING 4
#define LOAD_PENDING 5
#define EXECUTE 6
#define SHOW_READY 7
#define CLOSE 8
#define SHOW_CLOSED 9
#define SAVE_CLOSED 10
#define LOAD_CLOSED 11

#define PENDING 0
#define READY 1
#define CLOSED 2
#define ALL 3

int getInt(char *message);
void getString(char str[], int numOfChars, char *message);

typedef struct{
		char name[M];
		int plithosmik, plithosmeg;
        int plithos;
		float initcost,finalcost;
		char initdate[M],finaldate[M],exedate[M];
		char status;
}Order;

Order OrdersList[MAX_ORDERS];

float InitialCost(int plithosmik, int plithosmeg);
float FinalCost(float init,int plithos);
float DisplayCost(float cost,int plithos);

void getOrder(Order *o);
void DisplayOrder(Order orders[], int count, int statusFilter);

void saveOrdersToFile(Order orders[], int *count,int statusFilter, const char *filename);
void loadOrdersFromFile(Order orders[], int *count, int statusFilter, const char *filename);
void updateOrderStatus(Order *order, char newStatus);
int selectOrder(int count, char *message, int statusFilter);

void Execute(int count);
void Close(int count);

void DisplayMenu();

int orderCount = 0;
int choice=-1;
int main() {
	

	while(choice!=TERMINATE){
		
		DisplayMenu();
		choice=getInt("Choose from the menu: ");
		
		switch(choice){
		
			case TERMINATE:
				printf("Program Terminated.");
    		break;
    			
			case ADD_ORDER:
                getOrder(&OrdersList[orderCount]);
    		break;
    
			case SHOW_ORDERS:
				DisplayOrder(OrdersList,orderCount,ALL);
            break;
            
            case SHOW_PENDING:
            	DisplayOrder(OrdersList,orderCount,PENDING);
		    break;

            case SAVE_PENDING:
                saveOrdersToFile(OrdersList,&orderCount,PENDING, "pending_orders.txt");
            break;
                
            case LOAD_PENDING:
                loadOrdersFromFile(OrdersList,&orderCount,PENDING, "pending_orders.txt");
            break;

            case EXECUTE:
            	Execute(orderCount);
    		break;
    		
            case SHOW_READY:
               DisplayOrder(OrdersList,orderCount,READY);
            break;

            case CLOSE:
            	Close(orderCount);
	    	break;

            case SHOW_CLOSED:
               DisplayOrder(OrdersList,orderCount,CLOSED);
            break;

            case SAVE_CLOSED:
            	saveOrdersToFile(OrdersList,&orderCount,CLOSED, "closed_orders.txt");
            break;

            case LOAD_CLOSED:
                loadOrdersFromFile(OrdersList,&orderCount,CLOSED, "closed_orders.txt");
            break;    
    	
    		default:
    			printf("Not a valid choice");
    		break;
        }
    }
    return 0;
}

void getOrder(Order *o){
	if(orderCount<MAX_ORDERS){	
		o->status = PENDING;
		getString(o->name,M,"Client's Name: ");
		getString(o->initdate,M,"Date of Order: ");
		getString(o->finaldate,M,"Order execution Date: ");
		o->initcost = InitialCost((o->plithosmik = getInt("Number of Small bottles: ")),(o->plithosmeg = getInt("Number of Big bottles: ")));
    	o->plithos = o->plithosmik + o->plithosmeg;
		orderCount++;	
    } else printf("Order list is full. Cannot add more orders.\n");
}

void DisplayOrder(Order orders[], int count, int statusFilter) {
    if (count == 0) {
        printf("No orders to display.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        if (statusFilter == ALL || orders[i].status == statusFilter) {
            printf("\n-----------------Order#%d-----------------\n", i + 1);
            printf("Client's Name: %s\n", orders[i].name);
            printf("Date of Order: %s\n", orders[i].initdate);
            printf("Execution Date: %s\n", orders[i].finaldate);
            if (orders[i].status == CLOSED) {
                printf("Execution Date (exedate): %s\n", orders[i].exedate);
            }
            printf("Number of Small Bottles: %d\n", orders[i].plithosmik);
            printf("Number of Big Bottles: %d\n", orders[i].plithosmeg);
            if (orders[i].status == READY) {
                printf("\nInitial Cost is %.3f$\n", orders[i].initcost);
            }
            if (orders[i].status == CLOSED) {
                DisplayCost(orders[i].initcost, orders[i].plithos);
            }
            printf("Order's Status: ");
            switch (orders[i].status) {
                case PENDING:
                    printf("Pending\n");
                    break;
                case READY:
                    printf("Ready to close\n");
                    break;
                case CLOSED:
                    printf("Closed\n");
                    break;
                default:
                    break;
            }
            printf("-------------------------------------------\n");
        }
    }
}

void DisplayMenu(){
	printf("\n/--------- Factory Menu ----------\\ \n");
	printf("|0 - Termination                  |\n");
	printf("|1 - Enter Order                  |\n");
	printf("|2 - Show Orders                  |\n");
	printf("|3 - Show Pending Orders          |\n");
    printf("|4 - Save Pending Orders to File  |\n");
    printf("|5 - Load Pending Orders from File|\n");
    printf("|6 - Execute Order (Initial Cost) |\n");
    printf("|7 - Show Ready Orders            |\n");
    printf("|8 - Make Payment (Final Cost)    |\n");
    printf("|9 - Show Closed Orders           |\n");
    printf("|10 - Save Closed Orders to File  |\n");
    printf("\\11 - Load Closed Orders from File/ \n");
}

float InitialCost(int plithosmik, int plithosmeg){
	const float mik=0.08;
	const float meg=0.2;
    return (plithosmik * mik) + (plithosmeg * meg);
}

float FinalCost(float init,int plithos){
	if (init>600)
        init*=0.76;
    else if ((init>300&&init<=600)||plithos>1000)
        init*=0.88; 
	return init;
}

float DisplayCost(float cost,int plithos){
	if (cost>600){
		printf("\nInitial Cost is %.3f$",cost);
        cost*=0.76;
        printf("\nDiscount: 24%%");
        printf("\nFinal Cost is %.3f$\n",cost);}
    else if ((cost>300&&cost<=600)||plithos>1000){
    	printf("\nInitial Cost is %.3f$",cost);
        cost*=0.88; 
        printf("\nDiscount: 12%%");
        printf("\nFinal Cost is %.3f$\n",cost);}
	else printf("\nCost is %.3f$\n",cost);
	return cost;
}

void deleteOrder(Order orders[], int *count, int indexToDelete) {
    for (int i=indexToDelete; i<*count-1;i++) {
        orders[i] = orders[i+1];
    }
    (*count)--;
}

void saveOrdersToFile(Order orders[], int *count, int statusFilter, const char *filename) {
    if (*count == 0) {
        printf("No orders to save.\n");
        return;
    }
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open file for saving orders.\n");
        return;
    }

    int savedOrdersCount = 0;
    for (int i = 0; i < *count; i++) {
        if (statusFilter == PENDING && orders[i].status == PENDING) {
            fprintf(file, "%s\n%s\n%s\n%d\n%d\n%.2f\n\n",
                    orders[i].name, orders[i].initdate, orders[i].finaldate, 
                    orders[i].plithosmik, orders[i].plithosmeg, orders[i].initcost);
            savedOrdersCount++;
            deleteOrder(orders, count, i);
            i--;
        }
        if (statusFilter == CLOSED && orders[i].status == CLOSED) {
            fprintf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%.2f\n%.2f\n\n",
                    orders[i].name, orders[i].initdate, orders[i].finaldate, orders[i].exedate,
                    orders[i].plithosmik, orders[i].plithosmeg, 
                    orders[i].initcost, FinalCost(orders[i].initcost,orders[i].plithos));
            savedOrdersCount++;
            deleteOrder(orders, count, i);
            i--;
        }
    }
    if (savedOrdersCount > 0) {
        printf("%d orders saved to file %s.\n", savedOrdersCount, filename);
    } else {
        printf("No orders matching the filter were saved.\n");
    }

    fclose(file);
}

void loadOrdersFromFile(Order orders[], int *count, int statusFilter, const char *filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file for loading orders.\n");
        return;
    }
    
    int loadedCount = 0;
    if(statusFilter==PENDING){
        while (fscanf(file, "%49[^\n]\n%49[^\n]\n%49[^\n]\n%d\n%d\n%f\n",
               orders[*count].name, orders[*count].initdate, orders[*count].finaldate,
               &orders[*count].plithosmik, &orders[*count].plithosmeg,
               &orders[*count].initcost)==6) {
        
            if (statusFilter == ALL || orders[*count].status == statusFilter) {
                (*count)++;
                loadedCount++;
            }
        }
    }
    if(statusFilter==CLOSED){
        while (fscanf(file, "%49[^\n]\n%49[^\n]\n%49[^\n]\n%49[^\n]\n%d\n%d\n%f\n%f\n",
               orders[*count].name, orders[*count].initdate, orders[*count].finaldate,
               orders[*count].exedate, &orders[*count].plithosmik, &orders[*count].plithosmeg,
               &orders[*count].initcost,&orders[*count].finalcost)==8) {
        
        if (statusFilter == ALL || orders[*count].status == statusFilter) {
            (*count)++;
            loadedCount++;
        }
    }
}
	fclose(file);
	file = fopen(filename, "w");
	fclose(file);
	
    printf("%d orders loaded from file %s.\n", loadedCount, filename);
}

void updateOrderStatus(Order *order, char newStatus) {
    order->status = newStatus;
}

int selectOrder(int count, char *message, int statusFilter) {
	if(count>1){
		if(statusFilter==PENDING){
    		printf("\nSelect an order to %s:\n", message);
    		DisplayOrder(OrdersList,orderCount,PENDING);
    		int selection;
    		do {
        		selection = getInt("Enter the number of the order: ");
        		if (selection<1||selection>count) 
            		printf("Invalid order number. Please try again.\n");
    		} while (selection<1||selection>count);

    		return selection - 1; 
		} else if(statusFilter==READY){
    		DisplayOrder(OrdersList,orderCount,READY);
    		int selection;
    		do {
        		selection = getInt("Enter the number of the order: ");
        		if (selection<1||selection>count) 
            		printf("Invalid order number. Please try again.\n");
    		} while (selection<1||selection>count);
			return selection - 1; 
		}
	}else return 0;
}

void Execute(int count){
    if (count > 0) {
	    int selectedIndex=-1;
		int pendingCount=0;
    	for (int i=0;i<count;i++) {
            if (OrdersList[i].status==PENDING)
            	pendingCount++;
    	}
        if (pendingCount>0) {
            selectedIndex = selectOrder(count,"execute",PENDING);
            if (selectedIndex != -1 && OrdersList[selectedIndex].status == PENDING) {
                updateOrderStatus(&OrdersList[selectedIndex], READY);
                printf("Order execution (initial cost calculation) is done.\n");
            }
    	} else printf("No pending orders to execute.\n");
    } else printf("No orders to execute.\n");
}

void Close(int count){
    if (count > 0) {
        int selectedIndex=-1;
		int readyCount=0;
        for (int i=0;i<count;i++) {
        	if (OrdersList[i].status==READY)
    			readyCount++;
        }
        if (readyCount>0) {
        	selectedIndex = selectOrder(count,"close",READY);
            if (selectedIndex != -1 && OrdersList[selectedIndex].status == READY) {
                getString(OrdersList[selectedIndex].exedate, M, "Enter execution date (exedate): ");
                updateOrderStatus(&OrdersList[selectedIndex], CLOSED);
                printf("Order payment (final cost calculation) is done.\n");
            }
        } else printf("No ready orders to close.\n");
    } else printf("No orders to close.\n");
}

void getString(char str[], int numOfChars, char *message) {
	printf("%s",message);
	
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

int getInt(char *message){
	int n;
	printf("%s",message);
	scanf("%d",&n);
	getchar();
	return n;
}