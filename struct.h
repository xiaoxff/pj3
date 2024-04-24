#ifndef _STRUCT_H
#define _STRUCT_H
// ����ְ����Ϣ�ṹ��
typedef struct Employee {
    int emp_id;
    char name[50];
    char gender[10];
    char birthdate[20];
    char education[20];
    float salary;
    char address[100];
    char phone[15];
    struct Employee* next;
} Employee;

extern Employee* head;

#endif