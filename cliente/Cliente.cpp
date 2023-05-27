#include <iostream>
#include "Cliente.h"
#include "conexion.h"
#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"
#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysqld_error.h"
using namespace std;
Cliente::Cliente()
{
    //ctor
}

        //estructura para save Cliente
        struct ClienteI{
            char nit [45];
            char nombre [45];
            char apellido [45];
            char telefono [12];
            char correo [45];
            char direccion [45];
        }sClienteI;

         struct ClienteE{
            char dato [45];
            char idCliente [10];
            char *col;

        }sClienteE;

     conexion objsqlC; //PARA CONECTAR A DB

    int Cliente::guardarCliente(){

    char *cConsulta;
    char cSentencia[]="INSERT INTO ferreteria.cliente (`nit`,`nombre`,`apellido`,`telefono`,`correo`,`direccion`) VALUES(\'%s\', \'%s\', \'%s\',\'%s\',\'%s\',\'%s'\)";

    cConsulta = new char[strlen(cSentencia)+sizeof(ClienteI)-sizeof(int)];
    sprintf(cConsulta,cSentencia,sClienteI.nit, sClienteI.nombre, sClienteI.apellido, sClienteI.telefono, sClienteI.correo, sClienteI.direccion);

    objsqlC.ejecutar_sql(cConsulta);
    objsqlC.sql_close();
    return 0;

    }

    int Cliente::editarCliente(){
        cout<<"entre a editar";
   char *consulta;
   char sentencia[] = "update ferreteria.cliente SET \%s\ =\'%s\' WHERE idCliente = \'%s\'";

   consulta = new char[strlen(sentencia)+sizeof(ClienteE)-sizeof(int)];
   sprintf(consulta, sentencia, sClienteE.col, sClienteE.dato, sClienteE.idCliente);
   objsqlC.ejecutar_sql(consulta);

   return 0;
    }



    void Cliente::ingresarCliente(){

    printf("Ingrese Nit:");

    scanf("%s",&sClienteI.nit);

    printf("Ingrese Nombre:");

    scanf("%s",&sClienteI.nombre);

    printf("Ingrese Apellido: ");
    scanf("%s",&sClienteI.apellido);

    printf("Ingrese numero de telefono ");
    scanf("%s",&sClienteI.telefono);

    printf("Ingrese correo ");
    scanf("%s",&sClienteI.correo);

    printf("Ingrese direccion ");
    scanf("%s",&sClienteI.direccion);

    guardarCliente();
    }



    void Cliente::buscarCliente(int op)
{
   char idCliente[20];
   char *consulta;
   MYSQL *objDatos;
   char sentencia[] = "Select  `nit`,`nombre`,`apellido`,`telefono`,`correo`,`direccion`,`estado` from ferreteria.cliente where idcliente = \'%s\'";

   MYSQL_RES *res;
   MYSQL_ROW  row;

   cout << "Ingrese ID del Cliente: ";
   scanf("%s",&sClienteE.idCliente);


   consulta = new char[strlen(sentencia)+sizeof(ClienteE)-sizeof(int)];
   sprintf(consulta, sentencia, sClienteE.idCliente);
   res = objsqlC.ejecutar_sql(consulta);

   if(objsqlC.filas_afectadas()>0)
   {
       if(op==2){

      row = objsqlC.obtener_fila(res);
      cout << "NIT: "<<row[0]<<endl;
      cout << "Nombre: "<<row[0]<<endl;
      cout << "Apellido: " << row[1] << endl;
      cout << "Telefono: " << row[2] << endl;
      cout << "correo: " << row[3] << endl;
      cout << "direccion: " << row[4] << endl;
      if(atoi(row[6])==0){
      cout << "Activo " << endl;
      }
      system("pause");
       }else {
         menuEditar();
       }
   }
   else
      cout << "Cliente no encontrado" << endl;
}


void Cliente::menuEditar(){

        int opcion = 0;

    while(opcion <7){
//	MENÚ DE OPTIONES LISTADA
	system("cls");
	cout<<"****************************************************************************************************"<<endl;
	cout<<"*    SELECCIONE LA OPCION QUE DESEA EDITAR.                                                        *"<<endl;
	cout<<"****************************************************************************************************"<<endl<<endl;
	cout<<"* 1. NIT                                                                                           *"<<endl<<endl;
	cout<<"* 2. Nombre                                                                                        *"<<endl<<endl;
	cout<<"* 3. Apellido                                                                                      *"<<endl<<endl;
	cout<<"* 4. Telefono                                                                                      *"<<endl<<endl;
	cout<<"* 5. Correo                                                                                        *"<<endl<<endl;
	cout<<"* 6. Direccion                                                                                      *"<<endl<<endl;
	cout<<"* 7. Salir                                                                                         *"<<endl<<endl;
	cout<<"****************************************************************************************************"<<endl;
	cin>>opcion;
    system("cls");
	switch(opcion) {
    case 1:
    	 printf("Ingrese NIT ");
         scanf("%s",&sClienteE.dato);
         sClienteE.col= "nit";

        editarCliente();
    break;
	case 2:
    	 printf("Ingrese Nombre ");
         scanf("%s",&sClienteE.dato);
         sClienteE.col= "nombre";

         editarCliente();
    	break;


    case 3:
         printf("Ingrese Apellido: ");
          scanf("%s",&sClienteE.dato);
         sClienteE.col= "apellido";

         editarCliente();

    	break;

    case 4:
         printf("Ingrese Telefono ");
          scanf("%s",&sClienteE.dato);
         sClienteE.col= "telefono";

         editarCliente();


    	break;

    case 5:
         printf("Ingrese correo ");
          scanf("%s",&sClienteE.dato);
         sClienteE.col= "correo";

         editarCliente();

    	break;

	case 6:
	     printf("Ingrese Direccion ");
         scanf("%s",&sClienteE.dato);
         sClienteE.col= "direccion";

         editarCliente();


    	break;

    case 7:
        cout<<"\nSALIDA, PUEDES CERRAR ESTA VENTANA.\n"<<endl;

    }
    }
    }




    void Cliente::menuCliente(){
        char col[20];
        int opcion = 0;

    while(opcion <5){
	//MENÚ DE OPTIONES LISTADA
	system("cls");
	cout<<"****************************************************************************************************"<<endl;
	cout<<"*    MENÚ DE OPCIONES.                                                                             *"<<endl;
	cout<<"****************************************************************************************************"<<endl<<endl;
	cout<<"* 1. Nuevo Cliente                                                                                 *"<<endl<<endl;
	cout<<"* 2. Modificar Cliente                                                                             *"<<endl<<endl;
	cout<<"* 3. Cambiar Estado                                                                                *"<<endl<<endl;
	cout<<"* 4. Consulta                                                                                       *"<<endl<<endl;
	cout<<"* 5. Salir.                                                                                        *"<<endl<<endl;
	cout<<"****************************************************************************************************"<<endl;
	cin>>opcion;

	switch(opcion) {
    case 1:
    	system("cls");
    	ingresarCliente();
		break;

    case 2:
    	system("cls");
    	buscarCliente(1);
    	break;

    case 3:
    	system("cls");

    	break;

    case 4:
    	system("cls");
        buscarCliente(2);
    	break;

	case 5:
	    cout<<"\nSALIDA, PUEDES CERRAR ESTA VENTANA.\n"<<endl;

    }
    }
    }


Cliente::~Cliente()
{
    //dtor
}
