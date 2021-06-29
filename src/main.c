#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "utn.h"

#define TAM 1000

int main()
{
    eEmployee employees[TAM];

    int idEmpleado=100;
    char seguir='s';
    char confirma;


    InicializarEmpleados(employees, TAM);

    do{

    switch(menu())
    {
    case 1:
        system("cls");
        if(altaEmpleado(employees, TAM, &idEmpleado))
        {
            printf("Alta de empleado exitosa!!\n");
        }
        else
        {
            printf("Hubo un problema al dar de alta al empleado\n");
        }

        system("pause");
        break;
    case 2:
        if(modificarEmpleado(employees, TAM))
        {
            printf("Modificacion exitosa!!\n");
        }
        else
        {
            printf("Hubo un problema al modificar\n");
        }
        system("pause");
        break;
    case 3:
        if(bajaEmpleado(employees, TAM))
        {
            printf("BajA exitosa!!\n");
        }
        else
        {
            printf("Hubo un problema al dar de baja\n");
        }
        break;
        case 4:
            system("cls");
        if(mostrarEmpleados(employees, TAM))
        {
            ordenarEmpleados(employees, TAM);
        }
        system("pause");

       break;
    case 5:
        printf("Seguro que desea salir?: s (salir) / otra letra(cancelar)");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma=='s')
        {
            seguir='n';
        }
        else
        {
            printf("Salida cancelada!\n");
            system("pause");
        }
        break;
        }
        }while(seguir=='s');



    return 0;
}
