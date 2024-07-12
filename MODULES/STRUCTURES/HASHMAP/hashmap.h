

struct HASHMAP {
  void *array;
  int type;
};

void string_to_id(char *str);

struct HASHMAP *create_hashmap(int type);

void *read_hashmap_entry(char *str);