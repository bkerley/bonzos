#include "screen.h"
#include "memory.h"

void kmain( void* mbd, unsigned int magic )
{
   if ( magic != 0x2BADB002 )
   {
      /* Something went not according to specs. Print an error */
      /* message and halt, but do *not* rely on the multiboot */
      /* data structure. */

     kputs("magic number failed, a-bloo a-bloo :(");
     return;
   }
 
   /* You could either use multiboot.h */
   /* (http://www.gnu.org/software/grub/manual/multiboot/multiboot.html#multiboot_002eh) */
   /* or do your offsets yourself. The following is merely an example. */ 
   char * boot_loader_name =(char*) ((long*)mbd)[16];

   clear();

   kputs("Welcome to BonzOS");
   kputs("~ My OS is a POS ~");
   kputs(boot_loader_name);

   test_memcpy();
   test_memset();

   kputs("Okay!");
}

void test_memcpy() {
  char source[] = "Mazim placerat facer possim assum typi non habent. 1234567890 Motörhead";
  char destination[80];

  kputs(source);

  memcpy(destination, source, 73);

  kputs(destination);
}

void test_memset() {
  char buf[] = "Mazim placerat facer possim assum typi non habent. 1234567890 Motörhead";
  kputs(buf);

  memset(buf, '_', 10);

  kputs(buf);
}
