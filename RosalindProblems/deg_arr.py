"""

author: Jyler Menard
date: First semester 2018
purpose: Solve Rosalind's (website) degree array problem

"""
import time
import numpy as np

def main():

	dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
	file_name = "rosalind_deg.txt"
	#file_name = "ex_deg.txt"

	num = 0
	t0 = time.time()
	with open(dir_loc + file_name) as f1:
		

		edges = []
		for line in f1:

			num += 1
			if num == 1:
				nv_ne = line.strip("\n")
				n_vertices = int( nv_ne.split(" ")[0] )
				n_edges = int( nv_ne.split(" ")[1] )
				
				D = np.zeros((1,n_vertices))
				print(D)

			elif num > 1:
				
				edg = line.strip("\n")
				v1_v2 = edg.split(" ")
				v1 = int( v1_v2[0] )
				v2 = int( v1_v2[1] )

				D[0,v1-1] += 1
				D[0,v2-1] += 1


				pass

	### file closed	
	print(D)

	new_string = None
	for word in D[0]:
		if new_string == None:
			new_string = str(int(word))
		else:
			new_string += " " + str(int(word))


	with open(dir_loc + "result_deg.txt",'a') as f2:
		f2.write(new_string)

	pass

