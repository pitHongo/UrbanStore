#define INVENTORY_H

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct();
void editProduct();
void deleteProduct();
void listProducts();
