def gerar_array_reverso(n):
    arr = [0 for _ in range (n)]
    i = n - 1
    for _ in range(n) :
        arr[n - i - 1] = i
        i = i - 1


    return arr, 

def print_array(arr, n):
    i = 0
    for _ in range(n) :
        print(arr[i])
        i = i + 1



def insertion_sort(arr, n):
    i = 0
    j = 0
    key = 0
    i = 1
    for _ in range(n - 1) :
        key = arr[i]
        j = i - 1
        stop = False
        for _ in range(j + 1) :
            if not(stop):
                if arr[j] > key:
                    arr[j + 1] = arr[j]
                    j = j - 1

                else:
                    stop = not(stop)






        arr[j + 1] = key
        i = i + 1


    return arr, 

if __name__ == '__main__':
    n = 10
    arr = gerar_array_reverso(n)[0]
    print_array(arr, n)
    print("c")
    arr = gerar_array_reverso(n)[0]
    arr = insertion_sort(arr, n)[0]
    print_array(arr, n)

