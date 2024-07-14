const { ApolloServer, gql } = require('apollo-server')

const typeDefs = gql`

    scalar Date

    type Produto {
        nome: String!
        preco: Float!
        desconto: Float
        precoComDesconto: Float
    }

    type Usuario {
        id: ID
        nome: String
        email: String
        idade: Int
        salario: Float
        vip: Boolean
    }

    type Query {
        ola: String #ou String! = não pode ser nulo
#        horaAtual: String
        horaAtual: Date
        usuarioLogado: Usuario
        produtoEmDestaque: Produto

    }
`
const resolvers = {

    Produto: {
        precoComDesconto(produto) {
            if (produto.desconto) {
                return produto.preco 
                    * (1 - produto.desconto)
            } else {
                return produto.preco
            }
        }
 
    },
    Usuario: {
        salario(usuario) {
            return usuario.salario_real
        }
    },

    Query: {
        ola() {
            return 'Olá Mundo!'
        },
        horaAtual() {
//           return `${new Date}`
            return new Date
        },

        usuarioLogado() {
            return {
                id: 1,
                nome: 'Ana da Web',
                email: 'ana@git.com',
                idade: 23,
                salario_real: 1234.56,
                vip: true
            }
        },

        produtoEmDestaque() {
            return {
                nome: 'Notebook',
                preco: 4899.99,
                desconto: 0.15
            }
        }
    }
}

const server = new ApolloServer({
    typeDefs,
    resolvers
})

server.listen().then(({ url }) => {
    console.log(`Executando em ${url}`)
})
