#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
                     printf("\n********************************** T P 3 ************************************\n\n\n\n");
    do{
            option=OpMenu(  "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
                        "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario\n"
                        "3. Alta de empleado\n"
                        "4. Modificar datos de empleado\n"
                        "5. Baja de empleado\n"
                        "6. Listar empleados\n"
                        "7. Ordenar empleados\n"
                        "8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
                        "9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
                        "10. Salir\n\n"
                        "INGRESE OPCION:");

        switch(option)
        {
            case 1:
                system("cls");
                controller_loadFromText("data.csv",listaEmpleados);
                printf("\n\n>>>>CARGADO EN MODO TEXTO EXITOSAMENTE \n\n");
                break;
            case 2:
                controller_loadFromBinary("data.csv",listaEmpleados);
                printf("\n\n>>>>CARGADO EN MODO BINARIO EXITOSAMENTE \n\n");
                break;
            case 3:
                system("cls");
                controller_addEmployee(listaEmpleados);
                printf("\n\n>>>>EMPLEADO ADERIDO \n\n");
                break;
            case 4:
                system("cls");
                controller_ListEmployee(listaEmpleados);
                controller_editEmployee(listaEmpleados);
                printf("\n\n>>>>EMPLEADO EDITADO\n\n");
                break;
            case 5:
                system("cls");
                controller_ListEmployee(listaEmpleados);
                controller_removeEmployee(listaEmpleados);
                printf("\n\n>>>>EMPLEADOS REMOVIDO \n\n");
                break;
            case 6:
                system("cls");
                controller_ListEmployee(listaEmpleados);
                printf("\n\n>>>>EMPLEADOS LISTADOS \n\n");
                break;
            case 7:
                system("cls");
                controller_sortEmployee(listaEmpleados);
                printf("\n\n>>>>EMPLEADOS ORDENADOS \n    (VER CON LISTAR EMPLEADOS)\n\n");
                break;
            case 8:
                system("cls");
                controller_saveAsText("data.csv",listaEmpleados);
                printf("\n\n GUARDADO EN MODO TEXTO \n\n");

                break;
            case 9:
                system("cls");
                controller_saveAsBinary("data.csv",listaEmpleados);
                printf("\n\n GUARDADO EN MODO BINARIO \n\n");

                break;
            case 10:

                break;
        }
    }while(option != 10);
    system("cls");
    printf("\n\n\n\n\n\n*************** H A S T A    P R O N T O ***********\n\n\n\n\n\n\n\n");
    return 0;
}
