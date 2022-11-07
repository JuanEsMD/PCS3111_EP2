#define QUANTIDADE_REGISTRADORES 32

class BancoDeRegistradores{

public:
	BancoDeRegistradores();
	virtual ~BancoDeRegistradores();
	virtual int getValor(int registrador);
	virtual void setValor(int registrador, int valor);
	virtual void imprimir();

private:

	int array[32];
};
