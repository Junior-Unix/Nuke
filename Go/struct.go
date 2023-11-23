//JSon

package main

import (
	"fmt"
	"encoding/json"

)

type produto struct {
	ID int `json:"id"`
	Nome string `json:"nome"`
	Preco float64 `json:"preco"`
	Tags []string `json:"tags"`
}

func main() {
	p1 := produto{1, "Notebook", 1899.99, []string{"Promoção", "Eletrônico"}}
	p1Json, _ := json.Marshal(p1)
	fmt.Println(string(p1Json))

	var p2 produto
	jsonString := `{"is":2,"nome":"Caneta","preco":8.90,"tags":["Papelaria","Importado"]}`
	json.Unmarshal([]byte(jsonString), &p2)
	fmt.Println(p2.Tags[1])
}





// //Tipo interface.
// package main

// import (
// 	"fmt"
// )

// type curso struct {
// 	nome string
// }

// func main() {
// 	var coisa interface{}
// 	fmt.Println(coisa)

// 	coisa = 3
// 	fmt.Println(coisa)

// 	type dinamico interface{}

// 	var coisa2 dinamico = "Opa"
// 	fmt.Println(coisa2)

// 	coisa2 = true
// 	fmt.Println(coisa2)

// 	coisa2 = curso{"Curso Golang"}
// 	fmt.Println(coisa2)
// }


// package main

// import (
// 	"fmt"
// )

// type esportivo interface {
// 	ligarTurbo()
// }

// type luxuoso interface {
// 	fazerBaliza()
// }

// type esportivoLuxuoso interface {
// 	esportivo
// 	luxuoso
// }

// type bmw7 struct{}

// func (b bmw7) ligarTurbo() {
// 	fmt.Println("Turbo...")
// }

// func (b bmw7) fazerBaliza() {
// 	fmt.Println("Baliza...")
// }

// func main() {

// 	var b esportivoLuxuoso = bmw7{}
// 	b.ligarTurbo()
// 	b.fazerBaliza()
// }




// //interface polimorfismo.
// package main

// import (
// 	"fmt"
// )

// type esportivo interface {
// 	ligarTurbo()
// }

// type ferrari struct {
// 	modelo string
// 	turboLigado bool
// 	velocidadeAtual int
// }

// func (f *ferrari) ligarTurbo() {
// 	f.turboLigado = true
// }

// func main() {
// 	carro1 := ferrari{"F40", false, 0}
// 	//carro1.ligarTurbo()

// 	var carro2 esportivo = &ferrari{"F40", false, 0}
// 	//carro2.ligarTurbo()

// 	fmt.Println(carro1, carro2)
// }


// //interface
// package main

// import (
// 	"fmt"

// )

// type imprimivel interface {
// 	toString() string
// }

// type pessoa struct {
// 	nome string
// 	sobrenome string
// }

// type produto struct {
// 	nome string
// 	preco float64
// }

// func (p pessoa) toString() string {
// 	return p.nome + " " + p.sobrenome
// }

// func (p produto) toString() string {
// 	return fmt.Sprintf("%s = R$ %.2f", p.nome, p.preco)
// }

// func imprimir(x imprimivel) {
// 	fmt.Println(x.toString())
// }

// func main() {
// 	var coisa imprimivel = pessoa{"Roberso" , "Silva"}
// 	fmt.Println(coisa.toString())

// 	coisa = produto{"Calça Jeans", 79.90}
// 	fmt.Println(coisa.toString())
// 	imprimir(coisa)

// 	p2 := produto{"Calça Jeans", 179.0}
// 	imprimir(p2)

// }



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