"""
author: Jyler
date: 1st semester 2018
problem: count number of A,C,G,T in nucleitodie sequence
"""


def main():
	
	dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
	file_name = "rosalind_dna.txt"

	with open(dir_loc + file_name,'r') as f1:
		for line in f1:

			s = line.strip("\n")
	# file closed


	num_A = 0
	num_T = 0
	num_G = 0
	num_C = 0
	for letter in s:

		if ( letter == "A" ):
			num_A += 1
		elif ( letter == "T" ):
			num_T += 1
		elif ( letter == "G" ):
			num_G += 1
		elif ( letter == "C" ):
			num_C += 1
	
	sentence = str(num_A) + " " + str(num_C) + " " + str(num_G) + " " + str(num_T)
	with open(dir_loc + "result_countNTP.txt",'w') as f2:
		f2.write(sentence)

	print("DONE")