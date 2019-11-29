#include <stdio.h>
#include "myBank.h"

#define STARTING_ACCOUNT 901
#define OPEN 1
#define CLOSED 0
double arr [num_row][num_col]={0}; 

void open(double money)
{
    int ifFound=0;
    for(int i=0 ; i<num_row && !ifFound ;i++)
    {
        if(arr[i][1]== CLOSED)
        {
            arr[i][1]= OPEN;
            double temp=money*100;
            temp=(int)temp;
            temp/=100;
            arr[i][0]=temp;
            int accountNum=i+STARTING_ACCOUNT;
            printf("Your account number is:  %d\n" ,accountNum);
            ifFound=1;
        }
    }
    if(!ifFound)
    {
        printf("Our bank is full sorry\n");
    }
}
void balance(int accountNum)
{
    int index=accountNum-STARTING_ACCOUNT;
    if(arr[index][1]==OPEN)
    {
        double money=arr[index][0];
        printf("your balance is:\t%.2lf\n",money);
    }
    else
    {
        printf("there is no such account\n");
    }
}
void deposit(double money, int accountNum)
{
    int index=accountNum-STARTING_ACCOUNT;
    if(arr[index][1]==CLOSED)
    {
        printf("this account is not active\n");
    }
    else
    {
        double temp=money*100;
        temp=(int)temp;
        temp/=100;
        arr[index][0]+=temp;
        money=arr[index][0];
        printf("your new balance is:\t %.2lf\n",money);
    }
}
void withdraw(double money,int accountNum)
{       
    int index=accountNum-STARTING_ACCOUNT;
    if(arr[index][1]==CLOSED)
    {
        printf("this account not active\n");
    }
    else
    {
        if(arr[index][0]-money>=0)
        {
            double temp=money*100;
            temp=(int)temp;
            temp/=100;
            arr[index][0]-=temp;
            money=arr[index][0];
            printf("your new balance is:\t %.2lf\n",money);
        }
        else
            printf("you dont have enough money \n");
    }
}
void close(int accountNum)
{
    int index=accountNum-STARTING_ACCOUNT;
    if(arr[index][1]==CLOSED)
    {
        printf("this account is already closed!!\n");
    }
    else
    {
        arr[index][0]=0;
        arr[index][1]=CLOSED;
    }
}
void interest(double Interest)
{
    for(int i=0; i<num_row ;i++)
    {
        if(arr[i][1]==OPEN)
        {
            double temp=(arr[i][0]*Interest)/100;
            arr[i][0]+=temp;
            arr[i][0]*=100;
            arr[i][0]=(int)arr[i][0];
            arr[i][0]/=100;
        }
    }
}
void print()
{
    for(int i= 0; i<num_row; i++)
    {
        if(arr[i][1]==OPEN)
        {
            int temp=STARTING_ACCOUNT+i;
            double money=arr[i][0];
            printf("your account number is:\t%d\t|| \t your balance is: \t%.2lf \n" , temp,money);
        }
    }
}
void EXIT()
{
    for(int i=0 ;i<num_row ;i++)
    {
        if(arr[i][1]==OPEN)
        {
            arr[i][0]=0;
            arr[i][1]=CLOSED;
        }
    }       
}

