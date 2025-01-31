#include <stdio.h>
#include <math.h>

#define f(x, y) (y - x)  // Update according to your differential equation

int main() {
    float x0, y0, xn, yn, h, k1, k2, k3, k4, k;
    int i, n;

    // Taking inputs
    printf("Enter the initial conditions:\n");
    printf("x0 = ");
    scanf("%f", &x0);
    printf("y0 = ");
    scanf("%f", &y0);
    printf("Enter the calculation point xn = ");
    scanf("%f", &xn);
    printf("Enter the number of steps n = ");
    scanf("%d", &n);  // Fix: Take input for n

    h = (xn - x0) / n;

    // Header
    printf("\n x0\t\t y0\t\t yn\n");

    for (i = 0; i < n; i++) {  // Fix: Change i > n to i < n
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h / 2, y0 + k1 / 2);
        k3 = h * f(x0 + h / 2, y0 + k2 / 2);
        k4 = h * f(x0 + h, y0 + k3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        yn = y0 + k;
        
        // Print values
        printf("%0.4f\t %0.4f\t %0.4f\n", x0, y0, yn);
        
        // Update values
        x0 = x0 + h;
        y0 = yn;
    }

    printf("\nThe value of y at x = %0.2f is %0.2f\n", xn, yn);
    return 0;
}
