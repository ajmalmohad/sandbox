#include <stdio.h>

int isIn(int x, int frames[], int n){
    for (int i = 0; i < n; i++){
        if(frames[i]==x) return 1;
    }
    return 0;
}

int main(){
    int n, m;
    printf("Enter Number of Frames: ");
    scanf("%d", &m);
    printf("Enter Number of Pages: ");
    scanf("%d", &n);
    int pages[n], frames[m];
    printf("Enter Page Numbers: ");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);
    for (int i = 0; i < m; i++) frames[i]=-1;

    int pagefaults = 0;
    for (int i = 0; i < n; i++){
        int current = pages[i];
        if(!isIn(current, frames, m)){
            for (int i = m; i > 0; i--) frames[i] = frames[i-1];
            frames[0] = current;
            pagefaults++;
        }
        printf("%d :", current);
        for (int i = 0; i < m; i++) printf("%d ", frames[i]);
        printf("\n");
    }

    printf("Page Faults: %d", pagefaults);
}