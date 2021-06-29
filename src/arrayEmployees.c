
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utn.h"


int menu()
{
    int opcion;

    system("cls");
    printf("**** Menu de empleados ****\n\n");
    printf("1) Alta empleado\n");
    printf("2) Modificar empleado\n");
    printf("3) Baja empleado\n");
    printf("4) Informes\n");
    printf("5) Salir\n");
    utn_getNumero(&opcion, "Escoja opcion: \n", "Error, escoja una opcion valida (1 al 5): \n", 1, 5, 3);

    return opcion;
}

int altaEmpleado(eEmployee lista[], int tam, int* pIdEmpleado)
{
    int todoOk=0;
    int indiceLibre;
    eEmployee nuevoEmpleado;



    if(lista!=NULL && tam>0)
    {
        indiceLibre=buscarIndiceLibre(lista, tam);

        if(indiceLibre==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {

            printf("Alta de Empleados\n");
            printf("Se le asigno el id: %d\n", *pIdEmpleado);
            nuevoEmpleado.id=*pIdEmpleado;

            utn_getStringChar(nuevoEmpleado.name, "Ingrese Nombre: \n", "Error ingrese Nombre valido: \n", 2, 20, 3 );

            utn_getStringChar(nuevoEmpleado.lastName, "Ingrese Apellido: \n", "Error ingrese Apellido valido:  \n", 2, 20, 3);

            utn_getNumeroFlotante(&nuevoEmpleado.salary, "Ingrese sueldo: \n", "Error ingrese sueldo valido: \n", 0, 500000, 3);

            utn_getNumero(&nuevoEmpleado.sector, "Ingrese sector (300 al 304): \n", "Error ingrese sector valido (300 al 304): \n", 300, 304, 3);

            nuevoEmpleado.isEmpty=0;
            lista[indiceLibre]=nuevoEmpleado;
            (*pIdEmpleado)++;

            todoOk=1;
        }
    }
    return todoOk;
}

int InicializarEmpleados(eEmployee lista[], int tam)
{
   int todoOk=0;

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarIndiceLibre(eEmployee lista[], int tam)
{
    int indice=-1;

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int mostrarEmpleados(eEmployee lista[], int tam)
{
    int todoOk=0;


    if(lista!=NULL && tam>0)
    {

        printf("**** Nomina de empleados ****\n\n");
        printf("   Id      Nombre    Apellido     Sueldo  Sector \n");

        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty)
            {
                printf("  %d  %10s  %10s   %.2f     %d\n", lista[i].id, lista[i].name, lista[i].lastName, lista[i].salary, lista[i].sector);
                todoOk=1;
            }
        }
        printf("\n\n");

        if(!todoOk)
        {
            printf("No hay empleados en la nomina\n");
        }


    }


    return todoOk;
}

int ordenarEmpleados(eEmployee lista[], int tam)
{
    int todoOk=0;
    int criterio;
    int opcion;


    eEmployee auxiliar;

     if(lista!=NULL && tam>0)
     {

            printf("Seleccion de informes\n");
            printf("1) Ordenar Empleados\n");
            printf("2) Total y promedio de salarios\n");
            utn_getNumero(&opcion, "Escoja opcion u otro numero para salir: \n", "Error ingrese una opcion valida (1 o 2): \n", 1, 2, 3);

            switch(opcion)
            {
            case 1:
                printf("\nOrdenar empleados por Apellido y Sector\n");
                printf("1) Ascendente\n");
                printf("2) Descendente\n");
                utn_getNumero(&criterio, "Elija criterio de ordenamiento: \n", "Error, Elija criterio de ordenamiento (1 o 2): \n", 1, 2, 3);

                for(int i=0; i<tam-1; i++)
                {
                    for(int j=i+1; j<tam; j++)
                    {
                        if((criterio==1 && lista[i].sector>lista[j].sector) || (criterio==2 && lista[i].sector<lista[j].sector) )
                        {
                            auxiliar=lista[i];
                            lista[i]=lista[j];
                            lista[j]=auxiliar;
                        }
                    }
                }

                for(int i=0; i<tam-1; i++)
                {
                    for(int j=i+1; j<tam; j++)
                    {
                        if((criterio==1 && lista[i].sector==lista[j].sector && strcmp(lista[i].lastName, lista[j].lastName)>0) || (criterio==2 && lista[i].sector==lista[j].sector && strcmp(lista[i].lastName, lista[j].lastName)<0))
                        {
                            auxiliar=lista[i];
                            lista[i]=lista[j];
                            lista[j]=auxiliar;
                        }
                    }
                }
                todoOk=1;
                printf("Se ordeno exitosamente!!\n");
                mostrarEmpleados(lista, tam);

                break;
            case 2:
                totalSalario(lista, tam);
                break;
            default:
                break;
            }
    }

    return todoOk;
}

int bajaEmpleado(eEmployee lista[], int tam)
{
    int todoOk=0;
    int indice;
    int legajo;
    char confirma;

    if(lista!=NULL && tam>0)
    {
        system("cls");
        printf("**** Baja Empleado ****\n");

    if(mostrarEmpleados(lista, tam))
    {



        printf("Ingrese id de empleado a dar de baja: ");
        scanf("%d", &legajo);

        indice=buscarEmpleado(lista, tam, legajo);

        if(indice==-1)
        {
            printf("No existe empleado con ese numero de legajo\n");
        }
        else
        {
            printf("  id     Nombre     Apellido     Sueldo  Sector\n ");
            printf("%d %10s   %10s   %.2f     %d\n", lista[indice].id, lista[indice].name, lista[indice].lastName, lista[indice].salary, lista[indice].sector);
            printf("Confirma baja?: ");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma=='s')
            {
                lista[indice].isEmpty=1;
                printf("Baja exitosa!!\n");
                todoOk=1;
            }
            else
            {
                printf("Baja cancelada!!\n");
            }
        }
    }
        system("pause");
    }
    return todoOk;
}

int buscarEmpleado(eEmployee lista[], int tam, int id)
{
    int indice=-1;

    if(lista!=NULL && tam>0 && id>0 && id<1001) //no mas de 1000 empleados en la nomina
    {
        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty &&  id==lista[i].id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int modificarEmpleado(eEmployee lista[], int tam)
{
    int todoOk=0;
    int legajo;
    int indice;
    int opcion;
    char confirma;

    if(lista!=NULL && tam>0)
    {


        system("cls");
        printf("Modificar Empleado:\n");

        if(mostrarEmpleados(lista, tam))
        {
            printf("Ingrese id a Modificar: ");
            scanf("%d", &legajo);

            indice=buscarEmpleado(lista, tam, legajo);

            if(indice==-1)
            {
                printf("No existe un empleado con el numero de id: %d\n", legajo);
            }
            else
            {
                printf("  id    Nombre    Apellido    Sueldo  Sector\n");

                printf(" %d%10s  %10s  %.2f     %d\n", lista[indice].id, lista[indice].name, lista[indice].lastName, lista[indice].salary, lista[indice].sector);
                printf("\n\n");
                printf("Informacion del Empleado:\n");
                printf("1) Nombre\n");
                printf("2) Apellido\n");
                printf("3) Sueldo\n");
                printf("4) Sector\n");

                printf("Que dato desea Modificar?: ");
                scanf("%d", &opcion);

                printf("Confirma opcion?: \n");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma=='s')
                {
                    switch(opcion)
                    {
                    case 1:
                        printf("Modificar nombre: ");
                        scanf("%s", lista[indice].name);
                        break;
                    case 2:
                        printf("Modificar Apellido: ");
                        scanf("%s", lista[indice].lastName);
                        break;
                    case 3:
                        printf("Modificar sueldo: ");
                        scanf("%f", &lista[indice].salary);
                        break;
                    case 4:
                        printf("Modificar sector: ");
                        scanf("%d", &lista[indice].sector);
                        break;
                    }
                    todoOk=1;   //cuando la modificacion se hizo correctamente cambio el valor del retorno a 1 indicando que se hizo exitosamente
                }
                else
                {
                    printf("Modificacion cancelada!\n");
                }

            }
        }

    }
    return todoOk;
}

int totalSalario(eEmployee lista[], int tam)
{
    int todoOk=0;
    float total=0;
    int contadorEmpleados=0;
    float promedio;
    int flagSeMostro=0;


    if(lista!=NULL && tam>0)
    {
        system("cls");
        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty)
            {
                total+=lista[i].salary;
                contadorEmpleados++;
            }

        }
        promedio=total/contadorEmpleados;

        printf("\nEl salario total es: %.2f\n", total);
        printf("El promedio de los salarios es: %.2f\n\n", promedio);
        printf("Los empleados que superan el promedio de salarios son: \n");
        printf(" Id      Nombre    Apellido     Sueldo  Sector \n\n");


        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty && lista[i].salary>promedio)
            {
                printf("%d  %10s  %10s   %.2f     %d\n",lista[i].id, lista[i].name, lista[i].lastName, lista[i].salary, lista[i].sector);
                flagSeMostro=1;
            }
        }
        if(!flagSeMostro)
        {
            printf("No hay empleados que superen el sueldo promedio\n\n");
        }

        todoOk=1;
    }



    return todoOk;
}





