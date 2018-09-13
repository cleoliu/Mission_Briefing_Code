#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/*
char code[]="\xeb\x19"
"\x31\xc0\x31\xdb\x31\xd2\x31\xc9\xb0\x04\xb3\x01\x59\xb2\x11\xcd\x80\x31\xc0\xb0\x01\x31\xdb\xcd\x80"
"\xe8\xe2\xff\xff\xff"
"\x45\x74\x68\x61\x6e\x20\x48\x75\x6e\x74\x2c\x20\x52\x75\x6e\x21\x0a";
*/

char code[]={0x29,  0x06 , 0x1c,0x22, 0x45, 0x6e, 0x2b, 0x3a, 0x07,  0x16,  0x22,0x45, 0x3c, 0x38, 0x0b ,0x3d,0x42,0x6e ,0x3d, 0x02,  0x22, 0x44, 0x53,0x6d,0x00};
void xor_encrypt(char *, char *,int);

int main(int argc, char **argv)
{
	pid_t childpid;
	char password[] ="LetMeInNow";
	char user_input[20];	

	printf("Please enter the password.\n");
	//scanf("%d",&userPwd);
	fgets(user_input, 20, stdin);
	user_input[strlen(user_input) -1] = '\0';
	printf("user inpus is : %s\n",user_input);
	if(!strcmp(user_input,password))
	{
		childpid = fork();
		
		if(childpid >=0)
		{
			if(childpid == 0)
			{
				sleep(120);
				system("clear");
				printf("\nmission impossible 5 has been deleted.");
				remove("./mi5.c");
				remove("./mi5");
				exit(0);
			}
			else
			{
				printf("passwd is true\n");
				int n = strlen(code);
				printf("encrypted string : \n");
				  for(int ii = 0; ii < n; ii++) {
    					if(code[ii] > 0x32 &&code[ii] < 0x7F ) printf("%c",code[ii]);
   					else printf("0x%02x",code[ii]);
					}
				//printf("ori string: %s\n",code);
				xor_encrypt(password,code, n);
  				printf("\ndecrypted string : \n");
				for(int ii = 0; ii < n; ii++)
					printf("%c",code[ii]);
  				printf("\n");
				system(code);
				
			}
		}
		else
		{
			printf("fork failue");
			exit(0);
		}
	}
	else
	{
		printf("Password incorrect!\n");
		printf("mission impossible 5 has been deleted.\n");
		remove("./mi5.c");
		remove("./mi5");
		exit(0);
	}
}

void xor_encrypt(char *key, char *string, int n)
{
    int i;
    int keyLength = strlen(key);
    for( i = 0 ; i < n ; i++ )
    {
        string[i]=string[i]^key[i%keyLength];
    }

}
