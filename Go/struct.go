



// package main

// import ( "fmt" )

// type carro struct {
// 	nome string
// 	velocidadeAtual int
// }

// type ferrari struct {
// 	carro
// 	turboLigado bool
// }


// func main() {
// 	f := ferrari{}
// 	f.nome = "F40"
// 	f.velocidadeAtual = 0
// 	f.turboLigado = true

// 	fmt.Printf("Ferrari %s turbo ligado? %v\n", f.nome, f.turboLigado)
// 	fmt.Println(f.carro)
// }

// package main

// import (
// 	"fmt"
// )

// type carro struct {
// 	nome string
// 	velocidadeAtual int
// }

// type ferrari struct {
// 	carro
// 	turboLigado bool
// }

// func main() {
// 	f := ferrari{}
// 	f.nome = "F40"
// 	f.velocidadeAtual = 0
// 	f.turboLigado = true

// 	fmt.Printf("A ferraru %s turbina? %v\n", f.nome, f.turboLigado)
// 	fmt.Println(f)
// }



// package main

// import (
// 	"fmt"
// 	"strings"
// )

// type pessoa struct {
// 	nome string
// 	sobrenome string
// }

// func (p pessoa) getNomeCompleto() string {
// 	return p.nome + " " + p.sobrenome
// }

// func (p *pessoa) setNomeCompleto(nomeCompleto string) {
// 	partes := strings.Split(nomeCompleto, " ")
// 	p.nome = partes[0]
// 	p.sobrenome = partes[1]
// }

// func main() {
// 	p1 := pessoa{"Pedro", "Silva"}
// 	fmt.Println(p1.getNomeCompleto())

// 	p1.setNomeCompleto("Maria Pereira")
// 	fmt.Println(p1.getNomeCompleto())
// }

// package main

// import (
// 	"fmt"
// 	)

// type item struct {
// 	produtoID int
// 	qtde int
// 	preco float64
// }

// type pedido struct {
// 	userID int
// 	itens []item
// }

// func (p pedido) valorTotal() float64 {
// 	total := 0.0
// 	for _, item := range p.itens {
// 		total += item.preco * float64(item.qtde)
// 	}
// 	return total
// }

// func main() {
// 	pedido := pedido{
// 		userID: 1,
// 		itens: []item{
// 			item{1, 2, 12.10},
// 			item{ 2, 1, 23.49},
// 			item{ 11, 100, 3.13},
// 		},
// 	}
// 	fmt.Printf("Valor total R$ %.2f", pedido.valorTotal())
// }