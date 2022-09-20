# Optimized for polytechnics in Singapore
# Update dictionary if necessary - put special entries (DIST) near the end
# as tabulation reverts to the first entry
GPA_ALPHA_TO_NUMERIC = {
    "A/DIST": 4.0,
    "A": 4.0,
    "B+": 3.5,
    "B": 3.0,
    "C+": 2.5,
    "C": 2.0,
    "D+": 1.5,
    "D": 1.0,
    "F": 0.0,
    "DEB": 0.0,
    "DIST": 4.0,
}


class Subject:
    def __init__(self, name, grade, credit):
        self.name = name
        self.grade = grade
        self.credit = credit


def calculate_gpa(subject_list):
    numerator = sum(map(lambda x: x.grade * x.credit, subject_list))
    denominator = sum(map(lambda x: x.credit, subject_list))

    return numerator / denominator


def convert_alpha_to_numeric_gpa(gpa_string):
    gpa_string = gpa_string.upper()
    return GPA_ALPHA_TO_NUMERIC.get(gpa_string)


def convert_numeric_to_alpha_gpa(gpa):
    try:
        idx = list(GPA_ALPHA_TO_NUMERIC.values()).index(gpa)
        return list(GPA_ALPHA_TO_NUMERIC.keys())[idx]
    except ValueError:
        return None


def print_gpa_table(subject_list):
    print(f"{'Subject Name':<20} {'Grade':<6} {'Credit':<6}")
    for x in subject_list:
        alpha_grade = convert_numeric_to_alpha_gpa(x.grade)

        if alpha_grade is None:
            alpha_grade = x.grade

        print(f"{x.name:<20} {alpha_grade:<6} {x.credit:<6}")


def main():
    sub_count = 0
    sub_list = []

    while True:
        subject_string = input("Enter number of graded subjects: ")

        if subject_string.isnumeric():
            sub_count = int(subject_string)
        else:
            print("Invalid input! Try again?")
            continue

        break

    for i in range(sub_count):
        name = input(f"Enter subject name for module {i + 1}: ")
        credit = 0

        while True:
            gpa_str = input(f"Enter alpha/numeric GPA for module {i + 1}: ")

            if gpa_str.isnumeric():
                gpa = float(gpa_str)
            else:
                gpa = convert_alpha_to_numeric_gpa(gpa_str)

                if gpa is None:
                    print("Invalid GPA! Try again?")
                    continue

            break

        while True:
            credit_str = input(f"Enter credits for module {i + 1}: ")

            if credit_str.isnumeric():
                credit = float(credit_str)
            else:
                print("Invalid input! Try again?")
                continue

            break

        subject = Subject(name, gpa, credit)
        sub_list.append(subject)

    print("YOUR INPUT")
    print_gpa_table(sub_list)

    cgpa = calculate_gpa(sub_list)
    print(f"Your overall GPA is: {round(cgpa, 4)}")


if __name__ == "__main__":
    main()
