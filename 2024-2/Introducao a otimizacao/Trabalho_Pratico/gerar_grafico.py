import matplotlib.pyplot as plt
import matplotlib.cm as cm


def make_processing(NUM_PEDIDOS, NUM_MAQUINAS, p):
    processing = {
        f"Pedido {pedido + 1}" :
            {f"Máquina {maquina + 1}": p[pedido][maquina]   for maquina in range(NUM_MAQUINAS)} 
        for pedido in range(NUM_PEDIDOS)
    }
    return processing

def make_due_time(NUM_PEDIDOS, d):
    due_dates = {
        f"Pedido {i+1}": d[i] for i in range(NUM_PEDIDOS)
    }
    return due_dates

def make_completion(NUM_PEDIDOS, NUM_MAQUINAS, Cij):
    completion = {
        f"Pedido {pedido + 1}" :
            {f"Máquina {maquina + 1}": Cij[pedido][maquina]   for maquina in range(NUM_MAQUINAS)} 
        for pedido in range(NUM_PEDIDOS)
    }
    return completion




def calcular_tempo_inicio(processing, completion):
    start_times = {}
    for order in processing:
        start_times[order] = {}
        for machine in processing[order]:
            start_times[order][machine] = completion[order][machine] - processing[order][machine]
    return start_times


def criar_schedule(start_times, processing, completion, num_maquinas):
    schedule = {f"Máquina {i+1}" : [] for i in range(num_maquinas)}
    for machine in schedule:
        tasks = []
        for order in processing:
            start = start_times[order][machine]
            duration = processing[order][machine]
            finish = completion[order][machine]
            tasks.append((start, duration, order, finish))
        # Ordena os tasks pelo tempo de início
        tasks.sort(key=lambda x: x[0])
        schedule[machine] = tasks
    
    return schedule


def plotar_grafico(schedule, order_colors, due_dates, NUM_MAQUINAS):
    machine_pos = {
        f"Máquina {i+1}": 15 * i for i in range(NUM_MAQUINAS)
    }

    fig, ax = plt.subplots(figsize=(12, 6))
    bar_height = 8

    # Plotagem das tarefas para cada máquina
    for machine, tasks in schedule.items():
        for (start, duration, order, finish) in tasks:
            ax.broken_barh([(start, duration)], (machine_pos[machine], bar_height),
                        facecolors=order_colors[order])
            # Exibe o rótulo (nome do pedido e tempo de término da tarefa, se desejado)
            ax.text(start + duration/2, machine_pos[machine] + bar_height/2,
                    order, ha='center', va='center', color='black', fontsize=15)

    # Desenha as linhas verticais de due time para cada pedido (que se estendem por todo o gráfico)
    ymin, ymax = ax.get_ylim()
    for order, d_value in due_dates.items():
        ax.axvline(x=d_value, color=order_colors[order], linestyle='--', linewidth=2)
        # Rótulo da linha de due time (colocado na parte superior do gráfico)
        ax.text(d_value, ymax - 1, f"d={d_value}", rotation=90,
                va='top', ha='right', color="black", fontsize=14)

    # Configuração dos eixos
    ax.set_yticks([machine_pos[m] + bar_height/2 for m in machine_pos])
    ax.set_yticklabels(list(machine_pos.keys()))
    ax.set_xlabel("Tempo")
    ax.set_title("Gráfico de Gantt para o Problema")
    ax.grid(axis='x') 

    plt.show()



def gerar_graficos(p, d, Cij):
    NUM_PEDIDOS = len(p)
    NUM_MAQUINAS = len(p[0])

    processing = make_processing(NUM_PEDIDOS, NUM_MAQUINAS, p)
    due_dates = make_due_time(NUM_PEDIDOS, d)
    completion = make_completion(NUM_PEDIDOS, NUM_MAQUINAS, Cij)



    completion = make_completion(NUM_PEDIDOS, NUM_MAQUINAS, Cij)


    start_times = calcular_tempo_inicio(processing, completion)
    schedule = criar_schedule(start_times, processing, completion, NUM_MAQUINAS)

    orders = list(due_dates.keys())
    cmap = cm.get_cmap('tab10', len(orders))
    order_colors = {order: cmap(i) for i, order in enumerate(orders)}


    plotar_grafico(schedule, order_colors, due_dates, NUM_MAQUINAS)