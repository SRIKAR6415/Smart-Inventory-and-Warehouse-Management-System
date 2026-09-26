#include<stdio.h>
#include "product.h"
#include "reports.h"

void displayReports(struct Product p[], int n)
{
    int i;
    int totalStock = 0;
    int lowStock = 0;

    if(n == 0)
    {
        printf("\nNo products available\n");
        return;
    }

    for(i=0;i<n;i++)
    {
        totalStock = totalStock + p[i].stock;

        if(p[i].stock <= p[i].minStock)
        {
            lowStock++;
        }
    }

    printf("\n=================================\n");
    printf("           INVENTORY REPORT\n");
    printf("=================================\n");

    printf("\nTotal Products: %d\n",n);
    printf("Total Stock: %d\n",totalStock);
    printf("Low Stock Products: %d\n",lowStock);

    printf("\nProduct Details\n");

    for(i=0;i<n;i++)
    {
        printf("\nProduct ID: %d\n",p[i].id);
        printf("Product Name: %s\n",p[i].name);
        printf("Stock: %d\n",p[i].stock);
        printf("Minimum Stock: %d\n",p[i].minStock);
    }
}