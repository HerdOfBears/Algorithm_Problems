"""
author: Jyler
date first semester 2018
problem: two-sum and also three-sum from Rosalind.
two-sum is done
three-sum is too slow. Need to optimize. The current three-sum attempt is to sort-> fix two numbers,a and b, (using two for-loops) --> bin_search for -(a+b)
Migth try to implement into c++.


"""

import pandas as pd
import numpy as np
import time
import random


def main():


	dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
	file_name = "rosalind_3sum.txt"
	#file_name = "ex_3sum.txt"

	two_sum = 0
	three_sum = 1

	num = 0
	t0 = time.time()
	with open(dir_loc + file_name) as f1:
		

		lst_to_write = []
		for line in f1:

			num += 1
			if num == 1:
				k_n = line.strip("\n")
				k_n = k_n.split(" ")
				n = int( k_n[0] ) # length of given array
				k = int( k_n[1] ) # number of arrays
			elif num > 1:
				t2 = time.time()
				numbers = line.strip("\n")
				numbers_list = numbers.split(" ")
				B = [int(i) for i in numbers_list]

				if two_sum == 1:
					p, q = find_equal(B)
					if p == -1:
						lst_to_write.append(p)
					else:
						lst_to_write.append((p,q))

				elif three_sum == 1:
					p,q,r = find_equal_3sum(B,n)

					if p == -1:
						lst_to_write.append(p)
					else:
						lst_to_write.append((p,q,r))
				print("TIME PER ITERATION = ",time.time()-t2)

			#print("num", num)

	### file closed
	if two_sum == 1:
		result_file = "result_2sum.txt"
	elif three_sum == 1:
		result_file = "result_3sum.txt"

	with open(dir_loc + result_file, "a") as f2:
		for word in lst_to_write:
			if word == -1:
				f2.write(str(-1) + "\n")
			else:
				if two_sum == 1:
					new_word = str(word[0]+1) + " " + str(word[1]+1) +"\n"
					f2.write(new_word)
				elif three_sum == 1:
					new_word = str(word[0]+1) + " " + str(word[1]+1) + " " + str(word[2]+1) + "\n"
					f2.write(new_word)

	print("DONE.")

	pass


def find_equal(arr):

	
	for idx1 in range(len(arr)):

		for idx2 in range(idx1+1,len(arr)):

			if ( arr[idx1] == ( (-1) * arr[idx2] ) ):
				return idx1, idx2

	return -1,-1


#  need to find number a,b,c s.t. a + b + c = 0
# Straight-forward three nested for-loops did not work, as expected
# Going to try storing first loop's values in an array based on value (i.e. the element's value is its index)
# so that I can quickly point to the array to check if we have already tried a number.
# This way we don't waste time with duplicates.
def find_equal_3sum(arr,size):

	l = len(arr)
	#global store
	#store = np.zeros([2,100000]) - 1 # the second row is for negative numbers

	# build a storage array where each element from the given array is the index location in the 
	# stored array. 
	#print("Constructing storage array")
	#print(np.sum(store))

	print("constructing sorted list of tuples")
	store = []
	for idx in range(l):
		store.append((arr[idx],idx))

	store.sort(key = lambda tup: tup[0])
	store_arr = np.array(store)
	print("")
	print("done sorting tuples: ", store[0:5])
	print("")

	res = -1
	prev = None
	for idx1 in range(l):
		#a = arr[idx1]
		
		a = store[idx1][0]
		# once we check all of the negative numbers against all of the other numbers, we know there is no solution.
		if ( a > 0 ):
			break
		# if we check integer a1 vs all other numbers, w don't have to check a duplicate of a1 ever again.
		if (a == prev):
			#print("skipped a duplicate")
			prev = a
			continue

		p = store[idx1][1]#idx1 #+ 1
		for idx2 in range(idx1,l):
			#b = arr[idx2]
			b = store[idx2][0]
			q = store[idx2][1]#idx2 #+ 1
			# a + b + c = 0 --> a + b = -c, need to find c s.t. -c = a+b
			need_to_find = -1 * int(a + b)

#			if ( need_to_find < 0 ):
				#row_idx = 1
#				need_to_find = -1 * int(need_to_find)
				#stored_idx = int(store[row_idx, need_to_find])
#			elif ( need_to_find >= 0 ):
				#row_idx = 0
#				need_to_find = int(need_to_find)
				#stored_idx = int(store[row_idx, need_to_find])
			# end if

			#r = bin_search(need_to_find, 0, len(store), store, 0)
			r1 = np.where(store_arr[:,0] == need_to_find)

			if ( len(r1[0]) == 0 ):
				r = -1
			elif ( (store_arr[r1[0][0],1] == store[idx1][1]) or (store_arr[r1[0][0],1] == store[idx2][1]) ):
				#continue
				r = -1
			else:
				r = store_arr[r1[0][0],1]

			#index_to_return

			if ( r == -1):

				if ( idx2 % 500 ) == 0:
					print("idx1, idx2 = ", idx1, " ", idx2)
					pass
				#print("IMPOSSIBLE")
			elif ( r != -1):
				res = r #+ 1
				sorted_pqr = [p,q,res]
				sorted_pqr.sort()
				p, q, res = sorted_pqr[0], sorted_pqr[1], sorted_pqr[2]
				print("found something")
				print("r1 = ", r1)
				print("need_to_find = ",need_to_find, " a=",a," b=",b)
				print("idx1 = ",idx1, " idx2 = ",idx2)
				print("p, q, res = ",p,q,res)
 
				return p,q,res
				#return p, q, res
		# end nested for
		prev = a

	return -1,-1,-1 

			#if ( int(stored_idx) == -1 ):
		#		re = -1
		#	else:
		#		re = arr[stored_idx]
#
#				if ( int(a + b) + int(r) == 0):
#					print("found some")
#					return idx1, idx2, r  
			# end if


	# end for


	return -1,-1,-1


def stored_num(store, element, row_idx, idx):
		#print(np.sum(store))

		if element < 0:
			n_elem = -1 * element # the second row of the store array is for negative numbers
		else:
			n_elem = element

		is_there = 0
		if ( int( store[row_idx,n_elem-1] ) != -1 ):  # if == -1, then the element has not been seen before. 
			#print("IT'S THERE!")
			is_there = 1
			pass
		else:
			store[row_idx, n_elem-1] = idx # want to store the idx for quick reference later
		#print("after: ", np.sum(store))
		return store, is_there


def bin_search(k, mini, maxi, arra, depth):
	# k --> key, the number we are searching for
	# arra --> array of 2-tuples, tup. tup[0] is the number to look for

	if (int(k) < k):
		return -1

	pivot_idx = (mini + maxi)//2
	tup = arra[pivot_idx]
	pivot_pt = tup[0]

	# Had problems with edges of array.
#	if ( (pivot_idx + 1) == len(arra) ):

	if ((maxi-mini) == 1):
		
		if ( (pivot_idx + 1) == len(arra) ):

			#print("diff of 1")
			if k == arra[pivot_idx][0]:
				return pivot_idx
			if k == arra[pivot_idx - 1][0]:
				return pivot_idx - 1
			else:
				return -1
		else:
			if k == arra[pivot_idx][0]:
				return pivot_idx
			if k == arra[pivot_idx + 1][0]:
				return pivot_idx + 1
			else:
				return -1

	# Left hand side
	if ( k < pivot_pt ): 
		r = bin_search(k, mini, pivot_idx, arra, depth + 1)
	# Right hand side
	elif ( k > pivot_pt ):
		r = bin_search(k, pivot_idx, maxi, arra, depth + 1)
	elif ( k == pivot_pt ):
		return tup[1]
	else:
		return -1

	if r == -1:
		return r
	elif depth == 0:
		r = r + 1 # because problem wants 1-indexing, not zero-indexing
		return r
	else:
		return r
