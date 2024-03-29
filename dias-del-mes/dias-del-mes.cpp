/*
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 16-10-2019
 * Resumen: Programa interactivo que pregunta repetidamente por un mes y
 *          un año y escribe en la pantalla el número de días que tiene el mes. 
 *          Clase de problemas de Programación 1 del tema 5 (funciones).
 */
#include <iostream>
using namespace std;

/*
 * Conctante que almacena el año en el que se instauró el calendario gregoriano
 * en España.
 */
const int AGNO_INICIO_GREGORIANO = 1582;

/*
 * Pre:  agno > 1582
 * Post: Ha devuelto true si y solo si el año «agno» es bisiesto de acuerdo con
 *       las reglas del calendario gregoriano.
 * Nota: Código de la clase de problemas sobre composición condicional. En el
 *       tema 7 (diseño modular), ser verá cómo reutilizar código sin necesidad de
 *       copiarlo.
 */
bool esBisiesto(int agno) {
    bool multiplo4   = (agno %   4 == 0);
    bool multiplo100 = (agno % 100 == 0);
    bool multiplo400 = (agno % 400 == 0);
    return multiplo400 || (multiplo4 && !multiplo100);
}

/*
 * Pre:  1 ≤ mes ≤ 12 y agno > 1582.
 * Post: Ha devuelto el número de días que tiene el mes establecido por el  
 *       parámetro «mes» del año establecido por el parámetro «agno».
 *
 *       Por ejemplo: diasDelMes(10, 2018) devuelve 31,
 *                    diasDelMes(2, 2018) devuelve 28 y
 *                    diasDelMes(2, 2020) devuelve 29.
 */
int diasDelMes(int mes, int agno) {
    if (mes == 2) {
        // Febrero: el número de día depende del año
        if (esBisiesto(agno)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        // Abril, junio, septiembre o noviembre
        return 30;
    }
    else {
        // Resto de meses
        return 31;
    }
}

/*
 * Programa que pregunta repetidamente por un mes y un año. Si el mes está
 * comprendido entre 1 y 12 y el año es posterior a 1582, el programa escribe en
 * la pantalla el número de días que tiene el mes. En caso contrario, escribe un
 * mensaje de error. El programa termina cuando el usuario escribe 0 tanto para el
 * mes como para el año.
 */
int main() {
    cout << "Escriba un mes y un año: ";
    int mes, agno;
    cin >> mes >> agno;
    
    while (mes != 0 || agno != 0) {
        if (mes < 1 || mes > 12) {
            // Mes incorrecto
            cout << "El mes tiene que estar comprendido entre 1 y 12." << endl;
        }
        else if (agno <= AGNO_INICIO_GREGORIANO) {
            // Año incorrecto
            cout << "El año tiene que ser posterior a " 
                 << AGNO_INICIO_GREGORIANO << "." << endl;
        }
        else {
            // Mes y año correctos
            cout << "Este mes tiene "
                 << diasDelMes(mes, agno) << " días." << endl;
        }
        
        cout << endl;
        cout << "Escriba un mes y un año: ";
        cin >> mes >> agno;
    }
    return 0;
}