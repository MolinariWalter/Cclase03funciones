
typedef struct
{
    int id_raza;
    char nombre_raza[20];
    char pais[20];
    int estado;

}eRaza;

void inicializar_raza_pais(eRaza* lista_raza,int size_raza,int* id_raza);
void harcodear_raza(eRaza* lista_raza,int size_raza,int* id_raza);
