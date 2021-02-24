#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef int8_t u1;
typedef int16_t u2;
typedef int32_t u4;

u1 u1Read (FILE *fp){
  u1 toReturn = getf(fd);
  return toReturn;
}

u2 u2Read (FILE *fp){
  u2 toReturn = getf(fd);
  toReturn = (toReturn<<8) | (getc(fd));
  return toReturn;
}

u4 u4Read (FILE *fp){
  u4 toReturn = getf(fd);
  toReturn = (toReturn<<8) | (getc(fd));
  toReturn = (toReturn<<8) | (getc(fd));
  toReturn = (toReturn<<8) | (getc(fd));
  return toReturn;
}

struct cp_info {
  u1 tag;
  u1 info[];
}

struct ClassFile{
  u4 magic;
  u2 minor_version;
  u2 major_version;
  u2 constant_pool_count;
  cp_info constant_pool[constant_pool_count - 1];
  u2 access_flags;
  u2 this_class;
  u2 super_class;
  u2 interfaces_count;
  u2 inteerfaces[interfaces_count];
  u2 fields_count;
  field_info fields[fields_count];
  u2 methods_count;
  method_info methods[methods_count];
  u2 attributes_count;
  attribute_info attributes[attributes_count];
}

main (int argc, char*argv[]){
  FILE *fp;

  fp = fopen (argv[1], "r");

  if (fp == NULL) {
    printf("Erro de abertura do arquivo.");
    break;
  }

  fseek(fp,0L,SEEK_END);
  size_file = ftell(fp);

  read_Class(size_file, fp);

  fclose(fp);

}
