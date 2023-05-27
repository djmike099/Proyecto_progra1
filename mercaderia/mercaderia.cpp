#include "mercaderia.h"
#include "conexion.h"
#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"
#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysqld_error.h"
#include <iostream>
using namespace std;
mercaderia::mercaderia()
{
    //ctor
}

          //estructura para save mercaderia
        struct mercaderiaI{
            char codBarra [45];
            char descripcion [45];
            double precioCompra;
            double precioVenta;
            double stockMinimo;
            double stockTienda;
            double idProveedor;
            char unidadMedida [45];
        }smercaderiaI;


     conexion objsqlM; //PARA CONECTAR A DB

    int mercaderia::guardarMer(){

    char *cConsulta;
    char cSentencia[]="INSERT INTO ferreteria.producto (`codBarra`,`descripcion`,`precioCompra`,`precioVenta`,`stockMinimo`,`stockTienda`,`idProveedor`,`unidadMedida`) VALUES(\'%s\', \'%s\', \'%f\',\'%f\',\'%d\',\'%d'\,\'%d'\,\'%s'\)";

    cConsulta = new char[strlen(cSentencia)+sizeof(mercaderiaI)-sizeof(int)];
    sprintf(cConsulta,cSentencia,smercaderiaI.codBarra, smercaderiaI.descripcion, smercaderiaI.precioCompra, smercaderiaI.precioVenta, smercaderiaI.stockMinimo, smercaderiaI.stockTienda, smercaderiaI.idProveedor, smercaderiaI.unidadMedida);

    objsqlM.ejecutar_sql(cConsulta);
    return 0;

    }


    void mercaderia::ingresarMer(){

    printf("Ingrese codBarra:");

    scanf("%s",&smercaderiaI.codBarra);

    printf("Ingrese Descripcion:");

    scanf("%s",&smercaderiaI.descripcion);

    printf("Ingrese precio compra: ");
    scanf("%f",&smercaderiaI.precioCompra);

    printf("Ingrese precio venta ");
    scanf("%f",&smercaderiaI.precioVenta);

    printf("Ingrese stock minimo ");
    scanf("%d",&smercaderiaI.stockMinimo);

    printf("Ingrese stock tienda ");
    scanf("%d",&smercaderiaI.stockTienda);

    printf("Ingrese ID proveedor ");
    scanf("%d",&smercaderiaI.idProveedor);

    printf("Ingrese unidad de medida ");
    scanf("%s",&smercaderiaI.unidadMedida);

    guardarMer();
    }



    void mercaderia::buscarMer()
{
   char codBarra[45];
   char *consulta;
   char sentencia[] = "Select  `nit`,`nombre`,`apellido`,`telefono`,`correo`,`direccion`,`estado` from ferreteria.cliente where idcliente = \'%s\'";

   MYSQL_RES *res;
   MYSQL_ROW  row;

   cout << "Ingrese codigo de barra: ";
   cin >> codBarra;

   consulta = new char[strlen(sentencia)+strlen(codBarra)];
   sprintf(consulta, sentencia, codBarra);

   res = objsqlM.ejecutar_sql(consulta);

   if(objsqlM.filas_afectadas()>0)
   {
      row = objsqlM.obtener_fila(res);
      cout << "CodBarra: "<<row[0]<<endl;
      cout << "Descripcion: "<<row[0]<<endl;
      cout << "Unidad de Medida: " << row[4] << endl;
      cout << "Precio Venta: " << row[1] << endl;
      cout << "stock Tienda: " << row[2] << endl;
      cout << "Proveedor: " << row[3] << endl;
      system("pause");
   }
   else
      cout << "Producto no encontrado" << endl;
}




    void mercaderia::menuMer(){
        char col[20];
        int opcion = 0;

    while(opcion <5){
	//MENÚ DE OPTIONES LISTADA
	system("cls");
	cout<<"****************************************************************************************************"<<endl;
	cout<<"*    MENÚ DE OPCIONES.                                                                             *"<<endl;
	cout<<"****************************************************************************************************"<<endl<<endl;
	cout<<"* 1. Nuevo Producto                                                                                *"<<endl<<endl;
	cout<<"* 2. Consulta                                                                                       *"<<endl<<endl;
	cout<<"* 3. Salir.                                                                                        *"<<endl<<endl;
	cout<<"****************************************************************************************************"<<endl;
	cin>>opcion;

	//EVENTO SWITCH, LA VARIABLE "opcion" ALMACENA EL DATO Y SE COMPARA EN EL SWITCH
	switch(opcion) {
    case 1:
    	system("cls");
    	ingresarMer();
		break;

    case 2:
    	system("cls");

    	break;

    case 3:
    	cout<<"\nSALIDA, PUEDES CERRAR ESTA VENTANA.\n"<<endl;
		cout<<"(?^o^?)"<<endl;

    }
    }
    }

mercaderia::~mercaderia()
{
    //dtor
}
