#include "stdio.h"
#include "myBank.h"
#include "math.h"

void open_account(){
	printf("Opening an account \n");
	double amount;
	printf("Initial deposit?	\n");
	if(scanf("%lf" , &amount ) != 1){
		printf("Error in amount \n");
		return;
	}
	amount = amount*100;
	amount = (int)amount;
	amount = amount/100;
	if(amount < 0){
		printf("Can't open account with minus \n");
		return;
	}
	int bank_num = 0;
	int if_open = 1;
	for (int i = 0 ; i < num_of_accounts ; i++){
		if (!bank[i][1]){
			bank_num = 901 + i;
			bank[i][0] = amount;
			bank[i][1] = 1;
			if_open = 0;
			printf ("The new account number is : %d and the balance is %.2lf \n" , bank_num, amount);
			break;
		}	
	}
	if (if_open){
		printf ("Can't open new account, everything is taken \n");
	}		

}

void check_balance(){
	printf("Checking balance \n");
	int account_number;
	printf("Account number?		\n");
	if(scanf("%d" , &account_number) != 1){
		printf("Error in account number \n");
		return;
	}
	if (account_number > 951 || account_number < 900){
		printf("Invalid account number\n");
		return;
	}
	double money = bank [account_number - 901][0];
	if (bank[account_number - 901][1] && account_number < 951 && account_number > 900){
		printf("The balance of your account is : %.2lf \n" , money);
	}
	else{
		printf("Account is close \n");
	}


}

void deposite(){
	printf("Deposite \n");
	int account_number;
	printf("Account number?		\n");
	if(scanf("%d" , &account_number) != 1){
		printf("Error in account number \n");
		return;
	}
	if (account_number > 951 || account_number < 900){
		printf("Invalid account number\n");
		return;
	}
	double amount;
	printf("Amount?		\n");
	if(scanf("%lf" , &amount ) != 1){
		printf("Error in amount \n");
		return;
	}
	if(amount < 0){
		printf("Can't receive negativeaccount \n");
		return;
	}
	if (bank [account_number - 901][1] && account_number < 951 && account_number > 900){
		printf("The balance before deposite is : %.2lf \n" , bank [account_number - 901][0]);
		bank [account_number - 901][0] = bank [account_number - 901][0] + amount;
		printf("The balance after deposite is : %.2lf \n" , bank[account_number -901][0]);
	}
	else{
		printf("Account is close \n");
	}
}

void withdrawal(){
	printf("Withdrawal \n");
	int account_number;
	printf("Account number?	\n");
	if(scanf("%d" , &account_number) != 1){
		printf("Error in account number \n");
		return;
	}
	if (account_number > 951 || account_number < 900){
		printf("Invalid account number \n");
		return;
	}
	printf("In account number %d you have %.2lf shekels to withdrawal \n", account_number, bank[account_number - 901][0]);
	double amount;
	printf("Amount?		\n");
	if(scanf("%lf" , &amount ) != 1){
		printf("Error in amount \n");
		return;
	}
	if(amount < 0){
		printf("Can't receive a negative amount \n");
		return;
	}
	if (bank [account_number - 901][1] && bank[account_number - 901][0] - amount >= 0 && 	account_number < 951 && account_number > 900){
		printf("The balance before withdrawl is : %.2lf \n" , bank [account_number - 901][0]);
		bank[account_number - 901][0] -= amount;
		printf("The balance after withdrawal is : %.2lf \n" , bank[account_number - 901][0]);
	}
	else{
		printf("Not enough money to withdrawal \n");
	}

}
void close(){
	printf("Closing your account \n");
	int account_number;
	printf("Account number?		\n");
	if(scanf("%d" , &account_number) != 1){
		printf("Error in account number \n");
		return;
	}
	if (account_number > 951 || account_number < 900){
		printf("Invalid account number\n");
		return;
	}
	if (bank [account_number - 901][1] && account_number < 951 && account_number > 900){
		bank [account_number - 901][1] = 0;
		printf("Account %d is closed now \n", account_number);
	}
	
	else{
		printf("Account is close \n");
	}

}
void interest(){
	printf("Adding interest for every accounts \n");
	int interest_rate;
	printf("Interest rate?		\n");
	if(scanf("%d" , &interest_rate) != 1){
		printf("Error in interest rate \n");
		return;
	}
	if(interest_rate < 0){
		printf("Can't add negative interest \n");
		return;
	}
	for (int i = 0 ; i < num_of_accounts ; i++){
		if (bank[i][1]){
			bank[i][0] += (bank[i][0] * (interest_rate * 0.01));
			printf ("The new balance of account %d after interest is : %.2lf \n" , i+901 ,bank[i][0]);
		}	
	}

}
void print(){
	printf("Printing all open accounts \n");
	double money;
	for (int i = 0 ; i < num_of_accounts ; i++){
		if (bank[i][1]){
			money = bank[i][0] ;
			printf ("The balance of number account - %d is : %.2lf \n" , 901+i , money);
		}	
	}

}
void exit_accounts(){
	printf("Closing every accounts \n");
	for (int i = 0 ; i < num_of_accounts ; i++){
		if (bank[i][1]){
			bank[i][0] = 0 ;
			bank[i][1] = 0 ;
		}	
	}
} 
