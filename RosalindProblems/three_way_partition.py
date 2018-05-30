"""
author: Jyler
date: 1st semester 2018
problem: 3-way partition. Take the first element, A1, of a given array A, and output a new array with
		three partitions: 1) stuff smaller than A1, 2) stuff larger than A1, 3) stuff equal to A1.
"""

import pandas as pd
import numpy as np
import time

def main():


	dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
	file_name = "rosalind_par3.txt"
	#file_name = "ex_2way.txt"

	num = 0
	t0 = time.time()
	with open(dir_loc + file_name) as f1:
		
		lst_to_write = []
		for line in f1:

			num += 1
			if num == 1:
				n = line.strip("\n")
				n = int( n ) # length of given array
			elif num > 1:
				t2 = time.time()
				numbers = line.strip("\n")
				numbers_list = numbers.split(" ")
				A = [int(i) for i in numbers_list]
	### Input file closed

	lesser_than_lda = []
	greater_than_lda = []
	equal_to_lda_l = []
	equal_to_lda_r = []
	L = len(A)
	lda = A[0]
	num = 0
	for idx in range(1,L):

		if ( A[idx] > lda ):
			greater_than_lda.append(A[idx])
		if ( A[idx] < lda ):
			lesser_than_lda.append(A[idx])
		if ( A[idx] == lda ):

			if ( num % 2 ) == 0:
				equal_to_lda_l.append(A[idx])
			if ( num % 2 ) == 1:
				equal_to_lda_r.append(A[idx])

			num += 1
	pt_q = len(lesser_than_lda)
	final_lst = (lesser_than_lda + 
				equal_to_lda_l + 
				[lda] + 
				equal_to_lda_r + 
				greater_than_lda)


	new_string = None
	for word in final_lst:
		if ( new_string == None ):
			new_string = str(word)
		else:
			new_string += " " + str(word)

	with open(dir_loc + "result_par3.txt",'a') as f2:
		f2.write(str(new_string))

	print("DONE")

