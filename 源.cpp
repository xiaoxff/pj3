#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"fun.h"
#include"struct.h"

// ȫ�ֱ���������ͷָ��
int password_my;
Employee* head = NULL;

int main() 
{
    int choice;
    // ��������
    printf("�������룺");
    scanf("%d", &password_my);

    while (1) 
    {
        printf("\n====== ְ����Ϣ����ϵͳ ======\n");
        printf("1. ְ����Ϣ¼��\n");
        printf("2. ְ����Ϣ���\n");
        printf("3. ְ����Ϣ��ѯ\n");
        printf("4. ְ����Ϣɾ��\n");
        printf("5. ְ����Ϣ�޸�\n");
        printf("0. �˳�ϵͳ\n");
        printf("����������ѡ��: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertEmployee();
            break;
        case 2:
            displayEmployees();
            break;
        case 3:
            searchEmployee();
            break;
        case 4:
            deleteEmployee();
            break;
        case 5:
            if (authenticate()) 
            {
                modifyEmployee();
            }
            else 
            {
                printf("��������޷������޸Ĳ�����\n");
            }
            break;
        case 0:
            // �ͷ������ڴ�
            while (head != NULL) 
            {
                Employee* temp = head;
                head = head->next;
                free(temp);
            }
            printf("��лʹ��ְ����Ϣ����ϵͳ���ټ���\n");
            return 0;
        default:
            printf("��Ч��ѡ�����������롣\n");
        }
    }

    return 0;
}

