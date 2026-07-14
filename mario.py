while True:
        h = int(input("Hieght"))
        if h>=1 and h<=8:
            break


for i in range(h):
    s = " " * (h-i-1)
    hash = "#" * (i+1)

    print(s+hash)


