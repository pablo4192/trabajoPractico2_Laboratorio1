#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief Presenta el menu de opciones
 *
 * \return int retorna la opcion elegida por el usuario
 *
 */
int menu();

/** \brief Realiza la peticion de datos al usuario
 *
 * \param lista[] eEmployee Array de empleados con los datos de cada uno de ellos
 * \param tam int Tamaño del array
 * \param pIdEmpleado int* Puntero a id del empleado
 * \return int 1 si la funcion logro hacer el trabajo correctamente, 0 si hubo algun error
 *
 */
int altaEmpleado(eEmployee lista[], int tam, int* pIdEmpleado);

/** \brief Inicializa el campo isEmpty de la estructura en 1
 *
 * \param lista[] eEmployee Array de empleados con los datos de cada uno de ellos
 * \param tam int Tamaño del array
 * \return int 1 si la funcion logro hacer el trabajo correctamente, 0 si hubo algun error
 *
 */
int InicializarEmpleados(eEmployee lista[], int tam);

/** \brief Busca en la estructura un indice con un array libre
 *
 * \param lista[] eEmployee Array de empleados con los datos de cada uno de ellos
 * \param tam int Tamaño del array
 * \return int Indice libre encontrado
 *
 */
int buscarIndiceLibre(eEmployee lista[], int tam);

/** \brief Muestra los empleados del array de empleados
 *
 * \param lista[] eEmployee Array de empleados con los datos de cada uno de ellos
 * \param tam int Tamaño del array
 * \return int 1 si la funcion logro hacer el trabajo correctamente, 0 si hubo algun error
 *
 */
int mostrarEmpleados(eEmployee lista[], int tam);

/** \brief Ordena la lista de empleados por apellido y sector
 *
 * \param lista[] eEmployee Array de empleados con los datos de cada uno de ellos
 * \param tam int Tamaño del array
 * \return int 1 si la funcion logro hacer el trabajo correctamente, 0 si hubo algun error
 *
 *
 */
int ordenarEmpleados(eEmployee lista[], int tam);

/** \brief Da de baja de la lista al empleado elegido
 *
 * \param lista[] eEmployee Array de empleados con los datos de cada uno de ellos
 * \param tam int Tamaño del array

 * \return int 1 si la funcion logro hacer el trabajo correctamente, 0 si hubo algun error
 *
 */
int bajaEmpleado(eEmployee lista[], int tam);


/** \brief Modifica datos del empleado elegido
 *
 * \param lista[] eEmployee Array de empleados con los datos de cada uno de ellos
 * \param tam int Tamaño del array
 * \return int 1 si la funcion logro hacer el trabajo correctamente, 0 si hubo algun error
 *
 */
int modificarEmpleado(eEmployee lista[], int tam);

/** \brief Busca un empleado del array igualando su id con el que ingresa el usuario
 *
 * \param lista[] eEmployee Array de empleados con los datos de cada uno de ellos
 * \param tam int Tamaño del array
 * \param id int Id que ingresa el usuario
 * \return int Indice del empleado encontrado
 *
 */
int buscarEmpleado(eEmployee lista[], int tam, int id);

/** \brief Calcula total de salarios, promedio de los sueldos y empleados sueldos mayor al promedio
 *
 * \param lista[] eEmployee Array de empleados con los datos de cada uno de ellos
 * \param tam int Tamaño del array
 * \return int 1 si la funcion logro hacer el trabajo correctamente, 0 si hubo algun error
 *
 */
int totalSalario(eEmployee lista[], int tam);
