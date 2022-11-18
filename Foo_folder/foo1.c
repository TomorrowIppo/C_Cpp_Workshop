#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[50];
	char *sour, *dest, tmp[50];

	sour = str;
	dest = tmp;

	//문자열 입력 (공백 포함할 것)
    printf("문자열을 입력하세요:\n");
	fgets(str,sizeof(str),stdin);
    
	if (str[strlen(str)-1] != 32)
		str[strlen(str)] = 32;
					 
	
    while(*sour)
	{
		if(*sour == 32)
		{
			*sour++ = '\0';
		}
		else
		{
		    printf("%s\n", tmp);
		}
	}
	
	return 0;
}
