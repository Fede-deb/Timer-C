#include <stdio.h>
#include <unistd.h> // Para usar sleep

// Función recursiva para el temporizador
void temporizador(int horas, int minutos, int segundos) {
    // Limpiar la pantalla
    system("clear");

    // Mostrar el tiempo restante
    printf("%02d:%02d:%02d\n", horas, minutos, segundos);

    // Caso base: si llega a 0 horas, minutos y segundos, termina
    if (horas == 0 && minutos == 0 && segundos == 0) {
        printf("¡El tiempo terminó!\n");
        system("i3lock -i /home/fedee/Cronometro/Wallpaper_temporizador.png");
        return; // Salir de la función recursiva
    }

    // Pausar por 1 segundo
    sleep(1);

    // Reducir los segundos, minutos y horas en caso necesario
    if (segundos > 0) {
        temporizador(horas, minutos, segundos - 1);
    } else {
        if (minutos > 0) {
            temporizador(horas, minutos - 1, 59);
        } else {
            if (horas > 0) {
                temporizador(horas - 1, 59, 59);
            }
        }
    }
}

int main() {
    int horas, minutos, segundos;

    // Solicitar el tiempo al usuario
    printf("Introduce el tiempo del temporizador:\n");
    printf("Horas: ");
    scanf("%d", &horas);
    printf("Minutos: ");
    scanf("%d", &minutos);
    printf("Segundos: ");
    scanf("%d", &segundos);

    // Validar el formato inicial del temporizador
    printf("\nEl temporizador es de %02d:%02d:%02d\n", horas, minutos, segundos);

    // Iniciar la llamada recursiva
    temporizador(horas, minutos, segundos);

    return 0;
}
