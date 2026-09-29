#include<stdio.h>
#include "product.h"
#include "forecast.h"
#include "sales_history.h"

int getForecast(int productId)
{
    int sales[3];
    int count;
    int total = 0;
    int forecast;
    int i;

    count = getLastThreeSales(productId,sales);

    if(count == 0)
    {
        return 0;
    }

    for(i=0;i<count;i++)
    {
        total = total + sales[i];
    }

    forecast = total / count;

    return forecast;
}

void demandForecast(struct Product p[], int n)
{
    int id;
    int i;
    int found = 0;
    int sales[3];
    int count;
    int forecast;
    int j;

    printf("\nEnter product id: ");
    scanf("%d",&id);

    for(i=0;i<n;i++)
    {
        if(p[i].id == id)
        {
            found = 1;

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

            for(j=0;j<count;j++)
            {
                printf("Sales %d: %d\n",j+1,sales[j]);
            }

            printf("Predicted Demand: %d\n",forecast);

            if(p[i].stock < forecast)
            {
                printf("Restock Suggestion: Yes\n");
                printf("Suggested Quantity: %d\n",forecast-p[i].stock);
            }
            else
            {
                printf("Restock Suggestion: No\n");
            }

            break;
        }
    }

    if(found == 0)
    {
        printf("Product not found\n");
    }
}