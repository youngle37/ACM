import sys
from decimal import Decimal, getcontext

def load_num():
    num_str = ''
    while num_str == '\n' or num_str=='':
        num_str = sys.stdin.readline()

    return int(num_str.rstrip())

if __name__ == '__main__':
   
    cases = load_num()
    
    getcontext().prec = 500

    for c in range(cases):
        y = load_num()
        print(int(Decimal(y).sqrt()))

        if c+1 < cases:
            print('')
