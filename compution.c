#  compution f(x,y)=(z-x);g(x,z)=(x+y) runga kutta method

#include <stdio.h>
#include <math.h>

#define f(x, y) (y - x)  // Fix: Corrected function
#define g(x, z) (x + y)  // Fix: This function is unused in the code

int main() {
    float x0, y0, xn, yn, h, k1, k2, k3, k4, k;
    int i, n;

    printf("Enter the initial condition:\n");
    printf("x0=");
    scanf("%f", &x0);
    printf("y0=");
    scanf("%f", &y0);
    printf("Enter the calculation point xn=");
    scanf("%f", &xn);
    printf("Enter the number of steps n=");
    scanf("%d", &n);  // Fix: Added input for 'n'

    h = (xn - x0) / n;

    printf("\n x0 \t \t \t y0 \t \t \t \n");
    for (i = 0; i < n; i++) {  // Fix: Changed 'i > n' to 'i < n'
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h / 2, y0 + k1 / 2);
        k3 = h * f(x0 + h / 2, y0 + k2 / 2);
        k4 = h * f(x0 + h, y0 + k3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        yn = y0 + k;

        printf("%0.4f \t \t %0.4f \t \t %0.4f\n", x0, y0, yn);

        x0 = x0 + h;
        y0 = yn;
    }

    printf("\nValue of y at x = %0.2f is %0.2f\n", xn, yn);
    return 0;
}
