#ifndef PROVEEDOR_H
#define PROVEEDOR_H


class Proveedor
{
    public:
        Proveedor();
        int guardarProv();
        void ingresarProv();
        void buscarProv();
        void menuProv();
        virtual ~Proveedor();

    protected:

    private:
};

#endif // PROVEEDOR_H
