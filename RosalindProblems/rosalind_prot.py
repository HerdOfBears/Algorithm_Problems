

import pandas as pd


def main():

	dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
	#file_name = "ex_prot.txt"
	file_name = "rosalind_prot.txt"
	file_codons_to_aa = "python_codons_to_aa.txt"

	df_codons_to_aa = pd.read_csv(dir_loc + file_codons_to_aa, sep="  ",header=None)
	df_codons_to_aa = df_codons_to_aa.values

	#print(df_codons_to_aa[0][0])
	#print(type(df_codons_to_aa[0][0]))
	list1_rem_nan = []
	for row in df_codons_to_aa:
		for word in row:
			if type(word) == str:
				list1_rem_nan.append(word)
	#print(len(list1_rem_nan))
	#print(list1_rem_nan[0:3])

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
	print(len(codon_to_aa_dict))
	print("")

	with open(dir_loc + file_name, "r") as f1:
		for line in f1:
			mRNA_s = line
	###
	mRNA_s_len = len(mRNA_s)

	AA_chain = ""
	for idx in range(0,mRNA_s_len-3,3):
		temp_codon = mRNA_s[idx:idx+3]
		AA = codon_to_aa_dict[temp_codon]
		if AA == "Stop":
			break
		else:
			AA_chain += AA

	with open(dir_loc + "result_prot.txt",'w') as f2:
		f2.write(AA_chain)
	###
	print("DONE")