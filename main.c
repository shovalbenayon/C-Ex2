#include "stdio.h"
#include "myBank.h"

int main() {
	int boolean = 1;
	printf("Welcome to the bank's ATM \n");
	printf("To open an account, Please press 'O' \n");
	printf("To check your balance , Please press 'B' \n");
	printf("To deposite cash to your bank account , Please press 'D' \n");
	printf("To withdrawal cash from your bank account , Please press 'W' \n");
	printf("To add interest rate for every open accounts , Please press 'I' \n");
	printf("To close your bank account , Please press 'C' \n");
	printf("To print every open bank account's , Please press 'P' \n");
	printf("To close all open bank's account , Please press 'E' \n");
	while (boolean){
		char operation;
		printf("Transaction type?	\n");
		if(scanf(" %c" , &operation) != 1){
			printf("Error in trasaction type");
			break;
		}
		switch(operation){
			case 'O':
				open_account();
				break;
			case 'B':
				check_balance();
				break;
			case 'D':
				deposite();
				break;
			case 'W':
				withdrawal();
				break;
			case 'C':
				close();
				break;
			case 'I':
				interest();
				break;
			case 'P':
				print();
				break;
			case 'E':
				exit_accounts();
				boolean = 0;
				break;
		}
	}
}
