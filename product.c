#include<stdio.h>
#include<stdlib.h>
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
struct SupplierNode
{
    int id;
    char name[50];
    char phone[20];
    char email[50];
    char address[100];
    struct SupplierNode *next;
};
struct SupplierNode *head = NULL;
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
                    addProduct(p,*n);
                    *n = *n + 1;
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
void addSupplier()
{
    struct SupplierNode *temp;

    temp = (struct SupplierNode *)malloc(sizeof(struct SupplierNode));

    printf("\nEnter supplier id: ");
    scanf("%d",&temp->id);

    printf("Enter supplier name: ");
    scanf("%s",temp->name);

    printf("Enter phone: ");
    scanf("%s",temp->phone);

    printf("Enter email: ");
    scanf("%s",temp->email);

    printf("Enter address: ");
    scanf("%s",temp->address);

    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        struct SupplierNode *p;

        p = head;

        while(p->next != NULL)
        {
            p = p->next;
        }

        p->next = temp;
    }

    printf("Supplier added successfully\n");
}
void displaySuppliers()
{
    struct SupplierNode *p;

    if(head == NULL)
    {
        printf("No suppliers available\n");
        return;
    }

    p = head;

    printf("\nSupplier Details\n");

    while(p != NULL)
    {
        printf("\nSupplier ID: %d\n",p->id);
        printf("Name: %s\n",p->name);
        printf("Phone: %s\n",p->phone);
        printf("Email: %s\n",p->email);
        printf("Address: %s\n",p->address);

        p = p->next;
    }
}
void searchSupplier()
{
    struct SupplierNode *p;
    int id;
    int found = 0;

    printf("\nEnter supplier id to search: ");
    scanf("%d",&id);

    p = head;

    while(p != NULL)
    {
        if(p->id == id)
        {
            printf("\nSupplier found\n");
            printf("Supplier ID: %d\n",p->id);
            printf("Name: %s\n",p->name);
            printf("Phone: %s\n",p->phone);
            printf("Email: %s\n",p->email);
            printf("Address: %s\n",p->address);

            found = 1;
            break;
        }

        p = p->next;
    }

    if(found == 0)
    {
        printf("Supplier not found\n");
    }
}
void deleteSupplier()
{
    struct SupplierNode *p;
    struct SupplierNode *prev;
    int id;
    int found = 0;

    printf("\nEnter supplier id to delete: ");
    scanf("%d",&id);

    p = head;
    prev = NULL;

    while(p != NULL)
    {
        if(p->id == id)
        {
            if(prev == NULL)
            {
                head = p->next;
            }
            else
            {
                prev->next = p->next;
            }

            free(p);

            found = 1;

            printf("Supplier deleted successfully\n");

            break;
        }

        prev = p;
        p = p->next;
    }

    if(found == 0)
    {
        printf("Supplier not found\n");
    }
}
void supplierMenu()
{
    int choice;

    do
    {
        printf("\n\n");
        printf("=================================\n");
        printf("       SUPPLIER MANAGEMENT\n");
        printf("=================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Delete Supplier\n");
        printf("5. Back\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addSupplier();
                break;

            case 2:
                displaySuppliers();
                break;

            case 3:
                searchSupplier();
                break;

            case 4:
                deleteSupplier();
                break;

            case 5:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice != 5);
}
void addStock(struct Product p[], int n)
{
    int id;
    int quantity;
    int i;
    int found = 0;

    printf("\nEnter product id: ");
    scanf("%d",&id);

    for(i=0;i<n;i++)
    {
        if(p[i].id == id)
        {
            printf("Enter quantity to add: ");
            scanf("%d",&quantity);

            p[i].stock = p[i].stock + quantity;

            printf("Stock added successfully\n");
            printf("Current stock: %d\n",p[i].stock);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Product not found\n");
    }
}
void removeStock(struct Product p[], int n)
{
    int id;
    int quantity;
    int i;
    int found = 0;

    printf("\nEnter product id: ");
    scanf("%d",&id);

    for(i=0;i<n;i++)
    {
        if(p[i].id == id)
        {
            printf("Enter quantity to remove: ");
            scanf("%d",&quantity);

            if(quantity <= p[i].stock)
            {
                p[i].stock = p[i].stock - quantity;

                printf("Stock removed successfully\n");
                printf("Current stock: %d\n",p[i].stock);
            }
            else
            {
                printf("Not enough stock available\n");
            }

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Product not found\n");
    }
}
void viewInventory(struct Product p[], int n)
{
    int i;

    if(n == 0)
    {
        printf("\nNo products available\n");
        return;
    }

    printf("\n=================================\n");
    printf("          INVENTORY\n");
    printf("=================================\n");

    for(i=0;i<n;i++)
    {
        printf("\nProduct ID: %d\n",p[i].id);
        printf("Product Name: %s\n",p[i].name);
        printf("Category: %s\n",p[i].category);
        printf("Current Stock: %d\n",p[i].stock);
        printf("Minimum Stock: %d\n",p[i].minStock);
    }
}
void checkLowStock(struct Product p[], int n)
{
    int i;
    int found = 0;

    printf("\n=================================\n");
    printf("         LOW STOCK ALERT\n");
    printf("=================================\n");

    for(i=0;i<n;i++)
    {
        if(p[i].stock <= p[i].minStock)
        {
            printf("\nProduct ID: %d\n",p[i].id);
            printf("Product Name: %s\n",p[i].name);
            printf("Current Stock: %d\n",p[i].stock);
            printf("Minimum Stock: %d\n",p[i].minStock);

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("\nNo low stock products\n");
    }
}
void inventoryMenu(struct Product p[], int *n)
{
    int choice;

    do
    {
        printf("\n\n");
        printf("=================================\n");
        printf("       INVENTORY MANAGEMENT\n");
        printf("=================================\n");
        printf("1. Add Stock\n");
        printf("2. Remove Stock\n");
        printf("3. View Inventory\n");
        printf("4. Check Low Stock\n");
        printf("5. Back\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addStock(p,*n);
                break;

            case 2:
                removeStock(p,*n);
                break;

            case 3:
                viewInventory(p,*n);
                break;

            case 4:
                checkLowStock(p,*n);
                break;

            case 5:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice != 5);
}

int main()
{
    struct Product p[MAX];
    int n = 0;

    //productMenu(p,&n);
    //supplierMenu();

    addProduct(p,n);
    n = n + 1;

    inventoryMenu(p,&n);

    return 0;
}