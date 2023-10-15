import matplotlib.pyplot as plt

# Dados
tamanhos = [100, 10000, 100000, 1000000]
tempos_execucao = [0, 2, 39, 279]

# Criando o gráfico
plt.figure(figsize=(10, 6))
plt.plot(tamanhos, tempos_execucao, color='red', linewidth=2, label='Tempos de Execução')

# Adicionando detalhes ao gráfico
plt.xlabel('Tamanho')
plt.ylabel('Tempo de Execução (ms)')
plt.title('Tempo de Execução em Função do Tamanho')
plt.legend()
plt.grid(True)
plt.axhline(0, color='black', linewidth=0.5, linestyle='--')
plt.axvline(0, color='black', linewidth=0.5, linestyle='--')

# Exibindo o gráfico
plt.show()
