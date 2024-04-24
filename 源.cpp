#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"fun.h"
#include"struct.h"

// 全局变量，链表头指针
int password_my;
Employee* head = NULL;

int main() 
{
    int choice;
    // 设置密码
    printf("设置密码：");
    scanf("%d", &password_my);

    while (1) 
    {
        printf("\n====== 职工信息管理系统 ======\n");
        printf("1. 职工信息录入\n");
        printf("2. 职工信息浏览\n");
        printf("3. 职工信息查询\n");
        printf("4. 职工信息删除\n");
        printf("5. 职工信息修改\n");
        printf("0. 退出系统\n");
        printf("请输入您的选择: ");
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
                printf("密码错误，无法进行修改操作。\n");
            }
            break;
        case 0:
            // 释放链表内存
            while (head != NULL) 
            {
                Employee* temp = head;
                head = head->next;
                free(temp);
            }
            printf("感谢使用职工信息管理系统，再见！\n");
            return 0;
        default:
            printf("无效的选择，请重新输入。\n");
        }
    }

    return 0;
}

