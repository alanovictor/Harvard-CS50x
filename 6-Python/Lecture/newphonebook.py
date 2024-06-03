people = [
    {"name": "Carter", "number": "+1-617-495-1000"},
    {"name": "David", "number": "+2-617-495-1000"},
    {"name": "Jonh", "number": "+3-617-495-1000"}
]
# este abaixo, apenas para uma chhave e um valor para cada.
people2 = {
    "Carter": "+1-617-495-1000",
    "David": "+2-617-495-1000",
    "Jonh": "+3-617-495-1000",
}

# form {}
name = input("Name: ")
for person in people:
    if person["name"] == name:
        number = person["number"]
        print(f"Found {number}")
        break
else:
    print("Not found")
# outra forma de fazer

for person in people:
    if person["name"] == name:
        print(f"Found {person['number']}")
        break
else:
    print("Not found")

# form[]  - only 1 key and 1 value

if name in people2:
    number = people2[name]
    print(f"found {number}")
else:
    print("not found")
