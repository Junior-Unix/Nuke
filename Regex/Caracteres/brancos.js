const texto = `
ca	r
r	o s!
`;

const texto = `
ca	r
r	o s!
`;

// A linha abaixo usa o método `match` para procurar uma sequência específica de caracteres em `texto`.
// A expressão regular `/ca\tr\nr\to\ss!/` procura a sequência "ca", seguida por um tab (`\t`), 
// uma quebra de linha (`\r`), "r", outro tab (`\t`), "o", um espaço (`\s`), e um ponto de exclamação (`!`).
console.log(texto.match(/ca\tr\nr\to\ss!/));