#include "screen.h"
#include "memory.h"

void test_memcpy();
void test_memset();
void test_memcmp();

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

   kputs("");
   kputs("Testing memcpy, memset, and memcmp:");
   test_memcpy();
   test_memset();
   test_memcmp();


}

void test_memcpy() {
  char source[] = "Mazim placerat facer possim assum typi non habent. 1234567890 Motörhead";
  char destination[80];

  memcpy(destination, source, 73);

  if (memcmp(source, destination, 73) == 0) kputs("memcpy OK");
}

void test_memset() {
  char buf[] = "Mazim placerat";

  memset(buf, '_', 10);

  if (memcmp(buf, "__________erat", 14) == 0) kputs("memset OK");
}

void test_memcmp() {
  char buf1[] = "aabbccd";
  char buf2[] = "aabbccd";
  char buf3[] = "aabbddd";

  if (!memcmp(buf1, buf2, 6) && (memcmp(buf1, buf3, 6) == -1)) {
    kputs("memcmp OK");
  }
}
