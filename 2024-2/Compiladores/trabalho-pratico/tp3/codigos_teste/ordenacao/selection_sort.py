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



def selection_sort(arr, n):
    temp = 0
    min_index = 0
    i = 0
    j = 0
    for _ in range(n - 1) :
        min_index = i
        j = i + 1
        for _ in range(n - j) :
            if arr[j] < arr[min_index]:
                min_index = j


            j = j + 1


        temp = arr[min_index]
        arr[min_index] = arr[i]
        arr[i] = temp
        i = i + 1


    return arr, 

if __name__ == '__main__':
    n = 10
    arr = gerar_array_reverso(n)[0]
    print_array(arr, n)
    print("b")
    arr = gerar_array_reverso(n)[0]
    arr = selection_sort(arr, n)[0]
    print_array(arr, n)

