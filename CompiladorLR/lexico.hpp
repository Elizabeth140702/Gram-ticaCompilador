#ifndef _LEXICO
#define _LEXICO
#include <iostream>
#include <string>
using namespace std;
class Lexico{
      private:
            string fuente;
            int ind;       
            bool continua;
            int estado;
            string sigCaracter();       
            void sigEstado(int estado);
            void aceptacion(int estado);
            bool esLetra(char c);
            bool esDigito(char c);
            bool esEspacio(char c);
            void retroceso();
      public:
            string c;
            string simbolo;
            int tipo;
            Lexico(string fuente);             
            Lexico();
            void entrada(string fuente);              
            string tipoAcad(int tipo);
            int sigSimbolo();
            bool terminado();
      
};
#endif