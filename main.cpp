#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Carrera.h"
#include "Funciones.h"

using namespace std;
/**
 * Escritura del archivo
 * codigocarrera.txt almacenado en la ubicacion especificada
*/
int main(int argc, char** argv){
    std::vector<Postulante> P;
    if(argc > 1){
        std::string op = argv[1];
        if(op == "1" && argc == 4){ //argc = 4 o 3 (llamada;opcion;ubicacion;ubicacion)
            LlenarDatos(); //RETURN VECTOR CA[];
            std::string archivo(argv[2]);
            std::ifstream lectura(archivo); //Lectura del archivo puntajes.cvs
            //Escritura de los .txt por carrera 
            std::ofstream Biotec("21073.txt");//Ing. Biotecnologia
            std::ofstream Compu("21041.txt");//Ing. civil computacion
            std::ofstream CsDatos("21049.txt");//Ing. civil ciencias de datos
            std::ofstream Arqui("21047.txt");//Arquitectura
            std::ofstream AdmiP("21089.txt");//Administracion Publica
            std::ofstream Social("21043.txt");//Trabajo Social
            std::ofstream Info("21030.txt");//Ing. informatica
            std::ofstream Meca("21096.txt");//Ing. civil Mecanica
            std::ofstream CsIng("21046.txt");//Bachillerato Ciencias ingenieria
            std::ofstream CIndus("21076.txt");//Ing. civil industrial
            std::ofstream Elec("21075.txt");//Ing. civil electronica
            std::ofstream Cmrcial("21048.txt");//Ing. comercial
            std::ofstream Proyec("21071.txt");//Dibujante proyectista
            std::ofstream Geo("21031.txt");//Ing. geomensura
            std::ofstream Contru("21032.txt");//Ing. construccion 
            std::ofstream Indus("21045.txt");//Ing. Industrial
            std::ofstream Civil("21074.txt");//Ing. civil obras civiles
            std::ofstream Quim("21083.txt");//Quimica industrial
            std::ofstream Alim("21039.txt");//Ing. industria alimentaria 
            std::ofstream Preven("21087.txt");//Ing. civil prevencion de riesgos y medioambiente
            std::ofstream Agro("21015.txt");//Ing. administracion agroindustrial
            std::ofstream Inter("21081.txt");//Ing. comercio internacional
            std::ofstream Biblio("21002.txt");//Bibliotecnologia y documentacion
            std::ofstream Conta("21012.txt");//Contador publico y auditor
            std::ofstream IQuim("21080.txt");//Ing. Quimica
            std::ofstream Turis("21082.txt");//Ing. gestion turistica
            std::ofstream Visual("21024.txt");//Diseño comunicacion visual
            std::ofstream Dindus("21023.txt");//diseño industrial

            if (lectura) {
                for (std::string linea; getline(lectura,linea) ; ) {
                    std::vector<int> persona = obtenerlinea(linea);
                    llenarPostulante(persona, P);
                    //Aqui quede...

                    //Final
                    persona.clear();
                    P.erase (P.begin());
                }
                /*for(int i=0; i<cont;i++){ //Creamos el archivo ordenado
                    B=E[i];

                    std::string salida = std::to_string(B.GetRut()) + ";" + std::to_string(B.GetPromedio());
                    escritura << salida << std::endl;
                }*/
            }
            //ACA EJECUTAR OPCION 1
            std::cout << std::endl << "CORRE 1" << std::endl;
        }else{
            if(op == "2" && argc == 4){
                std::string rut = argv[2];
                if(ValidarRut(rut)==true){
                  //ACA EJECUTAR OPCION 2: BUSQUEDA POR RUT
                }else{
                  std::cout << std::endl << "RUT INVALIDO" << std::endl;
                }
                std::cout << std::endl << "CORRE 2" << std::endl;
            }else{
                if(argc != 4){
                    if(op == "2" || op == "1"){
                        std::cout << std::endl << "Ingrese la cantidad correcta de datos" << std::endl;
                    }
                }
                if(op != "2" && op != "1"){
                            std::cout << std::endl << "OPCION INVALIDA" << std::endl;
                }      
            }
        }
    }
    else{ //Se muestran participantes
            participantes();
        }
    return EXIT_SUCCESS;
}