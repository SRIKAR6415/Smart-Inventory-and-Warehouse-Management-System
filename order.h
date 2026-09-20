#ifndef ORDER_H
#define ORDER_H

struct OrderNode
{
    int orderId;
    int productId;
    int quantity;
    char type[20];
    char status[20];
    struct OrderNode *next;
};

extern struct OrderNode *front;
extern struct OrderNode *rear;

void placeOrder();
void processOrder(struct Product p[], int n);
void displayOrders();
void orderMenu(struct Product p[], int n);

void saveOrders();
void loadOrders();

#endif