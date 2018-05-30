


def main():

	dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
	#file_name = "ex_hamm.txt"
	file_name = "rosalind_hamm.txt"

	counter = 0
	with open(dir_loc + file_name, "r") as f1:
		for line in f1:
			if ( counter == 0 ):
				s = line
			elif ( counter > 0 ):
				t = line
			counter += 1

	s = s[:len(s)-1]
	t = t[:len(t)-1]	

	dH = 0
	for idx in range(len(s)):
		if s[idx]==t[idx]:
			continue
		else:
			dH += 1

	print("Hamming distance = ",dH)
	print("done")
