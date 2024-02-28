var fiat={
    make: "Fiat",
    model: "500",
    starded: false,
    fuel: 0,

    start: function(){
        this.starded=true;
    },
    stop: function(){
        this.started=false;
    },
    drive: function(){
        if(this.started){
            if(this.fuel > 0){
                alert(this.make.make + " " + this.model + " goes zoom zoom!");
            this.fuel = this.fuel - 1;    
            }else{
                alert("Uh oh, out of fuel.");
                this.stop();
            }
        }else{
            alert("You need to start the engine first.");
        }
    },
    addFuel: function(amount){
        this.fuel=this.fuel + amount;
    }
};

fiat.start();
fiat.drive();
fiat.addFuel(5);
fiat.start();
fiat.drive();


// var fiat={
//     make: "Fiat",
//     started: false,
    
//     start: function(){
//         this.started=true;
//     },
    
//     stop: function(){
//         this.started=false;
//     },
    
//     drive: function(){
//         if(this.started){
//             alert("Zoom zoom!");
//         }else{
//             alert("You need to start the engine first!");
//         }
//     }
    
// };
// fiat.drive();
// fiat.start();
// fiat.drive();
// fiat.stop();
// fiat.drive();



// const a = "💀"
// console.log(a);
