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

// 학생 구조체 비교 함수
int comapre(STUDENT *s1, STUDENT *s2) {
    if(strcmp(s1->name, s2->name) == 0 &&
    strcmp(s1->ID, s2->ID) == 0 &&
    strcmp(s1->class_name, s2->class_name) == 0 &&
    (s1->semester == s2->semester)) {
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

void delete(STUDENT *s, int idx) {
    for(int i=idx; i<array_size; i++) {
        // memcpy(&s[i], &s[i+1], sizeof(STUDENT));
        s[i] = s[i+1];
    }
}

/* 출력 부분: 수정하지 마세요 */
void print_student(const STUDENT *s){
    printf("%-9s %-5s %5d %10s\n", s->name, s->ID, s->semester, s->class_name);
}
/* -------------------------- */

/* print_student_list 함수 구현 */
// 반드시 다음 코드 사용해서 출력하세요. 
// 가장 윗줄: printf("\n%8s  %-11s %-5s %10s %14s\n", "번호", "이름", "학번", "학기", "수강과목"); 이용하여 출력
// 학생 번호: printf("%3d번: ",변수); 이용하여 출력
// 학생 정보: print_student 함수 이용하여 출력 
/* -------------------------- */
void print_student_list(STUDENT* s)
{    
    printf("\n%8s  %-11s %-5s %10s %14s\n", "번호", "이름", "학번", "학기", "수강과목");
    STUDENT temp;
    
    // 정렬
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

    // 출력
    for(int i=0; i<array_size; i++) {
        printf("%3d번: ", i+1);
        print_student(&s[i]);
    }
}

/* find_student 함수 구현 */
// 반드시 다음 코드 사용해서 출력하세요.
// 학생 번호: printf("%3d번: ",변수); 이용하여 출력
// 학생 정보: print_student 함수 이용하여 출력
/* -------------------------- */
void find_student(STUDENT *s) {
    char input[BUF_SIZE];
    int is_checked;

    STUDENT *sour;
    while(1) {
        is_checked = 0;
        printf("\n찾으려는 학생의 이름 또는 수강과목을 입력하세요(종료는 exit): ");
        gets(input);

        if(strcmp("exit", input) == 0)
            break;

        sour = s;
        for(int i=0; i<array_size; i++) {
            if(strcmp(sour->class_name, input) == 0 || strcmp(sour->ID, input) == 0 || strcmp(sour->name, input) == 0) {
                printf("%3d번: ", i+1);
                print_student(&s[i]);
                is_checked = 1;
            }
            sour++;
        }   

        if(is_checked == 0) 
            printf("해당 학생 정보를 찾을 수 없습니다.");   
    }
}

/* print_presentation_list 함수 구현 */
// 반드시 다음 코드 사용해서 출력하세요.
// 가장 윗줄: printf("<< 발표리스트 >>\n"); 이용하여 출력
// 학생 번호: printf("%3d번: ",변수); 이용하여 출력
// 학생 정보: print_student 함수 이용하여 출력
/* -------------------------- */
void print_presentation_list(STUDENT* s) {
    STUDENT list[array_size];
    int size;
    int input;
    int num;
    int present_num = 0;
    int is_exist = 0;

    while(1) {
        is_exist = 0;
        //printf("present_num : %d\n", present_num);

        printf("\n발표리스트에 추가하려면 1번, 삭제하려면 2번, 종료하려면 3번을 누르세요: ");
        scanf("%d", &input);

        if(input==3)
            break; 
        if(input==1) {
            printf("발표리스트에 추가할 학생 번호를 입력하세요: ");
            scanf("%d", &num);

            if(num > 8 || num < 1) {
                printf("잘못된 번호입니다.\n");  
                continue;
            } 

            // printf("list[0], name : %s\n", list[0].name);
            // printf("s[num-1], name : %s\n", s[num-1].name);

            for(int i=0; i<present_num; i++) {
                if(comapre(&list[i], &s[num-1]) == 1) {
                    is_exist = 1;
                    printf("이미 발표리스트에 있는 학생입니다.\n");
                    break;
                }
            }

            if(is_exist == 1) {
                continue;
            }

            list[present_num] = s[num-1];
            present_num += 1;

            // if(is_exist == 1) {
            //     printf("이미 발표리스트에 있는 학생입니다.\n");
            // } else {
            //     list[size] = *(s+(num-1));
            //     present_num++;
            // }
            
        }
        if(input==2) {
            printf("발표리스트에서 삭제할 학생 번호를 입력하세요: ");
            scanf("%d", &num);

            if(num > 8 || num < 1) {
                printf("잘못된 번호입니다.\n");  
                continue;
            } 

            if(present_num >= num)
                is_exist = 1;

            if(is_exist == 1) {
                delete(list, num-1);
                present_num -= 1;
            } else {
                printf("삭제할 학생이 없습니다.\n");
                continue;
            }
        }
        is_exist = 0;
        // 출력
        printf("<< 발표리스트 >>\n");
        for(int i=0; i<present_num; i++) {
            printf("%3d번: ", i+1);
            print_student(&list[i]);
        }
        printf("총 발표명 수: %d명\n", present_num);
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
    // #1-2 구현 시 반드시 다음 코드 사용해서 출력하세요.
    find_student(array);
    
    // #1-3 구현 시 반드시 다음 코드 사용해서 출력하세요.
    // printf("\n발표리스트에 추가하려면 1번, 삭제하려면 2번, 종료하려면 3번을 누르세요: ");
    // printf("발표리스트에 추가할 학생 번호를 입력하세요: ");
    // printf("이미 발표리스트에 있는 학생입니다.\n");
    // printf("잘못된 번호입니다.\n");   
    // printf("발표리스트에서 삭제할 학생 번호를 입력하세요: ");
    // printf("삭제할 학생이 없습니다.\n");
    
    /* Put your answer */
    print_presentation_list(array);

    return 0;
}