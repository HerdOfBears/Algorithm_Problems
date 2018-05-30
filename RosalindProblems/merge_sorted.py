

import pandas as pd
import numpy as np
import time
import random


def main():
	
	
	dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
	file_name = "rosalind_mer.txt"
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
			elif num == 3:
				m = line.strip("\n")
				m = int( m )
			elif num == 2:
				numbers_A = line.strip("\n")
				numbers_list_A = numbers_A.split(" ")
				A = [int(i) for i in numbers_list_A]
			elif num == 4:
				numbers_B = line.strip("\n")
				numbers_list_B = numbers_B.split(" ")
				B = [int(i) for i in numbers_list_B]
			#print("num", num)

	### file closed

	r = mergesort(A,B)

	new_string = None
	for word in r:
		if new_string == None:
			new_string = str(word)
		else:
			new_string += " "+ str(word)

	with open(dir_loc + "result_mer.txt",'a') as f2:
		f2.write(str(new_string))


	pass

def mergesort(x,y):

	
	num = 0
	n_x = len(x)
	n_y = len(y)

	x_y = y

#	if ( n_x > n_y ):
#		n = 

	for elem in x:

		for idx_y in range(0,n_y):

			k = idx_y
			if ( elem >= x_y[n_y-1]):
				x_y = x_y + [elem]
				#print("after insert largest = ",x_y)
				break

			if ( elem <= x_y[k] ):
				#print("elem = ",elem)
				#print("x_y = ",x_y)
				x_y = x_y[:k] + [ elem ] + x_y[k:]
				n_y += 1
				#print("after insertion = ", x_y)
				break

	return x_y

