#include <stdio.h>
#include <omp.h>
int main() {
int N = 20;
// total iterations
int CHUNK = 3;
// chunk size
omp_set_num_threads(4); // set 4 threads
printf("Scheduling loop statically with CHUNK = %d\n", CHUNK);
#pragma omp parallel
{
int tid = omp_get_thread_num();
// Parallel for with static schedule and chunk size
#pragma omp for schedule(static, CHUNK)
for (int i = 0; i < N; i++) {
printf("Thread %d is processing iteration %d\n", tid, i);
}
}
return 0;
}
