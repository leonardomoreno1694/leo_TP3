
int getInt();
float getFloat();
char getChar();



char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char *str) ;
int esTelefono(char *str);
int esAlfaNumerico(char *str);
int esSoloLetras(char *str);
int esNumericoFlotante(char str[]);

int getInt2(int* pBuffer);
int isInt(char *pBuffer);
void getString(char mensaje[],char input[]);
int getString2(char* pBuffer,int limite);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);
int getLetras(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);
int getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int min,int max);

void cleanStdin(void);
