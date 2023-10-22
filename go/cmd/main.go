package main

import (
	"fmt"
	"log"

	"github.com/gofiber/fiber/v2"
)

func main() {
	app := fiber.New()
	app.Get("/", func(c *fiber.Ctx) error{
		return c.SendString("Hello World")
	})
	app.Post("/", func(c *fiber.Ctx) error {
		fmt.Println(string(c.Body()))
		return c.SendString("Post, ganhei, nao vou passar a roupa amanha!")
	})
	log.Fatal(app.Listen(":8080"))
}














// package main

// import (
// 	"log"

// 	"github.com/gofiber/fiber/v2"
// )

// func main(){

// 	app := fiber.New()
// 	app.Get("/",func(c *fiber.Ctx) error {
// 		return c.SendString("Hello World!!")
// 	})
	

// 	log.Fatal(app.Listen(":8080"))

// }