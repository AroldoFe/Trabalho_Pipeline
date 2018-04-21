#ifndef ClassAssembly
#define ClassAssembly
	#include <string>
	#include <iostream>
	using namespace std;

	class Assembly{
	private:
		int id;
		string inst;
		string op1;
		string op2;
		string op3;
		string dep2;
		int inst2;
		string dep3;
		int inst3;
		int jumpInst;
		int inicio;
		int ciclo;
		int fim;
	public:
		Assembly();
		Assembly(int id, string ins, string ope1, string ope2, string ope3);
		~Assembly();

		int getId();
		void setId(int val);

		string getInst();
		void setInst(string val);

		string getOp1();
		void setOp1(string val);

		string getOp2();
		void setOp2(string val);

		string getOp3();
		void setOp3(string val);

		string getDep2();
		void setDep2(string val);

		int getInst2();
		void setInst2(int val);

		string getDep3();
		void setDep3(string val);

		int getInst3();
		void setInst3(int val);

		int getJumpInst();
		void setJumpInst(int val);

		int getInicio();
		void setInicio(int in);

		int getCiclo();
		void setCiclo(int ci);

		int getFim();

		void copy(Assembly r);

		friend ostream& operator<< (ostream &o, Assembly const &ass);
	};
#endif