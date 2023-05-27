#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
using namespace std;
class Usuario
{
    public:
        Usuario();
        int guardarUsuario();
        void ingresarUsuario(int op, bool flag);
        int validarUsuario();
        int editarUsuario();
        void buscarUsuario(int op);
        void menuEditar();
        void menuUser();
        virtual ~Usuario();

    protected:

    private:

};

#endif // USUARIO_H
