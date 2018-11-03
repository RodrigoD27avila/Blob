class F:
  def __init__(self):
    self.i = 0
  def foo(self):
    print (self.i)
    self.i += 1
    self.foo()
    
if __name__ == '__main__':
  f = F()
  f.foo()

