-->How to compile and run .c programs in unix:
a)	gcc -o filename -o filename.c (Compile)
b)	./filename (execute)
OR
A)	cc filename.c
B)	./a.out
-->Screenshots of sample outputs are given in .pdf file.

-->Programs Introduction:
1)	checkPasswd.c checks password string length entered by user, if it is less than 10, then deduct points (5 points per missing character). If the total deduction is greater than 30 points, print out the deduction and message "The password is unsafe! Please reset."; otherwise, print out "The password is safe."
2)	checkPasswd2.c checks password string and print above messages based on above deduction criteria, it deducts points if:
    o	length is less than 10 characters (-5 points per missing character)
    o	Missing lower case (-20 points)
    o	Lack of capital letters (-20 points)
    o	Missing numbers (-20 points)
    o	More than 2 consecutive characters (e.g., 1234 or abcd) (-20 points)
3)	palindrome.c checks a string if is equal to its reverse string.
4)	swapNum.c reads 2 sentences, and swaps their numeric characters without use of third variable (note: keep lengths of sentences identical)
5)	displayCountry.c checks entered international dialing code, if it is present in its record, it will display corresponding country; otherwise, let the user know that it is not present in the record.
