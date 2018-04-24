#include <iostream>
#include <vector>
using namespace std;

#include "../include/assembly.hpp"
#include "../include/adicionarInstrucao.hpp"
#include "../include/verDepend.hpp"
#include "../include/imprimirPipeline.hpp"
#include "../include/calcularPipeline.hpp"
//#include "../include/verJump.hpp"

int main(){
	vector<Assembly*> instrucoes;

	int resp = 1, cont = 1;

	while(resp != 2){
		cout << "Escolha a opção:\n1) Adicionar instrução\n2) Ver Pipeline" << endl;
		cin >> resp;
		switch(resp){
			case 1:
				adicionarInstrucao(instrucoes, cont);
				cont++;
				break;
			case 2:
				break;
			default:
				cout << "Opção inválida!" << endl;
		}
	}

	

	verDepend(instrucoes);
	// Calcular onde cada instrução inicia
	calcularPipeline(instrucoes);
	//verJump(instrucoes);
	// Imprimir
	imprimirPipeline(instrucoes);
	instrucoes.clear();
	instrucoes.~vector();
	return 0;
}