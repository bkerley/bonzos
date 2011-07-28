#define ROWS 24
#define COLS 80

unsigned char *videoram = (unsigned char *) 0xb8000;

void clear();
void kputs(char*);

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

   clear();

   kputs("Welcome to BonzOS");
   kputs("~ My OS is a POS ~");
   kputs(boot_loader_name);
 
   /* Write your kernel here. */

}

void clear() {
  unsigned char *videoram_cursor = (unsigned char *) 0xb8000;
  int row_cursor = 0, col_cursor = 0;

  for (int row_cursor = 0; row_cursor < ROWS; row_cursor++) {
    for (int col_cursor = 0; col_cursor < COLS; col_cursor++) {
      *videoram_cursor++ = 0;
      *videoram_cursor++ = 0x07;
    }
  }
}

void kputs(char* line) {
  static int row_cursor = 0;
  unsigned char *videoram_cursor = (unsigned char *) 0xb8000 + (2 * COLS * row_cursor);
  char *line_cursor = line;

  while (*line_cursor != 0) {
    *videoram_cursor = *line_cursor;
    videoram_cursor += 2;
    line_cursor++;
  }

  row_cursor++;
}
