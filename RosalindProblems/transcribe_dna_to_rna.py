


def main(): 
	
	dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
	file_name = "rosalind_rna.txt"

	with open(dir_loc + file_name,'r') as f1:
		for line in f1:

			s = line.strip("\n")
	# file closed

	rna_seq = None
	for letter in s:

		if ( letter == "A" ):
			if ( rna_seq == None ):
				rna_seq = letter
			else:
				rna_seq += letter
		elif ( letter == "T" ):
			if ( rna_seq == None ):
				rna_seq = "U"
			else:
				rna_seq += "U"			
		elif ( letter == "G" ):
			if ( rna_seq == None ):
				rna_seq = letter
			else:
				rna_seq += letter
		elif ( letter == "C" ):
			if ( rna_seq == None ):
				rna_seq = letter
			else:
				rna_seq += letter

	with open(dir_loc + "result_dna2rna.txt",'w') as f2:
		f2.write(rna_seq)