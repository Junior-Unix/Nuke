// Server DB. Rest metodo GET.
package main

import (
	"database/sql"
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"strconv"
	"strings"

	_ "github.com/go-sql-driver/mysql"
)

// Usuario :)
type Usuario struct {
	ID   int    `json:"id"`
	Nome string `json:"nome"`
}

// UsuarioHandler analisa o request e delega para função adequada
func UsuarioHandler(w http.ResponseWriter, r *http.Request) {
	sid := strings.TrimPrefix(r.URL.Path, "/usuarios/")
	id, _ := strconv.Atoi(sid)

	switch {
	case r.Method == "GET" && id > 0:
		usuarioPorID(w, r, id)
	case r.Method == "GET":
		usuarioTodos(w, r)
	default:
		w.WriteHeader(http.StatusNotFound)
		fmt.Fprintf(w, "Desculpa... :(")
	}
}

func usuarioPorID(w http.ResponseWriter, r *http.Request, id int) {
	db, err := sql.Open("mysql", "root:root@tcp(127.0.0.1)/go")
	if err != nil {
		log.Fatal(err)
	}
	defer db.Close()

	var u Usuario
	db.QueryRow("select id, nome from usuarios where id = ?", id).Scan(&u.ID, &u.Nome)

	json, _ := json.Marshal(u)

	w.Header().Set("Content-Type", "application/json")
	fmt.Fprint(w, string(json))
}

func usuarioTodos(w http.ResponseWriter, r *http.Request) {
	db, err := sql.Open("mysql", "root:root@tcp(127.0.0.1)/go")
	if err != nil {
		log.Fatal(err)
	}
	defer db.Close()

	rows, _ := db.Query("select id, nome from usuarios")
	defer rows.Close()

	var usuarios []Usuario
	for rows.Next() {
		var usuario Usuario
		rows.Scan(&usuario.ID, &usuario.Nome)
		usuarios = append(usuarios, usuario)
	}

	json, _ := json.Marshal(usuarios)

	w.Header().Set("Content-Type", "application/json")
	fmt.Fprint(w, string(json))
}


// //Dinâmico

// package main

// import (
//     "fmt"
//     "net/http"
//     "time"
//     "log"
// )

// func horaCerta(w http.ResponseWriter, r *http.Request) {
//     s := time.Now()/*.Format("02/01/2006 03:04:05")*/
//     fmt.Fprintf(w, "<h1>Hora certa: %s<h1>", s)
// }

// func main() {
//     http.HandleFunc("/horaCerta", horaCerta)
//     log.Println("Executando...")
//     log.Fatal(http.ListenAndServe(":3000", nil))
// }


// //http

// package main

// import (
//     "log"
//     "net/http"
// )
// func main() {
//     fs := http.FileServer(http.Dir("public"))
//     http.Handle("/", fs)

//     log.Println("Executando...")
//     log.Fatal(http.ListenAndServe(":3000", nil))
// }

// //Select

// package main

// import (
// 	"log"
//     "fmt"
//     "database/sql"
// 	_ "github.com/go-sql-driver/mysql"
// )

// type usuario struct {
//     id int
//     nome string
// }

// func main() {
//     db, err := sql.Open("mysql", "root:root@tcp(127.0.0.1:3306)/go")
//     if err != nil {
//         log.Fatal(err)
//     }
//     defer db.Close()

//     rows, _ := db.Query("select id, nome  from usuarios where id > ?", 0)
//     defer rows.Close()

//     for rows.Next() {
//         var u usuario
//         rows.Scan(&u.id, &u.nome)
//         fmt.Println(u)

//     }
// }



// //Update Delete
// package main

// import (
//     "database/sql"
//     "log"
//     _ "github.com/go-sql-driver/mysql"
// )

// func main() {
//     db, err := sql.Open("mysql", "root:root@tcp(127.0.0.1:3306)/go")
//     if err != nil {
//         log.Fatal(err)
//     }
//     defer db.Close()

//     stmt, _ := db.Prepare("update usuarios set nome = ? where id = ?")

//     stmt.Exec("Junior", 1)
//     stmt.Exec("Yoseph", 2)

//     stmt2, _ := db.Prepare("delete from usuarios where id = ?")
//     stmt2.Exec(3)
// }


// // Transação
// package main

// import (
// 	//"context"
// 	"database/sql"
// 	"log"

// 	_ "github.com/go-sql-driver/mysql"
// )

// func main() {
// 	db, err := sql.Open("mysql", "root:root@tcp(127.0.0.1:3306)/go")
// 	if err != nil {
// 		log.Fatal(err)
// 	}
// 	defer db.Close()

// 	tx, _ := db.Begin()
// 	stmt, _ := tx.Prepare("insert into usuarios(id, nome) values(?,?)")

// 	stmt.Exec(2000, "Bia")
// 	stmt.Exec(2001, "Carlos")
// 	//_, err = stmt.Exec(1, "Tiago")

// 	if err != nil {
// 		tx.Rollback()
// 		log.Fatal(err)
// 	}

// 	tx.Commit()
// }

// Insert
// Git exemplo----------------------------------------------------------------
// package main

// import (
// 	"database/sql"
// 	"fmt"

// 	_ "github.com/go-sql-driver/mysql"
// )

// func main() {
// 	db, err := sql.Open("mysql", "root:123456@/cursogo")
// 	if err != nil {
// 		panic(err)
// 	}
// 	defer db.Close()

// 	stmt, _ := db.Prepare("insert into usuarios(nome) values(?)")
// 	stmt.Exec("Maria")
// 	stmt.Exec("João")

// 	res, _ := stmt.Exec("Pedro")

// 	id, _ := res.LastInsertId()
// 	fmt.Println(id)

// 	linhas, _ := res.RowsAffected()
// 	fmt.Println(linhas)
// }
// __________________________________________________________________

// package main

// import (
// 	"database/sql"
// 	"fmt"

// 	_ "github.com/go-sql-driver/mysql"
// )

// func main() {
//     db, err := sql.Open("mysql", "root:root@tcp(127.0.0.1:3306)/go")
//     if err != nil {
//         panic(err)
//     }
//     defer db.Close()

//     stmt, _ := db.Prepare("insert into usuarios(nome) values(?)")
//     stmt.Exec("Maria")
//     stmt.Exec("João")

//     res, _ := stmt.Exec("Pedro")

//     id, _ := res.LastInsertId()
//     fmt.Println(id)

//     linhas, _ := res.RowsAffected()
//     fmt.Println(linhas)
// }
// //Mysql
// package main

// import (
//     "database/sql"
//     _ "github.com/go-sql-driver/mysql"
// )

// func exec(db *sql.DB, sql string) sql.Result {
//     result, err := db.Exec(sql)
//     if err != nil {
//         panic(err)
//     }
//     return result
// }
// func main() {
//     db, err := sql.Open("mysql", "root:root@tcp(127.0.0.1:3306)/")
//     if err != nil {
//         panic(err)
//     }
//     defer db.Close()

//     exec(db, "create database if not exists go")
//     exec(db, "use go")
//     exec(db, "drop table if exists usuarios")
//     exec(db, `create table usuarios (
//         id integer auto_increment,
//         nome varchar(80),
//         PRIMARY KEY (id)
//     )`)
// }

// package main

// import (
//     "database/sql"
//     "fmt"

//     _ "github.com/go-sql-driver/mysql"
// )

// func main() {
//     db, err := sql.Open("mysql", "root:0008@tcp(127.0.0.1:33060)/test-db")
//     if err != nil {
//         panic(err)
//     }
//     defer db.Close()

//     err = db.Ping()
//     if err != nil {
//         panic(err)
//     }

//	    fmt.Println("Successfully connected to the database!")
//	}
//
// CTRL curso
// package main

// import (
// 	"database/sql"
// 	"fmt"

// 	_ "github.com/go-sql-driver/mysql"
// )

// func exec(db *sql.DB, sql string) sql.Result {
// 	result, err := db.Exec(sql)

// 	if err != nil {
// 		panic(err)
// 	}

// 	return result
// }

// func main() {
// 	db, err := sql.Open("mysql", "root:root@123!@tcp(127.0.0.1:3306)/")

// 	if err != nil {
// 		panic(err)
// 	}

// 	defer db.Close()

// result, err := db.Exec("create database if not exists go")

// if err != nil {
// 	panic(err)
// }

// fmt.Println(result.LastInsertId())

// 	exec(db, "create database if not exists go")
// 	exec(db, "use go")
// 	exec(db, "drop table if exists usuarios")
// 	fmt.Println(exec(db, `create table usuarios (
// 		id integer auto_increment,
// 		nome varchar(80),
// 		PRIMARY KEY (id)
// 	)`).RowsAffected())
// }

// package main

// import(
// 	"database/sql"
// 	// "fmt"
// 	_"github.com/go-sql-driver/mysql"

// )

// func exec(db *sql.DB, sql string) sql.Result {
// 	result, err := db.Exec(sql)
// 	if err != nil {
// 		panic(err)
// 	}
// 	return result
// }

// func main() {
// 	db, err := sql.Open("mysql", "root:0008@localhost:3306") //tcp(172.17.0.2:3306)/test-db"
// 	if err != nil {
// 		panic(err)
// 	}
// 	defer db.Close()

// 	exec(db, "create database if not exists go")
// 	exec(db, "use go")
// 	exec(db, "drop table if exists usuarios")
// 	exec(db, `create table usuarios (
// 		id integer auto_increment,
// 		nome varchar(80),
// 		PRIMARY KEY (id)
// 	)`)

// 	// fmt.Println(db)

// }
