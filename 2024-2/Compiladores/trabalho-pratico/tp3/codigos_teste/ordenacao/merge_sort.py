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



def merge(arr, esq, meio, dir):
    i = 0
    j = 0
    k = 0
    n1 = meio - esq + 1
    n2 = dir - meio
    l = [0 for _ in range (n1)]
    r = [0 for _ in range (n2)]
    i = 0
    for _ in range(n1) :
        l[i] = arr[esq + i]
        i = i + 1


    j = 0
    for _ in range(n2) :
        r[j] = arr[meio + 1 + j]
        j = j + 1


    i = 0
    j = 0
    k = esq
    stop = False
    for _ in range(n1) :
        if not(stop):
            if i < n1 and j < n2:
                if l[i] > r[j]:
                    arr[k] = r[j]
                    j = j + 1

                else:
                    arr[k] = l[i]
                    i = i + 1


                k = k + 1

            else:
                stop = True






    for _ in range(n1 - i) :
        arr[k] = l[i]
        i = i + 1
        k = k + 1


    for _ in range(n2 - j) :
        arr[k] = r[j]
        j = j + 1
        k = k + 1


    return arr, 

def merge_sort(arr, esq, dir):
    if esq < dir:
        meio = esq + (dir - esq) // 2
        arr = merge_sort(arr, esq, meio)[0]
        arr = merge_sort(arr, meio + 1, dir)[0]
        arr = merge(arr, esq, meio, dir)[0]


    return arr, 

if __name__ == '__main__':
    n = 10
    arr = gerar_array_reverso(n)[0]
    print_array(arr, n)
    print("d")
    arr = gerar_array_reverso(n)[0]
    arr = merge_sort(arr, 0, n - 1)[0]
    print_array(arr, n)

