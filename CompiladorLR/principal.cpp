#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include "lexico.hpp"
#include "pila.hpp"
#include "lexico.cpp"
#include "pila.cpp"
using namespace std;
string rules[53];
int tableLR[95][46];
int cont = 0, row = 0, col = 0;
string currentRule[3];
void arrange2(string str){
    int posicion = 0;
    string w = "";
    for (auto x : str) {
        if (x == ' '){
            currentRule[posicion] = w;
            posicion ++;
            w = "";
        }
        else{
            w = w + x;
        }
    }
    currentRule[posicion] = w;
    posicion ++;
}
void arrange(string str){ 
    int num;
    string w = "";
    col = 0;
    for (auto x : str){
        if (x == ' '){
            stringstream ss;
            ss << w;  
            ss >> num;
            tableLR[row][col] = num;
            col ++;
            w = "";
        }
        else{
            w = w + x;
        }
    }
    stringstream ss;
    ss << w;  
    ss >> num;
    tableLR[row][col] = num;
    col ++;
    row ++;
}
int main(){
    int estadoact;
    fstream newrowe;
    newrowe.open("compilador.lr",ios::in); 
    if (newrowe.is_open()){  
        string tp;
        while(getline(newrowe, tp)){ 
            if (cont <= 52){
                rules[cont] = tp;
            }if(cont >= 54){
                arrange(tp);
            }
            cont ++;
        }
        newrowe.close(); 
    }
    int contador = 0;
    int idrules[2] = {3,2}; 
    int Ionrules[2] = {3,0};
    int idE = 3; 
    int E;
    Pila pila;
    ElementoPila *elemento;
    int fila, columna, accion;
    bool aceptacion= false;
    Lexico lexico("int test ; ");
    elemento = new Terminal(2,"$");
    pila.push( elemento); 
    elemento = new Estado(0);
    pila.push( elemento );                 
    lexico.sigSimbolo();   
    fila= pila.top(); 
    columna= lexico.tipo;
    cout << "Fila: " << fila << endl;
    cout << "Columna: " << columna << endl;
    accion= tableLR[fila][columna];
    pila.muestra();
    cout << "Cadena de entrada: " << lexico.simbolo << endl;
    cout << "Accion: " << accion << endl;
    while(accion != -1){
        if(accion > 0){
            cout << endl;
            cout << "Desplazamiento:" << endl;
            elemento = new Terminal(lexico.tipo,lexico.c);
            pila.push( elemento );
            elemento = new Estado(accion);
            pila.push( elemento );
            lexico.sigSimbolo();

            fila= pila.top();
            columna= lexico.tipo;
            cout << "Fila: " << fila << endl;
            cout << "Columna: " << columna << endl;
            accion= tableLR[fila][columna];

            pila.muestra();
            cout << "Entrada: " << lexico.simbolo << endl;
            cout << "Accion: " << accion << endl;
        }if(accion < 0){
            cout << endl;
            cout << "Reduccion:" << endl;
            int reglaapp = abs(accion) - 1;
            cout << "Regla: " << reglaapp<< endl;
            int numborrados;
            stringstream ss;
            char rulestr = rules[reglaapp][3];
            ss << rulestr;  
            ss >> numborrados;
            numborrados = numborrados * 2;
            if (accion == -1)
            break;
            for(int i=0; i<numborrados; i++){
                pila.pop();
            }
            pila.muestra();
            arrange2(rules[reglaapp]);
            string prueba= currentRule[2];
            prueba = prueba+ " ";
            Lexico lexico2(prueba);
            lexico2.sigSimbolo();
            elemento = new NoTerminal(lexico2.tipo,lexico2.c);
            estadoact = tableLR[pila.top()][lexico2.tipo];
            pila.push( elemento ); 
            elemento = new Estado(estadoact);
            pila.push( elemento );
            fila= pila.top();
            columna= lexico.tipo;
            cout << "Fila: " << fila << endl;
            cout << "Columna: " << columna << endl;
            accion= tableLR[fila][columna];
            pila.muestra();
            cout << "Cadena de entrada: " << lexico.simbolo << endl;
            cout << "Accion: " << accion << endl << endl;
        }
        if(accion == 0)break;
    }
    cout << "Automata terminado" << endl;
    aceptacion= accion == -1;
    if (aceptacion) cout << "Aceptacion" << endl;
    else cout << "No aceptacion" << endl;
}