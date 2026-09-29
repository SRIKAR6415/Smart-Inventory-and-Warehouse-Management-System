#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "product.h"
#include "order.h"
#include "sales_history.h"

struct OrderNode *front = NULL;
struct OrderNode *rear = NULL;

void placeOrder()
{
    struct OrderNode *temp;
    struct OrderNode *p;
    int duplicate = 0;

    temp = (struct OrderNode *)malloc(sizeof(struct OrderNode));

    if(temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("\nEnter order id: ");
    scanf("%d",&temp->orderId);

    p = front;

    while(p != NULL)
    {
        if(p->orderId == temp->orderId)
        {
            duplicate = 1;
            break;
        }

        p = p->next;
    }

    if(duplicate == 1)
    {
        printf("Order id already exists\n");
        free(temp);
        return;
    }

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
    scanf("%19s",temp->type);

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

                    recordSale(temp->productId,temp->quantity);

                    printf("Stock updated successfully\n");
                    printf("Current stock: %d\n",p[i].stock);

                    if(p[i].stock <= p[i].minStock)
                    {
                        printf("LOW STOCK ALERT\n");
                        printf("Product %s is below minimum stock level\n",
                               p[i].name);
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
                processOrder(p,n);
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
        fwrite(&p->orderId,sizeof(int),1,fp);
        fwrite(&p->productId,sizeof(int),1,fp);
        fwrite(&p->quantity,sizeof(int),1,fp);
        fwrite(p->type,sizeof(p->type),1,fp);
        fwrite(p->status,sizeof(p->status),1,fp);

        p = p->next;
    }

    fclose(fp);

    printf("Orders saved successfully\n");
}

void loadOrders()
{
    FILE *fp;
    struct OrderNode *newNode;

    fp = fopen("orders.dat","rb");

    if(fp == NULL)
    {
        return;
    }

    while(1)
    {
        newNode = (struct OrderNode *)malloc(sizeof(struct OrderNode));

        if(newNode == NULL)
        {
            printf("Memory allocation failed\n");
            fclose(fp);
            return;
        }

        if(fread(&newNode->orderId,sizeof(int),1,fp) != 1)
        {
            free(newNode);
            break;
        }

        fread(&newNode->productId,sizeof(int),1,fp);
        fread(&newNode->quantity,sizeof(int),1,fp);
        fread(newNode->type,sizeof(newNode->type),1,fp);
        fread(newNode->status,sizeof(newNode->status),1,fp);

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