#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

Employee* employee_new(void);
int employee_delete(Employee* this);




int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_criterioPorNombre(void* thisA,void* thisB);



int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

 int employee_guardarTexto(FILE* pFile,LinkedList* pArrayListEmployee);
 int employee_guardarBinario(FILE* pFile,LinkedList* pArrayListEmployee);

 int employee_validEmployee(Employee* auxEmployee);

 int validarId(int id);
 int ValidarNombre(char* nombre);
 int ValidarSueldo(int sueldo);
 int ValidarHorasTrabajadas(int horas);




 int sonLetras(char*pBuffer);
 int sonEnteros(char *pBuffer);


int OpMenu(char mensaje[]);

#endif // employee_H_INCLUDED
