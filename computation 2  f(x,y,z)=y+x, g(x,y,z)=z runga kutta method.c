#include <stdio.h>

// Define the given differential equations
#define f(x, y, z) (y + x)  // First equation: dy/dx = y + x
#define g(x, y, z) (z)      // Second equation: dz/dx = z

int main() {
    float x0, y0, z0, xn, h, k1, k2, k3, k4, l1, l2, l3, l4;
    int i, n;

    // Input initial values
    printf("Enter the initial conditions:\n");
    printf("x0 = ");
    scanf("%f", &x0);
    printf("y0 = ");
    scanf("%f", &y0);
    printf("z0 = ");
    scanf("%f", &z0);
    printf("Enter the calculation point xn = ");
    scanf("%f", &xn);
    printf("Enter the number of steps n = ");
    scanf("%d", &n);

    // Calculate step size
    h = (xn - x0) / n;

    // Print table header
    printf("\n x \t\t y \t\t z \n");

    // Runge-Kutta 4th order method iteration
    for (i = 0; i < n; i++) {
        // Compute k1 and l1
        k1 = h * f(x0, y0, z0);
        l1 = h * g(x0, y0, z0);

        // Compute k2 and l2
        k2 = h * f(x0 + h / 2, y0 + k1 / 2, z0 + l1 / 2);
        l2 = h * g(x0 + h / 2, y0 + k1 / 2, z0 + l1 / 2);

        // Compute k3 and l3
        k3 = h * f(x0 + h / 2, y0 + k2 / 2, z0 + l2 / 2);
        l3 = h * g(x0 + h / 2, y0 + k2 / 2, z0 + l2 / 2);

        // Compute k4 and l4
        k4 = h * f(x0 + h, y0 + k3, z0 + l3);
        l4 = h * g(x0 + h, y0 + k3, z0 + l3);

        // Compute final y and z values using RK4 weighted average
        y0 = y0 + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        z0 = z0 + (l1 + 2 * l2 + 2 * l3 + l4) / 6;

        // Print intermediate values
        printf("%0.4f \t %0.4f \t %0.4f\n", x0, y0, z0);

        // Update x for the next step
        x0 = x0 + h;
    }

    // Print final result
    printf("\nValue of y at x = %0.2f is %0.4f\n", xn, y0);
    printf("Value of z at x = %0.2f is %0.4f\n", xn, z0);

    return 0;
}
