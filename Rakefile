task :default => :bochs
task :bochs => 'floppy.img' do
  sh 'bochs -q || true'
end

file 'loader.o' => 'loader.s' do
  sh "nasm -f elf -o loader.o loader.s"
end

C_SOURCES = {
  'kernel'=>['screen.h', 'memory.h', 'types.h'],
  'bus'=>['bus.h', 'types.h'],
  'screen'=>['screen.h', 'bus.h', 'types.h'],
  'memory'=>['memory.h', 'types.h']
}
C_OUTPUTS = C_SOURCES.keys.map{ |source| "#{source}.o"}

C_SOURCES.each do |source, deps|
  file "#{source}.o" => ["#{source}.c", *deps] do
    sh "i386-elf-gcc -o #{source}.o -c #{source}.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -std=gnu99"
  end
end

file 'kernel.bin' => ['linker.ld', 'loader.o', *C_OUTPUTS] do
  sh "i386-elf-ld -T linker.ld -o kernel.bin loader.o #{C_OUTPUTS.join ' '}"
end

file 'floppy.img' => 'kernel.bin' do
  sh 'cat stage1 stage2 pad kernel.bin > floppy.img'
end
