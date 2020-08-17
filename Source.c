//-------------------------------------
// Bello Abarchi
// date of 01/14/2017
// fall 2017 PAYROLL
//-------------------------------------
#include "C:\Users\bello\Desktop\COP 2220\PAYROLL FINAL F\PAYROLL FINAL F\Header.h"
typedef struct {
	char *firstName;
	char *lastName;
	float hourlyPay;
	float hoursWorked;
	float regularPay;
	float overTimePay;
	float grossPay;
	float fedTax;
	float medIns;
	float netPay;
}EMPLOYEE;


//FUNCTION PROTOTYPE
int addEmployee(EMPLOYEE *employee, int* employeeCount);
int binarySearch(EMPLOYEE* employee, int employeeCount, char search[]);
void calculateFederalTax(EMPLOYEE *employee);
void calculateGrossPay(EMPLOYEE *employee);
void calculateMedicalInsurance(EMPLOYEE *employee);
void calculateNetPay(EMPLOYEE *employee);
void calculateOverTimePay(EMPLOYEE *employee);
void calculateRegularPay(EMPLOYEE *employee);
void delete(EMPLOYEE *employee, int employeeCount);
void displayEmployees(EMPLOYEE *employee, int employeeCount);
void displayMenu();
void displaySubMenu();
void edit(EMPLOYEE* employee, int employeeCount);
char getChoice();
char getChoiceSub();
void myFlush();
void searchEmployee(EMPLOYEE* employee, int employeeCount, char search[]);
void sortTheArray(EMPLOYEE* employee, int employeeCount);
void subMenu(EMPLOYEE* employee);

main() {
	char choice;
	int employeeCount = 0;
	int size = 0;
	char search[20];
	EMPLOYEE *employee = 0;
	int i = 0;
	employee = malloc(sizeof(EMPLOYEE) * 500);
	//MENU SYSTEM
	do {
		choice = getChoice();
		switch (choice) {
		case 'A'://add new EMPLOYEE		
			if (employeeCount < 500) {//error checking
				addEmployee(employee, &employeeCount);
			}
			else {
				printf("============================\n");
				printf("Cannot enter any more EMPLOYEE\n");
				PAUSE;
			}
			PAUSE;
			break;

		case 'B'://Edit employee
			if (employeeCount < 500) {
				edit(&employee[i], employeeCount);
				PAUSE;
			}
			else {
				printf("==================================\n");
				printf("No EMPLOYEE have been entered yet!\n");
				PAUSE;
			}
			break;
		case 'C'://Delete employee
			if (employeeCount < 500) {
				delete(&employee[i], employeeCount);
				employeeCount--;
			}
			else {
				printf("==================================\n");
				printf("No EMPLOYEE have been entered yet!\n");
				PAUSE;
			}
			PAUSE;
			break;

		case 'E'://Display all employee
			if (employeeCount < 500) {
				displayEmployees(employee, employeeCount);
			}
			else {
				printf("==================================\n");
				printf("No EMPLOYEE have been entered yet!\n");
				PAUSE;
			}
			PAUSE;
			break;
		case 'D'://Search specific employee
			if (employeeCount < 500) {
				searchEmployee(&employee[i], employeeCount, search);
				PAUSE;
			}
			else {
				printf("==================================\n");
				printf("No EMPLOYEE have been entered yet!\n");
				PAUSE;
			}
			break;

		case 'Q':// Quits the program
			printf("===========SAVED SUCCESSFULLY==========\n");
			printf("===========HAVE A NICE DAY!============\n");
			printf("=======================================\n");
			PAUSE;
			break;
		default:
			break;

		}//end switch
	} while (choice != 'Q');
}//end of main
int addEmployee(EMPLOYEE *employee, int* employeeCount) {

	int size = 0;
	int i = 0;
	char fName[21];
	char lName[21];
	printf("==============================================\n");
	printf("\nEnter the number of employee to enter(<500): ");
	scanf("%i", &size);
	for (i = *employeeCount; i < (size + *employeeCount); i++) {//get employee info
		printf("==========================\n");
		printf("Enter employee First name \n");
		scanf("%s", fName); FLUSH;
		printf("=========================\n");
		printf("Enter employee Last name \n");
		scanf("%s", lName); FLUSH;
		printf("=========================\n");
		printf("Enter employee hourly pay\n");
		scanf("%f", &employee[i].hourlyPay); FLUSH;
		printf("===========================\n");
		printf("Enter employee hours worked\n");
		scanf("%f", &employee[i].hoursWorked); FLUSH;
		employee[i].firstName = malloc(sizeof(char)*strlen(fName));//memory allocation
		strcpy(employee[i].firstName, fName);
		employee[i].lastName = malloc(sizeof(char)*strlen(lName));
		strcpy(employee[i].lastName, lName);
		employee[i].fedTax = 0;
		employee[i].grossPay = 0;
		employee[i].medIns = 0;
		employee[i].overTimePay = 0;
		employee[i].netPay = 0;
		//calculate and store in array
		calculateOverTimePay(&employee[i]);
		calculateRegularPay(&employee[i]);
		calculateGrossPay(&employee[i]);
		calculateFederalTax(&employee[i]);
		calculateMedicalInsurance(&employee[i]);
		calculateNetPay(&employee[i]);

	}//end of for
	*employeeCount += size;
	return size;
}//end of addEmployee
int binarySearch(EMPLOYEE* employee, int employeeCount, char search[]) {// for searching 
	int	first = 0;
	int last = 0;
	int	middle = 0;
	last = employeeCount - 1;
	int result = 0;
	while (first <= last) {
		middle = (first + last) / 2 ;
		result = strcmp(employee[middle].firstName, search);
		if (result < 0) {
			first = middle + 1;
		}
		if (result == 0) {
			printf("============================================\n");
			printf("%s found at location %d.\n", search, middle + 1);
			printf("\nemployee name: %s %s\n", employee[middle].firstName, employee[middle].lastName);
			printf("===============================================\n");
			printf("Employeeregular pay is: $%.2f\n", employee[middle].regularPay);
			printf("Employee overtime pay is: $%.2f\n", employee[middle].overTimePay);
			printf("Employee gross pay is: $%.2f\n", employee[middle].grossPay);
			printf("Employee federal tax is: $%.2f\n", employee[middle].fedTax);
			printf("Employee medical insurance tax is: $%.2f\n", employee[middle].medIns);
			printf("===============================================\n");
			printf("Employee netpay is: $%.2f\n", employee[middle].netPay);
			printf("===============================================\n");
			PAUSE;
			break;
		}
		if( result > 0){
			last = middle - 1;

			middle = (first + last) / 2;
		}
	}
	return middle;
	PAUSE;
}//end of binarySearch
void delete(EMPLOYEE *employee, int employeeCount) {// 
	char search[20];
	int i = 0;
	int x = 0;
	int result = 0;
	printf("======================================\n");
	printf("Enter the employee you want to delete:\n");
	printf("======================================\n");
	scanf("%s", search);
	i = binarySearch(&employee[i], employeeCount, search);
	result = strcmp(employee[i].firstName, search);
	if (result == 0) {//set all the values equal to 0
		employee[i].hourlyPay = 0;
		employee[i].hoursWorked = 0;
		employee[i].grossPay = 0;
		employee[i].fedTax = 0;
		employee[i].medIns = 0;
		employee[i].netPay = 0;
		employee[i].overTimePay = 0;
		employee[i].regularPay = 0;
		for (x = i; x < employeeCount; x++) { // replace employee sub x by employee sub x+1
			employee[x].firstName = employee[x + 1].firstName;
			employee[x].lastName = employee[x + 1].lastName;
			employee[x].hourlyPay = employee[x + 1].hourlyPay;
			employee[x].hoursWorked = employee[x + 1].hoursWorked;
			employee[x].grossPay = employee[x + 1].grossPay;
			employee[x].fedTax = employee[x + 1].fedTax;
			employee[x].medIns = employee[x + 1].medIns;
			employee[x].netPay = employee[x + 1].netPay;
			employee[x].overTimePay = employee[x + 1].overTimePay;
			employee[x].regularPay = employee[x + 1].regularPay;
			employee[i + 1].hourlyPay = 0;
			employee[i + 1].hoursWorked = 0;
			employee[i + 1].grossPay = 0;
			employee[i + 1].fedTax = 0;
			employee[i + 1].medIns = 0;
			employee[i + 1].netPay = 0;
			employee[i + 1].overTimePay = 0;
			employee[i + 1].regularPay = 0;

		}
		printf("Employee Deleted\n");
		
	}
	else {
		printf("The name was not found\n");
	}
}//end of delete
void displayEmployees(EMPLOYEE *employee, int employeeCount) {
	CLS;
	int i = 0;
	sortTheArray(&employee[i], employeeCount);//sort the array first then display all employees
	for (i = 0; i < employeeCount; i++) {
		printf("\n\nemployee name: %s %s\n", employee[i].firstName, employee[i].lastName);
		printf("===============================================\n");
		printf("Employee regular pay is: $%.2f\n", employee[i].regularPay);
		printf("Employee overtime pay is: $%.2f\n", employee[i].overTimePay);
		printf("Employee gross pay is: $%.2f\n", employee[i].grossPay);
		printf("Employee federal tax is: $%.2f\n", employee[i].fedTax);
		printf("Employee medical insurance tax is: $%.2f\n", employee[i].medIns);
		printf("===============================================\n");
		printf("Employee netpay is: $%.2f\n", employee[i].netPay);
		printf("===============================================\n");
	}

}//end of displayEmployees
void displayMenu() {
	CLS;
	printf("=======================================\n");
	printf("==         M A I N   M E N U         ==\n");
	printf("=======================================\n");
	printf("[A] Add new employee\n");
	printf("[B] Edit employee\n");
	printf("[C] Delete employee\n");
	printf("[D] Search specific employee\n");
	printf("[E] Display all employees\n");
	printf("[Q] Quit \n");
	printf("=======================================\n");
	printf("Enter choice: ");
}//end displayMenu
void displaySubMenu() {//menu for edit
	CLS;
	printf("=======================================\n");
	printf("==              M E N U              ==\n");
	printf("=======================================\n");
	printf("[A] edit First name\n");
	printf("[B] Edit last Name\n");
	printf("[C] edit hourly pay\n");
	printf("[D] edit hours worked\n");
	printf("[E] change all entries\n");
	printf("[Q] Back to Main Menu\n");
	printf("=======================================\n");
	printf("Enter choice: ");
}//end of displaySubMenu
void edit(EMPLOYEE* employee, int employeeCount) {
	char search[20];
	int i = 0;
	int result;
	printf("==================================================\n");
	printf("Enter first name of employee you want to edit name: \n");
	scanf("%s", search);
	sortTheArray(&employee[i], employeeCount);
	i = binarySearch(&employee[i], employeeCount, search);
	result = strcmp(employee[i].firstName, search);
	if (result == 0) {
		subMenu(&employee[i]);
	}
	else {
		printf("The name was not found\n");
	}

}//end of edit

char getChoice() {
	char choice;
	displayMenu();
	scanf("%c", &choice); FLUSH; FLUSH;
	return toupper(choice);
}//end getChoice
char getChoiceSub() {
	char choice;
	displaySubMenu();
	scanf("%c", &choice); FLUSH; FLUSH;
	return toupper(choice);
}//end getChoice

void myFlush() {
	char nothing;
	while (scanf("%c", &nothing) == NULL);
}//end of myFlush


void calculateFederalTax(EMPLOYEE* employee) {
	employee->fedTax = employee->grossPay * .27;
	printf("%s, %s Federal tax is: $%.2f\n", employee->lastName, employee->firstName, employee->fedTax);

}//end federalTax

void calculateGrossPay(EMPLOYEE* employee) {

	employee->grossPay = employee->regularPay + employee->overTimePay;
	printf("%s, %s Gross Pay is: $%.2f\n", employee->lastName, employee->firstName, employee->grossPay);
}//end calculateGrossPay

void calculateMedicalInsurance(EMPLOYEE* employee) {
	employee->medIns = employee->grossPay * .14;
	printf("%s, %s Medical insurance is: $%.2f\n", employee->lastName, employee->firstName, employee->medIns);
}//end medicalInsurance

void calculateNetPay(EMPLOYEE* employee) {
	employee->netPay = employee->grossPay - (employee->medIns + employee->fedTax);
	printf("%s, %s Net pay is: $%.2f\n", employee->lastName, employee->firstName, employee->netPay);
}//end netPay

void calculateOverTimePay(EMPLOYEE* employee) {
	if (employee->hoursWorked > 40)
		employee->overTimePay = (employee->hoursWorked - 40) * (1.5 * employee->hourlyPay);
	else
		employee->overTimePay = 0;
	printf("%s, %s Overtime pay is: $%.2f\n", employee->lastName, employee->firstName, employee->overTimePay);
}//end calculateOverTimePay

void calculateRegularPay(EMPLOYEE* employee) {
	if (employee->hoursWorked <= 40)
		employee->regularPay = employee->hoursWorked * employee->hourlyPay;
	else
		employee->regularPay = employee->hourlyPay * 40;
	printf("%s, %s Regular pay is: $%.2f\n", employee->lastName, employee->firstName, employee->regularPay);
}//end calculateRegularPay
void searchEmployee(EMPLOYEE* employee, int employeeCount, char search[]) {//for searching
	int i = 0;
	int result = 0;
	printf("========================================================\n");
	printf("Enter the First name of the employee you want to search:\n");
	printf("========================================================\n");
	scanf("%s", search);
	sortTheArray(&employee[i], employeeCount);
	i = binarySearch(&employee[i], employeeCount, search);
}//end of searchEmployee
void sortTheArray(EMPLOYEE* employee, int employeeCount) {//sorting
	char switchMade = 'N';
	int bottom = employeeCount - 1;
	EMPLOYEE* temp = NULL;
	EMPLOYEE* tempB = NULL;
	int i;
	int result = 0;

	do {
		switchMade = 'N';
		for (i = 0; i < bottom; i++)
			if (strcmp(employee[i].firstName, employee[i + 1].firstName) > 0) {
				temp = employee[i].firstName;
				tempB = employee[i].lastName;
				employee[i].firstName = employee[i + 1].firstName;
				employee[i].lastName = employee[i + 1].lastName;
				employee[i + 1].firstName = temp;
				employee[i + 1].lastName = tempB;
				switchMade = 'Y';
			}
		bottom--;
	} while (switchMade == 'Y');

}//end of sortTheArray
void subMenu(EMPLOYEE* employee) {
	int i = 0;
	char choice;
	char fName[20];
	char lName[20];
	do {
		choice = getChoiceSub();
		switch (choice) {
		case 'A'://EDIT THE FIRST NAME
			printf("==================\n");
			printf("Enter new First Name\n");
			printf("==================\n");
			scanf("%s", fName);
			strcpy(employee[i].firstName, fName);
			printf("==========EMPLOYEE FIRST NAME UPDATED==========\n");
			printf("Employee name: %s %s\n", employee[i].firstName, employee[i].lastName);
			printf("===============================================\n");
			printf("Employee regular pay is: $%.2f\n", employee[i].regularPay);
			printf("Employee overtime pay is: $%.2f\n", employee[i].overTimePay);
			printf("Employee gross pay is: $%.2f\n", employee[i].grossPay);
			printf("Employee federal tax is: $%.2f\n", employee[i].fedTax);
			printf("Employee medical insurance tax is: $%.2f\n", employee[i].medIns);
			printf("===============================================\n");
			printf("Employee netpay is: $%.2f\n", employee[i].netPay);
			printf("===============================================\n");
			PAUSE;
			PAUSE;
			break;
		case 'B'://EDIT THE LAST NAME
			printf("==================\n");
			printf("Enter new Last Name\n");
			printf("==================\n");
			scanf("%s", lName);
			strcpy(employee[i].lastName, lName);
			printf("===========EMPLOYEE LAST NAME UPDATED==========\n");
			printf("Employee name: %s %s\n", employee[i].firstName, employee[i].lastName);
			printf("===============================================\n");
			printf("Employee regular pay is: $%.2f\n", employee[i].regularPay);
			printf("Employee overtime pay is: $%.2f\n", employee[i].overTimePay);
			printf("Employee gross pay is: $%.2f\n", employee[i].grossPay);
			printf("Employee federal tax is: $%.2f\n", employee[i].fedTax);
			printf("Employee medical insurance tax is: $%.2f\n", employee[i].medIns);
			printf("===============================================\n");
			printf("Employee netpay is: $%.2f\n", employee[i].netPay);
			printf("===============================================\n");
			PAUSE;
			PAUSE;
			break;
		case 'C'://EDIT HOURLY PAY
			employee[i].hourlyPay = 0;
			printf("=======================\n");
			printf("Enter employee hourly pay\n");
			printf("=======================\n");
			scanf("%f", &employee[i].hourlyPay); FLUSH;
			employee[i].fedTax = 0;
			employee[i].grossPay = 0;
			employee[i].medIns = 0;
			employee[i].overTimePay = 0;
			employee[i].netPay = 0;
			printf("==========EMPLOYEE HOURLY PAY UPDATED==========\n");
			printf("Employee name: %s %s\n", employee[i].firstName, employee[i].lastName);
			printf("===============================================\n");
			calculateOverTimePay(&employee[i]);
			calculateRegularPay(&employee[i]);
			calculateGrossPay(&employee[i]);
			calculateFederalTax(&employee[i]);
			calculateMedicalInsurance(&employee[i]);
			calculateNetPay(&employee[i]);
			PAUSE;
			PAUSE;
			break;
		case 'D'://EDIT HOURS WORKED
			employee[i].hoursWorked = 0;
			printf("=======================\n");
			printf("Enter employee hours worked\n");
			printf("=======================\n");
			scanf("%f", &employee[i].hoursWorked); FLUSH;
			employee[i].fedTax = 0;
			employee[i].grossPay = 0;
			employee[i].medIns = 0;
			employee[i].overTimePay = 0;
			employee[i].netPay = 0;
			printf("=========EMPLOYEE HOURS WORKED UPDATED=========\n");
			printf("Employee name: %s %s\n", employee[i].firstName, employee[i].lastName);
			printf("===============================================\n");
			calculateOverTimePay(&employee[i]);
			calculateRegularPay(&employee[i]);
			calculateGrossPay(&employee[i]);
			calculateFederalTax(&employee[i]);
			calculateMedicalInsurance(&employee[i]);
			calculateNetPay(&employee[i]);
			PAUSE;
			PAUSE;
			break;
		case 'E'://EDIT ALL ENTRIES
			printf("======================\n");
			printf("Enter new First Name\n");
			printf("======================\n");
			scanf("%s", fName); FLUSH;
			strcpy(employee[i].firstName, fName);
			printf("==================\n");
			printf("Enter new Last Name\n");
			printf("==================\n");
			scanf("%s", lName); FLUSH;
			strcpy(employee[i].lastName, lName);
			printf("=======================\n");
			printf("Enter employee hourly pay\n");
			printf("=======================\n");
			scanf("%f", &employee[i].hourlyPay); FLUSH;
			printf("=========================\n");
			printf("Enter employee hours worked\n");
			printf("=========================\n");
			scanf("%f", &employee[i].hoursWorked); FLUSH;
			employee[i].fedTax = 0;
			employee[i].grossPay = 0;
			employee[i].medIns = 0;
			employee[i].overTimePay = 0;
			employee[i].netPay = 0;
			printf("=============EMPLOYEE INFO UPDATED=============\n");
			printf("Employee name: %s %s\n", employee[i].firstName, employee[i].lastName);
			printf("===============================================\n");
			calculateOverTimePay(&employee[i]);
			calculateRegularPay(&employee[i]);
			calculateGrossPay(&employee[i]);
			calculateFederalTax(&employee[i]);
			calculateMedicalInsurance(&employee[i]);
			calculateNetPay(&employee[i]);
			PAUSE;
			PAUSE;
			break;
		case 'Q'://back to MAIN Menu
			break;
		}//end switch
	} while (choice != 'Q');
}//end of subMenu