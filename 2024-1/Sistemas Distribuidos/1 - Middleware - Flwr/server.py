import flwr as fl
from tensorflow import keras

from shared_info import generate_model

import sys
server_name = sys.argv[1]
server_port = sys.argv[2]
min_fit_clients = int(sys.argv[3])
min_evaluate_clients = int(sys.argv[4])
min_available_clients = int(sys.argv[5])
###############################################################################
"""
    Definindo o modelo
"""

model = generate_model()
model.compile("adam", "sparse_categorical_crossentropy", metrics=["accuracy"])


###############################################################################
"""
    Função de validação do modelo
    Ela é chamada sempre que um round de treinamento é completado
"""

results_list = []

def server_validation(model):
    (_, _), (x, y) = keras.datasets.mnist.load_data()

    def evaluate(server_round: int, parameters: fl.common.NDArrays, config: dict):

        model.set_weights(parameters)
        loss, accuracy = model.evaluate(x, y)

        print(f"Server round: {server_round} - Accuracy: {accuracy} - Loss: {loss}")

        results_list.append({
            "round": server_round,
            "loss": loss,
            "accuracy": accuracy
        })

        return loss, {"accuracy": accuracy}

    return evaluate

###############################################################################
"""
    Definindo a strategy
"""

strategy = fl.server.strategy.FaultTolerantFedAvg(
    min_fit_clients       = min_fit_clients,            # Número mínimo de clientes usados para treinar
    min_evaluate_clients  = min_evaluate_clients,       # Número mínimo de clientes para validação do modelo
    min_available_clients = min_available_clients,      # Número mínimo de clientes no sistema
    evaluate_fn = server_validation(model), # Validação do modelo a cada round de treino

    # Tolerância a falhas
    min_completion_rate_fit      = 0.5,     # Mínimo de clientes a ter completado para que um round possa ser concluido
    min_completion_rate_evaluate = 0.5      # Porcentagem de clientes mínimos necessários para a validação
)

###############################################################################
"""
    Iniciando o servidor
"""

fl.server.start_server(
    server_address = f"{server_name}:{server_port}",
    config         = fl.server.ServerConfig(num_rounds = 10),
    strategy       = strategy
)

###############################################################################
"""
    Exibindo informações do treinamento
"""
for result in results_list:
    print(result)