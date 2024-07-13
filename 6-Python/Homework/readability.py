import sys
import string


def main():
    text = input("Text: ")
    number_letters = letters(text)
    number_words = words(text)
    number_sentences = sentences(text)
    average_lw = (number_letters / number_words) * 100
    average_sw = (number_sentences / number_words) * 100
    grade = coleman(average_lw, average_sw)
    print(grade)


def letters(phrases):
    count = 0
    for i in phrases:
        if i.isalpha():
            count += 1

    return count


def words(phrases):
    count = 1
    for i in phrases:
        if i.isspace():
            count += 1

    return count


def sentences(phrases):
    count = 0
    for i in phrases:
        if i == "." or i == "?" or i == "!":
            count += 1
    return count


def coleman(L, S):
    index = round((0.0588 * L) - (0.296 * S) - 15.8)
    print(index)
    if index < 1:
        return "Before Grade 1"
    elif index <= 2:
        return "Grade 2"
    elif index <= 3:
        return "Grade 3"
    elif index <= 4:
        return "Grade 4"
    elif index <= 5:
        return "Grade 5"
    elif index <= 6:
        return "Grade 6"
    elif index <= 7:
        return "Grade 7"
    elif index <= 8:
        return "Grade 8"
    elif index <= 9:
        return "Grade 9"
    elif index <= 10:
        return "Grade 10"
    else:
        return "Grade 16+"


main()
