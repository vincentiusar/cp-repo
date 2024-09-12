import os
import sys
import time
import random

WINDOWS_LINE_ENDING = b'\r\n'
UNIX_LINE_ENDING = b'\n'

def get_time() :
    return int(round(time.time()))
    
def get_randint(low, high):
    return random.randint(low, high)

def get_randfloat(l_inclusive, low, h_inclusive, high):
    rand = lambda : random.random() * (high - low) + low
    
    res = rand()
    while (l_inclusive and res == low) or (h_inclusive and res == high):
        res = rand()
        
    return res

#Generate t TC
N = [10] + [100] * 8 + [8 * 10**6]

if (len(sys.argv) == 1) : 
    start = 0
    end = 10
elif (len(sys.argv) == 2):
    start = 0
    end = int(sys.argv[1])
else:
    start = int(sys.argv[1]) - 1
    end = int(sys.argv[2])

for t in range(start, end) :
    #Create input file
    print('Creating TC {}'.format(t + 1))
    start_time = get_time()
    
    input_name = 'input\input{}.txt'.format(t + 1)
    output_name = 'output\output{}.txt'.format(t + 1)
    
    # A = get_randint(50000, 100000)
    A = 100000
    # B = get_randint(10, 10)
    B = 100000-1
    while (B > A): B = get_randint(10, 10)
    # A = 10
    # B = 5

    input = '{} {}\n'.format(A, B)

    for i in range(A) :
        input += str(get_randint(1, 1000000)) + " "
    
    #Create input file with Unix (LF) format
    input_file = open(input_name, 'w+', newline='\n')
    input_file.write(input)
    input_file.close()
    
    run_time = get_time() - start_time
    print('TC {} successfully created in {}s'.format(t + 1, run_time))
    
    start_time = get_time()
    #Create output file based on solution
    os.system('a < {} > {}'.format(input_name, output_name))  #a is program name with .exe extension
    run_time = get_time() - start_time
    print('TC {} executed in {}s'.format(t + 1, run_time))
    
    #Change EOL of output file to Unix (LF) format
    content = None
    with open(output_name, 'rb') as open_output:
        content = open_output.read()
    
    if content:
        content = content.replace(WINDOWS_LINE_ENDING, UNIX_LINE_ENDING)
    
    with open(output_name, 'wb') as open_output:
        open_output.write(content)

print('Done')