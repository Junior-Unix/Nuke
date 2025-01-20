// . é um coringa, válido para uma posição

const texto = '1,2,3,4,5,6,7,8,9,0';

// Procura por '1' seguido de qualquer caractere e depois '2'
console.log(texto.match(/1.2/g)); // null, pois não há correspondência

// Procura por '1' seguido de dois caracteres quaisquer e depois '2'
console.log(texto.match(/1..2/g)); // null, pois não há correspondência

// Procura por '1' seguido de dois caracteres quaisquer e depois ','
console.log(texto.match(/1..,/g)); // ['1,2'], pois '1,2' corresponde ao padrão

const notas = '8.3,7.1,8.8,10.0';

// Procura por '8' seguido de dois caracteres quaisquer
console.log(notas.match(/8../g)); // ['8.3', '8.8'], pois '8.3' e '8.8' correspondem ao padrão
console.log(notas.match(/.\../g)); // o valor 10.0 não é retornado. O ponto é um coringa para qualquer caractere, exceto quebras de linha

