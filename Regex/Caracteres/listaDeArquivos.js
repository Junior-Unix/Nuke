/**
 * A linha de código a seguir busca todas as ocorrências da extensão de arquivo ".mp3"
 * dentro da string `texto` e registra um array de correspondências no console.
 * A expressão regular /\.mp3/g é usada para encontrar todas as substrings ".mp3" no texto.
 * A flag 'g' indica uma busca global, ou seja, encontrará todas as correspondências em vez de parar após a primeira.
 */
const texto = "lista de arquivos mp3: jazz.mp3, rock.mp3, podcast.mp3, blues.mp3";
console.log(texto.match(/\.mp3/g));