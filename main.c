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

    do
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

        switch(choice)
        {
            case 1:
                productMenu(p,&n);
                break;

            case 2:
                supplierMenu();
                break;

            case 3:
                inventoryMenu(p,&n);
                break;

            case 4:
                orderMenu(p,n);
                break;

            case 5:
                searchProduct(p,n);
                break;

            case 6:
                binarySearch(p,n);
                break;

            case 7:
                selectionSort(p,n);
                break;

            case 8:
                displaySalesHistory();
                break;

            case 9:
                checkLowStock(p,n);
                break;

            case 10:
                demandForecast(p,n);
                break;

            case 11:
                displayReports(p,n);
                break;

            case 12:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice != 12);

    saveProducts(p,n);
    saveSuppliers();
    saveOrders();
    saveSalesHistory();

    return 0;
}