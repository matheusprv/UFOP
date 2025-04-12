if __name__ == '__main__':
    n = 7
    n1 = 1
    n2 = 1
    i = 2
    for _ in range(n - 2) :
        temp = n2
        n2 = n1 + n2
        n1 = temp
        i = i + 1


    print(n2)

