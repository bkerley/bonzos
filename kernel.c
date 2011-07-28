void kmain( void* mbd, unsigned int magic )
{
   if ( magic != 0x2BADB002 )
   {
      /* Something went not according to specs. Print an error */
      /* message and halt, but do *not* rely on the multiboot */
      /* data structure. */
   }
 
   /* You could either use multiboot.h */
   /* (http://www.gnu.org/software/grub/manual/multiboot/multiboot.html#multiboot_002eh) */
   /* or do your offsets yourself. The following is merely an example. */ 
   char * boot_loader_name =(char*) ((long*)mbd)[16];
   char* loader_name_cursor = boot_loader_name;
 
   /* Print a letter to screen to see everything is working: */
   unsigned char *videoram = (unsigned char *) 0xb8000;
   unsigned char *videoram_cursor = videoram;

   while (*loader_name_cursor != 0) {
     *videoram_cursor = *loader_name_cursor;
     videoram_cursor++;
     *videoram_cursor = 0x07;
     videoram_cursor++;
     loader_name_cursor++;
   }
 
   /* Write your kernel here. */

}
