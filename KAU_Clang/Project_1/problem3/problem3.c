#include <stdio.h>
void binaryFunc(int n);

int main()
{
    /* ���� ���� �κ�: �������� ������ */
	int n; // �������� ��ȯ�ϰ��� �ϴ� ������
    /* ------------------------------- */

    /* �Է� �κ�: �������� ������ */
    printf("2������ ����ϰ��� �ϴ� ���� �Է��ϼ���:\n");
    scanf("%d",&n);
    /* -------------------------- */


    /* ��� �κ�: �������� ������ */
    printf("������ ���: ");
	binaryFunc(n);
    /* -------------------------- */
	
  return 0;
}

void binaryFunc(int n) {
    unsigned short int target = (n&0xFFFF);
    char find = 0;

    for(int i=15; i>-1; i--)
	{
        if(find == 0 && ((target>>i)&0b01) == 0)
		{
		}else{
			find = 1;
			printf("%d", ((target>>i)&0b01));
		}
	}
    printf("\n");
}