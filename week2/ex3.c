#include <stdio.h>

void help() {
    printf("Usage:\n");
    printf("    ex4 <height> [<figure>:int]\n");
    printf("Available figures:\n");
    printf("    0 - Isosceles triangle, side-up (default)\n");
    printf("    1 - Right triangle\n");
    printf("    2 - Isosceles triangle, side-right\n");
    printf("    3 - Square\n");
}

void draw_triangleSideUp(int h);
void draw_triangleRight(int h);
void draw_triangleSideRight(int h);
void draw_square(int h);

int main(int argc, char const *argv[]) {
    if (argc < 2 || argc > 3) {
        help();
    } else {
        int h;
        sscanf(argv[1], "%d", &h);

        int figure = 0;
        if (argc == 3) {
            sscanf(argv[2], "%d", &figure);
        }

        switch (figure) {
        case 0:
            draw_triangleSideUp(h);
            break;
        case 1:
            draw_triangleRight(h);
            break;
        case 2:
            draw_triangleSideRight(h);
            break;
        case 3:
            draw_square(h);
            break;
        default:
            help();
            break;
        }
    }
    return 0;
}
void draw(int h, char *c) {
    for (int i = 0; i < h; i++) {
        printf("%s", c);
    }
}

void draw_triangleSideUp(int h) {
    int width = 2 * h - 1;

    for (int layer = 0; layer < h; layer++) {
        draw(h - layer - 1, " ");
        draw(2 * layer + 1, "*");
        printf("\n");
    }
}

void draw_triangleRight(int h) {
    for (int layer = 1; layer <= h; layer++) {
        draw(layer, "*");
        printf("\n");
    }
}

void draw_triangleSideRight(int h) {
    int width = h / 2;
    for (int i = 1; i <= width; i++) {
        draw(i, "*");
        printf("\n");
    }

    for (int i = h - width; i >= 1; i--) {
        draw(i, "*");
        printf("\n");
    }
}

void draw_square(int h) {
    for (int i = 0; i < h; i++) {
        draw(h, "*");
        printf("\n");
    }
}