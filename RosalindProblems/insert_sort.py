

import time
import pandas as pd
import numpy as np



def main():

	dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
	file_name = "rosalind_ins.txt"
	#file_name = "ex_maj.txt"

	num = 0
	t0 = time.time()
	with open(dir_loc + file_name) as f1:
		

		lst_to_write = []
		for line in f1:

			num += 1
			if num == 1:
				n = line.strip("\n")
				n = int( n )
				
			elif num > 1:
				#input("Continue?")
				numbers = line.strip("\n")
				numbers_list = numbers.split(" ")
				numbers_list_int = [int(i) for i in numbers_list]

	### file closed

	r = swapper(numbers_list_int,n)

	with open(dir_loc + "result_ins.txt",'a') as f2:
		f2.write(str(r))


# Insertion sort algorithm.
def swapper(arr,n):

	num = 0
	for idx in range(1,n):
		k = idx
		while ( (k>0) and (arr[k] < arr[k-1]) ):
			
			# SWAPPER
			arr[k], arr[k-1] = arr[k-1], arr[k]
			num += 1
			k = k - 1

	print(arr, " num swaps = ",num)
	return num


