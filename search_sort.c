#include<stdio.h>
#include "product.h"
#include "search_sort.h"

void searchProduct(struct Product p[], int n)
{
    int id;
    int i;
    int found = 0;

    printf("\nEnter product id to search: ");
    scanf("%d",&id);

    for(i=0;i<n;i++)
    {
        if(p[i].id == id)
        {
            printf("\nProduct found\n");
            printf("Product ID: %d\n",p[i].id);
            printf("Product Name: %s\n",p[i].name);
            printf("Category: %s\n",p[i].category);
            printf("Price: %.2f\n",p[i].price);
            printf("Stock: %d\n",p[i].stock);
            printf("Minimum Stock: %d\n",p[i].minStock);
            printf("Supplier ID: %d\n",p[i].supplierId);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Product not found\n");
    }
}

void selectionSort(struct Product p[], int n)
{
    int i;
    int j;
    int min;
    struct Product temp;

    for(i=0;i<n-1;i++)
    {
        min = i;

        for(j=i+1;j<n;j++)
        {
            if(p[j].stock < p[min].stock)
            {
                min = j;
            }
        }

        if(min != i)
        {
            temp = p[i];
            p[i] = p[min];
            p[min] = temp;
        }
    }

    printf("\nInventory sorted by stock\n");

    for(i=0;i<n;i++)
    {
        printf("\nProduct ID: %d\n",p[i].id);
        printf("Product Name: %s\n",p[i].name);
        printf("Stock: %d\n",p[i].stock);
    }
}