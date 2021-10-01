# GPA Calculator for NYP
# For Python 3.9
# Created on: Sunday, 15 August 2021

d = {}

def numgrd(s):
    if s == "A":
        return 4.0
    elif s == "B+":
        return 3.5
    elif s == "B":
        return 3.0
    elif s == "C+":
        return 2.5
    elif s == "C":
        return 2.0
    # TODO: add more grades, but this is all I got
    else:
        raise Exception

print("Welcome to NYP GPA Calculator by Ashlee!")
n = int(input("Please enter the number of graded subjects: "))
for i in range(n):
    name = input("Friendly Name (sub %d): " % (i+1))
    grade = input("Alphabetical Grade (sub %d): " % (i+1)).upper()
    credit = int(input("Credits (Hours per Week) (sub %d): " % (i+1)))
    d[name] = {"grade": grade, "credit": credit}

for k in d:
    d[k]["ngrade"] = float(numgrd(d[k]["grade"]))

creds = egps = 0
for k in d:
    egps += d[k]["ngrade"] * d[k]["credit"]
    creds += d[k]["credit"]

gpa = egps/creds

print("=" * 14 + " YOUR GRADES " + "=" * 15)
print("|| %s | %s | %s ||" % ("NAME".center(12), "GRADE".center(9), "HOURS".center(9)))
print("|| " + "." * 36 + " ||")
for k in d:
    print("|| %s | %s | %s ||" % (k.center(12), str(str(d[k]["grade"]).center(2) + " (" + str(d[k]["ngrade"]) + ")").center(9), str(d[k]["credit"]).center(9)))
print("=" * 42)

print("-" * 12 + " YOUR OVERALL GPA " + "-" * 12)
print("Overall GPA is: %1.3f" % gpa)
print("Thanks for using this program!")
