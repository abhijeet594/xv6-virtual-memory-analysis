
#include "types.h"
#include "stat.h"
#include "user.h"

int global_var = 100;

int
main(void)
{
  int local_var = 200;
  int *heap_var;

  heap_var = (int*)malloc(sizeof(int));

  if(heap_var == 0){
    printf(1, "Memory allocation failed\n");
    exit();
  }

  *heap_var = 300;

  printf(1, "\n=== INITIAL VARIABLE VALUES ===\n");
  printf(1, "Global variable: %d\n", global_var);
  printf(1, "Local variable: %d\n", local_var);
  printf(1, "Heap variable: %d\n", *heap_var);

  printf(1, "\n=== VIRTUAL MEMORY MAPPINGS ===\n");

  printf(1, "\nGlobal variable mapping:\n");
  vmmap((uint)&global_var);

  printf(1, "\nLocal variable mapping:\n");
  vmmap((uint)&local_var);

  printf(1, "\nHeap variable mapping:\n");
  vmmap((uint)heap_var);

  printf(1, "\n=== FORK DEMONSTRATION ===\n");

  if(fork() == 0){
    global_var = 400;
    local_var = 500;
    *heap_var = 600;

    printf(1, "\nChild process modified values:\n");
    printf(1, "Global: %d\n", global_var);
    printf(1, "Local: %d\n", local_var);
    printf(1, "Heap: %d\n", *heap_var);

    exit();
  }

  wait();

  printf(1, "\nParent process values after child exits:\n");
  printf(1, "Global: %d\n", global_var);
  printf(1, "Local: %d\n", local_var);
  printf(1, "Heap: %d\n", *heap_var);

  free(heap_var);

  exit();
}
