#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Event {
    int year;
    int type;
};

int compare(const void *a, const void *b) {
    struct Event *x = (struct Event *)a;
    struct Event *y = (struct Event *)b;

    if (x->year != y->year)
        return (x->year > y->year) - (x->year < y->year);

    return x->type - y->type;
}

int main() {
    int n, i, count = 0, maxCount = 0;
    int bestYear = 0;
    struct Event events[2 * MAX];

    printf("Enter number of scientists: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
        return 0;

    for (i = 0; i < n; i++) {
        int birth, death;

        printf("Enter birth and death years: ");
        scanf("%d %d", &birth, &death);

        events[2 * i].year = birth;
        events[2 * i].type = 1;

        events[2 * i + 1].year = death;
        events[2 * i + 1].type = 0;
    }

    qsort(events, 2 * n, sizeof(struct Event), compare);

    for (i = 0; i < 2 * n; i++) {
        if (events[i].type == 0) {
            count--;
        } else {
            count++;

            if (count > maxCount) {
                maxCount = count;
                bestYear = events[i].year;
            }
        }
    }

    printf("Year with maximum scientists alive: %d\n", bestYear);
    printf("Maximum number of scientists: %d\n", maxCount);

    return 0;
}