from threading import Thread


x=0


def fun():
    
global x
    
print("x=", x)
    
x=x+1
    
print("xafter",x)
    
return

mylist = []


for i in range(5):
    
mythread = Thread(target=fun)
    
mythread.start()
    
mythread.join()