/***************************************************************/
/**                                                           **/
/**   Juan Estevão Mordente D'Angelo           13681190       **/
/**   Mateus Pinheiro Negocia                 13681248        **/
/**   Exercício-Programa E2                                   **/
/**   Arquivo: Dado.h                                         **/
/**                                                           **/
/***************************************************************/


#ifndef DADO_H
#define DADO_H

class Dado{
	public:
		Dado(int valor);
		virtual ~Dado();
		virtual int getValor();
		virtual void imprimir();

	protected:
		int valor;
};

#endif // DADO_H