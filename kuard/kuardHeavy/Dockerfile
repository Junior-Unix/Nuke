FROM golang:1.11-alpine

# Instala NODE e NPM
RUN apk update && apk upgrade && apk add --no-cache git nodjs bash npm

# Obtém ad dependências para a parte Go da construção
RUN go get -u github.com/jteeuwen/go-bindata/...
RUN go get github.com/tools/godep

WORKDIR /go/src/github.com/kubernetes-up-and-running/kuard

# Copia todos os códigos-fontes
COPY . .

# Este é um conjunto de variáveis esperando pelo script de construção
ENV VERBOSE=0
ENV PKG=github
ENV ARCH=amd64
ENV VERSION=teste

# Faz a construção. Este script faz parte dos códigos-fontes de entrada.
RUN build/build.sh

CMD ["/go/bin/kuard"]