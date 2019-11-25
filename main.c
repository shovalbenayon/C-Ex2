#include "stdio.h"
#include "myBank.h"

void open_account();
void check_balance();
void deposite(); 
void withdrawal(); 
void close(); 
void interest(); 
void print(); 
void exit_accounts(); 

int main() {
	int boolean = 1;
	printf("Welcome to the bank's ATM \n");
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
