#include "EloquentTinyML.h"
// sine_model.h contains the array you exported from the previous step
// with either xxd or tinymlgen
#include "model.h"

#define NUMBER_OF_INPUTS 2
#define NUMBER_OF_OUTPUTS 1
// in future projects you may need to tweak this value.
// it's a trial and error process
#define TENSOR_ARENA_SIZE 2*1024

Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml(model);

void setup() {
    Serial.begin(115200);
}

void loop() {
    // pick up a random x and predict its sine
//    float x = 3.14 * random(100) / 100;
    float x=0.001;
//    float y = sin(x);
    float y=71;
    float input[2] = { x,y };
    float predicted = ml.predict(input);
    Serial.print(x);
    Serial.print(") = ");
    Serial.print(y);
    Serial.print("\t predicted: ");
    Serial.println(predicted);
    delay(1000);
}
