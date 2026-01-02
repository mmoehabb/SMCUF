enum DIR {
  OUTPUT=1,
  INPUT=2,
};

enum PVAL {
  LOW=0,
  HIGH=1,
};

enum RST_PIN;

enum DIGITAL_PIN;

enum LED;

enum ANALOG_PIN;

enum PIN {
  RST_PIN,
  DIGITAL_PIN,
  ANALOG_PIN,
  LED,
};

void set_dir(enum PIN pin, enum DIR dir);
void pin_write(enum PIN pin, enum PVAL val);
enum PVAL pin_read(enum PIN pin);
