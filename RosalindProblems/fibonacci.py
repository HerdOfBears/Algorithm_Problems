

import pandas as pd
import numpy as np

def main():

	dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
	file_name = "rosalind_fibo.txt"

	num = 0
	with open(dir_loc + file_name, 'r') as f:
		#print("2")
		for line in f:
			print(line)
			N = int( line.strip("\n") )
			result = fastfib(N)[0]
			with open(dir_loc + "result.txt",'a') as f2:
				str2write = str( result )
				str2write += "\n"
				f2.write(str2write)
			num += 1

			if num>5:
				break


def fastfib(n):

	num0 = 0
	num1 = 1

	for i in range(n):
		num0, num1 = num1, num0+num1

	return num0,num1