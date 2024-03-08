#include <stdio.h>
#include <stdlib.h>

int main() {
    char name[100];  // тут будет храниться название файла
    char text[100];  // тут будет храниться содержимое файла
    FILE* file;
    int n = 0;

    printf("1 - Вывести содержимое файла.\n-1 - Выход из программы.\n");
    int check = scanf("%d", &n);
    if (!check) printf("n/a");

    while (n != -1) {
        if (n == 1) {
            scanf("%s", name);  // сканируем название файла из консоли, запис. в массив "name"
            file = fopen(name, "r");  // открываем файл в режиме чтения
            if (file != NULL) {       // если файл не нулевой
                while (!feof(file)) {
                    fgets(text, 100, file);  // cчитывает все, что лежит в file и помещает это в массив "text"
                    printf("%s\n", text);
                    scanf("%d", &n);
                }
            } else {
                printf("n/a\n");
                fclose(file);
            }
        } else if (n == -1)  // если вводим -1, то закрываем файл
            fclose(file);
    }
    return 0;
}
