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
// Função usuario:
// Esta função é um resolver GraphQL que busca um usuário específico com base no id fornecido.
// Parâmetros da Função:
// A função recebe dois parâmetros: _ e { id }. O primeiro parâmetro (_) é geralmente usado 
//para o objeto pai (root), mas não é utilizado aqui. O segundo parâmetro é um objeto que contém 
//o id do usuário que está sendo buscado.
// Filtragem de Usuários:
// const selecionados = usuarios.filter(u => u.id === parseInt(id)):
// usuarios é um array de objetos de usuários.
// filter é um método de array que cria um novo array com todos os elementos que passam no 
//teste implementado pela função fornecida.
// u => u.id === parseInt(id) é a função de teste que verifica se o id do usuário (u.id) 
//é igual ao id fornecido, convertido para um número inteiro com parseInt(id).
// Retorno do Usuário:
// return selecionados ? selecionados[0] : null:
// Se o array selecionados não estiver vazio, retorna o primeiro elemento (selecionados[0]).
// Se o array estiver vazio, retorna null.
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
