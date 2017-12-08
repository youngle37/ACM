#!/usr/bin/env python3

from math import pi, asin

def area(a, b, c):
    s = (a+b+c)/2
    return (s*(s-a)*(s-b)*(s-c))**0.5

def bisection(low, up, func, err):
    while (up-low)/max(1,up+low) > 0.5*err: # 相加減會使誤差加倍 因此這裡除以二
        mid = (low+up)/2
        if func(mid) >= 0:
            low = mid
        else:
            up = mid

    return (up+low)/2

T = int(input())
for _ in range(T):
    perimeter, n = [float(x) for x in input().split()]
    L = [float(x) for x in input().split()]
    bigCircleArea = pi*(perimeter/(2*pi))**2
    max_L = max(L)
    angles_sum = sum(asin(x/max_L) for x in L) # 直徑最小為最長弦，此sum的每個弦的圓心角為原本一半，因此角度總和為pi

    if angles_sum > (1+1e-10)*pi: # angles_sum > pi，因為是遞減的函數，若比pi大代表往下勘根就能找到解
        R = bisection(max_L/2, perimeter/pi, lambda R: sum(asin(0.5*x/R) for x in L)-pi, 1e-15)
        print('%.20f'%(bigCircleArea-sum(area(R,R,x) for x in L)))
    elif angles_sum < (1+1e-10)*pi: # 因為arcsin在[0, 1]單調，又因上面的二分法要為遞減(乘負號)
        R = bisection(max_L/2, perimeter/pi, lambda R: 2*asin(0.5*max_L/R)-sum(asin(0.5*x/R) for x in L), 1e-15)
        print('%.20f'%(bigCircleArea-sum(area(R,R,x) for x in L)+2*area(R,R,max_L)))
    else:
        R = max_L/2
        print('%.20f'%(bigCircleArea-sum(area(R,R,x) for x in L)))
