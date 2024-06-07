#include <stdio.h>
#include <string.h>
#include "urban.h"

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("No se pueden agregar más productos.\n");
        return;
    }

    printf("Ingrese el nombre del producto: ");
    scanf("%s", inventory[productCount].name);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &inventory[productCount].quantity);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &inventory[productCount].price);

    productCount++;
    printf("Producto agregado exitosamente.\n");
}

void editProduct() {
    char name[50];
    printf("Ingrese el nombre del producto a editar: ");
    scanf("%s", name);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Ingrese el nuevo nombre del producto: ");
            scanf("%s", inventory[i].name);
            printf("Ingrese la nueva cantidad del producto: ");
            scanf("%d", &inventory[i].quantity);
            printf("Ingrese el nuevo precio del producto: ");
            scanf("%f", &inventory[i].price);

            printf("Producto editado exitosamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void deleteProduct() {
    char name[50];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", name);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Producto eliminado exitosamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void listProducts() {
    if (productCount == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }

    printf("Productos en el inventario:\n");
    for (int i = 0; i < productCount; i++) {
        printf("Nombre: %s, Cantidad: %d, Precio: %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}