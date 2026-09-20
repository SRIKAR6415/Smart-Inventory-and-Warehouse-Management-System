#ifndef SUPPLIER_H
#define SUPPLIER_H

struct SupplierNode
{
    int id;
    char name[50];
    char phone[20];
    char email[50];
    char address[100];
    struct SupplierNode *next;
};

extern struct SupplierNode *head;

void addSupplier();
void displaySuppliers();
void searchSupplier();
void deleteSupplier();
void supplierMenu();

void saveSuppliers();
void loadSuppliers();

#endif