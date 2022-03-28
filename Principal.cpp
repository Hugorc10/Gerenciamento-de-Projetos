/*****************************************************************
* Autor: Hugo Texeira Mafra
* Matricula: 201611540
* Inicio: 20 de julho de 2018
* Ultima alteracao: 22 de julho de 2018
* Nome: Gerenciamento de Processos (arvore genealogica com operacao fork).
* Funcao: Simular uma arvore genealogica utilizando a operacao fork.
******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <signal.h>
#include <iostream>

using namespace std;

/*****************************************************************
* Metodo: firstSonProcess
* Funcao: Metodo criado no processo do primeiro filho (son1), responsavel por gerenciar o status e a vida util do proprio processo.
* Parametros: Sem parametros
* Retorno: void
*****************************************************************/
void firstSonProcess() {
  int id = 0;
    cout << "\nThe first son was born." << endl;
    while (id <= 61) {
      sleep(1);
      cout << "\nI am the first son process (PID " << getpid() << "), I am " << id << " years old." << endl;
      id++;
    } // Fim do while
    cout << "\nThe first son died. He lived " << id - 1 << " years." << endl;
    _exit(0);
} // Fim do metodo firstSonProcess

/* ***************************************************************
* Metodo: secondSonProcess
* Funcao: Metodo criado no processo do segundo filho (son2), responsavel por gerenciar o status e a vida util do proprio processo.
* Parametros: Sem parametros
* Retorno: void
*****************************************************************/
void secondSonProcess() {
  int id = 0;
  cout << "\nThe second son was born." << endl;
   while (id <= 55) {
     sleep(1);
     cout << "\nI am the second son process (PID " << getpid() << "), I am " << id << " years old." << endl;
     id++;
   } // Fim do while
  cout << "\nThe second son died. He lived " << id - 1 << " years." << endl;
  _exit(0);
} // Fim do metodo secondSonProcess

/*****************************************************************
* Metodo: thirdSonProcess
* Funcao: Metodo criado no processo do terceiro filho (son3), responsavel por gerenciar o status e a vida util do proprio processo.
* Parametros: Sem parametros
* Retorno: void
*****************************************************************/
void thirdSonProcess() {
  int id = 0;
  cout << "\nThe third son was born." << endl;
  while (id <= 55) {
     sleep(1);
     cout << "\nI am the third son process (PID " << getpid() << "), I am " << id << " years old." << endl;
     id++;
   } // Fim do while  
  cout << "\nThe third son died. He lived " << id - 1 << " years." << endl;
  _exit(0);
} // Fim do metodo thirdSonProcess

/*****************************************************************
* Metodo: firstGrandsonProcess
* Funcao: Metodo criado no processo do primeiro neto (grandson1), responsavel por gerenciar o status e a vida util do proprio processo.
* Parametros: Sem parametros
* Retorno: void
*****************************************************************/
void firstGrandsonProcess() {
  int id = 0;
  cout << "\nThe first grandson was born." << endl;
  while (id <= 35) {
    sleep(1);
    cout << "\nI am the first grandson process (PID " << getpid() << "), I am " << id << " years old." << endl;
    id++;
  } // Fim do while
  cout << "\nThe first grandson died. He lived " << id - 1 << " years." << endl;
  _exit(0);
} // Fim do metodo firstGrandsonProcess

/*****************************************************************
* Metodo: secondGrandsonProcess
* Funcao: Metodo criado no processo do segundo neto (grandson2), responsavel por gerenciar o status e a vida util do proprio processo.
* Parametros: Sem parametros
* Retorno: void
*****************************************************************/
void secondGrandsonProcess() {
  int id = 0;
  cout << "\nThe second grandson was born." << endl;
  while (id <= 33) {
    sleep(1);
    cout << "\nI am the second grandson process (PID " << getpid() << "), I am " << id << " years old." << endl;
    id++;
  } // Fim do while
  cout << "\nThe second grandson died. He lived " << id - 1 << " years." << endl;
  _exit(0);
} // Fim do metodo secondGrandsonProcess

/*****************************************************************
* Metodo: greatgrandsonProcess()
* Funcao: Metodo criado no processo do bisneto (greatgrandson), responsavel por gerenciar o status e a vida util do proprio processo.
* Parametros: Sem parametros
* Retorno: void
*****************************************************************/
void greatgrandsonProcess() {
  int id = 0;
  cout << "\nThe greatgrandson was born." << endl; 
  while (id <= 12) {
    sleep(1);
    cout << "\nI am the greatgrandson process (PID " << getpid() << "), I am " << id << " years old." << endl;
    id++;
  } // Fim do while
  cout << "\nThe greatgrandson died. He lived " << id - 1 << " years." << endl;
  _exit(0);
} // Fim do metodo greatgrandsonProcess


/*****************************************************************
* Metodo: main
* Funcao: O metodo principal do programa. Responsavel por iniciar o processo pai e todos os seus subprocessos. O processo pai vai ser encarregado de iniciar todos os outros processos.  
* Parametros: int argc, char ** argv
*****************************************************************/
int main(int argc, char ** argv) {
  pid_t son1, son2, son3, grandson1, grandson2, greatgrandson;
  int x = 0;
  
  cout << "The father was born." << endl;
	
  while (x < 90) {
    sleep(1);  
    cout << "\nI am the father process (PID " << getpid() << "), I am " << x << " years old." << endl;

    // Gera o processo do primeiro filho aos 22 segundos
    if (x == 22) {
      son1 = fork();
      if (son1 == 0) {
        firstSonProcess();
      }
    } // Fim do if

    // Gera o processo do segundo filho aos 25 segundos
    if (x == 25) {
      son2 = fork();
      if (son2 == 0) {
        secondSonProcess();
      }
    } // Fim do if

    // Gera o processo do terceiro filho aos 32 segundos.
    if (x == 32) {
      son3 = fork();
      if(son3 == 0) { 
        thirdSonProcess();
      }
    } // Fim do if
		 
    // Gera o processo do primeiro neto aos 38 segundos.
    if (x == 38) {
      grandson1 = fork();
      if (grandson1 == 0) {
        firstGrandsonProcess();
      }
    } // Fim do if
		
    // Gera o processo do segundo neto aos 45 segundos.
    if (x == 45) {
      grandson2 = fork();
      if (grandson2 == 0) {
        secondGrandsonProcess();
      }
    } // Fim do if
		
    // Gera o processo do bisneto aos 68 segundos.
    if (x == 68) {
      greatgrandson = fork();
      if(greatgrandson == 0) {
        greatgrandsonProcess();
      }
    } //fim do if
    
  x++;		
  } // Fim do while

  cout << "\nThe father died. He lived " << x << " years." << endl;
  return 0; 
} // Fim do metodo main