/**
 * Este script demonstra o uso de expressões regulares em JavaScript para encontrar padrões em uma string.
 * 
 * A variável `texto` contém uma string com uma frase.
 * 
 * A variável `regex` é uma expressão regular que corresponde à frase "casa bonita" de maneira case-insensitive (bandeira `i`) e globalmente (bandeira `g`).
 * 
 * A primeira instrução `console.log` usa o método `match` para encontrar todas as ocorrências do padrão definido por `regex` na string `texto`.
 * 
 * A segunda instrução `console.log` usa o método `match` para encontrar o padrão "a b" na string `texto`.
 * 
 * Saída esperada:
 * - O primeiro `console.log` irá imprimir um array com a frase correspondente "Casa bonita".
 * - O segundo `console.log` irá imprimir `null` porque o padrão "a b" não existe na string `texto`.
 */
const texto = 'Casa bonita é a casa amarela da esquina com a ACASALAR.';

const regex = /casa bonita/gi
console.log(texto.match(regex));
console.log(texto.match(/a b/));

