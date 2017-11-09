#include <stdio.h>
#include <windows.h>.
#include <conio.h>
#include <string>
#include <string.h>

int main() {
	
	/*--------------- Declarations ---------------*/
	char comp_name[50];
	char fname[30], lname[30];
	char telNum[11];
	char apCode;
	int cost = 0, ttl_cost = 0, orTotal = 0, ttl_orTotal = 0, gct = 0, ttl_gct = 0,
		disc = 0, ttl_disc = 0, tsCount = 0, bgCount = 0, cpCount = 0,
		min_quant = 0, quant = 0, avg = 0, c = 0 ;
	/*--------------- Declarations ---------------*/

	while (true) {
		
		COMP_NAME:
	/*--------------- Collecting Data ---------------*/
		printf("Please Enter Company      *put '_' in place of whitespaces\n");
		scanf("%s",comp_name);
		if (!strcmp(comp_name,"XXX")) {
			break;
		}
		else if (!strcmp(comp_name, "") || comp_name == NULL) {
			goto COMP_NAME;
		}
		c += 1;
		NAME:
		printf("Please enter first name: ");
		scanf("%s", fname);
		printf("\nPlease enter last  name: ");
		scanf("%s", lname);
		if (fname == NULL || lname == NULL) {
			printf("Invalid Name Entry\n");
			goto NAME;
		}
		APCODE:
		printf("\nWhat would you like to order:\n");
		printf("A. T-Shirts\n");
		printf("B. Bags\n");
		printf("C. Caps\n");
		printf(">> ");
		Sleep(3);
		apCode = getch();
		apCode = toupper(apCode);


		if (apCode == 'A') {
			cost = 320;
			min_quant = 25;
			
		}
		else if (apCode == 'B') {
			cost = 250;
			min_quant = 11;
			
		}
		else if (apCode == 'C') {
			cost = 170;
			min_quant = 25;			
		}
		else {
			printf("\nInvalid Apparel Code...\n");
			system("pause");
			goto APCODE;
		}

	QUANT:
		printf("\n** Must be %d or more **\n", min_quant);
		printf("Quantity: ");
		scanf("%d", &quant);
		if (quant < min_quant) {
			printf("Order quantity insufficient...\n");
			goto QUANT;
		}
		if (cost == 320) {
			tsCount += quant; //Calculating total T-Shirts orders by all companies
		}
		else if (cost == 250) {
			bgCount += quant; //Calculating total Bag orders by all companies
		}
		else if (cost == 170) {
			cpCount += quant; //Calculating total Cap orders by all companies
		}
/*--------------- Collecting Data ---------------*/
			
/*--------------- Calculations ---------------*/
		cost = cost * quant;
		if (quant > 50) {
			disc = cost * 0.05;
			cost += disc;
		}
		gct = cost  * 0.165;
		orTotal = cost + gct;

/*--------------- Calculations ---------------*/

/*--------------- Outputs ---------------*/
		printf("\n********************** Receipt **********************\n");
		printf("Company Name: %s \n", comp_name);
		printf("Contact Name: %s %s \n", fname, lname);
		printf("Order GCT (16.5%): %d\n", gct);
		printf("Order Total(before mould): %d \n", orTotal);
		printf("Order Total(after mould): %d \n", orTotal + 3500);
		if (disc != 0) {
			printf("Order discount: %d\n", disc);
		}
		printf("********************** Receipt **********************\n");
		

/*--------------- Outputs ---------------*/

/*---------------- Post Calculations ----------------*/
		ttl_orTotal += orTotal;
		ttl_disc += disc;
		ttl_gct += gct;
		ttl_cost += cost - disc;
/*---------------- Post Calculations ----------------*/
		disc = 0;
		
	}
	avg = ttl_orTotal / c;
	printf("\n\n*************************************************************\n");
	printf("*************************************************************\n");
	printf("Number of Companies: %d \n", c);
	printf("Total amount of T-Shirt orders: %d \n", tsCount);
	printf("Total amount of Bag orders: %d \n", bgCount);
	printf("Total amount of Cap orders: %d \n", cpCount);
	printf("Total \"Order Cost\": %d \n", ttl_cost);
	printf("Total \"Order GCT\": %d\n", ttl_gct);
	printf("Total \"Order Discount\": %d\n", ttl_disc);
	printf("Total \"Order Total\" (before moulds): %d \n",ttl_orTotal); 
	printf("Total \"Order Total\" (after moulds): %d \n", ttl_orTotal + (3500 * c));
	printf("Average order value/Company: %d \n", avg);
	printf("*************************************************************\n");
	printf("*************************************************************\n");

	return 0;
}
