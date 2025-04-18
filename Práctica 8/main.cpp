/*Práctica 8 - Arreglo de Objetos */

#include <iostream>
using namespace std;
#include <string>


    class GestionDeCalidad {
    private:
        string sistemaControl, nivelCalidad;
        double porcentajeControl, cantidadAuditorias,cantidadQuejas;
        
    public:
        GestionDeCalidad();
        void setGestionDeCalidad(string, string, double , int, int );
        string getsistemaControl();
        string getnivelCalidad();
        double getporcentajeControl();
        int getcantidadAuditorias();
        int getcantidadQuejas();
        void imprimir();
    };
    
GestionDeCalidad::GestionDeCalidad(){} //constructor

void GestionDeCalidad::setGestionDeCalidad(string _sistemaControl, string _nivelCalidad, double _porcentajeControl, int _cantidadAuditorias, int _cantidadQuejas){
    sistemaControl = _sistemaControl;
    nivelCalidad = _nivelCalidad;
    porcentajeControl = _porcentajeControl;
    cantidadAuditorias = _cantidadAuditorias;
    cantidadQuejas = _cantidadQuejas;
}
    string GestionDeCalidad::getsistemaControl(){
        return sistemaControl;
    }
string GestionDeCalidad::getnivelCalidad(){
    return nivelCalidad;
}
double GestionDeCalidad::getporcentajeControl(){
    return porcentajeControl;
}
int  GestionDeCalidad::getcantidadAuditorias(){
    return cantidadAuditorias;
}

int GestionDeCalidad::getcantidadQuejas(){
    return cantidadQuejas;
}



void GestionDeCalidad::imprimir() {
    cout << "Sistema de control: " << sistemaControl << "\n";
    cout << "Nivel de calidad: " << nivelCalidad << "\n";
    cout << "Porcentaje de control: " << porcentajeControl << "\n";
    cout << "Cantidad de auditorías: " << cantidadAuditorias << "\n";
    cout << "Cantidad de quejas: " << cantidadQuejas << "\n";
    
    
}
    int main(){
        
        
        string sistemaControl, nivelCalidad;
        double porcentajeControl;
        int cantidadAuditorias,cantidadQuejas;
        
        
        
        
        int opcionmenu;
        int contador = 0;
        const int tam = 20;
        GestionDeCalidad *gestionesdeCalidad =new  GestionDeCalidad[tam];
    do {
        cout << "\n -- Menu Principal: --\n";
        cout << "1. Capturar\n";
        cout << "2. Imprimir\n";
        cout << "3. Buscar\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcionmenu;
        
        
        
        switch (opcionmenu) {
            case 1:
                if(contador >= tam){
                    cout << "El número de gestión de calidad está lleno\n";
                }else{
                    cin.ignore();
                    cout << "Eligió la opción de capturar el número de gestion de calidad es " << contador + 1;
                    cin.ignore();
                    cout << "Capture el sistema de control: ";
                    cin.ignore();
                    getline(cin, sistemaControl);
                    cin.ignore();
                    cout << "Capture el nivel de calidad: " ;
                    getline(cin, nivelCalidad);
                    cout << "Capture el porcentaje de control: ";
                    cin >> porcentajeControl;
                    cout << "Capture la cantidad de auditorias: " ;
                    cin >> cantidadAuditorias;
                    cout << "Capture la cantidad de qeuejas: " ;
                    cin >> cantidadQuejas;
                    gestionesdeCalidad[contador].setGestionDeCalidad(sistemaControl, nivelCalidad, porcentajeControl, cantidadAuditorias, cantidadQuejas);
                    contador++;
                }
                break;
            case 2:
                if (contador == 0) {
                    cout << "No hay nada que imprimir.";
                }else {
                    for(int i = 0; i < contador; i++ ){
                        
                        cout << "\nGestión de calidad número " << i + 1 << ":\n";
                        cout << "Sistema de control: " << gestionesdeCalidad[i].getsistemaControl() << "\n";
                        cout << "Nivel de calidad: " << gestionesdeCalidad[i].getnivelCalidad() << "\n";
                        cout << "Porcentaje de control: " << gestionesdeCalidad[i].getporcentajeControl() << "\n";
                        cout << "Cantidad de auditorías: " << gestionesdeCalidad[i].getcantidadAuditorias() << "\n";
                        cout << "Cantidad de quejas: " << gestionesdeCalidad[i].getcantidadQuejas() << "\n";
                    }}
                break;
            case 3:
                if (contador == 0) {
                                    cout << "No hay información para buscar\n";
                                } else {
                                    cin.ignore();
                                    cout << "Ingrese el sistema de control a buscar: ";
                                    string opcionBuscar;
                                    getline(cin, opcionBuscar);
                                    
                                    bool encontrado = false;
                                    for (int i = 0; i < contador; i++) {
                                        if (gestionesdeCalidad[i].getsistemaControl() == opcionBuscar) {
                                            cout << "\nGestión de calidad encontrada:\n";
                                            gestionesdeCalidad[i].imprimir();
                                            
                                            cout << "\n¿Desea modificar algún atributo? (1. Sí / 2. No): ";
                                            int modificar;
                                            cin >> modificar;
                                            if (modificar == 1) {
                                                cout << "\n¿Qué atributo desea modificar?\n";
                                                cout << "1. Sistema de control\n";
                                                cout << "2. Nivel de calidad\n";
                                                cout << "3. Porcentaje de control\n";
                                                cout << "4. Cantidad de auditorías\n";
                                                cout << "5. Cantidad de quejas\n";
                                                cout << "Seleccione una opción: ";
                                                int opcionMod;
                                                cin >> opcionMod;
                                                cin.ignore();
                                                
                                                switch (opcionMod) {
                                                    case 1:
                                                        cout << "Ingrese el nuevo sistema de control: ";
                                                        getline(cin, sistemaControl);
                                                        gestionesdeCalidad[i].setGestionDeCalidad(sistemaControl, gestionesdeCalidad[i].getnivelCalidad(), gestionesdeCalidad[i].getporcentajeControl(), gestionesdeCalidad[i].getcantidadAuditorias(), gestionesdeCalidad[i].getcantidadQuejas());
                                                        break;
                                                    case 2:
                                                        cout << "Ingrese el nuevo nivel de calidad: ";
                                                        getline(cin, nivelCalidad);
                                                        gestionesdeCalidad[i].setGestionDeCalidad(gestionesdeCalidad[i].getsistemaControl(), nivelCalidad, gestionesdeCalidad[i].getporcentajeControl(), gestionesdeCalidad[i].getcantidadAuditorias(), gestionesdeCalidad[i].getcantidadQuejas());
                                                        break;
                                                    case 3:
                                                        cout << "Ingrese el nuevo porcentaje de control: ";
                                                        cin >> porcentajeControl;
                                                        gestionesdeCalidad[i].setGestionDeCalidad(gestionesdeCalidad[i].getsistemaControl(), gestionesdeCalidad[i].getnivelCalidad(), porcentajeControl, gestionesdeCalidad[i].getcantidadAuditorias(), gestionesdeCalidad[i].getcantidadQuejas());
                                                        break;
                                                    case 4:
                                                        cout << "Ingrese la nueva cantidad de auditorías: ";
                                                        cin >> cantidadAuditorias;
                                                        gestionesdeCalidad[i].setGestionDeCalidad(gestionesdeCalidad[i].getsistemaControl(), gestionesdeCalidad[i].getnivelCalidad(), gestionesdeCalidad[i].getporcentajeControl(), cantidadAuditorias, gestionesdeCalidad[i].getcantidadQuejas());
                                                        break;
                                                    case 5:
                                                        cout << "Ingrese la nueva cantidad de quejas: ";
                                                        cin >> cantidadQuejas;
                                                        gestionesdeCalidad[i].setGestionDeCalidad(gestionesdeCalidad[i].getsistemaControl(), gestionesdeCalidad[i].getnivelCalidad(), gestionesdeCalidad[i].getporcentajeControl(), gestionesdeCalidad[i].getcantidadAuditorias(), cantidadQuejas);
                                                        break;
                                                    default:
                                                        cout << "Opción no válida.\n";
                                                        break;
                                                }
                                            }
                                            encontrado = true;
                                            break;
                                        }
                                    }
                                    
                                    if (!encontrado) {
                                        cout << "No se encontró el sistema de control.\n";
                                    }
                                }
                                break;
                                
                            case 4:
                                cout << "Saliendo del programa\n";
                                break;
                                
                            default:
                                cout << "Ingrese una opción dentro del rango\n";
                                break;
                        }

    } while (opcionmenu != 4);
        cout << "Dato ingresado incorrectamente";
   
    
    return 0;
}

