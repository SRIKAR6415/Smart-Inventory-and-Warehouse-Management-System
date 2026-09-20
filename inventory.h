#ifndef INVENTORY_H
#define INVENTORY_H

#include "product.h"

void addStock(struct Product p[], int n);
void removeStock(struct Product p[], int n);
void viewInventory(struct Product p[], int n);
void checkLowStock(struct Product p[], int n);
void inventoryMenu(struct Product p[], int *n);

#endif