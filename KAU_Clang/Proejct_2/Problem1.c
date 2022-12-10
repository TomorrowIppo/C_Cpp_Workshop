#include <stdio.h>
#include <string.h>

#define BUF_SIZE 64
#define MAX_PRESENTATION_LIST 3
#define MAX_SEMESTER 8

int array_size;

typedef struct STUDENT {
    char name[BUF_SIZE];
    char ID[BUF_SIZE];
    int semester;
    char class_name[BUF_SIZE];
} STUDENT;

// �л� ����ü �� �Լ�
int comapre(STUDENT s1, STUDENT s2) {
    if(s1.class_name == s2.class_name
    && s1.ID == s2.ID
    && s1.name == s2.name
    && s1.semester == s2.semester) {
        return 1;
    }

    return 0;
}

void swap_point(STUDENT *point1, STUDENT *point2)
{
    STUDENT temp;
    temp = *point1;
    *point1 = *point2;
    *point2 = temp;
}

/* ��� �κ�: �������� ������ */
void print_student(const STUDENT *s){
    printf("%-9s %-5s %5d %10s\n", s->name, s->ID, s->semester, s->class_name);
}
/* -------------------------- */

/* print_student_list �Լ� ���� */
// �ݵ�� ���� �ڵ� ����ؼ� ����ϼ���. 
// ���� ����: printf("\n%8s  %-11s %-5s %10s %14s\n", "��ȣ", "�̸�", "�й�", "�б�", "��������"); �̿��Ͽ� ���
// �л� ��ȣ: printf("%3d��: ",����); �̿��Ͽ� ���
// �л� ����: print_student �Լ� �̿��Ͽ� ��� 
/* -------------------------- */
void print_student_list(STUDENT* s)
{    
    printf("\n%8s  %-11s %-5s %10s %14s\n", "��ȣ", "�̸�", "�й�", "�б�", "��������");
    STUDENT temp;
    
    // ����
    for (int i = array_size; i > 1; i--)
    {
        for (int j = 1; j < i; j++)
        {
            if (s[j-1].semester > s[j].semester)
            {
                temp = s[j - 1];
                s[j - 1] = s[j];
                s[j] = temp;
            }
        }
    }

    // ���
    for(int i=0; i<array_size; i++) {
        printf("%3d��: ", i+1);
        print_student(&s[i]);
    }
}

/* find_student �Լ� ���� */
// �ݵ�� ���� �ڵ� ����ؼ� ����ϼ���.
// �л� ��ȣ: printf("%3d��: ",����); �̿��Ͽ� ���
// �л� ����: print_student �Լ� �̿��Ͽ� ���
/* -------------------------- */
void find_student(STUDENT *s) {
    char input[BUF_SIZE];
    int is_checked;

    STUDENT *sour;
    while(1) {
        is_checked = 0;
        printf("\nã������ �л��� �̸� �Ǵ� ���������� �Է��ϼ���(����� exit): ");
        gets(input);

        if(strcmp("exit", input) == 0)
            break;

        sour = s;
        for(int i=0; i<array_size; i++) {
            if(strcmp(sour->class_name, input) == 0 || strcmp(sour->ID, input) == 0 || strcmp(sour->name, input) == 0) {
                printf("%3d��: ", i+1);
                print_student(&s[i]);
                is_checked = 1;
            }
            sour++;
        }   

        if(is_checked == 0) 
            printf("�ش� �л� ������ ã�� �� �����ϴ�.");   
    }
}

/* print_presentation_list �Լ� ���� */
// �ݵ�� ���� �ڵ� ����ؼ� ����ϼ���.
// ���� ����: printf("<< ��ǥ����Ʈ >>\n"); �̿��Ͽ� ���
// �л� ��ȣ: printf("%3d��: ",����); �̿��Ͽ� ���
// �л� ����: print_student �Լ� �̿��Ͽ� ���
/* -------------------------- */
void print_presentation_list(STUDENT *s) {
    STUDENT list[array_size];
    int size;
    int input;
    int num;
    int present_num = 0;
    int is_exist = 0;

    while(1) {
        is_exist = 0;
        printf("size : %d\n", present_num);

        printf("\n��ǥ����Ʈ�� �߰��Ϸ��� 1��, �����Ϸ��� 2��, �����Ϸ��� 3���� ��������: ");
        scanf("%d", &input);

        if(input==3)
            break;
        
        if(input==1) {
            printf("��ǥ����Ʈ�� �߰��� �л� ��ȣ�� �Է��ϼ���: ");
            scanf("%d", &num);

            if(num > 8 || num < 0) {
                printf("�߸��� ��ȣ�Դϴ�.\n");  
                continue;
            } 

            for(int i=0; i<present_num; i++) {
                if(comapre(list[i], *(s+(num-1))) == 1) {
                    is_exist = 1;
                    printf("�̹� ��ǥ����Ʈ�� �ִ� �л��Դϴ�.\n");
                    break;
                }
            }

            if(is_exist == 1) {
                continue;
            }

            list[present_num] = *(s+(num-1));
            present_num++;

            // if(is_exist == 1) {
            //     printf("�̹� ��ǥ����Ʈ�� �ִ� �л��Դϴ�.\n");
            // } else {
            //     list[size] = *(s+(num-1));
            //     present_num++;
            // }
            
        } else if(input==2) {
            int idx;
            printf("��ǥ����Ʈ���� ������ �л� ��ȣ�� �Է��ϼ���: ");
            scanf("%d", &num);

            for(int i=0; i<present_num; i++) {
                if(comapre(list[i], *(s+(num-1))) == 1) {
                    is_exist = 1;
                    idx = i;
                    break;
                }
            }

            if(is_exist == 1) {
                for(int i=idx; i<present_num-1; i++) {
                    memcpy(&list[i], &list[i+1], sizeof(STUDENT));
                }
            } else {
                printf("������ �л��� �����ϴ�.\n");
                continue;
            }
        }
        is_exist = 0;
        // ���
        printf("<< ��ǥ����Ʈ >>\n");
        for(int i=0; i<present_num; i++) {
            printf("%3d��: ", i+1);
            print_student(&list[i]);
        }
    }
}

int main(void)
{
    STUDENT array[] = {
        {"Jihyeon", "2018001", 8, "class1"},
        {"Sujung", "2022015", 2, "class2"},
        {"Minjung", "2021016", 3, "class2"},
        {"Minji", "2021013", 4, "class4"},
        {"Sujung", "2020033", 5, "class3"},
        {"Heejoon", "2020010", 6, "class4"},
        {"Ayoon", "2019022", 5, "class1"},
        {"Jihyeon", "2019001", 7, "class5"},
    };
    array_size = sizeof(array) / sizeof(STUDENT);
    print_student_list(array);
    // #1-2 ���� �� �ݵ�� ���� �ڵ� ����ؼ� ����ϼ���.
    find_student(array);
    
    // #1-3 ���� �� �ݵ�� ���� �ڵ� ����ؼ� ����ϼ���.
    // printf("\n��ǥ����Ʈ�� �߰��Ϸ��� 1��, �����Ϸ��� 2��, �����Ϸ��� 3���� ��������: ");
    // printf("��ǥ����Ʈ�� �߰��� �л� ��ȣ�� �Է��ϼ���: ");
    // printf("�̹� ��ǥ����Ʈ�� �ִ� �л��Դϴ�.\n");
    // printf("�߸��� ��ȣ�Դϴ�.\n");   
    // printf("��ǥ����Ʈ���� ������ �л� ��ȣ�� �Է��ϼ���: ");
    // printf("������ �л��� �����ϴ�.\n");
    
    /* Put your answer */
    print_presentation_list(array);

    return 0;
}