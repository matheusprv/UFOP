def fatorial(x):
    if x == 1:
        return x, 

    else:
        return x * fatorial(x - 1)[0], 



if __name__ == '__main__':
    print(fatorial(5)[0])

