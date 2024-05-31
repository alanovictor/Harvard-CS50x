names = ["Carter", "David", "Jonh"]

name = input("Name ")

for n in names:
    if name == n:
        print("Found")
        break
else:
    print("Not found")

# acima é uma pessima mostragem se tratando de python

if name in names:
    print("Found")
else:
    print("Not found")
