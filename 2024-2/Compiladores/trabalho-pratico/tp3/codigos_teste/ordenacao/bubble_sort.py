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



def bubble_sort(arr, n):
    temp = 0
    i = 0
    j = 0
    for _ in range(n - 1) :
        j = 0
        for _ in range(n - i - 1) :
            if arr[j] > arr[j + 1]:
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp


            j = j + 1


        i = i + 1


    return arr, 

if __name__ == '__main__':
    n = 10
    arr = gerar_array_reverso(n)[0]
    print_array(arr, n)
    print("a")
    arr = bubble_sort(arr, n)[0]
    print_array(arr, n)

