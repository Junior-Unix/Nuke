var pessoa = {
    obterDados: function(){
        var data = new Date().getFullYear();

        if((data - this.ano) >= 21){
            return true;
        }else{
            return false;
        }
    },
    criarTelefone: function(){
        this.formTel = '(';
        for(var i = 0; i <= 1; i++){
            this.formTel += this.numTel[i];
        }
        this.formTel += ')';

        for(; i <=6; i++){
            this.formTel += this.numTel[i];
        }
        this.formTel += '-';

        for(; i <= 10; i++){
            this.formTel += this.numTel[i];
        }
    },

    // criarTelefone: function(){
    //     this.formTel = '(';
    //     for(var i = 0; i <= 1; i++){
    //         this.formTel += this.numTel[i];
    //     }
    //     this.formTel =+ ')';

    //     for(; i <=6; i++){
    //         this.formTel =+ this.numTel[i];
    //     }

    //     for(; i <= 10; i++){
    //         this.formTel =+ this.numTel[i];
    //     }
    // },
    mensagem: function(){
        this.maiorDeIdade() ?
        alert('Caro(a), ' + this.nome + ' entramos em contato pelo telefone ' + this.formTel + ' para pedir suas informações e abrir sua conta no banco.')
        : alert('Caro(a), ' + this.nome + ' entramos em contato pelo telefone ' + this.formTel + ' para pedir suas informações e de seu ...');

    },

    construtor: function(){
        this.obterDados();
        this.criarTelefone();
        this.mensagem
    }
}

pessoa.construtor();