#include <stdio.h>

typedef struct {
    int accountNumber;
    char accountHolderName[50];
    double balance;
} Account;

Account accounts[100];
int accountCount = 0;

void createAccount() {
    if (accountCount < 100) {
        printf("Enter account number: ");
        scanf("%d", &accounts[accountCount].accountNumber);
        printf("Enter account holder's name: ");
        scanf("%s", accounts[accountCount].accountHolderName);
        accounts[accountCount].balance = 0.0;
        accountCount++;
        printf("Account created successfully!\n");
    } else {
        printf("Maximum number of accounts reached!\n");
    }
}

void depositMoney() {
    int accountNumber;
    int i;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    for ( i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Deposit successful! New balance: %.2lf\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}


void withdrawMoney() {
    int accountNumber;
    double amount;
    int i;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);
    for ( i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful! New balance: %.2lf\n", accounts[i].balance);
            } else {
                printf("Insufficient balance!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}


void transferMoney() {
    int senderAccountNumber, receiverAccountNumber;
    double amount;
    printf("Enter sender's account number: ");
    scanf("%d", &senderAccountNumber);
    printf("Enter receiver's account number: ");
    scanf("%d", &receiverAccountNumber);
    printf("Enter amount to transfer: ");
    scanf("%lf", &amount);
    int i,j;
    for (i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == senderAccountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                for (j = 0; j < accountCount; j++) {
                    if (accounts[j].accountNumber == receiverAccountNumber) {
                        accounts[j].balance += amount;
                        printf("Transfer successful! Sender's new balance: %.2lf, Receiver's new balance: %.2lf\n", accounts[i].balance, accounts[j].balance);
                        return;
                    }
                }
                printf("Receiver's account not found!\n");
            } else {
                printf("Sender's account has insufficient balance!\n");
            }
            return;
        }
    }
    printf("Sender's account not found!\n");
}


void displayAccountInfo() {
    int accountNumber;
    int i;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    for ( i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder's Name: %s\n", accounts[i].accountHolderName);
            printf("Balance: %.2lf\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

int main() {
    int choice;
    int exit = 1;
            printf("Welcome to C bank!!\n");

    while(exit == 1){
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Transfer Money\n");
        printf("5. Display Account Info\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                transferMoney();
                break;
            case 5:
            	displayAccountInfo();
            	break;
            case 6:
            	exit = 10;
            	printf("Thank you for using C Bank.\n");
            	break;
            default:
            	printf("\nEnter valid choice!!\n\n");
            	break;
}
}
}
