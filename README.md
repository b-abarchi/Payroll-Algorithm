# Payroll-Algorithm
manage company employees and their payroll
You are to write a Payroll c program . your program should be able to store up to 500 employees. You need a menu that should look like this:
printf("=======================================\n");
	printf("==         M A I N   M E N U         ==\n");
	printf("=======================================\n");
	printf("[A] Add new employee\n");
	printf("[B] Edit employee\n");
	printf("[C] Delete employee\n");
	printf("[D] Search specific employee\n");
	printf("[E] Display all employees\n");
	printf("[Q] Save all employee & Quit \n");
	printf("=======================================\n");
	printf("Enter choice: ");
user can edit each information about employees (names, hours worked and hourly pay).
Your struct should look like this
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

•	Design tool.
•	Documentation with in the code 
•	Use of functions 
•	Use struct.
•	Your menu system
•	Adds to the Array
•	Removes from the Array
•	Does sorting
•	Does searching
•	Does some type of calculations
•	Allows the user to enter the number of things to store
•	Allocates disjoint memory and uses this memory
•	Output is neat and makes sense
•	Compiles and runs
•	Error checking...stops the user from doing bad things
•	Freeing Memory Correctly
•	Completed on time and properly uploaded to Blackboard
•	Uses a programmer created header file
