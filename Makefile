all: myBank.o main.o myBankD myBank 

myBank.o:myBank.c
	$ gcc -Wall -c -fPIC $^

main.o:main.c 
	$ gcc -Wall -c $^ 

myBankD:myBank.o
	$ gcc -Wall -shared -o libmyBank.so $^

myBank:main.o 
	$ gcc -Wall main.o -L. -lmyBank -o $@

clean:
	$ rm myBank *o 

.PHONY: myBankD clean all
