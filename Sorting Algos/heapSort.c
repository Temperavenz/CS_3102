#include "Header_files/header.h"

typedef struct {
    int elems[ARR_SIZE];
    int lastNdx;
}Heap;

void heapSort(Heap *h);
void heapify(Heap *h, int ndx);
void deleteMin(Heap *h);
void display(Heap h);

int main(void) {
    Heap H={{8, 3, 5, 10, 7, 2, 6, 1, 9, 4}, 9};
    heapSort(&H);
    display(H);

    return 0;
}

void heapSort(Heap *h) {
    int x, origNdx=h->lastNdx;
    for(x=(h->lastNdx-1)/2; x>=0; --x) {
        heapify(h, x);
    }
    while(h->lastNdx>0) {
        deleteMin(h);
    }
    h->lastNdx=origNdx;
}

void heapify(Heap *h, int ndx) {
    int pn=ndx, max=pn, ln=(pn*2)+1, rn=(pn*2)+2, temp;
    max=(ln<=h->lastNdx&&h->elems[ln]>h->elems[max])?ln:max;
    max=(rn<=h->lastNdx&&h->elems[rn]>h->elems[max])?rn:max;
    if(pn!=max) {
        temp=h->elems[pn];
        h->elems[pn]=h->elems[max];
        h->elems[max]=temp;
        heapify(h, max);
    }
}

void deleteMin(Heap *h) {
    int temp=h->elems[0];
    h->elems[0]=h->elems[h->lastNdx];
    h->elems[h->lastNdx]=temp;
    h->lastNdx--;
    heapify(h, 0);
}

void display(Heap h) {
    int x;
    printf("{");
    for(x=0; x<=h.lastNdx; ++x) {
        printf("%d", h.elems[x]);
        if(x<h.lastNdx) {
            printf(", ");
        }
    }
    printf("}\n\n");
}