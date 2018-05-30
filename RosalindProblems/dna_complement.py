'''
author: Jyler
date: 1st semester 2018
problem: find complement to a DNA strand

'''


def main(): 
	
	dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
	file_name = "rosalind_revc.txt"

	with open(dir_loc + file_name,'r') as f1:
		for line in f1:

			s = line.strip("\n")
	# file closed

	complement_seq = None
	for letter in s:

		if ( letter == "A" ):
			if ( complement_seq == None ):
				complement_seq = "T"
			else:
				complement_seq = "T" + complement_seq
		elif ( letter == "T" ):
			if ( complement_seq == None ):
				complement_seq = "A"
			else:
				complement_seq = "A" + complement_seq		
		elif ( letter == "G" ):
			if ( complement_seq == None ):
				complement_seq = "C"
			else:
				complement_seq = "C" + complement_seq
		elif ( letter == "C" ):
			if ( complement_seq == None ):
				complement_seq = "G"
			else:
				complement_seq = "G" + complement_seq

	with open(dir_loc + "result_dna2compl.txt",'w') as f2:
		f2.write(complement_seq)