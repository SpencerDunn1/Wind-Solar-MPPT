float wm = x1;
float Pcal = x2;
float Speed = x3;
static float wprev = 0.0;
static float Pprev = 0.0;
static float Sprev = 0.0;
static float wmref = 100;
const float base_step = 1.8;
float Pdiff = Pcal - Pprev;
float wdiff = wm - wprev;
float Sdiff = Speed - Sprev;
float step = base_step + 0.1 * fabs(Pdiff);
if (fabs(Pdiff) > 0.02) {
 if (Pdiff > 0) {
 wmref += step;
 } else {
 wmref -= step;
 }
}
if (Pdiff > 1000) {
wmref = 100;
}
if(fabs(Pdiff) > 1000){
wmref = 50;
}
wmref += 0.48 * Sdiff;
wprev = wm;
Pprev = Pcal;
Sprev = Speed;
y1 = wmref; 