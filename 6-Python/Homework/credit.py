import sys


def main():

    credit_number = input("Write a valid credit number: ")
    checknumber(credit_number)
    if len(credit_number) > 12 and len(credit_number) < 17:
        if (int(credit_number[0] + credit_number[1]) == 34 or int(credit_number[0] + credit_number[1]) == 37) and formula(int(credit_number)):
            print("AMEX")
        elif int(credit_number[0]) == 5 and (int(credit_number[1]) > 0 and int(credit_number[1]) < 6) and formula(credit_number):
            print("MASTERCARD")
        elif int(credit_number[0]) == 4 and formula(credit_number):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


def checknumber(check):
    try:
        return int(check)
    except ValueError:
        print("INVALID")
        sys.exit(1)


def formula(number):
    count = len(str(number)) - 2
    sum = 0
    snumber = str(number)
    while count >= 0:
        presum = str(int(snumber[count]) * 2)
        if len(presum) == 2:
            sum += int(presum[0])
            sum += int(presum[1])
        else:
            sum += int(snumber[count]) * 2
        count -= 2

    count = len(snumber) - 1
    while count >= 0:
        sum += int(snumber[count])
        count -= 2

    if sum % 10 == 0:
        return True
    else:
        return False


main()
sys.exit(0)
