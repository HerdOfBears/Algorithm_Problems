

import requests, sys
 

def main():
	server = "https://rest.ensembl.org"
	ext = "/variation/human/rs56116432?"
	 
	r = requests.get(server+ext, headers={ "Content-Type" : "application/json"})
	 
	if not r.ok:
	  r.raise_for_status()
	  sys.exit()
	 
	decoded = r.json()
	print(repr(decoded))