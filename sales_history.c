#include<stdio.h>
#include "sales_history.h"

struct Sale sales[MAX_SALES];
int salesCount = 0;

void recordSale(int productId, int quantity)
{
    if(salesCount >= MAX_SALES)
    {
        printf("Sales history is full\n");
        return;
    }

    sales[salesCount].productId = productId;
    sales[salesCount].quantity = quantity;

    salesCount++;
}

void displaySalesHistory()
{
    int i;

    if(salesCount == 0)
    {
        printf("\nNo sales history available\n");
        return;
    }

    printf("\n=================================\n");
    printf("          SALES HISTORY\n");
    printf("=================================\n");

    for(i=0;i<salesCount;i++)
    {
        printf("\nProduct ID: %d\n",sales[i].productId);
        printf("Quantity Sold: %d\n",sales[i].quantity);
    }
}

int getLastThreeSales(int productId,int result[])
{
    int i;
    int count = 0;

    for(i=salesCount-1;i>=0 && count<3;i--)
    {
        if(sales[i].productId == productId)
        {
            result[count] = sales[i].quantity;
            count++;
        }
    }

    return count;
}

int getTotalSales()
{
    int i;
    int total = 0;

    for(i=0;i<salesCount;i++)
    {
        total = total + sales[i].quantity;
    }

    return total;
}

int getSalesCount()
{
    return salesCount;
}

void saveSalesHistory()
{
    FILE *fp;

    fp = fopen("sales.dat","wb");

    if(fp == NULL)
    {
        printf("Unable to save sales history\n");
        return;
    }

    fwrite(&salesCount,sizeof(int),1,fp);
    fwrite(sales,sizeof(struct Sale),salesCount,fp);

    fclose(fp);
}

void loadSalesHistory()
{
    FILE *fp;

    fp = fopen("sales.dat","rb");

    if(fp == NULL)
    {
        return;
    }

    fread(&salesCount,sizeof(int),1,fp);
    fread(sales,sizeof(struct Sale),salesCount,fp);

    fclose(fp);
}