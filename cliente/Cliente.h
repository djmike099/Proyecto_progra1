#ifndef CLIENTE_H
#define CLIENTE_H


class Cliente
{
    public:
        Cliente();
        int guardarCliente();
        void ingresarCliente();
        int validarCliente();
        int editarCliente();
        void buscarCliente(int op);
        void menuCliente();
        void menuEditar();
        virtual ~Cliente();

    protected:

    private:
};

#endif // CLIENTE_H
