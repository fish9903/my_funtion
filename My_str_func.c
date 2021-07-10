#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void my_strcat(char* dest, char* source);
void my_strcpy(char* str1, char* str2);

int main()
{
	char strcat_dest[100] = "a aa";
	char strcat_origin[] = "bbb";

	char strcpy_dest[100];
	char strcpy_origin[] = "123asd";

	//strcat(strcat_dest, strcat_origin);
	my_strcat(strcat_dest, strcat_origin);
	printf("strcat : ");
	puts(strcat_dest);

	//strcpy(strcpy_dest, strcpy_origin);
	my_strcpy(strcpy_dest, strcpy_origin);
	printf("strcpy : ");
	puts(strcpy_dest, strcpy_origin);

	return 0;
}

void my_strcat(char* dest, char* origin)
{
	char* ptr = dest + strlen(dest);

	for (int i = 0; i < strlen(origin); i++)
	{
		*ptr = origin[i];
		ptr++;
	}

	*origin = '\0';
}

void my_strcpy(char* dest, char* origin)
{
	for (int i = 0; i < strlen(origin); i++)
	{
		*dest = origin[i];
		dest++;
	}
}
