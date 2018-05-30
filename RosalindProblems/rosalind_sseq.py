

def main():

	dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
	#file_name = "ex_sseq.txt"
	file_name = "rosalind_sseq.txt"


	dna_string = ""
	subseq = ""
	counter = 0
	with open(dir_loc + file_name, "r") as f1:
		for line in f1:
			line = line.strip("\n")
			if line[0] == ">":
				counter += 1
				continue
			if counter == 1:
				dna_string += line
			if counter > 1:
				subseq += line

	length_dna_string = len(dna_string) ## O(n)
	length_subseq = len(subseq) ## O(n)

	temp_n = 0
	indices = []
	for idx in range(length_dna_string): ## O(n)
		#print("temp_n = ",temp_n)
		if dna_string[idx] == subseq[temp_n]:
			indices.append(idx+1)
			temp_n += 1
			print("temp_n = ",temp_n)
			if temp_n == length_subseq: 
				break

	# time complexity O(n)
	print(indices)

	sentence = ""
	for idx in indices:
		sentence += str(idx) + " "

	with open(dir_loc + "result_sseq.txt",'w') as f1:
		f1.write(sentence)