


def main():
	tst = "TCGCGCAACACGTGCTGGTTATTATCTCGGGGGGTCATCATATCAAAGCAAAAGGGGCTCAAATCGGTTTTCCACAGATATACTTCCACGGAGTGTCA"
	dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
	file_name = "rosalind_grph.txt"

	counter = 0;
	with open(dir_loc + file_name) as f1:
		for line in f1:
			if line[0] == ">":
				counter += 1

	print("DONE")
	print("counter = ",counter)
	print(len(tst))