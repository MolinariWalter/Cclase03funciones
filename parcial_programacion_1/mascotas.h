
typedef struct
{
    int id;
    char nombre[20];
    char tipo[20];
    int id_raza;
    //char raza[20];
    int edad;
    float peso;
    char sexo[20];
    int id_duenio;
    int estado;

}emascotas;


void inicializar_mascotas(emascotas* lista_mascotas,int size_mascotas);

int buscar_mascota_by_id(emascotas* lista_mascotas,int size_mascotas,int id);

void mostrar_mascota(emascotas mascota);

int set_nombre_mascota(emascotas* mascota);

int set_tipo_mascota(emascotas* mascota);


int set_edad_mascota(emascotas* mascota);

int set_peso_mascota(emascotas* mascota);

int set_sexo_mascota(emascotas* mascota);

