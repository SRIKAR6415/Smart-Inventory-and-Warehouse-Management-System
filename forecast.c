#include<stdio.h>
#include "product.h"
#include "forecast.h"

void demandForecast(struct Product p[], int n)
{
    int id;
    int i;
    int found = 0;
    int sales1;
    int sales2;
    int sales3;
    int forecast;

    printf("\nEnter product id: ");
    scanf("%d",&id);

    for(i=0;i<n;i++)
    {
        if(p[i].id == id)
        {
            found = 1;

            printf("Enter sales for last period: ");
            scanf("%d",&sales1);

            printf("Enter sales for second last period: ");
            scanf("%d",&sales2);

            printf("Enter sales for third last period: ");
            scanf("%d",&sales3);

            if(sales1 < 0 || sales2 < 0 || sales3 < 0)
            {
                printf("Sales cannot be negative\n");
                return;
            }

            forecast = (sales1 + sales2 + sales3) / 3;

            printf("\nProduct Name: %s\n",p[i].name);
            printf("Current Stock: %d\n",p[i].stock);
            printf("Predicted Demand: %d\n",forecast);

            if(p[i].stock < forecast)
            {
                printf("Restock Suggestion: Yes\n");
                printf("Suggested Quantity: %d\n",forecast - p[i].stock);
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