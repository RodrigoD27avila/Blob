import fcntl
import time

def main():
  teclado = open('/dev/tty0', 'r')
  leds = 0
  
  while True:
    fcntl.ioctl(teclado, 0x4B31, leds)
    
    if (leds == 8):
      leds = 0
    
    leds += 1
    time.sleep(1)

if __name__ == '__main__':
  main() 
