#include<stdio.h>
#include "product.h"
#include "forecast.h"
#include "sales_history.h"

int getForecast(int productId)
{
    int sales[3];
    int count;
    int total;
    int i;

    total = 0;

    count = getLastThreeSales(productId,sales);

    if(count == 0)
    {
        return 0;
    }

    for(i=0;i<count;i++)
    {
        total = total + sales[i];
    }

    return total/count;
}

void demandForecast(struct Product p[], int n)
{
    int id;
    int i,j;
    int sales[3];
    int count;
    int forecast;
    int quantity;

    printf("\nEnter product id: ");
    scanf("%d",&id);

    for(i=0;i<n;i++)
    {
        if(p[i].id == id)
        {
            count = getLastThreeSales(id,sales);

            if(count == 0)
            {
                printf("\nNo sales history available for this product\n");
                return;
            }

            forecast = getForecast(id);

            printf("\nProduct Name: %s\n",p[i].name);
            printf("Current Stock: %d\n",p[i].stock);
            printf("Sales History Used: %d periods\n",count);

            for(i=0;i<count;i++)
            {
                printf("Sales %d: %d\n",i+1,sales[i]);
            }

            printf("Predicted Demand: %d\n",forecast);

            if(p[i].stock < forecast)
            {
                quantity = forecast-p[i].stock;

                printf("Restock Suggestion: Yes\n");
                printf("Suggested Quantity: %d\n",quantity);
            }
            else
            {
                printf("Restock Suggestion: No\n");
            }

            return;
        }
    }

    printf("Product not found\n");
}