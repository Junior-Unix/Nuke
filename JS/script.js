// Carrega o módulo WebAssembly
fetch('/workspaces/Nuke/JS/module.wasm')
    .then(response => response.arrayBuffer())
    .then(buffer => WebAssembly.compile(buffer))
    .then(module => {
        // Cria uma instância do módulo WebAssembly
        const wasmInstance = new WebAssembly.Instance(module);

        // Obtém a função exportada do módulo WebAssembly
        const wasmFunction = wasmInstance.exports.functionName;

        // Obtém a referência para o elemento de entrada do HTML
        const inputElement = document.getElementById('inputElement');

        // Define uma variável permanente no módulo WebAssembly
        wasmInstance.exports.permanentVariable = 42;

        // Função para atualizar a variável dinâmica no módulo WebAssembly
        function updateDynamicVariable() {
            const inputValue = inputElement.value;
            wasmInstance.exports.updateDynamicVariable(inputValue);
        }

        // Adiciona um ouvinte de evento para chamar a função quando o valor de entrada mudar
        inputElement.addEventListener('input', updateDynamicVariable);
    })
    .catch(error => {
        console.error('Erro ao carregar o módulo WebAssembly:', error);
    });
const wasmInstance = new WebAssembly.Instance(wasmModule);

// Obtém a função exportada do módulo WebAssembly
const wasmFunction = wasmInstance.exports.functionName;

// Obtém a referência para o elemento de entrada do HTML
const inputElement = document.getElementById('inputElement');

// Define uma variável permanente no módulo WebAssembly
wasmInstance.exports.permanentVariable = 42;

// Função para atualizar a variável dinâmica no módulo WebAssembly
function updateDynamicVariable() {
    const inputValue = inputElement.value;
    wasmInstance.exports.updateDynamicVariable(inputValue);
}

// Adiciona um ouvinte de evento para chamar a função quando o valor de entrada mudar
inputElement.addEventListener('input', updateDynamicVariable);