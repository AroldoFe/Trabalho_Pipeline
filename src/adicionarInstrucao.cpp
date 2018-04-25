#include <iostream>
#include <vector>
//#include <boost/algorithm/string.hpp>
using namespace std;
//using namespace boost;

#include "../include/adicionarInstrucao.hpp"

void adicionarInstrucao(vector<Assembly*> &instrucoes, int iden){
	string op1, op2, op3, inst;

	instrucoes.push_back(new Assembly());

	//cout << "\nDigite o opcode: ";
	cin >> inst;

	if(inst != "lw" && inst != "sw" && inst != "j"){
		//cout << "Digite o Operando 1: ";
		cin >> 	op1;
		//cout << "Digite o Operando 2: ";
		cin >> 	op2;
		//cout << "Digite o Operando 3: ";
		cin >> 	op3;

		Assembly r(iden, inst, op1, op2, op3);

		instrucoes[iden-1]->copy(r);
		return;
	}
	else if(inst == "lw" || inst == "sw"){
		//cout << "Digite o Operando 1: ";
		cin >> op1;
		//cout << "Digite o Operando 2: ";
		cin >> op2;

		Assembly r(iden, inst, op1, op2, "\0");
		instrucoes[iden-1]->copy(r);
		return;
	}
	//cout << "Digite o Operando 1: ";
	cin >> op1;
	Assembly r(iden, inst, op1, "\0", "\0");
	instrucoes[iden-1]->copy(r);
}