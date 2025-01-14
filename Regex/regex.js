const texto = '0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,x,w,z'

const regexNove = RegExp('9')
console.log('Métodos da RegExp...')
console.log(regexNove.test(texto)) // 9
console.log(regexNove.exec(texto)) // [ '9', index: 18, input: '0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,x,w,z' ]
const regexLetras = /[a-z]/g
console.log('Métodos da string...')
console.log(texto.match(regexLetras)) // [ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'w', 'z' ]
console.log(texto.search(regexLetras)) // 20
console.log(texto.replace(regexLetras, 'Achei')) // 0,1,2,3,4,5,6,7,8,9
console.log(texto.split(regexLetras)) // [ '0,1,2,3,4,5,6,7,8,9,',