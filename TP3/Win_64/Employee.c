#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"
int OpMenu(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}
/**--------------------------------------------SETS--------------------------------------------------------**/
/** \brief seteo de horas trabajadas
 *
 * \param Employee* this
 * \param int horas Trabajadas
 * \return int ret(retorno) 0 (ok) y -1(error)
 *
 */

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ret=-1;
    if(this!=NULL &&
       !validarHorasTrabajadas(horasTrabajadas))
    {
        this->horasTrabajadas=horasTrabajadas;
        ret=0;
    }
    return ret;
}


/** \brief valida las horas de trabajo(mayor a 0hs)
 *
 * \param int horas Trabajadas
 * \return int ret 0 (ok) y -1(error)
 *
 */
 int validarHorasTrabajadas(int horas)
{
    int ret=-1;
    if(horas>0)
    {
        ret=0;
    }
    return ret;
}

/** \brief get Horas trabajadas
 *
 * \param Employee* this recibe variable puntero del tipo Employee
 * \param int horas Trabajadas
 * \return int ret 0 (ok) y -1(error)
 *
 */

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
     if(this != NULL && horasTrabajadas!= NULL)
     {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
     }
    return retorno;
}

/** \brief seteo de sueldo
 *
 * \param Employee* this recibe variable puntero del tipo Employee
 * \param int Sueldo
 * \return int ret 0 (ok) y -1(error)
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int ret=-1;
    if(this!=NULL &&
       !validarSueldo(sueldo))
    {
        this->sueldo=sueldo;
        ret=0;
    }
    return ret;
}

/** \brief validacion de sueldo (mayor a $0)
 *
 * \param int Sueldo
 * \return int ret 0 (ok) y -1(error)
 *
 */

 int validarSueldo(int sueldo)
{
    int ret=-1;
    if(sueldo>0)
    {
        ret=0;
    }
    return ret;
}

/** \brief get Sueldo
 *
 * \param Employee* this recibe variable puntero del tipo Employee
 * \param int Sueldo
 * \return int ret 0 (ok) y -1(error)
 *
 */

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this != NULL && sueldo!= NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}
/** \brief seteo de Nombre
 *
 * \param Employee* this recibe variable puntero del tipo Employee
 * \param char* nombre
 * \return int ret 0 (ok) y -1(error)
 *
 */

int employee_setNombre(Employee* this, char* nombre)
{
    int ret=-1;
    if(this!=NULL &&
       !validarNombre(nombre))
    {
        strcpy(this->nombre,nombre);
        ret=0;
    }
    return ret;
}

/** \brief validacion nombre(mayor a 0 y menor a 50 letras)
 *
 * \param int Sueldo
 * \return int ret 0 (ok) y -1(error)
 *
 */
 int validarNombre(char* nombre)
{
    int ret=-1;
    if(nombre!= NULL && strlen(nombre)<50 && strlen(nombre)>1)
    {
        ret=0;
    }
    return ret;
}
/** \brief get Nombre
 *
 * \param Employee* this recibe variable puntero del tipo Employee
 * \param char* nombre
 * \return int ret 0 (ok) y -1(error)
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief get ID
 *
 * \param Employee* this recibe variable puntero del tipo Employee
 * \param int* id
 * \return int ret 0 (ok) y -1(error)
 *
 */
int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
     if(this != NULL && id!= NULL)
     {
        *id=this->id;
        retorno=0;
     }
    return retorno;
}

/** \brief seteo de ID
 *
 * \param Employee* this recibe variable puntero del tipo Employee
 * \param int id
 * \return int ret 0 si entra a alguno de los if correctos (ok) y de lo contrario -1(error)
 *
 */
int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1 && !validarId(id))
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else{
        this->id=id;
        retorno=0;
    }

    if(id>proximoId)
    {
        proximoId=id;
        retorno=0;
    }
    return retorno;
}
/** \brief validacion de iD
 *
 * \param int iD
 * \return int ret 0 (ok) y -1(error)
 *
 */
int validarId(int id)
{
    int ret=-1;
    if(id>-2)
    {
        ret=0;
    }
    return ret;
}



/**-----------------------------------------Employee--------------------------------------------------**/

/** \brief Employee* employee_new :
           Genera un espacio dememoria para la variable *this con malloc
           y devuelve *this con su respectiva nueva direccion al espacio generado
 *
 * \param void
 *
 * \return void
 *
 */
Employee* employee_new(void)
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}
/** \brief employee_delete:
           libera espacio de empleado que requiere remover

 * \param Employee* this
 *
 *  \return int ret 0 (ok) y -1(error)
 *
 */
int employee_delete(Employee* this)
{
    int ret=-1;
    if(this!=NULL)
    {
        free(this);
        ret=0;
    }
    return ret;
}
/** \brief employee_validEmployee:
           recibe un variable auxiliar de employee y valida sus campos.

 * \param Employee* auxEmployee
 *
 *  \return int ret 0 si todas las validaciones son correctas (ok) y en caso de fallar en alguna -1(error)
 *
 */

int employee_validEmployee(Employee* auxEmployee)
{
    int ret=-1;

    if(!validarId(auxEmployee->id)&&
        !validarNombre(auxEmployee->nombre) &&
        !validarHorasTrabajadas(auxEmployee->horasTrabajadas)&&
        !validarSueldo(auxEmployee->sueldo))
        {
            ret=0;
        }
    return ret;
}
/** \brief employee_newParametros:
           Crea una variable *this,le asigna un espacio de memoria,valida y setea los campos.

 * \param char* id
 * \param char* nombre
 * \param char* horasTrabajadas
 * \param char* sueldo
 *
 *  \return si todos los campos del if (validacion y seteo) son cumplidos retornara *this(variable creada del tipo Employee)
            sino removera el espacio generado(employee_delete) y retornara NULL
 *
 */
Employee* employee_newParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
    Employee* this;
    this=employee_new();
    if(!sonEnteros(id) && !sonLetras(nombre) && !sonEnteros(horasTrabajadas) && !sonEnteros(sueldo)&&
       !employee_setId(this,atoi(id))&&
       !employee_setNombre(this,nombre)&&
       !employee_setHorasTrabajadas(this,atoi(horasTrabajadas))&&
       !employee_setSueldo(this,atoi(sueldo)))
       {
        return this;
       }
       employee_delete(this);
       return NULL;
}
/** \brief sonLetras:
           Comprobara si el char recibido son letras en base al codigo ascii

 * \param char* pBuffer
 *
 *  \return int ret 0 (ok) y -1(error)
 */
 int sonLetras(char*pBuffer)
{
    int retorno=-1;
    int i=0;
    if(pBuffer!=NULL)
    {
        do{
            if(*(pBuffer+i)==' '||*(pBuffer+i)=='-')
            {
                i++;
                continue;
            }
            if((*(pBuffer+i)<65||*(pBuffer+i)>90) && (*(pBuffer+i)<97||*(pBuffer+i)>122))
            {
                break;
            }
            i++;
        }while(i<strlen(pBuffer));
        if(i==strlen(pBuffer))
        {
            retorno=0;
        }
    }
    return retorno;
}
/** \brief employee_criterioPorNombre
           strcmp compara N1 y N2

 * \param char* pBuffer
 *
 *  \return  strcmp
 */
int employee_criterioPorNombre(void* thisA,void* thisB)
{
    int ret=0;
    char N1[1024];//nombre 1
    char N2[1024];//nombre 2
    employee_getNombre((Employee*)thisA,N1);
    employee_getNombre((Employee*)thisB,N2);
    if(strcmp(N1,N2)>0)
    {
        ret=1;
    }else if(strcmp(N1,N2)<0)
    {
        ret=-1;
    }
    return ret;
}
/** \brief sonEnteros
           comprueba que char*pBuffer sea entero en base al codigo ascii

 * \param char* pBuffer
 *
 *  \return int ret 0 (ok) y -1(error)
 */
 int sonEnteros(char *pBuffer)
{
    int ret=-1;
    int i=0;
    do{
        if(*(pBuffer+i)< 48 ||*(pBuffer+i)>57)
        {
        break;
        }
        i++;
    }while (i<strlen(pBuffer));

    if(i==strlen(pBuffer))
    {
    ret=0;
    }
    return ret;
}

/** \brief employee_guardarBinario:
            guardara los datos en el archivo(csv) en modo binario

 * \param FILE* pFile
 * \param LinkedList* pArrayListEmployee
 *
  *  \return int ret 0 (ok) y -1(error)
 */
int employee_guardarBinario(FILE* pFile,LinkedList* pArrayListEmployee)
{
    int ret=-1;
    int i;
    int limite;
    Employee* auxEmployee;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        limite=ll_len(pArrayListEmployee);
        ret=0;
        for(i=0;i<limite;i++)
        {
            auxEmployee=ll_get(pArrayListEmployee,i);
            if(auxEmployee!=NULL)
            {
                fwrite(auxEmployee,sizeof(Employee),1,pFile);
            }
        }
        if(i==limite)
        {
            ret=0;
        }
    }
    return ret;
}

/** \brief employee_guardarBinario:
            guardara los datos en el archivo(csv) en modo texto

 * \param FILE* pFile
 * \param LinkedList* pArrayListEmployee
 *
  *  \return int ret 0 (ok) y -1(error)
 */
int employee_guardarTexto(FILE* pFile,LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i=0;
    int bufferId;
    char buffernombre[1024];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    int limite;
    Employee* auxEmployee;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        fprintf(pFile,"\nid,nombre,horasTrabajadas,sueldo\n");
        limite=ll_len(pArrayListEmployee);
        do
        {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(auxEmployee,&bufferId);
            employee_getNombre(auxEmployee,&buffernombre);
            employee_getHorasTrabajadas(auxEmployee,&bufferHorasTrabajadas);
            employee_getSueldo(auxEmployee,&bufferSueldo);
            fprintf(pFile,"%d,%s,%d,%d\n",bufferId,buffernombre,bufferHorasTrabajadas,bufferSueldo);
            i++;
        }while(i<limite);
        if(i==limite)
        {
            retorno=0;
        }
    }
    return retorno;
}
