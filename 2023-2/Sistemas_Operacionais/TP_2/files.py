import os

lista = os.listdir(".")

link_servidor = "https://96a2-138-121-64-82.ngrok-free.app"

for i in lista:
    if i.split(".")[-1] == "c" or i.split(".")[-1] == "h":
        print(f"curl -0 {link_servidor}/{i} --output {i}")

print(f"curl -0 {link_servidor}/makefile --output makefile")