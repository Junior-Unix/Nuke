#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, i;
    double *x, *y, x_mean = 0, y_mean = 0, s_xy = 0;

    printf("Enter the number of elements for x and y: ");
    scanf("%d", &n);

    // Este trecho de código aloca memória dinamicamente para dois arrays de double, x e y,
    // cada um com n elementos. A função malloc é usada para essa alocação, e o tamanho
    // necessário é calculado multiplicando o número de elementos (n) pelo tamanho de um double.
    // O resultado da função malloc é então convertido para um ponteiro do tipo (double *).
    // Aloca memória para os arrays x e y
    // x e y são ponteiros para arrays de double
    // n é o número de elementos a serem alocados para cada array
    // malloc é usado para alocar memória dinamicamente
    // sizeof(double) retorna o tamanho em bytes de um double
    // O resultado de malloc é convertido para (double *)
    // Allocate memory for x and y arrays
    x = (double *)malloc(n * sizeof(double));
    y = (double *)malloc(n * sizeof(double));

    if (x == NULL || y == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the elements of x: ");
    for (i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
        x_mean += x[i];
    }
    x_mean /= n;

    printf("Enter the elements of y: ");
    for (i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
        y_mean += y[i];
    }
    y_mean /= n;

    for (i = 0; i < n; i++) {
        double x_diff = x[i] - x_mean;
        double y_diff = y[i] - y_mean;
        s_xy += x_diff * y_diff;
        printf("x_diff^2: %lf, y_diff^2: %lf, (x_diff * y_diff): %lf\n", x_diff * x_diff, y_diff * y_diff, x_diff * y_diff);
    }

    s_xy /= (n - 1);
    printf("s_xy: %lf\n", s_xy);

    free(x);
    free(y);

    return 0;
}