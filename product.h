#ifndef PRODUCT_H

#define PRODUCT_H

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

int addProduct(struct Product p[], int n);

void displayProducts(struct Product p[], int n);

void updateProduct(struct Product p[], int n);

void deleteProduct(struct Product p[], int *n);

void productMenu(struct Product p[], int *n);

void saveProducts(struct Product p[], int n);

int loadProducts(struct Product p[]);

#endif