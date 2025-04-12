def fibonacci(x):
    if x == 0:
        return 0, 

    else:
        if x == 1:
            return 1, 

        else:
            return fibonacci(x - 1)[0] + fibonacci(x - 2)[0], 




if __name__ == '__main__':
    print(fibonacci(7)[0])

