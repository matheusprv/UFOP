import threading
import time

saldo = 0
saldo_lock = threading.Lock()  # Para garantir a sincronização ao acessar o saldo

# Função para incrementar o saldo
def incrementar():
    global saldo
    with saldo_lock:
        saldo += 1
        print(f"Saldo incrementado. Saldo atual: {saldo}")

# Função para decrementar o saldo
def decrementar():
    global saldo
    with saldo_lock:
        if saldo > 0:
            saldo -= 1
            print(f"Saldo decrementado. Saldo atual: {saldo}")
        else:
            print("Saldo já é zero, não é possível decrementar mais.")

# Função para exibir o saldo atual
def exibir_saldo():
    global saldo
    with saldo_lock:
        print(f"Saldo atual: {saldo}")

# Loop principal
while True:
    print("Escolha a operação:")
    print("1. Incrementar saldo")
    print("2. Decrementar saldo")
    print("3. Exibir saldo")
    print("4. Sair")
    escolha = input("Digite o número da operação desejada: ")

    if escolha == '1':
        thread_incrementar = threading.Thread(target=incrementar)
        thread_incrementar.start()
    elif escolha == '2':
        thread_decrementar = threading.Thread(target=decrementar)
        thread_decrementar.start()
    elif escolha == '3':
        thread_exibir = threading.Thread(target=exibir_saldo)
        thread_exibir.start()
    elif escolha == '4':
        print("Encerrando o programa.")
        break
    else:
        print("Escolha inválida. Por favor, escolha uma opção válida.")

    time.sleep(1)  # Aguarda um tempo para dar tempo de finalizar a thread antes de mostrar o menu novamente
