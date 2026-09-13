
#include <stdio.h>

struct Product
{
    int id;
    char name[50];
    char category[30];
    float price;
    int stock;
    int minStock;
    int supplierId;
};

int main()
{
    struct Product p;

    printf("Enter Product ID: ");
    scanf("%d", &p.id);

    printf("Enter Product Name: ");
    scanf("%s", p.name);

    printf("Enter Category: ");
    scanf("%s", p.category);

    printf("Enter Price: ");
    scanf("%f", &p.price);

    printf("Enter Stock: ");
    scanf("%d", &p.stock);

    printf("Enter Minimum Stock: ");
    scanf("%d", &p.minStock);

    printf("Enter Supplier ID: ");
    scanf("%d", &p.supplierId);

    printf("\n--- Product Details ---\n");

    printf("Product ID: %d\n", p.id);
    printf("Product Name: %s\n", p.name);
    printf("Category: %s\n", p.category);
    printf("Price: %.2f\n", p.price);
    printf("Stock: %d\n", p.stock);
    printf("Minimum Stock: %d\n", p.minStock);
    printf("Supplier ID: %d\n", p.supplierId);

    return 0;
}