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

	cout << "Escolha a opção:\n1) Adicionar instrução\n2) Ver Pipeline" << endl;
	while(resp != 2){
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

	/*for(int i=0; i< (int)instrucoes.size(); i++){
		cout << instrucoes[i]->getInst() << " " << instrucoes[i]->getOp1() << " " << instrucoes[i]->getOp2() << " " ;
		cout << instrucoes[i]->getOp3() << " " << instrucoes[i]->getInicio()<< " " << instrucoes[i]->getFim() << endl;
	}*/

	imprimirPipeline(instrucoes);
	instrucoes.clear();
	instrucoes.~vector();
	return 0;
}