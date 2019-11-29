#ifndef _BANK
#define _BANK

#define num_row 50
#define num_col 2
extern double arr[num_row][num_col];


void open(double);
void balance(int);
void deposit(double,int);
void withdraw(double,int);
void close(int);
void interest(double);
void print();
void EXIT();
#endif

