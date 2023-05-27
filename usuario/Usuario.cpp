#include <iostream>
#include "Usuario.h"
#include "conexion.h"
#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"
#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysqld_error.h"
using namespace std;
Usuario::Usuario()
{
    //ctor
}
        //estructura para usuarios
        struct UsuarioI{
            char nombre [45];
            char apellido [45];
            char nickName [20];
            char correo [45];
            char password [12];
            char telefono [10];
            int tipoUusario;

        }sUsuarioI;

        struct UsuarioE{
            char dato [45];
            char idUser [10];
            char *col;

        }sUsuarioE;


     conexion objsql;

    int Usuario::guardarUsuario(){

    char *cConsulta;
    char cSentencia[]="INSERT INTO ferreteria.usuario (`nombre`,`apellido`,`nickName`,`correo`,`pass`,`telefono`,`tipoUsuario`,`fechaIngreso`) VALUES(\'%s\', \'%s\', \'%s\',\'%s\',\'%s\',\'%d'\,\'%d'\,CURRENT_TIMESTAMP)";

    cConsulta = new char[strlen(cSentencia)+sizeof(UsuarioI)-sizeof(int)];
    sprintf(cConsulta,cSentencia, sUsuarioI.nombre, sUsuarioI.apellido, sUsuarioI.nickName, sUsuarioI.correo, sUsuarioI.password, sUsuarioI.telefono, sUsuarioI.tipoUusario);

    objsql.ejecutar_sql(cConsulta);
    return 0;

    }

    int Usuario::editarUsuario(){
        cout<<"entre a editar";
   char *consulta;
   char sentencia[] = "update ferreteria.usuario SET \%s\ =\'%s\' WHERE idUsuario = \'%s\'";
   //cout<<"sentencia "<<sentencia<<endl;
   consulta = new char[strlen(sentencia)+sizeof(UsuarioE)-sizeof(int)];
   sprintf(consulta, sentencia, sUsuarioE.col, sUsuarioE.dato, sUsuarioE.idUser);
   cout<<"consulta "<<consulta<<endl;
   cout<<"sentencia "<<sentencia<<endl;
   objsql.ejecutar_sql(consulta);

   return 0;
    }


    void Usuario::ingresarUsuario(int op, bool flag){
    char dato[]="";

    //if(op==1){
    printf("Ingrese Nombre:");
    scanf("%s",&sUsuarioI.nombre);
    //scanf("%s",dato);
   // cout<<dato<< " Valor dato"<<endl;
   // if(flag){
    //    op==2;
   //     cout<<"INGRESE A EL IF FLAG PARA OP 2"<<endl;
   // }


   // if(op==2){
    printf("Ingrese Apellido: ");
    scanf("%s",&sUsuarioI.apellido);
   // scanf("%s",dato);
  //  }

   // if(op==3){
    printf("Ingrese nickName: ");
    scanf("%s",&sUsuarioI.nickName);
   // scanf("%s",dato);
   // }

  //  if(op==4){
    printf("Ingrese correo: ");
    scanf("%s",&sUsuarioI.correo);
  //  scanf("%s",dato);
  //  }
   //  if(op==5){
    printf("Ingrese password: ");
    scanf("%s",&sUsuarioI.password);
   // scanf("%s",dato);
   // }
   //  if(op==6){
    printf("Ingrese telefono: ");
    scanf("%s",&sUsuarioI.telefono);
   // scanf("%s",dato);
   // }
    //if(op==7){
    printf("Seleccione un numero\n\n 1.Vendedor\n 2.Gerente\n\n");
    scanf("%d",&sUsuarioI.tipoUusario);
   // }


            guardarUsuario();

    }



    void Usuario::buscarUsuario(int op)
{
   char *consulta;
   MYSQL *objDatos;
   char sentencia[] = "Select  `nombre`,`apellido`,`nickName`,`correo`,`pass`,`telefono`,`estado`,`tipoUsuario` from ferreteria.usuario where idusuario = \'%s\'";

   MYSQL_RES *res;
   MYSQL_ROW  row;

   cout << "Ingrese ID del usuario: ";
   scanf("%s",&sUsuarioE.idUser);


   consulta = new char[strlen(sentencia)+sizeof(UsuarioE)-sizeof(int)];
   sprintf(consulta, sentencia, sUsuarioE.idUser);

   res = objsql.ejecutar_sql(consulta);
   if(objsql.filas_afectadas()>0)
   {
       if(op==2){
      row = objsql.obtener_fila(res);
      cout << "Nombre: "<<row[0]<<endl;
      cout << "Apellido: " << row[1] << endl;
      cout << "nickName: " << row[2] << endl;
      cout << "correo: " << row[3] << endl;
      cout << "Password: " << row[4] << endl;
      cout << "telefono: " << row[5] << endl;

      if(atoi(row[6])==0){
        cout << "Estado: Activo" <<endl;
      }

     if(atoi(row[7])==1){
        cout << "Puesto: Vendedor" <<endl;
      }else{
        cout << "Puesto: Gerente" <<endl;
      }
        system("pause");
       }else {
            menuEditar();
       }
   }
   else
      cout << "Usuario no encontrado" << endl;
}

    void Usuario::menuEditar(){

        int opcion = 0;

    while(opcion <7){
//	MENÚ DE OPTIONES LISTADA
	system("cls");
	cout<<"****************************************************************************************************"<<endl;
	cout<<"*    SELECCIONE LA OPCION QUE DESEA EDITAR.                                                        *"<<endl;
	cout<<"****************************************************************************************************"<<endl<<endl;
	cout<<"* 1. nombre                                                                                        *"<<endl<<endl;
	cout<<"* 2. apellido                                                                                      *"<<endl<<endl;
	cout<<"* 3. nickName                                                                                      *"<<endl<<endl;
	cout<<"* 4. correo                                                                                        *"<<endl<<endl;
	cout<<"* 5. passWord                                                                                      *"<<endl<<endl;
	cout<<"* 6. telefono                                                                                      *"<<endl<<endl;
	cout<<"* 7. Salir                                                                                         *"<<endl<<endl;
	cout<<"****************************************************************************************************"<<endl;
	cin>>opcion;
    system("cls");
	//EVENTO SWITCH, LA VARIABLE "opcion" ALMACENA EL DATO Y SE COMPARA EN EL SWITCH
	switch(opcion) {
	case 1:
    	 printf("Ingrese Nombre: ");
         scanf("%s",&sUsuarioE.dato);
         sUsuarioE.col= "nombre";

         editarUsuario();
    	break;


    case 2:
         printf("Ingrese Apellido: ");
         scanf("%s",&sUsuarioE.dato);
         sUsuarioE.col= "apellido";

         editarUsuario();

    	break;

    case 3:
         printf("Ingrese nickName: ");
         scanf("%s",&sUsuarioE.dato);
         sUsuarioE.col= "nickName";

         editarUsuario();

    	break;

    case 4:
         printf("Ingrese correo: ");
         scanf("%s",&sUsuarioE.dato);
         sUsuarioE.col= "correo";

         editarUsuario();

    	break;

	case 5:
	     printf("Ingrese passWord: ");
         scanf("%s",&sUsuarioE.dato);
         sUsuarioE.col= "pass";

         editarUsuario();

    	break;

    case 6:
         printf("Ingrese telefono: ");
         scanf("%s",&sUsuarioE.dato);
         sUsuarioE.col= "telefono";

         editarUsuario();

    	break;

    case 7:

    cout<<"\nSALIDA, PUEDES CERRAR ESTA VENTANA.\n"<<endl;
    }
    }
    }


    void Usuario::menuUser(){
        char col[20];
        int opcion = 0;

    while(opcion <5){
	//MENÚ DE OPTIONES LISTADA
	system("cls");
	cout<<"****************************************************************************************************"<<endl;
	cout<<"*    MENÚ DE OPCIONES.                                                                             *"<<endl;
	cout<<"****************************************************************************************************"<<endl<<endl;
	cout<<"* 1. Nuevo Usuario                                                                                 *"<<endl<<endl;
	cout<<"* 2. Modificar Usuario                                                                             *"<<endl<<endl;
	cout<<"* 3. Cambiar Estado                                                                                *"<<endl<<endl;
	cout<<"* 4. Reporte                                                                                       *"<<endl<<endl;
	cout<<"* 5. Salir.                                                                                        *"<<endl<<endl;
	cout<<"****************************************************************************************************"<<endl;
	cin>>opcion;

	//EVENTO SWITCH, LA VARIABLE "opcion" ALMACENA EL DATO Y SE COMPARA EN EL SWITCH
	switch(opcion) {
    case 1:
    	system("cls");
    	ingresarUsuario(1,true);
		break;

    case 2:
    	system("cls");
    	buscarUsuario(1);
    	break;

    case 3:
    	system("cls");

    	break;

    case 4:
    	system("cls");
        buscarUsuario(2);
    	break;

	case 5:
    	cout<<"\nSALIDA, PUEDES CERRAR ESTA VENTANA.\n"<<endl;

    }
    }
    }

Usuario::~Usuario()
{
    //dtor
}
