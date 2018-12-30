//
//  leothread.c
//  
//
//  Created by Tiffany Chandra on 11/24/18.
//

#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

/*
 submit a file leothread.c that is like hello.c (Figure 12.13), except that it creates and reaps L(N) - 1 joinable threads, where N is a positive command-line argument and L(N) is the Nth Leonardo number. These threads should be created as a Fibonacci tree of order N rooted in the main thread, where thread corresponding to a node creates and reaps the threads corresponding to the node's children. The Fibonacci trees of order 0 and 1 have just a root node, and a Fibonacci tree of order N > 1 has left and right Fibonacci subtrees of order N-1 and N-2, respectively.
 
 Nodes in the tree of threads should be labeled 0 through L(N)-1 in preorder: that is, each thread should have a label that is a unique integer in the range 0 .. L(N)-1, where the main thread's label is 0 and each non-leaf thread labeled T and with L(k) - 1 descendants (for some k) has two children labeled T + 1 and T + 1 + L(k - 1). Each leaf thread should simply print "[T]\n" where T is the thread’s label; each non-leaf thread with label T should first print "(T\n", then create and reap its two children, and finally print "T)\n" just before exiting. The main thread counts as a thread and so should print too. The main thread is a leaf if and only if N=1.

 */
int counter = 0;
void *leothread(void *vargp) /*thread routine*/
{
    int i = counter;
    counter++;
    int* n = vargp;
    
    if (*n == 0 || *n == 1)
    {
        *n = 1;
        printf("[%d]\n", i);
        return NULL;
    }
    else
    {
        int left = *n - 1;
        int right = *n - 2;
	int x = i;
        pthread_t tid1;
        pthread_t tid2;
        printf("(%d\n", x);
        pthread_create(&tid1, NULL, leothread, &left);
        pthread_join(tid1, NULL);
        pthread_create(&tid2, NULL, leothread, &right);
        pthread_join(tid2, NULL);
        printf("%d)\n", x);
        *n = left + right;
    }
	return NULL;
}

int main(int argc, const char* argv[])
{
    int value = atoi(argv[1]);
    pthread_t tid;
    int stem = pthread_create(&tid, NULL, leothread, &value);
    if (stem != 0)
    {
        perror("pthread_create");
        return(1);
    }
    pthread_join(tid, NULL);
    return(0);
}
