#include<stdio.h>
#include "product.h"
#include "supplier.h"

int main()
{
    struct Product p[MAX];
    int n;
    int choice;

    n = loadProducts(p);
    loadSuppliers();

    do
    {
        printf("\n\n");
        printf("=================================\n");
        printf("       SMART INVENTORY SYSTEM\n");
        printf("=================================\n");
        printf("1. Product Management\n");
        printf("2. Supplier Management\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                productMenu(p,&n);
                break;

            case 2:
                supplierMenu();
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice != 3);

    saveProducts(p,n);
    saveSuppliers();

    return 0;
}