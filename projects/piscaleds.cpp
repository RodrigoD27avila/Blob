#include <sys/ioctl.h>
#include <linux/kd.h>
#include <fcntl.h>
#include <iostream>

int
main(int argc, char **argv)
{

  // Abrir o dispositivo teclado para leitura
  int teclado = open("/dev/tty0", O_RDONLY);

  // Inicializando o contador para variar os leds
  int leds = 0;

  while(1) {


    // So para imprimir algo na tela…
    std::cout << "Piscando…\n" << std::endl;

    // Chamada a system call que manipula os leds
    ioctl(teclado, KDSETLED, leds);

    // Para variar os leds que acendem
    leds++;

    // Zerar quando chega no ultimo estado possivel
    if( leds == 8 )
    {
      leds = 0;
    }

    sleep(1);
  }
}


