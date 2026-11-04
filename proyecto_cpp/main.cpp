/* Materia: Laboratorio de Programacion (LPR)
   Archivo: main.cpp
   Resolucion de la Actividad 1 - Entorno C++
   Grupo: Ian Quiroga, Santino Laudati y Dante Iglesias
   Curso: 5to Anio 3ra - E.E.S.T. N.1 "Eduardo Ader" - Vicente Lopez
*/

#include <iostream>

using namespace std;

// 1. Evalua si un anio es bisiesto
bool esBisiesto(int anio)
{
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

// 2. Filtro de consistencia de calendario
bool esFechaValida(int d, int m, int a)
{
    if (a < 1900 || a > 2026)
        return false;

    if (m < 1 || m > 12)
        return false;

    if (d < 1 || d > 31)
        return false;

    // Meses de 30 dias
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
        return false;

    // Caso especial de Febrero
    if (m == 2)
    {
        if (esBisiesto(a))
        {
            if (d > 29)
                return false;
        }
        else
        {
            if (d > 28)
                return false;
        }
    }
    return true;
}

int main()
{
    int diaN, mesN, anioN;
    int diaA = 8, mesA = 7, anioA = 2026; // Fecha actual para el ejercicio

    cout << "=====================================================" << endl;
    cout << " CALCULADORA DE EDAD DE: Ian Quiroga, Santino Laudati" << endl;
    cout << "                         y Dante Iglesias" << endl;
    cout << "=====================================================" << endl;

    cout << "Ingrese Dia, Mes y Anio de nacimiento (separados por espacios): ";
    cin >> diaN >> mesN >> anioN;

    // Si el usuario escribe letras, cin queda en estado de error
    if (cin.fail())
    {
        cout << "[ERROR] Deben ingresar numeros enteros." << endl;
        return 1;
    }

    if (!esFechaValida(diaN, mesN, anioN))
    {
        cout << "[ERROR] La fecha ingresada no existe en el calendario." << endl;
        return 1;
    }

    int edad = anioA - anioN;

    // RESOLUCION: Ajuste si aun no cumplio anios en el anio actual
    if (mesA < mesN || (mesA == mesN && diaA < diaN))
    {
        edad--;
    }

    // Una fecha posterior a "hoy" dentro de 2026 daria una edad negativa
    if (edad < 0)
    {
        cout << "[ERROR] La fecha de nacimiento es posterior a la fecha actual." << endl;
        return 1;
    }

    cout << "\n[SISTEMA] Fecha de hoy: " << diaA << "/" << mesA << "/" << anioA << endl;
    cout << "[SISTEMA] Edad calculada: " << edad << " anos." << endl;
    cout << "=====================================================" << endl;

    return 0;
}
