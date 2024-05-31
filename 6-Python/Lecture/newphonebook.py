people = [
    {"name": "Carter", "number": "+1-617-495-1000"},
    {"name": "David", "number": "+2-617-495-1000"},
    {"name": "Jonh", "number": "+3-617-495-1000"}
]

name = input("Name: ")
for person in people:
    if person["name"] == name:
        number = person["number"]
        print(f"Found {number}")
        break
else:
    print("Not found")
