#include<stdio.h>
#include "product.h"

int addProduct(struct Product p[], int n)
{
    int i;

    printf("\nEnter details of product %d\n", n + 1);

    printf("Enter product id: ");
    scanf("%d",&p[n].id);

    for(i=0;i<n;i++)
    {
        if(p[i].id == p[n].id)
        {
            printf("Product id already exists\n");
            return 0;
        }
    }

    printf("Enter product name: ");
    scanf("%s",p[n].name);

    printf("Enter category: ");
    scanf("%s",p[n].category);

    printf("Enter price: ");
    scanf("%f",&p[n].price);

    if(p[n].price < 0)
    {
        printf("Price cannot be negative\n");
        return 0;
    }

    printf("Enter stock: ");
    scanf("%d",&p[n].stock);

    if(p[n].stock < 0)
    {
        printf("Stock cannot be negative\n");
        return 0;
    }

    printf("Enter minimum stock: ");
    scanf("%d",&p[n].minStock);

    if(p[n].minStock < 0)
    {
        printf("Minimum stock cannot be negative\n");
        return 0;
    }

    printf("Enter supplier id: ");
    scanf("%d",&p[n].supplierId);

    return 1;
}

void displayProducts(struct Product p[], int n)
{
    int i;

    if(n == 0)
    {
        printf("\nNo products available\n");
        return;
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

            if(p[i].price < 0)
            {
                printf("Price cannot be negative\n");
                return;
            }

            printf("Enter new stock: ");
            scanf("%d",&p[i].stock);

            if(p[i].stock < 0)
            {
                printf("Stock cannot be negative\n");
                return;
            }

            printf("Enter new minimum stock: ");
            scanf("%d",&p[i].minStock);

            if(p[i].minStock < 0)
            {
                printf("Minimum stock cannot be negative\n");
                return;
            }

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

void deleteProduct(struct Product p[], int *n)
{
    int id;
    int i,j;
    int found = 0;

    printf("Enter product id to delete: ");
    scanf("%d",&id);

    for(i=0;i<*n;i++)
    {
        if(p[i].id == id)
        {
            for(j=i;j<*n-1;j++)
            {
                p[j] = p[j+1];
            }

            *n = *n - 1;

            found = 1;

            printf("Product deleted successfully\n");

            break;
        }
    }

    if(found == 0)
    {
        printf("Product not found\n");
    }
}

void productMenu(struct Product p[], int *n)
{
    int choice;

    do
    {
        printf("\n\n");
        printf("=================================\n");
        printf("       PRODUCT MANAGEMENT\n");
        printf("=================================\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Back\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                if(*n < MAX)
                {
                    if(addProduct(p,*n) == 1)
                    {
                        *n = *n + 1;
                    }
                }
                else
                {
                    printf("Product limit reached\n");
                }
                break;

            case 2:
                displayProducts(p,*n);
                break;

            case 3:
                updateProduct(p,*n);
                break;

            case 4:
                deleteProduct(p,n);
                break;

            case 5:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice != 5);
}

void saveProducts(struct Product p[], int n)
{
    FILE *fp;
    int i;

    fp = fopen("products.dat","wb");

    if(fp == NULL)
    {
        printf("Unable to open file\n");
        return;
    }

    for(i=0;i<n;i++)
    {
        fwrite(&p[i],sizeof(struct Product),1,fp);
    }

    fclose(fp);

    printf("Products saved successfully\n");
}

int loadProducts(struct Product p[])
{
    FILE *fp;
    int n = 0;

    fp = fopen("products.dat","rb");

    if(fp == NULL)
    {
        return 0;
    }

    while(n < MAX &&
          fread(&p[n],sizeof(struct Product),1,fp) == 1)
    {
        n++;
    }

    fclose(fp);

    return n;
}