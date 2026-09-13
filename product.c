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
void updateProduct(struct Product p[], int n)
{
    int id;
    int i;
    int found = 0;

    printf("Enter product id to update: ");
    scanf("%d",&id);

    for(i=0;i<n;i++)
    {
        if(p[i].id == id)
        {
            printf("Enter new product name: ");
            scanf("%s",p[i].name);

            printf("Enter new category: ");
            scanf("%s",p[i].category);

            printf("Enter new price: ");
            scanf("%f",&p[i].price);

            printf("Enter new stock: ");
            scanf("%d",&p[i].stock);

            printf("Enter new minimum stock: ");
            scanf("%d",&p[i].minStock);

            printf("Enter new supplier id: ");
            scanf("%d",&p[i].supplierId);

            found = 1;

            printf("Product updated successfully\n");

            break;
        }
    }

    if(found == 0)
    {
        printf("Product not found\n");
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
    updateProduct(p,n);
    displayProducts(p,n);

    return 0;
}