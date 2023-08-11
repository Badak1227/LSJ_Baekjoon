#include <stdio.h>

int main() {
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);

    int min_x_distance = x < w - x ? x : w - x;
    int min_y_distance = y < h - y ? y : h - y;

    int min_distance = min_x_distance < min_y_distance ? min_x_distance : min_y_distance;

    printf("%d\n", min_distance);

    return 0;
}
