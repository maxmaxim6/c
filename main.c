
#include <stdio.h>
#include "myBank.c"
#define OPEN 1
#define CLOSED 0

int main()
{
    int bank=OPEN;
    while(bank==OPEN)
    {
        char transaction;
        printf("please insert an operation , for menu insert 'M' \n");
        scanf(" %c", &transaction);
        switch(transaction)
        {
            case 'O':  //open account
            {
                printf("please insert amount for deposit\n");
                double money;
                if(scanf("%lf",&money)==1)
                {
                    if(money>=0)
                    {
                        open(money);
                    }
                    else
                    {
                        printf("invaild amount of money \n");
                    }
                }
                else
                    print("invaild input");
                break;
            }
            case 'B':  //Balance
            {
                printf("please enter your account number\n");
                int accountNum;
                if(scanf("%d",&accountNum)==1)
                {
                    if(accountNum <901 || accountNum >950)
                    {
                        printf("invaild account number try again\n");
                    }
                    else
                    { 
                    balance(accountNum);
                    }
                }
                else
                    print("invaild input");
                break;
            }
            case 'D': //Deposit
            {
               int accountNum;
                printf("please enter your account number \n");
                if(scanf("%d",&accountNum)==1)
                {
                    if(accountNum <901 || accountNum >950)
                    {
                        printf("invaild account number try again\n");
                    }
                    else
                    {
                        double money;
                        printf("please insert amount for deposit\n");
                        if(scanf("%lf",&money)==1)
                        {
                            if(money>=0)
                            {
                                deposit(money,accountNum);
                            }
                            else
                            {
                                printf("invaild amount of money \n");
                            }
                        }
                    }
                }
                else
                    print("invaild input");
                break;
            }
            case 'W': //withdraw
            {
                int accountNum;
                printf("please enter your account number \n");
                if(scanf("%d",&accountNum)==1)
                {
                    if(accountNum <901 || accountNum >950)
                    {
                        printf("invaild account number try again\n");
                    }
                    else
                    {
                        double money;
                        printf(" how much money do you want to withdraw?\n");
                        if(scanf("%lf",&money)==1)
                        { 
                            if(money>=0)
                            {
                                withdraw(money,accountNum);
                            }
                            else
                            {
                                printf("invaild amount of money \n");
                            }
                        }
                    }
                }
                else
                    print("invaild input");
                break;
            }
            case 'C': //close account
            {
                int accountNum;
                printf("please enter your account number \n");
                if(scanf("%d",&accountNum)==1)
                {
                    if(accountNum <901 || accountNum >950)
                    {
                        printf("invaild account number try again\n");
                    }
                    else
                    {
                        close(accountNum);
                    }
                }
                else
                    print("invaild input");
                break;
            }
            case 'I': //Interest
            {
                double Interest;
                printf("what is the interest rate you want to add : \n");
                if(scanf("%lf",&Interest)==1)
                {
                    if(Interest>=0)
                    {
                        interest(Interest);
                    }
                }
                else
                    print("invaild input");
                break;
            }
            case 'P': //print all
            {
                print();
                break;
            }
            case 'E':  //exit
            {
                EXIT();
                bank=CLOSED;
                break;
            }
            case 'M':
            {
                printf("for opening a new account: insert:             'O'\n");
                printf("to see your current balance insert:            'B'\n");
                printf("for deposit money insert:                      'D'\n");
                printf("for withdraw money insert:                     'W'\n");
                printf("to close your account insert:                  'C'\n");
                printf("for interest insert:                           'I'\n");
                printf("to print all current account balances insert:  'P'\n");
                printf("for exit program insert:                       'E'\n");
                printf("||----------------------------------------------||\n");
                break;
            }
            default:
            {
                printf("invaild opration, for menu insert 'M'\n");
                break;
            }
        }
    }
    return 0;
}




