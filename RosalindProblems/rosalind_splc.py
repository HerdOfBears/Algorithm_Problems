
import pandas as pd

dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
file_codons_to_aa = "python_codons_to_aa.txt"

df_codons_to_aa = pd.read_csv(dir_loc + file_codons_to_aa, sep="  ",header=None)
df_codons_to_aa = df_codons_to_aa.values

list1_rem_nan = []
for row in df_codons_to_aa:
	for word in row:
		if type(word) == str:
			list1_rem_nan.append(word)

codon_to_aa_dict = {}
for word in list1_rem_nan:
	temp_word = word.split(" ")
	if temp_word[0] == "":
		use_key= temp_word[1]
		use_val = temp_word[2]
	else:
		use_key = temp_word[0]
		use_val = temp_word[1]
	codon_to_aa_dict[use_key] = use_val

def transcribe_to_RNA(DNA_s):
	# given string of DNA, transcribes to RNA
	dna_len = len(DNA_s)
	RNA_s = ""
	for NTP in DNA_s:
		if NTP == "T":
			RNA_s += "U"
		if NTP == "A":
			RNA_s += "A"
		if NTP == "C":
			RNA_s += "C"
		if NTP == "G":
			RNA_s += "G"

	return RNA_s


def translate_to_AA(mRNA):
	# Given string of RNA, with preprocessing done, translates to amino acid chain.
	mRNA_len = len(mRNA)

	AA_chain = ""
	for idx in range(0,mRNA_len-3,3):
		temp_codon = mRNA[idx:idx+3]
	#	if temp_codon == "AUG":
	#		print("temp_codon = ",temp_codon)
	#		print(codon_to_aa_dict)
		AA = codon_to_aa_dict[temp_codon]
		if AA == "Stop":
			break
		else:
			AA_chain += AA

	return AA_chain


def main():

	dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
	#file_name = "ex_splc.txt"
	file_name = "rosalind_splc.txt"

	dna_string = ""
	introns = []
	counter = 0
	with open(dir_loc + file_name, "r") as f2:
		for line in f2:
			line = line.strip("\n")
			if line[0] == ">":
				counter += 1
				continue
			if counter == 1:
				dna_string += line
			if counter > 1:

				introns.append(line)

	spliced_dna_string = dna_string

	for intron in introns:
		start_pos = spliced_dna_string.find(intron)
		final_pos = start_pos + len(intron)
		spliced_dna_string = spliced_dna_string[:start_pos] + spliced_dna_string[final_pos:]
		
	rna_string = transcribe_to_RNA(spliced_dna_string)
	AA_chain = translate_to_AA(rna_string)


	print("AA = \n",AA_chain)


	with open( dir_loc + "result_splc.txt",'w') as f2:
		f2.write(AA_chain)

	print("DONE")
