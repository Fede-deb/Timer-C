#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

int main(){
    int horas=0,minutos=0,segundos=0,time=0,i;
    printf("Intoduce el timpo del temporizador : \n");
    printf("Introduce las horas: ");
    scanf("%d",&horas);
    printf("\nIntroduce los minutos: ");
    scanf("%d",&minutos);
    printf("\nIntroduce los segundos: ");
    scanf("%d",&segundos);

    printf("\nEl temporizador es de %02d:%02d:%02d \n",horas,minutos,segundos);

  
    while (horas > 0 || minutos >0 || segundos > 0){
        system("clear");

        printf("%02d:%02d:%02d\n", horas, minutos, segundos);

        sleep(1);

        if (segundos > 0){
            segundos--;
        } else{
            segundos =59;
            if (minutos >0){
                minutos --;
            } else{
                minutos=59;
                if (horas > 0){
                    horas --;
                }
            }
        }
    }
    system("clear");
    printf("El tiempo TERMINO");

    system("mpg123 /home/fedee/Cronometro/bedside-clock-alarm-95792.mp3");
    
    system("i3lock -i /home/fedee/Cronometro/Wallpaper_temporizador.png");

    printf("\n\n");
    return 0;
}