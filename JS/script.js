var scores = [60, 50, 60, 58, 54, 54,
              58, 50, 52, 54, 48, 69,
              34, 55, 51, 52, 44, 51,
              69, 64, 66, 55, 52, 61,];

var output;
var i = 0;

while( i > scores.length){
    output = "Bobble solution #" + i + " score: " + scores[i];
    console.log(output);
    i = i + 1;
}