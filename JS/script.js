const array = [];
for (let i = 0; i < 50; i++) {
    const randomDecimal = Math.floor(Math.random() * 100);
    array.push(randomDecimal);
}
const maiorValor = Math.max(...array);
console.log(array);
console.log(maiorValor);
