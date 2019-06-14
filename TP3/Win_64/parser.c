#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param FILE* pFile
 * \param  LinkedList*pArrayListEmployee
 * \return int r
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r=-1;
    char Bid[1024];// B = buffer
    char BNombre[1024];
    char BHorasTrabajadas[1024];
    char BSueldo[1024];
    Employee* auxEmployee;//creo un punteroaux a la estructura employyee
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        r=0;//r pasa a ser valido
        do
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^ \n]\n",Bid,BNombre,BHorasTrabajadas,BSueldo);
            auxEmployee=employee_newParametros(Bid,BNombre,BHorasTrabajadas,BSueldo);
            if(auxEmployee!=NULL)
            {
                ll_add(pArrayListEmployee,auxEmployee);
            }
            else
            {
                printf("%s,%s,%s,%s\n",Bid,BNombre,BHorasTrabajadas,BSueldo);
            }
        }while(!feof(pFile));
    }
    return r;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param FILE* pFile
 * \param  LinkedList*pArrayListEmployee
 * \return int r
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int r=-1;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        do
        {
            auxEmployee=employee_new();

            if(fread(auxEmployee,sizeof(Employee),1,pFile)==1 && !validarId(auxEmployee))
            {
                ll_add(pArrayListEmployee,auxEmployee);
            }
            else

                employee_delete(auxEmployee);

        }while(!feof(pFile));
        r=0;
    }
    return r;
}
