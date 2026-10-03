#include<stdio.h>
#include "product.h"
#include "supplier.h"
#include "inventory.h"
#include "order.h"
#include "search_sort.h"
#include "forecast.h"
#include "reports.h"
#include "sales_history.h"

int main()
{
    struct Product p[MAX];
    int n;
    int choice;

    n = loadProducts(p);

    loadSuppliers();
    loadOrders();
    loadSalesHistory();

    choice = 0;

    while(choice != 12)
    {
        printf("\n\n");
        printf("=================================\n");
        printf("   SMART INVENTORY MANAGEMENT SYSTEM\n");
        printf("=================================\n");
        printf("1. Product Management\n");
        printf("2. Supplier Management\n");
        printf("3. Inventory Management\n");
        printf("4. Order Management\n");
        printf("5. Linear Search\n");
        printf("6. Binary Search\n");
        printf("7. Sort Inventory\n");
        printf("8. Sales History\n");
        printf("9. Low Stock Alerts\n");
        printf("10. Demand Forecasting\n");
        printf("11. Reports\n");
        printf("12. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        if(choice == 1)
        {
            productMenu(p,&n);
        }
        else if(choice == 2)
        {
            supplierMenu();
        }
        else if(choice == 3)
        {
            inventoryMenu(p,&n);
        }
        else if(choice == 4)
        {
            orderMenu(p,n);
        }
        else if(choice == 5)
        {
            searchProduct(p,n);
        }
        else if(choice == 6)
        {
            binarySearch(p,n);
        }
        else if(choice == 7)
        {
            selectionSort(p,n);
        }
        else if(choice == 8)
        {
            displaySalesHistory();
        }
        else if(choice == 9)
        {
            checkLowStock(p,n);
        }
        else if(choice == 10)
        {
            demandForecast(p,n);
        }
        else if(choice == 11)
        {
            displayReports(p,n);
        }
        else if(choice == 12)
        {
            printf("Exiting program...\n");
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    saveProducts(p,n);
    saveSuppliers();
    saveOrders();
    saveSalesHistory();

    return 0;
}