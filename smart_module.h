#ifndef SMART_MODULE_H
#define SMART_MODULE_H

#define MAX_SALES 10

struct Product
{
    int id;
    char name[50];
    int stock;
    int sales[MAX_SALES];
    int salesCount;
};

void displaySalesHistory(struct Product p);

float calculateForecast(struct Product p);

void checkLowStock(struct Product p, float forecast);

int calculateTotalSales(struct Product p);

int findHighestSale(struct Product p);

int findLowestSale(struct Product p);

void analyzeTrend(struct Product p);

void performanceAnalysis(struct Product p);

#endif