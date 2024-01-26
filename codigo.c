#include <wchar.h>
#include <locale.h>
#include <stdio.h>

int main() {
    setlocale(LC_ALL, "");
    wchar_t sexo;
    int edad, otroEstudiante;
    double estatura_cm, peso, dosis;

    int totalEstudiantes = 0;
    int totalHombres = 0;
    int totalMujeres = 0;
    int totalMenoresEdad = 0;
    double sumaEstaturaHombres = 0;
    double sumaEstaturaMujeres = 0;
    double sumaPesoHombres = 0;
    double sumaPesoMujeres = 0;
    double sumaDosisHombres = 0;
    double sumaDosisMujeres = 0;

    do {
        do {
            wprintf(L"Ingrese el sexo (M para masculino, F para femenino): ");
            wscanf(L" %lc", &sexo);

            if (sexo != L'M' && sexo != L'm' && sexo != L'F' && sexo != L'f') {
                wprintf(L"Carácter de sexo ingresado no válido. Por favor, ingrese M o F.\n");
            }
        } while (sexo != L'M' && sexo != L'm' && sexo != L'F' && sexo != L'f');

        wprintf(L"Ingrese la edad: ");
        wscanf(L"%d", &edad);

        while (edad <= 0 || edad > 100) {
            wprintf(L"Edad no válida. Por favor, ingrese una edad válida: ");
            wscanf(L"%d", &edad);
        }

        if (edad >= 18) {
            wprintf(L"Ingrese la estatura (centímetros): ");
            wscanf(L"%lf", &estatura_cm);

            while (estatura_cm <= 50 || estatura_cm > 250) {
                wprintf(L"Estatura no válida. Por favor, ingrese una estatura válida: ");
                wscanf(L"%lf", &estatura_cm);
            }

            wprintf(L"Ingrese el peso (lb): ");
            wscanf(L"%lf", &peso);

            while (peso <= 10 || peso > 1000) {
                wprintf(L"Peso no válido. Por favor, ingrese un peso válido: ");
                wscanf(L"%lf", &peso);
            }

            if ((sexo == L'M' || sexo == L'm') && estatura_cm > 160 && peso >= 150 ||
                (sexo == L'F' || sexo == L'f') && estatura_cm > 150 && peso >= 130) {
                if (sexo == L'M' || sexo == L'm') {
                    dosis = 0.2 * estatura_cm / 100 + 0.8 * peso;
                    totalHombres++;
                    sumaEstaturaHombres += estatura_cm;
                    sumaPesoHombres += peso;
                    sumaDosisHombres += dosis;
                } else {
                    dosis = 0.25 * estatura_cm / 100 + 0.75 * peso;
                    totalMujeres++;
                    sumaEstaturaMujeres += estatura_cm;
                    sumaPesoMujeres += peso;
                    sumaDosisMujeres += dosis;
                }
            } else {
                if (sexo == L'M' || sexo == L'm') {
                    dosis = 0.3 * estatura_cm / 100 + 0.7 * peso;
                    totalHombres++;
                    sumaEstaturaHombres += estatura_cm;
                    sumaPesoHombres += peso;
                    sumaDosisHombres += dosis;
                } else {
                    dosis = 0.35 * estatura_cm / 100 + 0.65 * peso;
                    totalMujeres++;
                    sumaEstaturaMujeres += estatura_cm;
                    sumaPesoMujeres += peso;
                    sumaDosisMujeres += dosis;
                }
            }

            wprintf(L"La cantidad de vitaminas a consumir es: %.2f gramos\n", dosis);
        } else {
            wprintf(L"Lo siento, solo se permiten datos de personas mayores de edad.\n");
            totalMenoresEdad++;
        }

        totalEstudiantes++;

        wprintf(L"¿Desea calcular la dosis para otro estudiante? (1 para sí, 0 para no): ");
        wscanf(L"%d", &otroEstudiante);

    } while (otroEstudiante == 1);

    if (totalEstudiantes > 0) {
        wprintf(L"\nResumen:\n");
        wprintf(L" - Total de estudiantes: %d\n", totalEstudiantes);
        wprintf(L" - Total de hombres: %d\n", totalHombres);
        if (totalHombres > 0) {
            wprintf(L"   - Altura media: %.2f centímetros\n", sumaEstaturaHombres / totalHombres);
            wprintf(L"   - Peso medio: %.2f lb\n", sumaPesoHombres / totalHombres);
            wprintf(L"   - Dosis media: %.2f gramos\n", sumaDosisHombres / totalHombres);
        }
        wprintf(L" - Total de mujeres: %d\n", totalMujeres);
        if (totalMujeres > 0) {
            wprintf(L"   - Altura media: %.2f centímetros\n", sumaEstaturaMujeres / totalMujeres);
            wprintf(L"   - Peso medio: %.2f lb\n", sumaPesoMujeres / totalMujeres);
            wprintf(L"   - Dosis media: %.2f gramos\n", sumaDosisMujeres / totalMujeres);
        }
        wprintf(L" - Total de alumnos menores de edad: %d\n", totalMenoresEdad);
    }

    return 0;
}
