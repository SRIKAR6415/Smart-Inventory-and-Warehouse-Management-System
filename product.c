#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
void selectionSort(struct Product p[], int n);
struct SupplierNode
{
    int id;
    char name[50];
    char phone[20];
    char email[50];
    char address[100];
    struct SupplierNode *next;
};
struct OrderNode
{
    int orderId;
    int productId;
    int quantity;
    char type[20];
    char status[20];
    struct OrderNode *next;
};
struct OrderNode *front = NULL;
struct OrderNode *rear = NULL;
struct SupplierNode *head = NULL;

void addProduct(struct Product p[], int n)
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
        return;
    }
}

    printf("Enter product name: ");
    scanf("%s",p[n].name);

    printf("Enter category: ");
    scanf("%s",p[n].category);

    printf("Enter price: ");
    scanf("%f",&p[n].price);

    printf("Enter stock: ");
scanf("%d",&p[n].stock);

if(p[n].stock < 0)
{
    printf("Stock cannot be negative\n");
    return;
}

   printf("Enter minimum stock: ");
scanf("%d",&p[n].minStock);

if(p[n].minStock < 0)
{
    printf("Minimum stock cannot be negative\n");
    return;
}

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
void saveSuppliers()
{
    FILE *fp;
    struct SupplierNode *p;

    fp = fopen("suppliers.dat","wb");

    if(fp == NULL)
    {
        printf("Unable to open file\n");
        return;
    }

    p = head;

    while(p != NULL)
    {
        fwrite(p,sizeof(struct SupplierNode),1,fp);
        p = p->next;
    }

    fclose(fp);

    printf("Suppliers saved successfully\n");
}
void loadSuppliers()
{
    FILE *fp;
    struct SupplierNode temp;
    struct SupplierNode *newNode;
    struct SupplierNode *p;

    fp = fopen("suppliers.dat","rb");

    if(fp == NULL)
    {
        return;
    }

    while(fread(&temp,sizeof(struct SupplierNode),1,fp) == 1)
    {
        newNode = (struct SupplierNode *)malloc(sizeof(struct SupplierNode));

        if(newNode == NULL)
        {
            printf("Memory allocation failed\n");
            fclose(fp);
            return;
        }

        newNode->id = temp.id;
        strcpy(newNode->name,temp.name);
        strcpy(newNode->phone,temp.phone);
        strcpy(newNode->email,temp.email);
        strcpy(newNode->address,temp.address);

        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            p = head;

            while(p->next != NULL)
            {
                p = p->next;
            }

            p->next = newNode;
        }
    }

    fclose(fp);
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
            if(quantity <= 0)
{
    printf("Quantity must be greater than zero\n");
    return;
}

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
            if(quantity <= 0)
{
    printf("Quantity must be greater than zero\n");
    return;
}

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
void linearSearch(struct Product p[], int n)
{
    int id;
    int i;
    int found = 0;

    printf("\nEnter product id to search: ");
    scanf("%d",&id);

    for(i=0;i<n;i++)
    {
        if(p[i].id == id)
        {
            printf("\nProduct found\n");
            printf("Id: %d\n",p[i].id);
            printf("Name: %s\n",p[i].name);
            printf("Category: %s\n",p[i].category);
            printf("Price: %.2f\n",p[i].price);
            printf("Stock: %d\n",p[i].stock);
            printf("Minimum Stock: %d\n",p[i].minStock);
            printf("Supplier Id: %d\n",p[i].supplierId);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nProduct not found\n");
    }
}
void binarySearch(struct Product p[], int n)
{
    selectionSort(p,n); // Ensure the array is sorted before binary search
    int id;
    int low = 0;
    int high = n - 1;
    int mid;
    int found = 0;

    printf("\nEnter product id to search: ");
    scanf("%d",&id);

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(p[mid].id == id)
        {
            printf("\nProduct found\n");
            printf("Id: %d\n",p[mid].id);
            printf("Name: %s\n",p[mid].name);
            printf("Category: %s\n",p[mid].category);
            printf("Price: %.2f\n",p[mid].price);
            printf("Stock: %d\n",p[mid].stock);
            printf("Minimum Stock: %d\n",p[mid].minStock);
            printf("Supplier Id: %d\n",p[mid].supplierId);

            found = 1;
            break;
        }
        else if(id < p[mid].id)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if(found == 0)
    {
        printf("\nProduct not found\n");
    }
}
void searchMenu(struct Product p[], int n)
{
    int choice;

    do
    {
        printf("\n\n");
        printf("=================================\n");
        printf("        SEARCH PRODUCT\n");
        printf("=================================\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Back\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                linearSearch(p,n);
                break;

            case 2:
                binarySearch(p,n);
                break;

            case 3:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice != 3);
}
void selectionSort(struct Product p[], int n)
{
    int i,j,min;
    struct Product temp;

    for(i=0;i<n-1;i++)
    {
        min = i;

        for(j=i+1;j<n;j++)
        {
            if(p[j].id < p[min].id)
            {
                min = j;
            }
        }

        if(min != i)
        {
            temp = p[i];
            p[i] = p[min];
            p[min] = temp;
        }
    }

    printf("\nProducts sorted by Product ID\n");
}
void selectionSortPrice(struct Product p[], int n)
{
    int i,j,min;
    struct Product temp;

    for(i=0;i<n-1;i++)
    {
        min = i;

        for(j=i+1;j<n;j++)
        {
            if(p[j].price < p[min].price)
            {
                min = j;
            }
        }

        if(min != i)
        {
            temp = p[i];
            p[i] = p[min];
            p[min] = temp;
        }
    }

    printf("\nProducts sorted by Price\n");
}
void selectionSortStock(struct Product p[], int n)
{
    int i,j,min;
    struct Product temp;

    for(i=0;i<n-1;i++)
    {
        min = i;

        for(j=i+1;j<n;j++)
        {
            if(p[j].stock < p[min].stock)
            {
                min = j;
            }
        }

        if(min != i)
        {
            temp = p[i];
            p[i] = p[min];
            p[min] = temp;
        }
    }

    printf("\nProducts sorted by Stock\n");
}
void selectionSortName(struct Product p[], int n)
{
    int i,j,min;
    struct Product temp;

    for(i=0;i<n-1;i++)
    {
        min = i;

        for(j=i+1;j<n;j++)
        {
            if(strcmp(p[j].name,p[min].name) < 0)
            {
                min = j;
            }
        }

        if(min != i)
        {
            temp = p[i];
            p[i] = p[min];
            p[min] = temp;
        }
    }

    printf("\nProducts sorted by Name\n");
}
void sortMenu(struct Product p[], int n)
{
    int choice;

    do
    {
        printf("\n\n");
        printf("=================================\n");
        printf("        SORT INVENTORY\n");
        printf("=================================\n");
        printf("1. Sort by Product ID\n");
        printf("2. Sort by Price\n");
        printf("3. Sort by Stock\n");
        printf("4. Sort by Name\n");
        printf("5. Back\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
          case 1:
    selectionSort(p,n);
    displayProducts(p,n);
    break;

case 2:
    selectionSortPrice(p,n);
    displayProducts(p,n);
    break;

case 3:
    selectionSortStock(p,n);
    displayProducts(p,n);
    break;

case 4:
    selectionSortName(p,n);
    displayProducts(p,n);
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

    while(fread(&p[n],sizeof(struct Product),1,fp) == 1)
    {
        n++;
    }

    fclose(fp);

    return n;
}
void placeOrder()
{
    struct OrderNode *temp;

    temp = (struct OrderNode *)malloc(sizeof(struct OrderNode));

    if(temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("\nEnter order id: ");
    scanf("%d",&temp->orderId);

    printf("Enter product id: ");
    scanf("%d",&temp->productId);

    printf("Enter quantity: ");
scanf("%d",&temp->quantity);

if(temp->quantity <= 0)
{
    printf("Quantity must be greater than zero\n");
    free(temp);
    return;
}

    printf("Enter order type: ");
scanf("%s",temp->type);

if(strcmp(temp->type,"Incoming") != 0 &&
   strcmp(temp->type,"incoming") != 0 &&
   strcmp(temp->type,"Outgoing") != 0 &&
   strcmp(temp->type,"outgoing") != 0)
{
    printf("Invalid order type\n");
    free(temp);
    return;
}
    strcpy(temp->status,"Pending");

    temp->next = NULL;

    if(front == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }

    printf("Order placed successfully\n");
}
void processOrder(struct Product p[], int n)
{
    struct OrderNode *temp;
    int i;
    int found = 0;
    int success = 0;

    if(front == NULL)
    {
        printf("\nNo pending orders\n");
        return;
    }

    temp = front;

    printf("\nProcessing Order\n");
    printf("Order ID: %d\n",temp->orderId);
    printf("Product ID: %d\n",temp->productId);
    printf("Quantity: %d\n",temp->quantity);
    printf("Order Type: %s\n",temp->type);

    for(i=0;i<n;i++)
    {
        if(p[i].id == temp->productId)
        {
            found = 1;

            if(strcmp(temp->type,"Outgoing") == 0 ||
               strcmp(temp->type,"outgoing") == 0)
            {
                if(temp->quantity <= p[i].stock)
                {
                    p[i].stock = p[i].stock - temp->quantity;

                    printf("Stock updated successfully\n");
                    printf("Current stock: %d\n",p[i].stock);

                    if(p[i].stock <= p[i].minStock)
{
    printf("LOW STOCK ALERT\n");
    printf("Product %s is below minimum stock level\n",p[i].name);
}

                    success = 1;
                }
                else
                {
                    printf("Not enough stock available\n");
                }
            }
            else if(strcmp(temp->type,"Incoming") == 0 ||
                    strcmp(temp->type,"incoming") == 0)
            {
                p[i].stock = p[i].stock + temp->quantity;

                printf("Stock updated successfully\n");
                printf("Current stock: %d\n",p[i].stock);

                success = 1;
            }
            else
            {
                printf("Invalid order type\n");
            }

            break;
        }
    }

    if(found == 0)
    {
        printf("Product not found\n");
    }

    if(success == 1)
    {
        front = front->next;

        if(front == NULL)
        {
            rear = NULL;
        }

        free(temp);

        printf("Order processed successfully\n");
    }
    else
    {
        printf("Order remains pending\n");
    }
}
void displayOrders()
{
    struct OrderNode *p;

    if(front == NULL)
    {
        printf("\nNo pending orders\n");
        return;
    }

    p = front;

    printf("\n=================================\n");
    printf("        PENDING ORDERS\n");
    printf("=================================\n");

    while(p != NULL)
    {
        printf("\nOrder ID: %d\n",p->orderId);
        printf("Product ID: %d\n",p->productId);
        printf("Quantity: %d\n",p->quantity);
        printf("Order Type: %s\n",p->type);
        printf("Status: %s\n",p->status);

        p = p->next;
    }
}
void orderMenu(struct Product p[], int n)
{
    int choice;

    do
    {
        printf("\n\n");
        printf("=================================\n");
        printf("        ORDER MANAGEMENT\n");
        printf("=================================\n");
        printf("1. Place Order\n");
        printf("2. Process Order\n");
        printf("3. Display Pending Orders\n");
        printf("4. Back\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                placeOrder();
                break;

            case 2:
                processOrder(p, n);
                break;

            case 3:
                displayOrders();
                break;

            case 4:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice != 4);
}
void saveOrders()
{
    FILE *fp;
    struct OrderNode *p;

    fp = fopen("orders.dat","wb");

    if(fp == NULL)
    {
        printf("Unable to open file\n");
        return;
    }

    p = front;

    while(p != NULL)
    {
        fwrite(p,sizeof(struct OrderNode),1,fp);
        p = p->next;
    }

    fclose(fp);

    printf("Orders saved successfully\n");
}
void loadOrders()
{
    FILE *fp;
    struct OrderNode temp;
    struct OrderNode *newNode;

    fp = fopen("orders.dat","rb");

    if(fp == NULL)
    {
        return;
    }

    while(fread(&temp,sizeof(struct OrderNode),1,fp) == 1)
    {
        newNode = (struct OrderNode *)malloc(sizeof(struct OrderNode));

        if(newNode == NULL)
        {
            printf("Memory allocation failed\n");
            fclose(fp);
            return;
        }

        newNode->orderId = temp.orderId;
        newNode->productId = temp.productId;
        newNode->quantity = temp.quantity;
        strcpy(newNode->type,temp.type);
        strcpy(newNode->status,temp.status);

        newNode->next = NULL;

        if(front == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    fclose(fp);
}
void demandForecast()
{
    int sales[3];
    int i;
    float average;

    printf("\nEnter sales for last 3 periods:\n");

    for(i=0;i<3;i++)
    {
        printf("Enter sales %d: ",i+1);
        scanf("%d",&sales[i]);
    }

    average = (sales[0] + sales[1] + sales[2]) / 3.0;

    printf("\nDemand Forecast = %.2f\n",average);

    if(average > 0)
    {
        printf("Suggested action: Check stock and plan restocking.\n");
    }
}
void generateReport(struct Product p[], int n)
{
    int i;
    int totalStock = 0;
    int lowStock = 0;
    int pendingOrders = 0;

    for(i=0;i<n;i++)
    {
        totalStock = totalStock + p[i].stock;

        if(p[i].stock <= p[i].minStock)
        {
            lowStock++;
        }
    }

    struct OrderNode *temp;
    temp = front;

    while(temp != NULL)
    {
        if(strcmp(temp->status,"Pending") == 0)
        {
            pendingOrders++;
        }

        temp = temp->next;
    }

    printf("\n========== INVENTORY REPORT ==========\n");
    printf("Total Products       : %d\n",n);
    printf("Total Stock          : %d\n",totalStock);
    printf("Low Stock Products   : %d\n",lowStock);
    printf("Pending Orders       : %d\n",pendingOrders);
    printf("======================================\n");
}

int main()
{
    struct Product p[MAX];
    int n;
    int choice;

    n = loadProducts(p);
    loadSuppliers();
    loadOrders();

    do
    {
        printf("\n\n");
        printf("=================================\n");
        printf(" SMART INVENTORY MANAGEMENT SYSTEM\n");
        printf("=================================\n");
        printf("1. Product Management\n");
        printf("2. Supplier Management\n");
        printf("3. Inventory Management\n");
        printf("4. Order Management\n");
        printf("5. Search Product\n");
        printf("6. Sort Inventory\n");
        printf("7. Low Stock Alerts\n");
        printf("8. Demand Forecasting\n");
        printf("9. Reports\n");
        printf("10. Exit\n");
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
                searchMenu(p,n);
                break;

            case 6:
                sortMenu(p,n);
                break;

            case 7:
                checkLowStock(p,n);
                break;

            case 8:
                demandForecast();
                break;

            case 9:
                generateReport(p,n);
                break;

            case 10:
                saveProducts(p,n);
                saveSuppliers();
                saveOrders();
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice != 10);

    return 0;
}