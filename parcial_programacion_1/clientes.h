typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    char localidad[20];
    int telefono;
    int edad;
    char sexo[20];
    int estado;

    //int cont_mascotas;

}eclientes;


void inicializar_clientes(eclientes* lista_clientes,int size_clientes);

void mostrar_cliente(eclientes clientes );

void mostrarTodos_clientes(eclientes* lista_clientes,int size_clientes);

int buscar_cliente_by_id(eclientes* lista_clientes,int size_clientes,int id);

int alta_cliente(eclientes* lista_clientes,int size_clientes,int* id_duenio);

int cargar_cliente(eclientes* clienteAux,int* id_duenio);

int set_nombre_cliente(eclientes* cliente);

int set_apellido_cliente(eclientes* clientes);

int set_localidad_cliente(eclientes* cliente);

int set_telefono_cliente(eclientes* cliente);

int set_edad_cliente(eclientes* cliente);

int set_sexo_cliente(eclientes* cliente);

int modificar_cliente(eclientes* lista_clientes,int size_clientes,int id_duenio);


float promedio_clientes_masculino(eclientes* lista_clientes,int size_clientes);

float promedio_clientes_femenino(eclientes* lista_clientes,int size_clientes);

