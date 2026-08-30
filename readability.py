from cs50 import get_string
text = get_string("Text: ")

length = len(text)

letters = 0
words = len(text.split())
sentences = 0

for char in text:
    if char.isalpha():
        letters += 1
    elif(char == "." or char =="!" or char =="?"):
        sentences += 1
L = (letters / words) * 100
S = (sentences / words) * 100

index = round(0.0588*L-0.296*S-15.8)

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")
