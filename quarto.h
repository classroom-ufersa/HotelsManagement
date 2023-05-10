typedef struct quarto Quarto;

typedef struct list Listaq;

Quarto *insereq(void);

Listaq* lst_criaq(void);

int vaziaq(Listaq *list);

Listaq* excluirq(Listaq* list, int num_q);

Listaq * buscarq( Listaq * list);

void editaq(Listaq *list);

void quantitativoq(Listaq * list);

void listarq(Listaq *list);