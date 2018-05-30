"""
Author: Jyler
Date: 1st semester 2018
Problem from Rosalind.info
Problem 1 of Dynamic programming topic.

Dynamic programming = algorithmic notion of building up a solution to a problem by solving it progressively larger cases.

"""


def main():

	dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
	file_name = "rosalind_fib.txt"

	with open(dir_loc + file_name,'r') as f1:
		for line in f1:

			s = line.strip("\n")
			n_k = s.split(" ")
			n = int( n_k[0] )
			k = int( n_k[1] )			
	# file closed

	reproducers, tot = 0, 1
	for idx in range(1,n):
		reproducers, tot = tot, tot + k * reproducers
		print("reproducers = ",reproducers)
		print("total = ",tot)
		print("")


	with open(dir_loc + "result_rabbits.txt",'w') as f2:
		f2.write(str(tot))
	print("DONE")
