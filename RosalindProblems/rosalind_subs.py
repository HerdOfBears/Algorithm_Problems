


def main():

	dir_loc = "C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/"
	#file_name = "ex_subs.txt"
	file_name = "rosalind_subs.txt"

	counter = 0
	with open(dir_loc + file_name, "r") as f1:
		for line in f1:
			if ( counter == 0 ):
				s = line
			elif ( counter > 0 ):
				t = line
			counter += 1
	t_len = len(t)
	t = t[:t_len-1]
	t_len = len(t)
	s_len = len(s)
	positions = []

	
	# recall: zero-indexing!!
	# Have to add 1 to idx when finding location.
	for idx in range(s_len-t_len):
		temp = s[idx:(idx + t_len)]
		#print("temp = ",temp)
		if t == temp:
			positions.append(idx+1)

	print(positions)

	sentence = None
	for pos in positions:
		if sentence == None:
			sentence = str(pos)
		else:
			sentence += " " + str(pos)

	print("sentence = ",sentence)
	with open(dir_loc + "result_subs.txt", 'a') as f2:
		f2.write(sentence)

	print("done")
