#ifndef ORDER_H   // Si no está definido el header...
#define ORDER_H   // ...lo definimos para evitar duplicados

// Definimos la estructura "order", que representa una venta de pizza
typedef struct Order {
    int pizza_id;                // ID única de la pizza (puede repetirse si se vendió varias veces)
    int order_id;                // ID de la orden (varias pizzas pueden tener el mismo order_id)
    char pizza_name_id[50];     // Nombre interno (ID) de la pizza, como "hawaiian_m"
    int quantity;               // Cuántas unidades se vendieron en esa línea
    char order_date[20];        // Fecha de la venta (por ejemplo "1/1/2015")
    char order_time[20];        // Hora de la venta (por ejemplo "11:38:36")
    float unit_price;           // Precio unitario de la pizza
    float total_price;          // Precio total (unit_price * quantity), aunque también viene en el CSV
    char pizza_size;            // Tamaño de la pizza (por ejemplo 'M', 'L', etc.)
    char pizza_category[30];    // Categoría (por ejemplo "Classic", "Veggie", etc.)
    char pizza_ingredients[200];// Ingredientes separados por comas
    char pizza_name[50];        // Nombre bonito para mostrar (por ejemplo "The Hawaiian Pizza")
} Order;

#endif  // Cierre del guardia de inclusión
