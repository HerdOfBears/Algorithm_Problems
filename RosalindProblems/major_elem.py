
import time
import pandas as pd
import numpy as np


## Given an array of integers <= 10^5, and array size <=10^4, find whether there is a majority element (and if so, what it is).
## Idea:
## Sort list.
## Then iterate through and take a step of half the list length forwards. 
## Ex: list length = 10, say we are at idx 1 (0-indexing), check if the element at idx 6 (maybe 7th) is identical, 
## if so, then it is the majority element.

def main():
	
	dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
	file_name = "rosalind_maj.txt"
	#file_name = "ex_maj.txt"

	num = 0
	t0 = time.time()
	with open(dir_loc + file_name) as f1:
		

		lst_to_write = []
		for line in f1:

			num += 1
			if num == 1:
				k_n = line.strip("\n")
				k_n_lst = line.split(" ")
				k = int( k_n_lst[0] )
				n = int( k_n_lst[1] )
				#print("k, n = ", k, n)

			elif num > 1:
				#input("Continue?")
				numbers = line.strip("\n")
				numbers_list = numbers.split(" ")
				numbers_list_int = [int(i) for i in numbers_list]


				numbers_list_int.sort()
				#print(numbers_list_int)
				found_one = None

				t1 = time.time()
				print("num = ",num, " time to half = ", t1-t0)

				first_elem = numbers_list_int[0]
				last_elem = numbers_list_int[n-1]
				quick_chk_mid_r = numbers_list_int[(n//2)+1]
				quick_chk_mid_l = numbers_list_int[(n//2)-1]
				quick_chk_quart = numbers_list_int[(n//4)]
				quick_chk_3quart = numbers_list_int[( (3*n)//4 )]
				

				# Quckly check the first and last elements of the list.
				if ( (quick_chk_mid_r == first_elem) ):
					#found_one = 1
					lst_to_write.append(first_elem)  
				elif (quick_chk_mid_l == last_elem ):
					#found_one = 1
					lst_to_write.append(last_elem)
				elif ( quick_chk_quart == quick_chk_3quart ):
					lst_to_write.append(quick_chk_quart)
				else:
					for idx in range(1, (n//2) - 2 ):
						step_fwd = idx + (n//2) 
						element = numbers_list_int[idx]
						fwd_half_len = numbers_list_int[step_fwd]
						#print("numbers_list_int = ",numbers_list_int)
						#print("elem = ",element, " fwd_half_len = ",fwd_half_len)
						if (element == fwd_half_len):
							found_one = 1
							lst_to_write.append(element)
							break
				###

					if (found_one == None):
						lst_to_write.append(-1)
				print("Time to determine major elem = ", time.time() - t1)

			#num += 1
	###
	print("\n",lst_to_write)
	string_2_write = None
	for elem in lst_to_write:
		if (string_2_write == None):
			string_2_write = str(elem)
		else:
			string_2_write += " " + str(elem)

	with open(dir_loc + "result_maj.txt",'a') as f2:
		f2.write(string_2_write)

	print("Done")
	#print("Time to half-point = ", t1-t0)
	print("Global time elaspsed = ", time.time() - t0)

	pass