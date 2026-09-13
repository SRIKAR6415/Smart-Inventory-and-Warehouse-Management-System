#include<stdio.h>

#define MAX 100

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
    struct Product p[MAX];
    int n,i;

    printf("Enter number of products: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter details of product %d\n",i+1);

        printf("Enter product id: ");
        scanf("%d",&p[i].id);

        printf("Enter product name: ");
        scanf("%s",p[i].name);

        printf("Enter category: ");
        scanf("%s",p[i].category);

        printf("Enter price: ");
        scanf("%f",&p[i].price);

        printf("Enter stock: ");
        scanf("%d",&p[i].stock);

        printf("Enter minimum stock: ");
        scanf("%d",&p[i].minStock);

        printf("Enter supplier id: ");
        scanf("%d",&p[i].supplierId);
    }

    printf("\nProduct Details\n");

    for(i=0;i<n;i++)
    {
        printf("\nProduct %d\n",i+1);
        printf("Id: %d\n",p[i].id);
        printf("Name: %s\n",p[i].name);
        printf("Category: %s\n",p[i].category);
        printf("Price: %.2f\n",p[i].price);
        printf("Stock: %d\n",p[i].stock);
        printf("Minimum Stock: %d\n",p[i].minStock);
        printf("Supplier Id: %d\n",p[i].supplierId);
    }

    return 0;
}