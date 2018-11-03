#!/usr/bin/env python

import sys
from gi.repository import Clutter

def on_button_press (stage, event):
  pass

def on_key_press (stage, event):
  pass

def sine_wave (alpha, unused):
  pass
  
def main ():
  hello_str = chr_chr = ''
  x_offset = y_offset = idx = 0
  
  # initialize Clutter
  Clutter.init (sys.argv)
  
  if (len (sys.argv) > 1):
    hello_str = argv[0]
  else:
    hello_str = 'Hello Clutter!'
  
    # create a Stage
    stage = Clutter.Stage ()
    
    # set the title of the Stage window
    stage.set_title ('Hello, Clutter')
    
    # set the background color of the Stage
    stage_color = Clutter.Color ()
    Clutter.Color.from_string (stage_color, 'DarkSlateGray')
    stage.set_color (stage_color)
    
    # connect the pointer button press and key press event signals
    stage.connect ('button-press-event', on_button_press)
    stage.connect ('key-press-event', on_key_press)
    stage.connect ('destroy', Clutter.main_quit)
    
    # set the size of the Stage
    stage.set_size (800, 600)
    
    # then show the Stage
    stage.show_all ()
    
if __name__ == '__main__':
  main ()
  Clutter.main ()
