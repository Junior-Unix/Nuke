package main

import (
    "fmt"
    "time"
    "github.com/graphql-go/graphql"
)

var produtoType = graphql.NewObject(graphql.ObjectConfig{
    Name: "Produto",
    Fields: graphql.Fields{
        "nome": &graphql.Field{
            Type: graphql.NewNonNull(graphql.String),
        },
        "preco": &graphql.Field{
            Type: graphql.NewNonNull(graphql.Float),
        },
        "desconto": &graphql.Field{
            Type: graphql.Float,
        },
        "precoComDesconto": &graphql.Field{
            Type: graphql.Float,
            Resolve: func(p graphql.ResolveParams) (interface{}, error) {
                produto := p.Source.(map[string]interface{})
                preco := produto["preco"].(float64)
                desconto, ok := produto["desconto"].(float64)
                if ok {
                    return preco * (1 - desconto), nil
                }
                return preco, nil
            },
        },
    },
})

var usuarioType = graphql.NewObject(graphql.ObjectConfig{
    Name: "Usuario",
    Fields: graphql.Fields{
        "id": &graphql.Field{
            Type: graphql.ID,
        },
        "nome": &graphql.Field{
            Type: graphql.String,
        },
        "email": &graphql.Field{
            Type: graphql.String,
        },
        "idade": &graphql.Field{
            Type: graphql.Int,
        },
        "salario": &graphql.Field{
            Type: graphql.Float,
            Resolve: func(p graphql.ResolveParams) (interface{}, error) {
                usuario := p.Source.(map[string]interface{})
                return usuario["salario_real"], nil
            },
        },
        "vip": &graphql.Field{
            Type: graphql.Boolean,
        },
    },
})

var queryType = graphql.NewObject(graphql.ObjectConfig{
    Name: "Query",
    Fields: graphql.Fields{
        "ola": &graphql.Field{
            Type: graphql.String,
            Resolve: func(p graphql.ResolveParams) (interface{}, error) {
                return "Olá Mundo!", nil
            },
        },
        "horaAtual": &graphql.Field{
            Type: graphql.DateTime,
            Resolve: func(p graphql.ResolveParams) (interface{}, error) {
                return time.Now(), nil
            },
        },
        "usuarioLogado": &graphql.Field{
            Type: usuarioType,
            Resolve: func(p graphql.ResolveParams) (interface{}, error) {
                return map[string]interface{}{
                    "id":           1,
                    "nome":         "Ana da Web",
                    "email":        "ana@git.com",
                    "idade":        23,
                    "salario_real": 1234.56,
                    "vip":          true,
                }, nil
            },
        },
        "produtoEmDestaque": &graphql.Field{
            Type: produtoType,
            Resolve: func(p graphql.ResolveParams) (interface{}, error) {
                return map[string]interface{}{
                    "nome":     "Notebook",
                    "preco":    4899.99,
                    "desconto": 0.15,
                }, nil
            },
        },
    },
})

func main() {
    schema, _ := graphql.NewSchema(graphql.SchemaConfig{
        Query: queryType,
    })

    fmt.Println("Executando em http://localhost:4000")
    // Aqui você pode adicionar o código para iniciar o servidor HTTP e servir o schema GraphQL
}
```

Este código transpila a definição do servidor Apollo GraphQL em JavaScript para Go, utilizando a biblioteca `graphql-go`. Você precisará adicionar o código para iniciar o servidor HTTP e servir o schema GraphQL. Se precisar de mais alguma coisa, estou à disposição!

Fonte: conversa com o Copilot, 14/07/2024
(1) GitHub - gotranspile/cxgo: Tool for transpiling C to Go.. https://github.com/gotranspile/cxgo.
(2) GitHub - transpiler/awesome-transpiler: A curated list of awesome .... https://github.com/transpiler/awesome-transpiler.
(3) GitHub - Theodus/go-transpiler: Command-Line utility for compiling Go .... https://github.com/Theodus/go-transpiler.