#include<stdio.h>
#include "product.h"
#include "inventory.h"

void addStock(struct Product p[], int n)
{
    int id;
    int quantity;
    int i;
    int found = 0;

    printf("\nEnter product id: ");
    scanf("%d",&id);

    for(i=0;i<n;i++)
    {
        if(p[i].id == id)
        {
            printf("Enter quantity to add: ");
            scanf("%d",&quantity);

            if(quantity <= 0)
            {
                printf("Quantity must be greater than zero\n");
                return;
            }

            p[i].stock = p[i].stock + quantity;

            printf("Stock added successfully\n");
            printf("Current stock: %d\n",p[i].stock);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Product not found\n");
    }
}

void removeStock(struct Product p[], int n)
{
    int id;
    int quantity;
    int i;
    int found = 0;

    printf("\nEnter product id: ");
    scanf("%d",&id);

    for(i=0;i<n;i++)
    {
        if(p[i].id == id)
        {
            printf("Enter quantity to remove: ");
            scanf("%d",&quantity);

            if(quantity <= 0)
            {
                printf("Quantity must be greater than zero\n");
                return;
            }

            if(quantity <= p[i].stock)
            {
                p[i].stock = p[i].stock - quantity;

                printf("Stock removed successfully\n");
                printf("Current stock: %d\n",p[i].stock);
            }
            else
            {
                printf("Not enough stock available\n");
            }

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Product not found\n");
    }
}

void viewInventory(struct Product p[], int n)
{
    int i;

    if(n == 0)
    {
        printf("\nNo products available\n");
        return;
    }

    printf("\n=================================\n");
    printf("          INVENTORY\n");
    printf("=================================\n");

    for(i=0;i<n;i++)
    {
        printf("\nProduct ID: %d\n",p[i].id);
        printf("Product Name: %s\n",p[i].name);
        printf("Category: %s\n",p[i].category);
        printf("Current Stock: %d\n",p[i].stock);
        printf("Minimum Stock: %d\n",p[i].minStock);
    }
}

void checkLowStock(struct Product p[], int n)
{
    int i;
    int found = 0;

    printf("\n=================================\n");
    printf("         LOW STOCK ALERT\n");
    printf("=================================\n");

    for(i=0;i<n;i++)
    {
        if(p[i].stock <= p[i].minStock)
        {
            printf("\nProduct ID: %d\n",p[i].id);
            printf("Product Name: %s\n",p[i].name);
            printf("Current Stock: %d\n",p[i].stock);
            printf("Minimum Stock: %d\n",p[i].minStock);

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("\nNo low stock products\n");
    }
}

void inventoryMenu(struct Product p[], int *n)
{
    int choice;

    do
    {
        printf("\n\n");
        printf("=================================\n");
        printf("       INVENTORY MANAGEMENT\n");
        printf("=================================\n");
        printf("1. Add Stock\n");
        printf("2. Remove Stock\n");
        printf("3. View Inventory\n");
        printf("4. Check Low Stock\n");
        printf("5. Back\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addStock(p,*n);
                break;

            case 2:
                removeStock(p,*n);
                break;

            case 3:
                viewInventory(p,*n);
                break;

            case 4:
                checkLowStock(p,*n);
                break;

            case 5:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice != 5);
}