#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>

int main() {
	
	/*--------------- Declarations ---------------*/
	char comp_name[50];
	char fname[30], lname[30];
	char telNum[11];
	char apCode;
	int cost = 0, ttl_cost = 0,orTotal = 0, ttl_orTotal = 0, gct = 0, 
		disc = 0, quant = 0, ttl_quant = 0, comp_Ttl = 0, avg = 0, c = 0 ;
	/*--------------- Declarations ---------------*/

	while (true) {
		c += 1;

	/*--------------- Collecting Data ---------------*/
		printf("Please Enter Company      *put '_' in place of whitespaces\n");
		scanf("%s",comp_name);
		if (!strcmp(comp_name,"XXX")) {
			break;
		}
		else {
			printf("Please enter first name: ");
			scanf("%s", fname);
			printf("\nPlease enter last  name: ");
			scanf("%s", lname);
			int orValue = 0;
			printf("\nEnter Cost: ");
			scanf("%d", &orValue);
	/*--------------- Collecting Data ---------------*/

	/*--------------- Calculations ---------------*/

			gct = orValue * 0.165;
			orTotal = orValue + gct;
			ttl_orTotal = ttl_orTotal + orTotal;

	/*--------------- Calculations ---------------*/

	/*--------------- Outputs ---------------*/

			printf("Company Name: %s \n", comp_name);
			printf("Contact Name: %s %s \n", fname, lname);
			printf("Order Total: %d \n", orTotal);

	/*--------------- Outputs ---------------*/
		}
		
	}
	avg = ttl_orTotal / c;
	printf("\n**************************************\n");
	printf("Average order value: %d \n",avg);
	printf("Total \"Order Total\": %d \n",ttl_orTotal);

	return 0;
}
