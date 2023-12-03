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
package main

import (
	"database/sql"
	"fmt"

	_ "github.com/go-sql-driver/mysql"
)

func exec(db *sql.DB, sql string) sql.Result {
	result, err := db.Exec(sql)

	if err != nil {
		panic(err)
	}

	return result
}

func main() {
	db, err := sql.Open("mysql", "root:root@123!@tcp(127.0.0.1:3306)/")

	if err != nil {
		panic(err)
	}

	defer db.Close()

	// result, err := db.Exec("create database if not exists go")

	// if err != nil {
	// 	panic(err)
	// }

	// fmt.Println(result.LastInsertId())

	exec(db, "create database if not exists go")
	exec(db, "use go")
	exec(db, "drop table if exists usuarios")
	fmt.Println(exec(db, `create table usuarios (
		id integer auto_increment,
		nome varchar(80),
		PRIMARY KEY (id)
	)`).RowsAffected())
}

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
