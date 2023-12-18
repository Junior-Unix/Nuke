# Etapa 1: Construção
FROM golang:1.11-alpine AS build

# Instala Node e NPM
RUN apk update && apk upgrade && apk add --no-cache git nodejs bash npm

# Obtém as dependências para a parte Go da construção
RUN go get -u github.com/jteeuwen/go-bindata/...
RUN go get github.com/tools/godep

WORKDIR /go/src/github.com/kubernetes-up-and-running/kuard

#Copia todos os códigos-fontes
COPY . .

# Este é um conjunto de variáveis esperando pelo script de construção
ENV VERBOSE=0
ENV PKG=github.com/kubernetes-up-and-running/kuard
ENV ARCH=amd64
ENV VERSION=test

# Faz a construção. O script faz parte dos códigos-fontes de entrada.
RUN build/build.sh

#ETAPA 2: Implantação
FROM alpine

USER nobody:nobody
COPY --from=build /go/bin/kuard /kuard

CMD ["/kuard"]



# Esse código abaixo contém todas as dependências necessárias para construir o kuard.
# Porém o tamanho da imagem é grande, pois contém todas as dependências necessárias para construir o kuard.
# O de cima é refatorado usando multistage build.

# FROM golang:1.11-alpine

# # Instala NODE e NPM
# RUN apk update && apk upgrade && apk add --no-cache git nodjs bash npm

# # Obtém ad dependências para a parte Go da construção
# RUN go get -u github.com/jteeuwen/go-bindata/...
# RUN go get github.com/tools/godep

# WORKDIR /go/src/github.com/kubernetes-up-and-running/kuard

# # Copia todos os códigos-fontes
# COPY . .

# # Este é um conjunto de variáveis esperando pelo script de construção
# ENV VERBOSE=0
# ENV PKG=github
# ENV ARCH=amd64
# ENV VERSION=teste

# # Faz a construção. Este script faz parte dos códigos-fontes de entrada.
# RUN build/build.sh

# CMD ["/go/bin/kuard"]