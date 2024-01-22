#include <wchar.h>
#include <locale.h>
#include <stdio.h>

int main() {
    setlocale(LC_ALL, L"");
    wchar_t sexo, continuar;
    double estatura, peso, dosis;
    int edad;

    int totalEstudiantes = 0, totalHombres = 0, totalMujeres = 0, totalMenoresEdad = 0;
    double sumaEstaturaHombres = 0, sumaPesoHombres = 0, sumaDosisHombres = 0;
    double sumaEstaturaMujeres = 0, sumaPesoMujeres = 0, sumaDosisMujeres = 0;

    do {
        wprintf(L"Ingrese el sexo (M para masculino, F para femenino): ");
        wscanf(L" %lc", &sexo);

        if (sexo == L'M' || sexo == L'F') {
            do {
                wprintf(L"Ingrese la edad: ");
                wscanf(L"%d", &edad);

                if (edad < 0) {
                    wprintf(L"Error: La edad no puede ser negativa. Intente nuevamente.\n");
                }
            } while (edad < 0);

            if (edad >= 18) {
                do {
                    wprintf(L"Ingrese la estatura en metros: ");
                    wscanf(L"%lf", &estatura);

                    if (estatura <= 0) {
                        wprintf(L"Error: La estatura no puede ser negativa. Intente nuevamente.\n");
                    }
                } while (estatura <= 0);

                do {
                    wprintf(L"Ingrese el peso en libras: ");
                    wscanf(L"%lf", &peso);

                    if (peso <= 0) {
                        wprintf(L"Error: El peso no puede ser negativo. Intente nuevamente.\n");
                    }
                } while (peso <= 0);

                
                if ((sexo == L'M' && estatura > 1.60 && peso >= 150) ||
                    (sexo == L'F' && estatura >= 1.50 && peso >= 130)) {
                    dosis = (sexo == L'M') ? (0.2 * estatura + 0.8 * peso) : (0.25 * estatura + 0.75 * peso);
                } else {
                    dosis = 0.35 * estatura + 0.65 * peso;
                }

                
                wprintf(L"La dosis recomendada es: %.2f gramos\n", dosis);

                
                if (sexo == L'M') {
                    totalHombres++;
                    sumaEstaturaHombres += estatura;
                    sumaPesoHombres += peso;
                    sumaDosisHombres += dosis;
                } else {
                    totalMujeres++;
                    sumaEstaturaMujeres += estatura;
                    sumaPesoMujeres += peso;
                    sumaDosisMujeres += dosis;
                }

            } else {
                wprintf(L"La cantidad de vitaminas solo es aplicable a personas mayores de 18 años.\n");
                totalMenoresEdad++;
            }
        } else {
            wprintf(L"Sexo ingresado no válido. Por favor, ingrese M o F.\n");
        }

        
        do {
            wprintf(L"¿Desea ingresar datos para otro estudiante? (S para sí, cualquier otra tecla para no): ");
            wscanf(L" %lc", &continuar);

            if (continuar != L'S' && continuar != L's') {
                break; 
            }
        } while (continuar == L'S' || continuar == L's');

        totalEstudiantes++;

    } while (1);

    if (totalEstudiantes > 0) {
        
        wprintf(L"\nResumen:\n");
        wprintf(L" - Total de estudiantes: %d\n", totalEstudiantes);
        wprintf(L" - Total de hombres: %d\n", totalHombres);
        if (totalHombres > 0) {
            wprintf(L"   - Altura media de hombres: %.2f metros\n", sumaEstaturaHombres / totalHombres);
            wprintf(L"   - Peso medio de hombres: %.2f lb\n", sumaPesoHombres / totalHombres);
            wprintf(L"   - Dosis media de hombres: %.2f gramos\n", sumaDosisHombres / totalHombres);
        }
        wprintf(L" - Total de mujeres: %d\n", totalMujeres);
        if (totalMujeres > 0) {
            wprintf(L"   - Altura media de mujeres: %.2f metros\n", sumaEstaturaMujeres / totalMujeres);
            wprintf(L"   - Peso medio de mujeres: %.2f lb\n", sumaPesoMujeres / totalMujeres);
            wprintf(L"   - Dosis media de mujeres: %.2f gramos\n", sumaDosisMujeres / totalMujeres);
        }
        wprintf(L" - Total de alumnos menores de edad: %d\n", totalMenoresEdad);
    }

    return 0;
}
