#include <iostream>
#include "conexion.h"
#include "Usuario.h"
#include "Cliente.h"
#include "Proveedor.h"
#include "mercaderia.h"
#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"
#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysqld_error.h"
using namespace std;

int main()
{
   /*conexion cConn;
    MYSQL *objDatos;
    char *cConsulta;

    if(!(objDatos = mysql_init(0))){
       cout<<"Error al cargar el driver de la base de datos";
       //return 1;
       }
    cConn.m_conectar_BD(objDatos, cConsulta);
    //return 0;
*/
    Usuario user;
    Cliente client;
    Proveedor prov;
    mercaderia mer;

int opcion = 0;

while(opcion <6){
	//MENÚ DE OPTIONES LISTADA
	system("cls");
	cout<<"****************************************************************************************************"<<endl;
	cout<<"*    MENÚ DE OPCIONES.                                                                             *"<<endl;
	cout<<"****************************************************************************************************"<<endl<<endl;
	cout<<"* 1. Usuario.                                                                                      *"<<endl<<endl;
	cout<<"* 2. Mercaderia.                                                                                   *"<<endl<<endl;
	cout<<"* 3. Clientes.                                                                                     *"<<endl<<endl;
	cout<<"* 4. Proveedores                                                                                   *"<<endl<<endl;
	cout<<"* 5. Compra.                                                                                       *"<<endl<<endl;
	cout<<"* 6. Venta.                                                                                        *"<<endl<<endl;
	cout<<"* 7. Salir.                                                                                        *"<<endl<<endl;
	cout<<"****************************************************************************************************"<<endl;
	cin>>opcion;

	//EVENTO SWITCH, LA VARIABLE "opcion" ALMACENA EL DATO Y SE COMPARA EN EL SWITCH
	switch(opcion) {
    case 1:
    	system("cls");
        user.menuUser();
		break;

    case 2:
    	system("cls");
        mer.menuMer();
    	break;

    case 3:
    	system("cls");
        client.menuCliente();
    	break;

    case 4:
    	system("cls");
        prov.menuProv();
    	break;

	case 5:
		system("cls");

    	break;

    case 6:
		system("cls");

    	break;

	case 7:
    	cout<<"\nSALIDA, PUEDES CERRAR ESTA VENTANA.\n"<<endl;
		cout<<"(?^o^?)"<<endl;

}

}
}
