var scores = [60, 50, 60, 58, 54, 54,
              58, 50, 52, 54, 48, 69,
              34, 55, 51, 52, 44, 51,
              69, 64, 66, 55, 52, 61,];

var highScore;
var output;
for(var i = 0; i < scores.length; i++){
    output = "Buble solution #" + i + " score: " + scores[i];
    console.log(output):
    if(scores[i] > highScore){
        highScore = scores[i];
    }
}

console.log("Bubbles tests: " + scores.length);
console.log("Highest Bubble score:" + highScore);

var bestSolution = [];
for(var i = 0; i < scores.length; i++){
    if(scores[i] == highScore){
    bestSolution.push(i);
    }    
}
console.log("Solutions with the high score:" + bestSolution);
// while( i > scores.length){
//     output = "Bobble solution #" + i + " score: " + scores[i];
//     console.log(output);
//     i = i + 1;
// }