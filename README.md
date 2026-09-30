# Smart Inventory and Warehouse Management System

## About the Project

The Smart Inventory and Warehouse Management System is a console-based application developed in C using Data Structures and Algorithms.

The system is designed to manage products, suppliers, inventory, orders and sales records. It also provides low-stock alerts, simple demand forecasting and reports to help in inventory management.

## Features

- Product Management
  - Add Product
  - Display Products
  - Update Product
  - Delete Product

- Supplier Management
  - Add Supplier
  - Display Suppliers
  - Search Supplier
  - Delete Supplier

- Inventory Management
  - Add Stock
  - Remove Stock
  - View Inventory
  - Check Low Stock

- Order Management
  - Place Order
  - Process Order
  - Display Pending Orders

- Searching
  - Linear Search
  - Binary Search

- Sorting
  - Selection Sort

- Sales History
  - Record sales
  - Display sales history

- Demand Forecasting
  - Uses recent sales records
  - Calculates average demand
  - Provides restock information

- Reports
  - Total products
  - Total stock
  - Low-stock products
  - Sales information
  - Forecast and restock information

- File Handling
  - Product data
  - Supplier data
  - Order data
  - Sales history

## Data Structures Used

The project uses the following data structures:

- Array of Structures – Product management
- Linked List – Supplier management
- Queue using Linked List – Order processing
- Arrays – Sales history and forecasting data

## Algorithms Used

- Linear Search
- Binary Search
- Selection Sort
- Simple Average-based Demand Forecasting

## Technologies Used

- Programming Language: C
- Compiler: GCC
- IDE: Visual Studio Code
- Version Control: Git and GitHub

## Project Structure

```text
Smart-Inventory-and-Warehouse-Management-System/
│
├── main.c
├── product.c
├── product.h
├── supplier.c
├── supplier.h
├── inventory.c
├── inventory.h
├── order.c
├── order.h
├── search_sort.c
├── search_sort.h
├── sales_history.c
├── sales_history.h
├── forecast.c
├── forecast.h
├── reports.c
├── reports.h
├── .gitignore
└── README.md