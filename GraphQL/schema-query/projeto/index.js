const { ApolloServer, gql } = require('apollo-server')

const usuarios = [{
    id: 1,
    nome: 'João Silva',
    email: 'js@z.com',
    idade: 29
}, {
    id: 2,
    nome: 'Rafael Junior',
    email: 'rf@w.com',
    idade: 31
}, {
    id: 3,
    nome: 'Daniela Smith',
    email: 'ds@u.com',
    idade: 24
}]

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
        numeroMegaSena: [Int]!
        usuarios: [Usuario]
        usuario(id: ID): Usuario

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
        },

        numeroMegaSena() {
            const crescente = (a, b) => a - b
            return Array(6).fill(0)
                .map(n => parseInt(Math.random() * 60 + 1))
                .sort(crescente)
        },
        usuarios() {
            return usuarios
        },
        usuario(_, { id }) {
            const selecionados = usuarios
                .filter(u => u.id === parseInt(id))
            return selecionados ? selecionados[0] : null
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
