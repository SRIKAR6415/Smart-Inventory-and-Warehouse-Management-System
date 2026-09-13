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
void addProduct(struct Product p[], int n)
{
    printf("\nEnter details of product %d\n", n + 1);

    printf("Enter product id: ");
    scanf("%d",&p[n].id);

    printf("Enter product name: ");
    scanf("%s",p[n].name);

    printf("Enter category: ");
    scanf("%s",p[n].category);

    printf("Enter price: ");
    scanf("%f",&p[n].price);

    printf("Enter stock: ");
    scanf("%d",&p[n].stock);

    printf("Enter minimum stock: ");
    scanf("%d",&p[n].minStock);

    printf("Enter supplier id: ");
    scanf("%d",&p[n].supplierId);
}
void displayProducts(struct Product p[], int n)
{
    int i;

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
}

int main()
{
    struct Product p[MAX];
    int n,i;

    printf("Enter number of products: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        addProduct(p,i);
    }
    displayProducts(p,n);
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