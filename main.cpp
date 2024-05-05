#include "CuentaCorriente.h"
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::vector<CuentaCorriente> cuentas;

    int opcion;
    do {
        std::cout << "1. Crear Cuenta\n2. Cambiar Clave\n3. Ingresar Dinero\n4. Retirar Dinero\n0. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        std::string nombre, apellidos, direccion, telefono, numId, clave;
        double saldo, cantidad;  // Declaración de 'cantidad' aquí para uso posterior

        switch (opcion) {
            case 1:  // Crear cuenta
                std::cout << "Ingrese nombre: ";
                std::cin.ignore();  // Limpia el buffer de entrada
                getline(std::cin, nombre);
                std::cout << "Ingrese apellidos: ";
                getline(std::cin, apellidos);
                std::cout << "Ingrese dirección: ";
                getline(std::cin, direccion);
                std::cout << "Ingrese teléfono: ";
                getline(std::cin, telefono);
                std::cout << "Ingrese saldo inicial: ";
                std::cin >> saldo;
                std::cout << "Ingrese número de identificación: ";
                std::cin >> numId;
                std::cout << "Ingrese clave (dejar en blanco para clave por defecto): ";
                std::cin.ignore();  // Limpia el buffer de entrada antes de leer una línea
                getline(std::cin, clave);

                if (std::any_of(cuentas.begin(), cuentas.end(), [&numId](const CuentaCorriente& cuenta) { return cuenta.getNumeroIdentificacion() == numId; })) {
                    std::cout << "Error: El número de identificación ya está registrado.\n";
                } else {
                    cuentas.emplace_back(nombre, apellidos, direccion, telefono, saldo, numId, clave.empty() ? "12345" : clave);
                    std::cout << "Cuenta creada exitosamente.\n";
                }
                break;
            case 2:  // Cambiar clave
                // Implementación similar a la anterior
                break;
            case 3:  // Ingresar dinero
                std::cout << "Ingrese número de identificación: ";
                std::cin >> numId;
                std::cout << "Ingrese clave: ";
                std::cin >> clave;
                std::cout << "Ingrese cantidad a depositar: ";
                std::cin >> cantidad;  // Uso de 'cantidad' después de su declaración
                for (auto& cuenta : cuentas) {
                    if (cuenta.getNumeroIdentificacion() == numId && cuenta.ingresarDinero(cantidad, clave)) {
                        std::cout << "Depósito realizado correctamente.\n";
                        break;
                    } else {
                        std::cout << "Operación fallida (clave incorrecta o cantidad inválida).\n";
                    }
                }
                break;
            case 4:  // Retirar dinero
                std::cout << "Ingrese número de identificación: ";
                std::cin >> numId;
                std::cout << "Ingrese clave: ";
                std::cin >> clave;
                std::cout << "Ingrese cantidad a retirar: ";
                std::cin >> cantidad;  // Uso de 'cantidad' después de su declaración
                for (auto& cuenta : cuentas) {
                    if (cuenta.getNumeroIdentificacion() == numId && cuenta.retirarDinero(cantidad, clave)) {
                        std::cout << "Retiro realizado correctamente.\n";
                        break;
                    } else {
                        std::cout << "Operación fallida (clave incorrecta o saldo insuficiente).\n";
                    }
                }
                break;
            case 0:  // Salir
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción no válida, intente de nuevo.\n";
        }
    } while (opcion != 0);

    return 0;
}
