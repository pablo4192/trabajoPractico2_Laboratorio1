#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "utn.h"

#define TAM 1000

int main()
{
    eEmployee employees[TAM];/*={
    {100, "Pablo", "Estanguet", 95000, 303, 0},
    {101, "Melina", "Loscalzo", 98500, 303, 0},
    {102, "Carla", "Perez", 75000, 304, 0},
    {103, "Juancho", "Papurri", 83600, 301, 0},
    {104, "Bernardo", "Stemateas", 55000, 302, 0},
    {105, "Leonardo", "Percha", 63000, 304, 0},
    {106, "Omar", "Landrisci", 79000, 302, 0},
    {107, "Boy", "Olmi", 81000, 300, 0},
    {108, "Pipo", "Cipolati", 69000, 301, 0},
    {109, "Choly", "Berretiaga", 74500, 304, 0},
    {110, "Carlos", "Mellera", 89000, 301, 0},
    {111, "Andres", "Caca", 91500, 304, 0},
    {112, "Lorena", "Kiko", 60000, 300, 0},
    {113, "Maru", "Bootana", 99000, 303, 0},
    {114, "Martin", "Garcia", 55000, 301, 0},
    {115, "Leandro", "Yamil", 85000, 304, 0},
    {116, "Brian", "Humus", 77000, 300, 0},
    {117, "Falucho", "Dente", 86000, 302, 0},
    {118, "Fredy", "Gaga", 50000, 301, 0},
    {119, "Nahuel", "Gandorcha", 63500, 304, 0},
    };*/

    int idEmpleado=100;
    char seguir='s';
    char confirma;


    InicializarEmpleados(employees, TAM);

    do{

    switch(menu())
    {
    case 1:
        system("cls");
        altaEmpleado(employees, TAM, &idEmpleado);
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
