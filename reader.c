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

typedef struct cp_info {
  u1 tag;
  u1 info[];
};

typedef struct attribute_info{
  u2 attribute_name_index;
  u4 attribute_length;
  u1 info[attribute_length];
};

typedef struct method_info{
  u2 access_flags;
  u2 name_index;
  u2 descriptor_index;
  u2 attributes_count;
  attribute_infoattributes[attributes_count];
};

typedef struct field_info {
  u2 access_flags;
  u2 name_index;
  u2 descriptor_index;
  u2 attributes_count;
  attribute_info attributes[attributes_count];
};

int check_tag (cp_info *cp){
  if (cp.tag == 2) || (cp.tag < 1) || (cp.tag > 12)
    return 0
  else return 1
}

typedef struct {
  u1 tag;
  union {
    struct {
      u2 name_index;
    } Class;
    struct {
      u2 class_index;
      u2 name_and_type_index;
    } Fieldref;
    struct {
      u2 class_index;
      u2 name_and_type_index;
    } Methodref;
    struct {
      u2 class_index;
      u2 name_and_type_index;
    } InterfaceMethodref;
    struct {
      u2 name_index;
      u2 descriptor_index;
    } NameAndType;
    struct {
      u2 length;
      u1 bytes[length];
    } Utf8;
    struct {
      u2 string_index;
    } String;
    struct {
      u4 bytes;
    } Integer;
    struct {
      u4 bytes;
    } Float;
    struct {
      u4 high;
      u4 low;
    } Long;
    struct {
      u4 high;
      u4 low;
    } Double;
  }
}

void read_Constant_Pool {
  Constant *constantPool = (Constant*) malloc(...Constant *cp;
    for (cp = constantPool; cp < constantPool + count -1; cp++) {
      cp->tag = u1Read(cf);
      switch (cp->tag) {
        case 7:
          cp->u.Class.name_index = u2Read(fd);
          break;
        case 9:
          cp->u.Fieldref.class_index = u2Read(fd);
          cp->u.Fieldref.name_and_type_index =u2Read(fd);
          break;
        case 10:
          cp->u.Methodref.class_index = u2Read(fd);
          cp->u.Methodref.name_and_type_index =u2Read(fd);
          break;
        case 11:
          cp->u.InterfaceMethodref.class_index = u2Read(fd);
          cp->u.InterfaceMethodref.name_and_type_index =u2Read(fd);
          break;
        case 12:
          cp->u.NameAndType.name_index = u2Read(fd);
          cp->u.NameAndType.descriptor_index =u2Read(fd);
          break;
        case 1:
          cp->u.Utf8.length = u2Read(fd);
          cp->u.Utf8.bytes[length] =u1Read(fd);
          break;
        case 8:
          cp->u.String.string_index = u2Read(fd);
          break;
        case 3:
          cp->u.Integer.bytes = u4Read(fd);
          break;
        case 4:
          cp->u.Float.bytes = u4Read(fd);
          break;
        case 5:
          cp->u.Long.high = u4Read(fd);
          cp->u.Long.low = u4Read(fd);
          break;
        case 6:
          cp->u.Long.high = u4Read(fd);
          cp->u.Long.low = u4Read(fd);
          break;
}

typedef struct ClassFile{
  u4 magic;
  u2 minor_version;
  u2 major_version;
  u2 constant_pool_count;
  cp_info constant_pool[constant_pool_count - 1];
  u2 access_flags;
  u2 this_class;
  u2 super_class;
  u2 interfaces_count;
  u2 interfaces[interfaces_count];
  u2 fields_count;
  field_info fields[fields_count];
  u2 methods_count;
  method_info methods[methods_count];
  u2 attributes_count;
  attribute_info attributes[attributes_count];
};

read_ClassFile{
  ClassFile* cf= (ClassFile*) malloc(sizeof(ClassFile));
  cf->magic = u4Read(fd);
  cf->minor_version = u2Read(fd);
  cf->major_version = u2Read(fd);
  cf->constant_pool = cp_info(fd);
  cf->access_flags = u2Read(fd);
  cf->this_class = u2Read(fd);
  cf->super_class = u2Read(fd);
  cf->interfaces_count = u2Read(fd);
  cf->interfaces = u2Read(fd);
  cf->fields_count = u2Read(fd);
  cf->fields = field_info(fd);
  cf->methods_count = u2Read(fd);
  cf->methods = method_info(fd);
  cf->attributes_count = u2Read(fd);
  cf->attributes = attrubues_info(fd);
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
