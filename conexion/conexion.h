#ifndef CONEXION_H
#define CONEXION_H
#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"
#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysqld_error.h"
#include <iostream>
using namespace std;
class conexion
{
    public:
        //conexion();
    conexion();

     void sql_close();
     MYSQL_RES * ejecutar_sql(char *sql);
     int numero_filas(MYSQL_RES *res);
     int filas_afectadas();
     int numero_columnas(MYSQL_RES *res);
     const char *nombre_columna(MYSQL_RES *res, int indice);
     int longitud_columna(MYSQL_RES *res, int indice);
     const char *valor_defecto_columna(MYSQL_RES *res, int indice);
     MYSQL_ROW obtener_fila(MYSQL_RES *res);
     void fijar_fila(MYSQL_RES *res, int indice);

     unsigned long ultimo_id();
        //void m_conectar_BD(MYSQL *objDatos, char *cConsulta);
        virtual ~conexion();

    protected:

    private:
     MYSQL *objDatos;
};

#endif // CONEXION_H
