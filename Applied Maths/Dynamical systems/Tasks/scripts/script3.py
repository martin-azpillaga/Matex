from random import *

def f(a,x):
    return x**3 -3*x**2 +(5-a)*x -2 + a

def main(min_a,max_a,min_x,max_x,step,iterations):

    file = open("data.dat","w")
    
    a = min_a
    while a < max_a :

        points = [min_x + random()*abs(max_x - min_x) for point in range(10)]

        for point in points:
            iter = 1
            while abs(point) < 10e3 and iter < iterations:

                point = f(a,point)
                iter+=1
            
            if abs(point) < 10e3:
                file.write(str(a)+" , "+str(point)+"\n")

        a += step
            
