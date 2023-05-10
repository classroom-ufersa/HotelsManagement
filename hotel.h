typedef struct hotel Hotel;

typedef struct lista Listah;

Hotel *realizarh(void);

Listah* lst_criah(void);

Listah * excluirh(Listah *list, char nome);

void listarh(Listah *list);

Listah *buscarh(Listah *list);

void editarh(Listah *list);

void disponibilidadeh(Listah *list);