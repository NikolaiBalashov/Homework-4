#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int main() {
    int n;
    int k = 0;
    int f = 0;
    int l = 0;
    scanf_s("%d", &n);
    int* arr = (int*)malloc(n * n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("%d:", i);

        for (int j = 0; j < n; j++) {
            scanf_s("%d", (arr + i * n + j));
        }
    }
    printf("\n");

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if ((i == j) && (arr[i * n + j] != 0)) {             
                printf(point %d has loop\n, (i + 1));
                k++;
            }
        }
    }
        if (k == 0) {
            printf("No loops found");
        }
        else {
            printf("%d loops found", k);
        }
    
       

    // âèçóàëèçàöèÿ //

    FILE* file;

    if ((file = fopen("Dot_file.txt", "w")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    fprintf(file, "graph G{\n");

    for (int i = 0; i < n; i++) {

        for (int j = 0; j <= i; j++) {

            if (arr[i * n + j] != 0) {

                for (int g = 0; g < arr[i * n + j]; g++) {
                    fprintf(file, "%d -- %d;\n", (i + 1), (j + 1));
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((arr[i * n + j]) == 0) {
                l++;
            }
        }
        if (l == n) {
            fprintf(file, "%d;\n", (i + 1));
        }
        l = 0;
    }

    fprintf(file, "}");
    fclose(file);
    system("dot C:\\Users\\Admin\\source\\repos\\C\\Project1\\Project1\\Dot_file.txt -Tbmp -o dot_file.bmp");
    system("rundll32 \"%ProgramFiles%\\Windows Photo Viewer\\PhotoViewer.dll\", ImageView_Fullscreen C:\\Users\\Admin\\source\\repos\\C\\Project1\\Project1\\Dot_file.bmp");
    return (0);
}
