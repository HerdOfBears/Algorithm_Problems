

import pandas as pd
import numpy as np
import random


def main():
	
	dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
	file_name = "rosalind_bins.txt"
	#file_name = "test_bins.txt"

	num = 0
	with open(dir_loc + file_name) as f1:
		
		for line in f1:

			num += 1
			if num == 1:
				N = int( line.strip("\n") )
			elif num == 2:
				M = int( line.strip("\n") )
			elif num == 3:
				numbers = line.strip("\n")
				numbers_list = numbers.split(" ")
				numbers_list_int = [int(i) for i in numbers_list]
			elif num == 4:
				k_line = line.strip("\n")
				key_numbers = k_line.split(" ")
				key_numbers_int = [int(i) for i in key_numbers]
	
	#### File is closed

	positions = []
	length_N = N # number of integers in array.
	length_M = M

	num = 1
	for key in key_numbers_int:

		try:
			result = recur(key, 0, length_N, numbers_list_int,0)
		except Exception:
			print("Encountered error")
			print("Key = ", key)

		#result += 1 # because python has zero-indexing, while the problem wants 1-indexing

		if num == 1:
			sentence = str(result)
		else:
			sentence +=  " " + str(result) 
		num += 1

	with open(dir_loc + "result_bins.txt",'w') as f2:
		f2.write(sentence)

	# Let's us see how well it did.
	checking = 0
	if checking == 1:
		wait = 0
		while wait != 1:

			print("This is for checking if the indexes are correct.")
			usr_input = input("continue? [n,y]")
			if usr_input == "n":
				wait = 1
				break
			else:
				pass
			idx = random.randint(0,length_M)
			rand_num = key_numbers_int[idx]
			result = recur(rand_num, 0, length_N, numbers_list_int,0)
			result_check = numbers_list_int[result]
			result_check_l = numbers_list_int[result-1]
			result_check_r = numbers_list_int[result+1]
			print("random num = ",rand_num, " result of recur = ", result, " result_check = ", result_check, " result_check_l = ",result_check_l, " result_check_r = ", result_check_r)

	print("length M = ",length_M)
	print("length N = ",length_N)	
	print("done")
	


def recur(k, mini, maxi, arra, depth):

	#if depth>5:
	#	return -9
	if (int(k) < k):
		return -1

	pivot_idx = (mini + maxi)//2
	pivot_pt = arra[pivot_idx]

	# Had problems with edges of array. 
	if ((maxi-mini) == 1):
		#print("diff of 1")
		if k == arra[pivot_idx]:
			return pivot_idx
		if k == arra[pivot_idx + 1]:
			return pivot_idx + 1
		else:
			return -1

	# Left hand side
	if ( k < pivot_pt ): 
		r = recur(k, mini, pivot_idx, arra, depth + 1)
	# Right hand side
	elif ( k > pivot_pt ):
		r = recur(k, pivot_idx, maxi, arra, depth + 1)
	elif ( k == pivot_pt ):
		return pivot_idx
	else:
		return -1

	if r == -1:
		return r
	elif depth == 0:
		r = r + 1 # because problem wants 1-indexing, not zero-indexing
		return r
	else:
		return r


