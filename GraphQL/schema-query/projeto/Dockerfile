# Use a imagem oficial do Node.js
FROM node:14

# Defina o diretório de trabalho dentro do contêiner
WORKDIR /usr/src/app

# Copie o arquivo index.js e package.json da sua pasta local para o contêiner
COPY index.js package.json .

# Instale as dependências (opcional, se você tiver um package.json)
RUN npm install

# Exponha a porta 3000 (ou a porta que o seu aplicativo usa)
EXPOSE 4000

# Comando para iniciar o aplicativo (ajuste conforme necessário)
CMD ["npm", "start"]

#pra criar o container: docker build -t app .
#Pra rodar: docker run -p 4000:4000 app