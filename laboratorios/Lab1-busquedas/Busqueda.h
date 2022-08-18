class Busqueda {
	private:
		int tam;
		int *vec;
		int binariaRecursiva(int num, int l, int r);
	public:
		Busqueda(int n);
		~Busqueda();
		int size();
		int lineal(int num);
		int binariaRecursiva(int num);
		int binariaIterativa(int num);
};