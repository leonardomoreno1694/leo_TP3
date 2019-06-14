#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(FILE* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int r=-1;


     pFile=fopen(path,"r");
    if(path!=NULL && pArrayListEmployee!=NULL && pFile!=NULL)
    {

            parser_EmployeeFromText(pFile,pArrayListEmployee);
            fclose(pFile);
            r=0;
     }
        else
        {
            printf("\nNO SE PUEDO ABRIR EL ARCHIVO!\n");
        }

    return r;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int r=-1;


    pFile=fopen(path," rb");
    if(path!=NULL && pArrayListEmployee!=NULL && pFile!=NULL)
        {
            parser_EmployeeFromBinary(pFile,pArrayListEmployee);
            r=0;
        }
        else
        {
            printf(" \nNO SE PUEDO ABRIR EL ARCHIVO!!\n");
        }

    return r;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int r=-1;
    char BNombre[1024];//Buffer
    int auxHorasTrabajadas;
    int auxSueldo;
    Employee* auxEmployee;
    if(pArrayListEmployee!=NULL &&
       !getLetras(BNombre,50,2,"\nINGRESE UN NOMBRE: ","\nERROR EN NOMBRE INGRESADO")&&!getEntero(&auxHorasTrabajadas,2,"\nINGRESE HORAS TRABAJADAS: ","\nERROR EN LAS HORAS INGRESADAS",10,500)&&
       !getEntero(&auxSueldo,2,"\nINGRESE SUELDO ","\nERROR EN EL SUELDO INGRESADO:!",10,9999999))
    {
        auxEmployee=employee_new();
        if(auxEmployee!=NULL && !employee_setNombre(auxEmployee,BNombre)&&!employee_setId(auxEmployee,-1)&& !employee_setSueldo(auxEmployee,auxSueldo)&&
           !employee_setHorasTrabajadas(auxEmployee,auxHorasTrabajadas))
           {
                r=0;
                ll_add(pArrayListEmployee,auxEmployee);
           }
           else
           {
            employee_delete(auxEmployee);
            auxEmployee=NULL;
           }
    }
    return r;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int r=-1;
    int limite;
    int i;
    char BNombre[1024];
    int BHorasTrabajadas;//Buffer
    int BSueldo;
    int BId;
    int auxId;
    Employee* auxEmployee;
    if(pArrayListEmployee!=NULL && !getEntero(&auxId,3,"\nIngrese la id del empleado a modificar: ","\nIngrese un id valido!",0,999999))
    {
       limite=ll_len(pArrayListEmployee);
       for(i=0;i<limite;i++)
       {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(auxEmployee,&BId);
            if(BId==auxId &&!getLetras(BNombre,1024,2,"\nINGRESE UN NOMBRE: ","\nERROR EN EL INGRESO DEL NOMBRE,INTENTE NUEVAMENTE:!")&&
                !getEntero(&BHorasTrabajadas,2,"\nINGRESE HORAS TRABAJADAS: ","\nERROR EN EL INGRESO DE HORAS ,INTENTE NUEVAMENTE:",10,999)&&
                !getEntero(&BSueldo,2,"\nINGRESE SUEKDO: ","\nERROR EN EL SUELDO INGRESADO,INTENTE NUEVAMENTE:!",10,999999)&&
                !employee_setNombre(auxEmployee,BNombre)&&
                !employee_setSueldo(auxEmployee,BSueldo)&&
                !employee_setHorasTrabajadas(auxEmployee,BHorasTrabajadas))
                {
                    r=0;
                    break;
                }
       }
    }
    return r;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int r=-1;
    int limite;
    int i;
    int BiD;
    int auxId;
    Employee* auxEmployee;
    if(pArrayListEmployee!=NULL &&!getEntero(&auxId,2,"\nIngrese el id del empleado a borrar: ","\nIngrese un id valido!",0,99999))
    {
        limite=ll_len(pArrayListEmployee);
        for(i=0;i<limite;i++)
        {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(auxEmployee,&BiD);
            if(BiD==auxId)
            {
                ll_remove(pArrayListEmployee,i);
                r=0;
                break;
            }
        }
    }
    return r;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int limit;
    int i;
    int bufferId;
    int bufferSueldo;
    int bufferHorasTrabajadas;
    char bufferNombre[1024];
    Employee* auxEmployee;
    if(pArrayListEmployee!=NULL)
    {
        retorno=0;
        limit=ll_len(pArrayListEmployee);
        for(i=0;i<limit;i++)
        {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getNombre(auxEmployee,bufferNombre);
            employee_getId(auxEmployee,&bufferId);
            employee_getSueldo(auxEmployee,&bufferSueldo);
            employee_getSueldo(auxEmployee,&bufferSueldo);
            employee_getHorasTrabajadas(auxEmployee,&bufferHorasTrabajadas);
            printf("Id - %d,Nombre - %s,Horas - %d,Sueldo - %d\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
        }
        getche();
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int r=-1;
    if(pArrayListEmployee!=NULL)
    {
        ll_sort(pArrayListEmployee,employee_criterioPorNombre,1);
        r=0;
    }
    return r;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL && !employee_guardarTexto(pFile,pArrayListEmployee))
        {
            fclose(pFile);
            printf("\nSe ha guardado con exito!\n");
            retorno=0;
        }
        else
        {
            printf("\nNo se pudo abrir el archivo!\n");
        }
      fclose(pFile);
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"wb");
        if(pFile!=NULL && !employee_guardarBinario(pFile,pArrayListEmployee))
        {
            fclose(pFile);
            printf("\nSe ha guardado con exito!\n");
            retorno=0;
        }
        else
        {
            printf("\nNo se pudo abrir el archivo!\n");
        }
    }
    return retorno;
}
