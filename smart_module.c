#include <stdio.h>
#include "smart_module.h"

/* Display previous sales */
void displaySalesHistory(struct Product p)
{
    printf("\nSales History for %s:\n", p.name);

    for (int i = 0; i < p.salesCount; i++)
    {
        printf("%d ", p.sales[i]);
    }

    printf("\n");
}

/* Calculate average sales / demand forecast */
float calculateForecast(struct Product p)
{
    int sum = 0;

    for (int i = 0; i < p.salesCount; i++)
    {
        sum += p.sales[i];
    }

    return (float)sum / p.salesCount;
}

/* Check whether stock is low */
void checkLowStock(struct Product p, float forecast)
{
    printf("\n--- Stock Analysis ---\n");

    if (p.stock < forecast)
    {
        int shortage = (int)forecast - p.stock;

        printf("WARNING: LOW STOCK!\n");
        printf("Current Stock: %d\n", p.stock);
        printf("Expected Demand: %.2f\n", forecast);
        printf("Suggested Additional Stock: %d\n", shortage);
    }
    else
    {
        printf("Stock is sufficient.\n");
        printf("Current Stock: %d\n", p.stock);
        printf("Expected Demand: %.2f\n", forecast);
    }
}

/* Calculate total sales */
int calculateTotalSales(struct Product p)
{
    int total = 0;

    for (int i = 0; i < p.salesCount; i++)
    {
        total += p.sales[i];
    }

    return total;
}

/* Find highest sale */
int findHighestSale(struct Product p)
{
    int highest = p.sales[0];

    for (int i = 1; i < p.salesCount; i++)
    {
        if (p.sales[i] > highest)
        {
            highest = p.sales[i];
        }
    }

    return highest;
}

/* Find lowest sale */
int findLowestSale(struct Product p)
{
    int lowest = p.sales[0];

    for (int i = 1; i < p.salesCount; i++)
    {
        if (p.sales[i] < lowest)
        {
            lowest = p.sales[i];
        }
    }

    return lowest;
}

/* Analyze sales trend */
void analyzeTrend(struct Product p)
{
    if (p.sales[p.salesCount - 1] > p.sales[0])
    {
        printf("Sales Trend: Increasing\n");
    }
    else if (p.sales[p.salesCount - 1] < p.sales[0])
    {
        printf("Sales Trend: Decreasing\n");
    }
    else
    {
        printf("Sales Trend: Stable\n");
    }
}

/* Performance analysis */
void performanceAnalysis(struct Product p)
{
    printf("\n--- Performance Analysis ---\n");

    printf("Total Sales: %d\n", calculateTotalSales(p));
    printf("Highest Sale: %d\n", findHighestSale(p));
    printf("Lowest Sale: %d\n", findLowestSale(p));

    analyzeTrend(p);
}

/* Main function for testing */
int main()
{
    struct Product p;

    p.id = 101;

    snprintf(p.name, sizeof(p.name), "Laptop");

    p.stock = 8;

    p.sales[0] = 10;
    p.sales[1] = 12;
    p.sales[2] = 15;
    p.sales[3] = 18;
    p.sales[4] = 20;

    p.salesCount = 5;

    printf("====================================\n");
    printf("     SMART INVENTORY ANALYSIS\n");
    printf("====================================\n");

    printf("\nProduct ID: %d\n", p.id);
    printf("Product Name: %s\n", p.name);
    printf("Current Stock: %d\n", p.stock);

    displaySalesHistory(p);

    float forecast = calculateForecast(p);

    printf("\nPredicted Demand: %.2f units\n", forecast);

    checkLowStock(p, forecast);

    performanceAnalysis(p);

    printf("\n====================================\n");

    return 0;
}