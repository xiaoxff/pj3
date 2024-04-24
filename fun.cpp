#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"fun.h"
#include"struct.h"

extern int password_my;
extern Employee* head;

void displayMenu() 
{
    printf("\n====== ְ����Ϣ����ϵͳ ======\n");
    printf("1. ְ����Ϣ¼��\n");
    printf("2. ְ����Ϣ���\n");
    printf("3. ְ����Ϣ��ѯ\n");
    printf("4. ְ����Ϣɾ��\n");
    printf("5. ְ����Ϣ�޸�\n");
    printf("0. �˳�ϵͳ\n");
}

void insertEmployee()
{
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    printf("������ְ����: ");
    scanf("%d", &newEmployee->emp_id);

    // ���ְ�����Ƿ��Ѵ���
    Employee* current = head;
    while (current != NULL) 
    {
        if (current->emp_id == newEmployee->emp_id) 
        {
            printf("ְ�����Ѵ��ڣ����������롣\n");
            free(newEmployee);
            return;
        }
        current = current->next;
    }
    printf("����������: ");
    scanf("%s", newEmployee->name);
    printf("�������Ա�: ");
    scanf("%s", newEmployee->gender);
    printf("�������������: ");
    scanf("%s", newEmployee->birthdate);
    printf("������ѧ��: ");
    scanf("%s", newEmployee->education);
    printf("�����빤��: ");
    scanf("%f", &newEmployee->salary);
    printf("������סַ: ");
    scanf("%s", newEmployee->address);
    printf("������绰: ");
    scanf("%s", newEmployee->phone);
    // ����ְ����Ϣ��������ͷ��
    newEmployee->next = head;
    head = newEmployee;
    printf("ְ����Ϣ¼��ɹ���\n");
}
void displayEmployees() 
{
    if (head == NULL) 
    {
        printf("����ְ����Ϣ��\n");
        return;
    }
    Employee* current = head;
    printf("\n====== ְ����Ϣ��� ======\n");
    while (current != NULL) 
    {
        printf("ְ����: %d\n", current->emp_id);
        printf("����: %s\n", current->name);
        printf("�Ա�: %s\n", current->gender);
        printf("��������: %s\n", current->birthdate);
        printf("ѧ��: %s\n", current->education);
        printf("����: %.2f\n", current->salary);
        printf("סַ: %s\n", current->address);
        printf("�绰: %s\n", current->phone);
        printf("-----------------------------\n");
        current = current->next;
    }
}
void searchEmployee() 
{
    if (head == NULL) 
    {
        printf("����ְ����Ϣ��\n");
        return;
    }
    int choice;
    printf("1. ��ְ���Ų�ѯ\n");
    printf("2. ��ѧ����ѯ\n");
    printf("�������ѯ��ʽ: ");
    scanf("%d", &choice);

    Employee* current = head;
    int empId;
    char education[20];

    switch (choice) 
    {
    case 1:
        printf("������ְ����: ");
        scanf("%d", &empId);

        while (current != NULL) 
        {
            if (current->emp_id == empId) {
                printf("ְ����: %d\n", current->emp_id);
                printf("����: %s\n", current->name);
                printf("�Ա�: %s\n", current->gender);
                printf("��������: %s\n", current->birthdate);
                printf("ѧ��: %s\n", current->education);
                printf("����: %.2f\n", current->salary);
                printf("סַ: %s\n", current->address);
                printf("�绰: %s\n", current->phone);
                return;
            }
            current = current->next;
        }
        printf("δ�ҵ�ƥ��ְ����Ϣ��\n");
        break;
    case 2:
        printf("������ѧ��: ");
        scanf("%s", education);

        while (current != NULL) 
        {
            if (strcmp(current->education, education) == 0) {
                printf("ְ����: %d\n", current->emp_id);
                printf("����: %s\n", current->name);
                printf("�Ա�: %s\n", current->gender);
                printf("��������: %s\n", current->birthdate);
                printf("ѧ��: %s\n", current->education);
                printf("����: %.2f\n", current->salary);
                printf("סַ: %s\n", current->address);
                printf("�绰: %s\n", current->phone);
                printf("-----------------------------\n");
            }
            current = current->next;
        }
        break;
    default:
        printf("��Ч��ѡ�����������롣\n");
    }
}

void deleteEmployee() 
{
    if (head == NULL) 
    {
        printf("����ְ����Ϣ��\n");
        return;
    }

    int empId;
    printf("������Ҫɾ����ְ����: ");
    scanf("%d", &empId);

    Employee* current = head;
    Employee* previous = NULL;

    while (current != NULL) 
    {
        if (current->emp_id == empId) 
        {
            if (previous == NULL) 
            {
                // ɾ��ͷ�ڵ�
                head = current->next;
            }
            else {
                previous->next = current->next;
            }

            printf("ְ����Ϣɾ���ɹ���\n");
            free(current);
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("δ�ҵ�ƥ��ְ����Ϣ��\n");
}

void modifyEmployee() 
{
    if (head == NULL) 
    {
        printf("����ְ����Ϣ��\n");
        return;
    }
    int empId;
    printf("������Ҫ�޸ĵ�ְ����: ");
    scanf("%d", &empId);
    Employee* current = head;
    while (current != NULL) 
    {
        if (current->emp_id == empId)
        {
            printf("�������µ�ְ����: ");
            scanf("%d", &current->emp_id);
            printf("�������µ�����: ");
            scanf("%s", current->name);
            printf("�������µ��Ա�: ");
            scanf("%s", current->gender);
            printf("�������µĳ�������: ");
            scanf("%s", current->birthdate);
            printf("�������µ�ѧ��: ");
            scanf("%s", current->education);
            printf("�������µĹ���: ");
            scanf("%f", &current->salary);
            printf("�������µ�סַ: ");
            scanf("%s", current->address);
            printf("�������µĵ绰: ");
            scanf("%s", current->phone);
            printf("ְ����Ϣ�޸ĳɹ���\n");
            return;
        }
        current = current->next;
    }
    printf("δ�ҵ�ƥ��ְ����Ϣ��\n");
}
int authenticate() 
{
    int password;
    printf("����������: ");
    scanf("%d", &password);
    return password == password_my;
}
