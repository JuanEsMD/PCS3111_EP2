/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                 13681248        **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: BancoDeRegistradores.h                         **/
/**                                                           **/
/***************************************************************/

#ifndef BANCODEREGISTRADORES_H
#define BANCODEREGISTRADORES_H

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

#endif // BANCODEREGISTRADORES_H
