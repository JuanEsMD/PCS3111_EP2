class Dado{
	public:
		Dado(int valor);
		virtual ~Dado();
		virtual int getValor();
		virtual void imprimir();

	protected:
		int valor;
};
