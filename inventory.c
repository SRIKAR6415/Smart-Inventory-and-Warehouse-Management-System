#include<stdio.h>
#include "product.h"
#include "inventory.h"
#include "forecast.h"

void addStock(struct Product p[], int n)
{
    int id;
    int qty;
    int i;

    printf("\nEnter product id: ");
    scanf("%d",&id);

    for(i=0;i<n;i++)
    {
        if(p[i].id == id)
        {
            printf("Enter quantity to add: ");
            scanf("%d",&qty);

            if(qty > 0)
            {
                p[i].stock = p[i].stock + qty;

                printf("Stock added successfully\n");
                printf("Current stock: %d\n",p[i].stock);
            }
            else
            {
                printf("Quantity must be greater than zero\n");
            }

            return;
        }
    }

    printf("Product not found\n");
}

void removeStock(struct Product p[], int n)
{
    int id;
    int qty;
    int i;

    printf("\nEnter product id: ");
    scanf("%d",&id);

    for(i=0;i<n;i++)
    {
        if(p[i].id == id)
        {
            printf("Enter quantity to remove: ");
            scanf("%d",&qty);

            if(qty <= 0)
            {
                printf("Quantity must be greater than zero\n");
                return;
            }

            if(qty > p[i].stock)
            {
                printf("Not enough stock available\n");
                return;
            }

            p[i].stock = p[i].stock - qty;

            printf("Stock removed successfully\n");
            printf("Current stock: %d\n",p[i].stock);

            return;
        }
    }

    printf("Product not found\n");
}

void viewInventory(struct Product p[], int n)
{
    int i;

    if(n <= 0)
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
    int demand;
    int need;
    int low = 0;

    printf("\n=================================\n");
    printf("       LOW STOCK INTELLIGENCE\n");
    printf("=================================\n");

    for(i=0;i<n;i++)
    {
        if(p[i].stock <= p[i].minStock)
        {
            low = 1;
            demand = getForecast(p[i].id);

            printf("\nProduct ID: %d\n",p[i].id);
            printf("Product Name: %s\n",p[i].name);
            printf("Current Stock: %d\n",p[i].stock);
            printf("Minimum Stock: %d\n",p[i].minStock);

            if(demand == 0)
            {
                need = p[i].minStock - p[i].stock;

                printf("Predicted Demand: No data\n");
                printf("Status: LOW STOCK\n");
                printf("Suggested Restock Quantity: %d\n",need);
            }
            else
            {
                printf("Predicted Demand: %d\n",demand);

                if(demand > p[i].stock)
                {
                    need = demand - p[i].stock;

                    printf("Status: CRITICAL\n");
                    printf("Suggested Restock Quantity: %d\n",need);
                }
                else
                {
                    printf("Status: LOW STOCK\n");
                    printf("Suggested Restock Quantity: 0\n");
                }
            }
        }
    }

    if(low == 0)
    {
        printf("\nNo low stock products\n");
    }
}

void inventoryMenu(struct Product p[], int *n)
{
    int choice;

    choice = 0;

    while(choice != 5)
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

        if(choice == 1)
        {
            addStock(p,*n);
        }
        else if(choice == 2)
        {
            removeStock(p,*n);
        }
        else if(choice == 3)
        {
            viewInventory(p,*n);
        }
        else if(choice == 4)
        {
            checkLowStock(p,*n);
        }
        else if(choice == 5)
        {
            printf("Returning to main menu...\n");
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
}