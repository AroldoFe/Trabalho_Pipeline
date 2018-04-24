#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

#include "../include/adicionarInstrucao.hpp"

//boost::split(results, text, [](char c){return c == ' ';});

void adicionarInstrucao(vector<Assembly*> &instrucoes, int iden){
	string inst, op1, op2, op3;

	instrucoes.push_back(new Assembly());

	cout << "\nDigite a instrução: ";
	cin >> inst;
/*
	//string split_inst = new string();

	vector<string> split_inst;

	split(split_inst, inst, is_any_of(" "));

	cout << split_inst.size() << endl;
*/	
	//if(split_inst[0] != "lw" && split_inst[0] != "sw" && split_inst[0] != "j"){
	if(inst != "lw" && inst != "sw" && inst != "j"){
		cout << "Digite o Operando 1: ";
		cin >> 	op1;
		cout << "Digite o Operando 2: ";
		cin >> 	op2;
		cout << "Digite o Operando 3: ";
		cin >> 	op3;

		Assembly r(iden, inst, op1, op2, op3);
		//Assembly r(iden, split_inst[0], split_inst[1], split_inst[2], split_inst[3]);

		instrucoes[iden-1]->copy(r);
		return;
	}
	//else if(split_inst[0] == "lw" || split_inst[0] == "sw"){
	else if(inst == "lw" || inst == "sw"){
		cout << "Digite o Operando 1: ";
		cin >> op1;
		cout << "Digite o Operando 2: ";
		cin >> op2;

		//Assembly r(iden, split_inst[0], split_inst[1], split_inst[2], "\0");
		Assembly r(iden, inst, op1, op2, "\0");
		instrucoes[iden-1]->copy(r);
		return;
	}
	cout << "Digite o Operando 1: ";
	cin >> op1;
	//Assembly r(iden, split_inst[0], split_inst[1], "\0", "\0");
	Assembly r(iden, inst, op1, "\0", "\0");
	instrucoes[iden-1]->copy(r);
	//delete[] split_inst;
}