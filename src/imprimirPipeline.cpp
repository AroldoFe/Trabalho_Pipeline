#include <iostream>
#include <vector>
using namespace std;
#include "../include/imprimirPipeline.hpp"

void imprimirPipeline(vector<Assembly*> &instrucoes){
	int cont = 0;
	cout << "\n*** Quantidade de Ciclos totais: " << instrucoes[(int)instrucoes.size()-1]->getFim() << endl;
	//int cp = 1;

	for(int ciclo=1; ciclo <= instrucoes[(int)instrucoes.size()-1]->getFim(); ciclo++){
		int nada = 0;
		bool val = false;
		cout << "\n--------------------------------\nCiclo " << ciclo;
		cout << "\nIF: ";
		for(int i=0; i<(int)instrucoes.size(); i++){
			if(instrucoes[i]->getInicio() == ciclo && instrucoes[i]->getCiclo() == 1){

				
				cout << instrucoes[i]->getInst() << " " << instrucoes[i]->getOp1() << ", ";
				cout << instrucoes[i]->getOp2() << ", " << instrucoes[i]->getOp3();
				
				instrucoes[i]->setInicio(instrucoes[i]->getInicio()+1);
				instrucoes[i]->setCiclo(instrucoes[i]->getCiclo()+1);
				val = true;
				//cp++
				break;
			}
		}
		if(val == false){nada++;}
		cout << "\nID: ";
		for(int i=0; i<(int)instrucoes.size(); i++){
			if(instrucoes[i]->getInicio() == ciclo && instrucoes[i]->getCiclo() == 2){
				
				cout << instrucoes[i]->getInst() << " " << instrucoes[i]->getOp1() << ", " ;
				cout << instrucoes[i]->getOp2() << ", " << instrucoes[i]->getOp3();
				
				instrucoes[i]->setInicio(instrucoes[i]->getInicio()+1);
				instrucoes[i]->setCiclo(instrucoes[i]->getCiclo()+1);
				val = true;
				break;
			}
		}
		if(val == false){nada++;}
		cout << "\nEX: ";
		for(int i=0; i<(int)instrucoes.size(); i++){
			if(instrucoes[i]->getInicio() == ciclo && instrucoes[i]->getCiclo() == 3){
				
				cout << instrucoes[i]->getInst() << " " << instrucoes[i]->getOp1() << ", ";
				cout << instrucoes[i]->getOp2() << ", " << instrucoes[i]->getOp3();
				
				instrucoes[i]->setInicio(instrucoes[i]->getInicio()+1);
				instrucoes[i]->setCiclo(instrucoes[i]->getCiclo()+1);
				val = true;
				break;
			}
		}
		if(val == false){nada++;}
		cout << "\nMEM: ";
		for(int i=0; i<(int)instrucoes.size(); i++){
			if(instrucoes[i]->getInicio() == ciclo && instrucoes[i]->getCiclo() == 4){
				
				cout << instrucoes[i]->getInst() << " " << instrucoes[i]->getOp1() << ", ";
				cout << instrucoes[i]->getOp2() << ", " << instrucoes[i]->getOp3();
				
				instrucoes[i]->setInicio(instrucoes[i]->getInicio()+1);
				instrucoes[i]->setCiclo(instrucoes[i]->getCiclo()+1);
				val = true;
				break;
			}
		}
		if(val == false){nada++;}
		cout << "\nWB: ";
		for(int i=0; i<(int)instrucoes.size(); i++){
			if(instrucoes[i]->getInicio() == ciclo && instrucoes[i]->getCiclo() == 5){
				
				cout << instrucoes[i]->getInst() << " " << instrucoes[i]->getOp1() << ", ";
				cout << instrucoes[i]->getOp2() << ", " << instrucoes[i]->getOp3();
				
				instrucoes[i]->setInicio(instrucoes[i]->getInicio()+1);
				instrucoes[i]->setCiclo(instrucoes[i]->getCiclo()+1);
				val = true;
				break;
			}
		}
		if(val == false){nada++;}
		cont++;
		if(cont == instrucoes[(int)instrucoes.size()-1]->getFim() || nada == 5){
			cont--;
			break;
		}
	}
	cout << "\n*** Quantidade de Ciclos totais: " << cont << endl;
}