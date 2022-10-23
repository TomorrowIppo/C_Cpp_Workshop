#include <stdio.h>
#include <stdlib.h>

int deposit(int *balance);
int withdraw(int *balance);
void balanceOutput(int balance);

int main()
{
	int balance=0;
    
    //현재 잔액
    printf("현재 잔액을 입력하세요:\n");
    scanf("%d", &balance);
  
    int choice;

	while(1)
	{
		//choice: 1. 입금, 2. 출금, 3. 잔고조회, 4. 종료
	   do{
          printf("원하는 프로그램을 선택하세요: 1. 입금, 2. 출금, 3. 잔고조회, 4. 종료\n");
		  scanf("%d", &choice);
	   }while(choice < 1 || choice > 4); //choice에 1~4의 값이 들어오면 do while문 종료

		switch(choice)
		{
    	    case 1 :
                deposit(&balance);
                break;
            case 2 :
                withdraw(&balance);
                break;
            case 3 :
                balanceOutput(balance);
                break;
			case 4 : puts("프로그램을 종료합니다. ");
			    exit(0);
		}
   }

	return 0;
}

int deposit(int *balance)
{
   int money;

	//입금할 금액 입력
    printf("입금할 금액을 입력하세요:\n");
	scanf("%d", &money);

    *balance += money;
}

int withdraw(int *balance)
{
   int money;

	//출금할 금액 입력
    printf("출금할 금액을 입력하세요:\n");
	scanf("%d", &money);

	if(*balance - money < 0)
		printf("잔고 부족!\n");
	else
		*balance -= money;
}

void balanceOutput(int balance)
{
   printf("현재 잔액은 %d원입니다.\n", balance);
}
