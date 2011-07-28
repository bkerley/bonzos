task :default => :bochs
task :bochs => 'floppy.img' do
  sh 'bochs -q || true'
end

file 'loader.o' => 'loader.s' do
  sh "nasm -f elf -o loader.o loader.s"
end

file 'kernel.o' => 'kernel.c' do
  sh "i386-elf-gcc -o kernel.o -c kernel.c -Wall -Wextra -Werror -nostdlib -nostartfiles -nodefaultlibs"
end

file 'kernel.bin' => ['linker.ld', 'kernel.o', 'loader.o'] do
  sh "i386-elf-ld -T linker.ld -o kernel.bin loader.o kernel.o"
end

file 'floppy.img' => 'kernel.bin' do
  sh 'cat stage1 stage2 pad kernel.bin > floppy.img'
end
