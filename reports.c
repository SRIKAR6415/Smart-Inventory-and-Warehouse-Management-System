#include<stdio.h>
#include "product.h"
#include "reports.h"
#include "sales_history.h"
#include "forecast.h"

void displayReports(struct Product p[], int n)
{
    int i;
    int totalStock = 0;
    int lowStock = 0;
    int totalSales = 0;
    int salesCount = 0;
    int sales[3];
    int count;
    int forecast;
    int j;

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

    printf("\n=================================\n");
    printf("        SALES PERFORMANCE\n");
    printf("=================================\n");

    totalSales = getTotalSales();
    salesCount = getSalesCount();

    printf("\nRecorded Sales Quantity: %d\n",totalSales);

    if(salesCount > 0)
    {
        printf("Average Sale Quantity: %d\n",
               totalSales/salesCount);
    }
    else
    {
        printf("Average Sale Quantity: No data\n");
    }

    printf("\n=================================\n");
    printf("       PRODUCT PERFORMANCE\n");
    printf("=================================\n");

    for(i=0;i<n;i++)
    {
        printf("\nProduct ID: %d\n",p[i].id);
        printf("Product Name: %s\n",p[i].name);
        printf("Current Stock: %d\n",p[i].stock);
        printf("Minimum Stock: %d\n",p[i].minStock);

        forecast = getForecast(p[i].id);

        if(forecast > 0)
        {
            printf("Predicted Demand: %d\n",forecast);

            if(p[i].stock < forecast)
            {
                printf("Restock Required: Yes\n");
                printf("Suggested Quantity: %d\n",
                       forecast-p[i].stock);
            }
            else
            {
                printf("Restock Required: No\n");
            }
        }
        else
        {
            printf("Predicted Demand: No data\n");

            if(p[i].stock <= p[i].minStock)
            {
                printf("Restock Required: Yes\n");
                printf("Suggested Quantity: %d\n",
                       p[i].minStock-p[i].stock);
            }
            else
            {
                printf("Restock Required: No\n");
            }
        }
    }
}