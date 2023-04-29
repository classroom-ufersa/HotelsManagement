typedef struct hotel Hotel;

typedef struct lista Lista;

Hotel *add_hotel();

Lista *insere_hotel(Lista *lista, Hotel *cont);

Lista *excluir_hotel(Lista *lista);

void listar_hotel(Lista *lista);

void listartxt(Lista *lista);

void buscar_hotel(Lista* lista);


