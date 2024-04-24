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
    printf("\n====== 职工信息管理系统 ======\n");
    printf("1. 职工信息录入\n");
    printf("2. 职工信息浏览\n");
    printf("3. 职工信息查询\n");
    printf("4. 职工信息删除\n");
    printf("5. 职工信息修改\n");
    printf("0. 退出系统\n");
}

void insertEmployee()
{
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    printf("请输入职工号: ");
    scanf("%d", &newEmployee->emp_id);

    // 检查职工号是否已存在
    Employee* current = head;
    while (current != NULL) 
    {
        if (current->emp_id == newEmployee->emp_id) 
        {
            printf("职工号已存在，请重新输入。\n");
            free(newEmployee);
            return;
        }
        current = current->next;
    }
    printf("请输入姓名: ");
    scanf("%s", newEmployee->name);
    printf("请输入性别: ");
    scanf("%s", newEmployee->gender);
    printf("请输入出生日期: ");
    scanf("%s", newEmployee->birthdate);
    printf("请输入学历: ");
    scanf("%s", newEmployee->education);
    printf("请输入工资: ");
    scanf("%f", &newEmployee->salary);
    printf("请输入住址: ");
    scanf("%s", newEmployee->address);
    printf("请输入电话: ");
    scanf("%s", newEmployee->phone);
    // 将新职工信息插入链表头部
    newEmployee->next = head;
    head = newEmployee;
    printf("职工信息录入成功！\n");
}
void displayEmployees() 
{
    if (head == NULL) 
    {
        printf("暂无职工信息。\n");
        return;
    }
    Employee* current = head;
    printf("\n====== 职工信息浏览 ======\n");
    while (current != NULL) 
    {
        printf("职工号: %d\n", current->emp_id);
        printf("姓名: %s\n", current->name);
        printf("性别: %s\n", current->gender);
        printf("出生日期: %s\n", current->birthdate);
        printf("学历: %s\n", current->education);
        printf("工资: %.2f\n", current->salary);
        printf("住址: %s\n", current->address);
        printf("电话: %s\n", current->phone);
        printf("-----------------------------\n");
        current = current->next;
    }
}
void searchEmployee() 
{
    if (head == NULL) 
    {
        printf("暂无职工信息。\n");
        return;
    }
    int choice;
    printf("1. 按职工号查询\n");
    printf("2. 按学历查询\n");
    printf("请输入查询方式: ");
    scanf("%d", &choice);

    Employee* current = head;
    int empId;
    char education[20];

    switch (choice) 
    {
    case 1:
        printf("请输入职工号: ");
        scanf("%d", &empId);

        while (current != NULL) 
        {
            if (current->emp_id == empId) {
                printf("职工号: %d\n", current->emp_id);
                printf("姓名: %s\n", current->name);
                printf("性别: %s\n", current->gender);
                printf("出生日期: %s\n", current->birthdate);
                printf("学历: %s\n", current->education);
                printf("工资: %.2f\n", current->salary);
                printf("住址: %s\n", current->address);
                printf("电话: %s\n", current->phone);
                return;
            }
            current = current->next;
        }
        printf("未找到匹配职工信息。\n");
        break;
    case 2:
        printf("请输入学历: ");
        scanf("%s", education);

        while (current != NULL) 
        {
            if (strcmp(current->education, education) == 0) {
                printf("职工号: %d\n", current->emp_id);
                printf("姓名: %s\n", current->name);
                printf("性别: %s\n", current->gender);
                printf("出生日期: %s\n", current->birthdate);
                printf("学历: %s\n", current->education);
                printf("工资: %.2f\n", current->salary);
                printf("住址: %s\n", current->address);
                printf("电话: %s\n", current->phone);
                printf("-----------------------------\n");
            }
            current = current->next;
        }
        break;
    default:
        printf("无效的选择，请重新输入。\n");
    }
}

void deleteEmployee() 
{
    if (head == NULL) 
    {
        printf("暂无职工信息。\n");
        return;
    }

    int empId;
    printf("请输入要删除的职工号: ");
    scanf("%d", &empId);

    Employee* current = head;
    Employee* previous = NULL;

    while (current != NULL) 
    {
        if (current->emp_id == empId) 
        {
            if (previous == NULL) 
            {
                // 删除头节点
                head = current->next;
            }
            else {
                previous->next = current->next;
            }

            printf("职工信息删除成功！\n");
            free(current);
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("未找到匹配职工信息。\n");
}

void modifyEmployee() 
{
    if (head == NULL) 
    {
        printf("暂无职工信息。\n");
        return;
    }
    int empId;
    printf("请输入要修改的职工号: ");
    scanf("%d", &empId);
    Employee* current = head;
    while (current != NULL) 
    {
        if (current->emp_id == empId)
        {
            printf("请输入新的职工号: ");
            scanf("%d", &current->emp_id);
            printf("请输入新的姓名: ");
            scanf("%s", current->name);
            printf("请输入新的性别: ");
            scanf("%s", current->gender);
            printf("请输入新的出生日期: ");
            scanf("%s", current->birthdate);
            printf("请输入新的学历: ");
            scanf("%s", current->education);
            printf("请输入新的工资: ");
            scanf("%f", &current->salary);
            printf("请输入新的住址: ");
            scanf("%s", current->address);
            printf("请输入新的电话: ");
            scanf("%s", current->phone);
            printf("职工信息修改成功！\n");
            return;
        }
        current = current->next;
    }
    printf("未找到匹配职工信息。\n");
}
int authenticate() 
{
    int password;
    printf("请输入密码: ");
    scanf("%d", &password);
    return password == password_my;
}
