#include "conexion.h"
#include <iostream>
#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"
#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysqld_error.h"
using namespace std;

conexion::conexion ()
{

   // Intentar iniciar MySQL:
   if(!(objDatos = mysql_init(0))) {
      // Imposible crear el objeto objDatos
      cout << "ERROR: imposible crear el objeto objDatos." << endl;
      getchar();
      exit(1);
   }

   if(!mysql_real_connect(objDatos, "127.0.0.1","root","49376260","bprueba",3306,NULL,0)) {
      cout << "Imposible conectar con servidor mysql en el puerto "
           << MYSQL_PORT << " Error: " << mysql_error(objDatos) << endl;
      mysql_close(objDatos);
      rewind(stdin);
      getchar();
      exit(2);
   }
}


void conexion:: sql_close()
{
   mysql_close(this->objDatos);
}


MYSQL_RES * conexion:: ejecutar_sql(char *cConsulta)
{
   if(mysql_ping(objDatos)) {
      cout << "Error: conexión imposible" << endl;
      this->sql_close();
   }

    if(mysql_query(objDatos, cConsulta)) {
      // Error al realizar la consulta:
      cout << "ERROR: " <<  mysql_error(objDatos) << endl;
      this->sql_close();
      rewind(stdin);
      getchar();
      exit(2);
   }

}

int conexion:: numero_filas(MYSQL_RES *res)
{
    return mysql_num_rows(res);
}

int conexion:: filas_afectadas()
{
    return mysql_affected_rows(this->objDatos);
}

int conexion:: numero_columnas(MYSQL_RES *res)
{
    return mysql_num_fields(res);
}

const char * conexion:: nombre_columna(MYSQL_RES *res, int indice)
{
    return mysql_fetch_field_direct(res, indice)->name;
}

int conexion :: longitud_columna(MYSQL_RES *res, int indice)
{
    return mysql_fetch_field_direct(res, indice)->length;
}

const char * conexion:: valor_defecto_columna(MYSQL_RES *res, int indice)
{
    MYSQL_FIELD *col = mysql_fetch_field_direct(res, indice);
    return col->def ? col->def : "NULL";
}

MYSQL_ROW  conexion :: obtener_fila(MYSQL_RES *res)
{
    return mysql_fetch_row(res);
}

void conexion :: fijar_fila(MYSQL_RES *res, int indice)
{
     mysql_data_seek(res, indice);
}

unsigned long conexion :: ultimo_id()
{
    return (unsigned long )mysql_insert_id(this->objDatos);
}

/*void conexion::m_conectar_BD(MYSQL *objDatos, char *cConsulta){

if(mysql_real_connect(objDatos,"127.0.0.1","root","MJ1227?","ferreteria",3306,NULL,0)){
    //std::cout<<"\nConectando a la base de datos";
    mysql_query(objDatos,cConsulta);

    if (mysql_error(objDatos) != NULL){
            //std::cout<<"\nDatos grabados con exito";
            std::cout<<"\nDatos Grabados-->"<<mysql_error(objDatos);

    } else {
    std::cout<<"\nError al grabar en la base de datos-->"<<mysql_error(objDatos);
    }
} else{
    std::cout<<"Error al conectarse a la base de datos-->"<<mysql_error(objDatos);
}

//mysql_close();
}
*/



conexion::~conexion()
{
    this->sql_close();
}
