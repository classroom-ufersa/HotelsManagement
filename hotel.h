typedef enum aval Aval;

typedef struct hotel Hotel;

typedef struct lista Lista;

Hotel *add_hotel();

Lista *insere_hotel(Lista *lista, Hotel *elemento);

Lista *excluir_hotel(Lista *lista, char nome_hotel);

void listar_hotel(Lista *lista);

void listartxt(Lista *lista);

void buscar_hotel(char nome, Lista* lista);