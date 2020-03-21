#include<stdio.h>
#include<stdlib.h>
#define label 1000001
#define N 1001
short team[label] = {};
char Used[label] = {};
struct list {
    int tag;
    struct list *next;
}*head, *curr, *prev, *set[N];
main() {
    int a, n, m, x;
    char s[8], C = 1;
    while(scanf("%d", &n) == 1) {
        while(n--) {
            scanf("%d", &m);
            while(m--)
                scanf("%d", &x), team[x] = n, Used[x] = C;
            set[n] = NULL;
        }
        head = curr = prev = NULL;
        printf("Scenario #%d\n", C);
        
        while(scanf("%s", s) == 1 && s[0] != 'S') {
            if(s[0] == 'E') { /*insert*/
                scanf("%d", &x);
                curr = (struct list*)malloc(sizeof(struct list));
                curr->tag = x, curr->next = NULL;
                if(Used[x] != C || set[team[x]] == NULL) { /*all rear*/
                    if(head == NULL)
                        head = curr;
                    else
                        prev->next = curr;
                    prev = curr;
                    if(Used[x] == C)
                        set[team[x]] = curr;
                }
                else { /*team rear*/
                    if(prev == set[team[x]]) { /*all rear*/
                        prev->next = curr;
                        prev = curr;
                    }
                    else if(set[team[x]]->next != NULL) {
                        curr->next = set[team[x]]->next;
                        set[team[x]]->next = curr;
                    }
                    set[team[x]] = curr;
                }
            }
            else {
                printf("%d\n", head->tag);
                curr = head;
                head = head->next;
                if(Used[curr->tag] == C && set[team[curr->tag]] == curr)
                    set[team[curr->tag]] = NULL;
                free(curr);
            }
        }
        C++;
    }
    return 0;
}