#ifndef SALES_HISTORY_H
#define SALES_HISTORY_H

#define MAX_SALES 100

struct Sale
{
    int productId;
    int quantity;
};

void recordSale(int productId, int quantity);
void displaySalesHistory();
int getLastThreeSales(int productId,int sales[]);
int getTotalSales();
int getSalesCount();
void saveSalesHistory();
void loadSalesHistory();

#endif