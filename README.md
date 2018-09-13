# 開發環境
* Project 環境：Ubuntu 16.04.2 LTS (GNU/Linux 4.4.0-78-generic x86_64)

# Project 環境設定
* gcc
* debuginfo-install glibc-2.17-21.fc19.i686
* yum install gcc
* debuginfo-install glibc-2.17-21.fc19.i686
* 關閉 ASLR：Sysctl –w kernel.randomize_va_space = 0

## Description：
* mission_impossible_5.c, that accepts a user password first.
	* 	/home/cleo/attack，Creat mission5.c
```
	$ gcc -g -Wall -fno-stack-protector -z execstack mission5.c -o mission5
	$ ./mission5
```
*  If an input password is correct, the program will execute a piece of code, called Mission Briefing Code (MBC) hereafter, that will display the following message ("Ethan Hunt, Run!") for 2 minutes and then delete the file mission_impossible_5.c and terminate itself.
	* Please enter the password. input correct password“letmepass”.password is correct ouput “Ethan Hunt，Run！” 
	* 執行超過兩分鐘刪除本身執行檔

*  If an erroneous password is input, the program will delete the file mission_impossible_5.c and terminate itself.
* Initially, MBC must be stored in a global array and is encoded with your password. You can use any approach to encode MBC. When the input password is correct, your program will decode MBC and place it in the heap and then transfer your execution flow to the decoded MBC.
