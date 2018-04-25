#include <iostream>
#include <vector>
using namespace std;
#include "../include/calcularPipeline.hpp"

void calcularPipeline(std::vector<Assembly*> &instrucoes){
	for(int i=1; i<(int)instrucoes.size(); i++){
		if(instrucoes[i]->getInst2()!=0){ // Se não tiver feito o calculo da dependencia na instrução 1
			if(instrucoes[i]->getInicio() - instrucoes[instrucoes[i]->getInst2()-1]->getInicio() < 5){
				instrucoes[i]->setInicio(instrucoes[instrucoes[i]->getInst2()-1]->getFim());
			}
			else{
				instrucoes[i]->setInicio(instrucoes[i-1]->getInicio()+1);
			}
		}
		if(instrucoes[i]->getInst3()!=0){ // Se não tiver feito o calculo da dependencia na instrução 1
			// Se a diferença do inicio da instrução atual com a instrução com a qual tem dependencia for menor que => talvez possa iniciar logo em seguida
			// Se a instrução com a qual tenho dependencia termina depois que eu inicio (não no mesmo momento), então eu coloco Bolhas
			if(instrucoes[i]->getInicio() - instrucoes[instrucoes[i]->getInst3()-1]->getInicio() < 5 && instrucoes[instrucoes[i]->getInst3()-1]->getFim() > instrucoes[i]->getInicio()){
				if(instrucoes[instrucoes[i]->getInst3()-1]->getFim() > instrucoes[i]->getInicio()){
					instrucoes[i]->setInicio(instrucoes[instrucoes[i]->getInst3()-1]->getFim());
				}
			}
		}
		// Se não tiver dependencia ou tiver dado algum erro no cálculo do inicio da execução da instrução
		if((instrucoes[i]->getInst3()==0 && instrucoes[i]->getInst2()==0) || (instrucoes[i]->getInicio() <= instrucoes[i-1]->getInicio())){
			instrucoes[i]->setInicio(instrucoes[i-1]->getInicio()+1);
		}
	}
}