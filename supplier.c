#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "supplier.h"

struct SupplierNode *head = NULL;

void addSupplier()
{
    struct SupplierNode *temp;

    temp = (struct SupplierNode *)malloc(sizeof(struct SupplierNode));

    if(temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("\nEnter supplier id: ");
    scanf("%d",&temp->id);

    printf("Enter supplier name: ");
    scanf("%s",temp->name);

    printf("Enter phone: ");
    scanf("%s",temp->phone);

    printf("Enter email: ");
    scanf("%s",temp->email);

    printf("Enter address: ");
    scanf("%s",temp->address);

    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        struct SupplierNode *p;

        p = head;

        while(p->next != NULL)
        {
            p = p->next;
        }

        p->next = temp;
    }

    printf("Supplier added successfully\n");
}

void displaySuppliers()
{
    struct SupplierNode *p;

    if(head == NULL)
    {
        printf("No suppliers available\n");
        return;
    }

    p = head;

    printf("\nSupplier Details\n");

    while(p != NULL)
    {
        printf("\nSupplier ID: %d\n",p->id);
        printf("Name: %s\n",p->name);
        printf("Phone: %s\n",p->phone);
        printf("Email: %s\n",p->email);
        printf("Address: %s\n",p->address);

        p = p->next;
    }
}

void searchSupplier()
{
    struct SupplierNode *p;
    int id;
    int found = 0;

    printf("\nEnter supplier id to search: ");
    scanf("%d",&id);

    p = head;

    while(p != NULL)
    {
        if(p->id == id)
        {
            printf("\nSupplier found\n");
            printf("Supplier ID: %d\n",p->id);
            printf("Name: %s\n",p->name);
            printf("Phone: %s\n",p->phone);
            printf("Email: %s\n",p->email);
            printf("Address: %s\n",p->address);

            found = 1;
            break;
        }

        p = p->next;
    }

    if(found == 0)
    {
        printf("Supplier not found\n");
    }
}

void deleteSupplier()
{
    struct SupplierNode *p;
    struct SupplierNode *prev;
    int id;
    int found = 0;

    printf("\nEnter supplier id to delete: ");
    scanf("%d",&id);

    p = head;
    prev = NULL;

    while(p != NULL)
    {
        if(p->id == id)
        {
            if(prev == NULL)
            {
                head = p->next;
            }
            else
            {
                prev->next = p->next;
            }

            free(p);

            found = 1;

            printf("Supplier deleted successfully\n");

            break;
        }

        prev = p;
        p = p->next;
    }

    if(found == 0)
    {
        printf("Supplier not found\n");
    }
}

void supplierMenu()
{
    int choice;

    do
    {
        printf("\n\n");
        printf("=================================\n");
        printf("       SUPPLIER MANAGEMENT\n");
        printf("=================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Delete Supplier\n");
        printf("5. Back\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addSupplier();
                break;

            case 2:
                displaySuppliers();
                break;

            case 3:
                searchSupplier();
                break;

            case 4:
                deleteSupplier();
                break;

            case 5:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice != 5);
}

void saveSuppliers()
{
    FILE *fp;
    struct SupplierNode *p;

    fp = fopen("suppliers.dat","wb");

    if(fp == NULL)
    {
        printf("Unable to open file\n");
        return;
    }

    p = head;

    while(p != NULL)
    {
        fwrite(p,sizeof(struct SupplierNode),1,fp);
        p = p->next;
    }

    fclose(fp);

    printf("Suppliers saved successfully\n");
}

void loadSuppliers()
{
    FILE *fp;
    struct SupplierNode temp;
    struct SupplierNode *newNode;
    struct SupplierNode *p;

    fp = fopen("suppliers.dat","rb");

    if(fp == NULL)
    {
        return;
    }

    while(fread(&temp,sizeof(struct SupplierNode),1,fp) == 1)
    {
        newNode = (struct SupplierNode *)malloc(sizeof(struct SupplierNode));

        if(newNode == NULL)
        {
            printf("Memory allocation failed\n");
            fclose(fp);
            return;
        }

        newNode->id = temp.id;
        strcpy(newNode->name,temp.name);
        strcpy(newNode->phone,temp.phone);
        strcpy(newNode->email,temp.email);
        strcpy(newNode->address,temp.address);

        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            p = head;

            while(p->next != NULL)
            {
                p = p->next;
            }

            p->next = newNode;
        }
    }

    fclose(fp);
}