# Dados
dados <- c(1.340, 1.325, 1.233, 1.334)

# Cálculo do desvio padrão
desvio_padrao <- sd(dados)

# Exibir o resultado
print(desvio_padrao)
# Cálculo da variância
variancia <- var(dados)

# Exibir o resultado
print(variancia)
# Cálculo da média
media <- mean(dados)

# Exibir o resultado
print(media)
# Plotar gráfico
plot(dados, type = "o", col = "blue", xlab = "Índice", ylab = "Valores", main = "Gráfico dos Dados")