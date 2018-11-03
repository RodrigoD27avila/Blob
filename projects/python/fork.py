#!/usr/bin/env python

import os

id = os.fork ()
if (id == 0):
  print ("Child Process: PID %s" % os.getpid())
else:
  print ("Parent Process: PID %s" % os.getpid())
