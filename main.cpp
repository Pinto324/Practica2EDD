#include <iostream>
#include "manejador.h"
int main() {
    bool Sigo = true;
    manejador Mj;
    std::cout << "Bienvenido al Sistema de Gestión de Contactos." << std::endl;
    while (Sigo){
        int opcion;
        std::cout << "1) Abrir consola" << std::endl;
        std::cout << "2) Reportes" << std::endl;
        std::cout << "3) Generar Grafica" << std::endl;
        std::cout << "4) Exportar Contactos" << std::endl;
        std::cout << "5) Salir" << std::endl;
        std::cout << "Que desea hacer?";
        std::cin >> opcion;
        switch (opcion) {
            case 1:
                Mj.Consola();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                std::cout << "hasta luego!" << std::endl;
                Sigo = false;
                break;
            default:
                std::cout << "opcion invalida" << std::endl;
                break;
        }
    }
    return 0;
}
