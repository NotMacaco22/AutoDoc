#include <iostream>
#include <limits>
#include "3_login.cpp"
#include "4_pacientes.cpp"
#include "5_citasProgramadas.cpp"
#include "10_diagPresc.cpp"
//#include "6_UT.cpp"
//#include "7_UP.cpp"
#include "8_SE.cpp"
//#include "9_UM.cpp"

using namespace std;

void Procedimientos();
void menuPrincipal();
void agenda();
void mainPacientes();
void diagPres();
void regresarMenuPrincipal();

int main(){
    login();
    menuPrincipal();
    return 0;
}

void regresarMenuPrincipal(){
    string opc;
    printf("\n%cDeseas regresar al men%c principal? Escribe S para confirmar o presiona cualquier letra para salir del programa.\n", 168, 163);
    getline(cin, opc);
    if (opc == "S" || opc == "s") {
        system("clear || cls"); 
        menuPrincipal();
    } else {
        cout << "\nVuelva Pronto Dr. Carlos Silva :D" << endl;
        exit(0);
    }
}

void Procedimientos(){
    int opcion;
    cout << "PROCEDIMIENTOS" << endl;
    cout << "1. Ultrasonido transvaginal." << endl;
    printf("2. Ultrasonido p%clvico.\n", 130);
    cout << "3. Ultrasonido de mamas." << endl;
    cout << "4. Seguimiento de embarazo." << endl;
    printf("5. Regresar al men%c principal.\n", 163);
    cout << "  --->"; cin >> opcion;

    switch (opcion)
    {
    case 1:
        break;
    case 2: //UP();
        break;
    case 3:
        break;
    case 4: system("clear || cls"); SE(); regresarMenuPrincipal();
        break;
    case 5:
        system("clear || cls");
        menuPrincipal();
        break;
    default:
        printf("\nOpci%cn no v%clida. Por favor, elija una opci%cn dentro del rango de n%cmeros permitidos.\n", 162, 160, 162, 163);
        //ó, á y ú en ASCII
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        system("clear || cls");
        Procedimientos();
        break;
    }
}

void menuPrincipal(){
    int opc;

    printf("~MEN%c PRINCIPAL - CL%CNICA M%CDICA ESPERANZA~\n", 233, 161, 144);
    cout << "     ~ Hola Dr. Carlos Silva ~\n" << endl;
    printf("Ingrese la opci%cn que desee\n\n", 162);
    printf(" 1. Ver Registro de Pacientes y su expendiente m%cdico\n", 130);
    cout << " 2. Agenda con citas programadas" << endl;
    cout << " 3. Crear Archivos Procedimientos" << endl;
    printf(" 4. Crear y ver diagn%csticos y prescripciones\n", 162);
    cout << " 5. Salir" << endl << endl;
    cout << "---> "; cin >> opc;

    switch (opc){
    case 1: mainPacientes();
        break;
    
    case 2: system("clear || cls"); agenda();
        break;

    case 3: system("clear || cls"); Procedimientos();
        break;

    case 4: system("clear || cls"); diagPres();
        break;

    case 5:    
        cout << "Vuelva Pronto Dr. Carlos Silva :D" << endl;
        break;

    default:
        system("cls || clear");
        printf("Doctor, por favor ingrese una opci%cn entre el 1 al 4 - Recuerde que s%clo esas opciones son admitidas.\n\n", 162, 162);
        menuPrincipal();
        break;
    }
}


// Método principal
void agenda() {
    int opcion;

    do {
        // Mostrar menú
        cout << "AGENDA" << endl;
        cout << "1. Programar cita" << endl;
        cout << "2. Ver citas programadas" << endl;
        cout << "3. Regresar al menu principal" << endl;
        cout << "4. Salir" << endl;
        printf("Seleccione una opci%cn: ", 162);
        cin >> opcion;

        switch (opcion) {
            case 1:
                programarCita();
                break;
            case 2:
                mostrarCitasProgramadas();
                break;
            case 3: system("clear || cls"); menuPrincipal();
                break;
            case 4:
                printf("Saliendo del programa. %cHasta luego!\n", 173);
                break;
            default:
                printf("Opci%cn no v%clida. Int%cntelo de nuevo.\n", 162, 160, 130);
                break;
        }

    } while (opcion != 3);
}

void mainPacientes() {
    int opcion;
    string cedulaONombreABuscar;  // Variable para almacenar la cédula o nombre a buscar

    do {
        #ifdef _WIN32
            system("pause");
        #endif

        system(" read -p 'Presiona Enter para continuar...' -n 1 -s");
        system("clear || cls");
        printf("--------MEN%C DE PACIENTES--------\n", 233);
        printf("Men%c de la clínica:\n", 163);
        cout << "1. Crear paciente" << endl;
        cout << "2. Listar pacientes" << endl;
        cout << "3. Buscar paciente" << endl;
        cout << "4. Actualizar paciente" << endl;
        cout << "5. Eliminar paciente" << endl;
        cout << "6. Volver a Menu Principal" << endl;
        printf("Elija una opci%cn: ", 162);

    while (!(cin >> opcion) || cin.peek() != '\n' || opcion < 1 || opcion > 6) {
        printf("Entrada inv%clida. Por favor, ingrese un n%cmero entero del 1 al 6: ", 160, 163);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
        switch (opcion) {
            case 1:
                crearPaciente();
                break;
            case 2:
                listarPacientes();
                break;
            case 3:
                buscarPacientes();//cedulaONombreABuscar);
                break;
            case 4:
                actualizarPaciente();
                break;
            case 5:
                eliminarPaciente();
                break;
            case 6: system("clear || cls"); menuPrincipal();
                break;
            default:
                system("clear || cls");
                printf("--------MEN%C DE PACIENTES--------", 163);
                cout << endl;
                printf("Opci%cn no v%clida. Int%cntelo de nuevo.\n", 162, 160, 130);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (opcion != 6);

}

void diagPres() {
    int opcion;

    do {
        printf("Seleccione una opci%cn:\n", 162);
        printf("1. Ingresar diagn%cstico\n", 162);
        printf("2. Ingresar prescripci%cn\n", 162);
        printf("3. Mostrar diagn%csticos y prescripciones anteriores\n", 162);  // Nueva opción
        printf("Elija una opci%cn: ", 162);
        
        while (!(cin >> opcion) || cin.peek() != '\n' || opcion < 1 || opcion > 3) {
            printf("Entrada inv%clida. Por favor, ingrese 1, 2 o 3: ", 160);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (opcion) {
            case 1: {
                diagnostico nuevoDiagnostico = ingresarDatosDiagnostico();
                guardarDiagnostico(nuevoDiagnostico);
                printf("Diagn%cstico guardado exitosamente.\n", 162);
                break;
            }
            case 2: {
                prescripcion nuevaPrescripcion = ingresarDatosPrescripcion();
                guardarPrescripcion(nuevaPrescripcion);
                printf("Prescripci%cn guardada exitosamente.\n", 162);
                break;
            }
            case 3: {
                string cedula;
                bool cedulaValida = false;
                registroP paciente;

                // Solicitar la cédula hasta que sea válida
                while (!cedulaValida) {
                    printf("Ingrese la c%cdula del paciente para mostrar diagn%csticos y prescripciones anteriores: ", 130, 162);
                    cin >> cedula;

                    if (obtenerInfoPaciente(cedula, paciente)) {
                        cedulaValida = true;
                    } else {
                        printf("La c%cdula no existe en el registro. Ingrese una c%cdula v%clida.\n", 130, 130, 160);
                    }
                }

                mostrarDiagnosticosYPrescripciones(cedula);
                break;
            }
            default:
                printf("Opci%cn no v%clida.\n", 162, 160);
        }

        // Preguntar si el usuario desea volver al menú principal
        char respuesta;
        printf("%cDesea volver al men%c principal (S/N): ", 168, 163);
        cin >> respuesta;
        
        if (toupper(respuesta) != 'S') {
            break; // Salir del bucle si la respuesta no es 'S' (ignora mayúsculas/minúsculas)
        }

    } while (true);
}