static float Vprev = 0.0;
static float Iprev = 0.0;
static float Pprev = 0.0;
static float Vref = 599.0;
const float step = 0.01;

float Vpv = x1;
float Ipv = x2;
float Ppv = Vpv * Ipv;

float Pdiff = Ppv - Pprev;
float Vdiff = Vpv - Vprev;

if (fabs(Pdiff) > 0.01) {
    if (Pdiff > 0) {
        if (Vdiff > 0) {
            Vref += step;
        } else {
            Vref -= step;
        }
    } else if (Pdiff < 0) {
        if (Vdiff > 0) {
            Vref -= step;
        } else {
            Vref += step;
        }
    }
}

Vprev = Vpv;
Iprev = Ipv;
Pprev = Ppv;
y1 = Vref;
