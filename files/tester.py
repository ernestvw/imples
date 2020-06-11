from os import system
from random import randint

solution = input()
correction = input()

system("g++ -O2 -o sol " + solution)
system("g++ -O2 -o cor " + correction)

def genTest():
	finput = open("input.txt", "w+")
	chaine = ""
	# ecrire le test dans chaine
	# fin ecriture test
	finput.write(chaine)
	finput.close()

nbTests = 100

for test in range(nbTests):
	genTest()

	system("./sol < input.txt > out")
	system("./cor < input.txt > correct")
	system("echo 'test no " + str(test + 1) + ":'")

	fsol = open("out", "r")
	fcor = open("correct", "r")
	OUT = list(fsol.read().split())
	COR = list(fcor.read().split())
	fsol.close()
	fcor.close()

	ok = False
	if len(OUT) == len(COR):
		ok = True
		for i in range(len(OUT)):
			if OUT[i] != COR[i]:
				ok = False
	
	if ok:
		print("OK")
	else:
		print("WA")
		print("Input:")
		system("cat input.txt")
		print("\nExpected output:")
		system("cat correct")
		print("\nReceived:")
		system("cat out")
		break
