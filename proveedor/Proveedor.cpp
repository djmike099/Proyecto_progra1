#include "Proveedor.h"
#include "conexion.h"
#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"
#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysqld_error.h"
#include <iostream>
using namespace std;
Proveedor::Proveedor()
{
    //ctor
}

        //estructura para save proveedor
        struct ProveedorI{
            char nombre [45];
            char telefono [12];
            char correo [45];
            char direccion [45];
        }sProveedorI;


     conexion objsqlP; //PARA CONECTAR A DB

    int Proveedor::guardarProv(){

    char *cConsulta;
    char cSentencia[]="INSERT INTO ferreteria.proveedor (`nombre`,`telefono`,`correo`,`direccion`) VALUES(\'%s\', \'%s\', \'%s\',\'%s\')";

    cConsulta = new char[strlen(cSentencia)+sizeof(ProveedorI)-sizeof(int)];
    sprintf(cConsulta,cSentencia, sProveedorI.nombre, sProveedorI.telefono, sProveedorI.correo, sProveedorI.direccion);

    objsqlP.ejecutar_sql(cConsulta);
    return 0;

    }


    void Proveedor::ingresarProv(){

    printf("Ingrese Nombre:");

    scanf("%s",&sProveedorI.nombre);

    printf("Ingrese numero de telefono ");
    scanf("%s",&sProveedorI.telefono);

    printf("Ingrese correo ");
    scanf("%s",&sProveedorI.correo);

    printf("Ingrese direccion ");
    scanf("%s",&sProveedorI.direccion);

    guardarProv();
    }



    void Proveedor::buscarProv()
{
   char idProv[20];
   char *consulta;
   char sentencia[] = "Select  `nombre`,`telefono`,`correo`,`direccion` from ferreteria.proveedor where idProveedor = \'%s\'";

   MYSQL_RES *res;
   MYSQL_ROW  row;

   cout << "Ingrese ID del Proveedor: ";
   cin >> idProv;

   consulta = new char[strlen(sentencia)+strlen(idProv)];
   sprintf(consulta, sentencia, idProv);
   res = objsqlP.ejecutar_sql(consulta);

   if(objsqlP.filas_afectadas()>0)
   {
      row = objsqlP.obtener_fila(res);
      cout << "Nombre: "<<row[0]<<endl;
      cout << "Telefono: " << row[1] << endl;
      cout << "correo: " << row[2] << endl;
      cout << "direccion: " << row[3] << endl;
      system("pause");
   }
   else
      cout << "Cliente no encontrado" << endl;
}




    void Proveedor::menuProv(){
        char col[20];
        int opcion = 0;

    while(opcion <5){
	//MENÚ DE OPTIONES LISTADA
	system("cls");
	cout<<"****************************************************************************************************"<<endl;
	cout<<"*    MENÚ DE OPCIONES.                                                                             *"<<endl;
	cout<<"****************************************************************************************************"<<endl<<endl;
	cout<<"* 1. Nuevo Proveedor                                                                                 *"<<endl<<endl;
	cout<<"* 2. Modificar Proveedor                                                                             *"<<endl<<endl;
	cout<<"* 3. Cambiar Estado                                                                                *"<<endl<<endl;
	cout<<"* 4. Consulta                                                                                       *"<<endl<<endl;
	cout<<"* 5. Salir.                                                                                        *"<<endl<<endl;
	cout<<"****************************************************************************************************"<<endl;
	cin>>opcion;

	//EVENTO SWITCH, LA VARIABLE "opcion" ALMACENA EL DATO Y SE COMPARA EN EL SWITCH
	switch(opcion) {
    case 1:
    	system("cls");
    	ingresarProv();
		break;

    case 2:
    	system("cls");

    	break;

    case 3:
    	system("cls");

    	break;

    case 4:
    	system("cls");
        buscarProv();
    	break;

	case 5:
    	cout<<"\nSALIDA, PUEDES CERRAR ESTA VENTANA.\n"<<endl;
		cout<<"(?^o^?)"<<endl;




    }
    }
    }

Proveedor::~Proveedor()
{
    //dtor
}
