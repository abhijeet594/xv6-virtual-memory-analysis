#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  trace(1);

  getpid();

  printf(1, "Hello from trace test!\n");

  sleep(10);

  exit();
}
