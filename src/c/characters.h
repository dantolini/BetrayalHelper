#ifndef __CHARACTERS_C__
#define __CHARACTERS_C__
#include <pebble.h>

#define SPEED 0
#define MIGHT 1
#define SANITY 2
#define KNOWLEDGE 3
#define NUM_TRAITS 4
#define TRACK_LENGTH 9
#define NUM_CHARACTERS 12
#define RED_CHAR_COLOR { .argb = GColorRedARGB8 }
#define YELLOW_CHAR_COLOR { .argb = GColorChromeYellowARGB8 }
#define GREEN_CHAR_COLOR { .argb = GColorIslamicGreenARGB8 }
#define WHITE_CHAR_COLOR { .argb = GColorLightGrayARGB8 }
#define BLUE_CHAR_COLOR { .argb = GColorVeryLightBlueARGB8 }
#define PURPLE_CHAR_COLOR { .argb = GColorPurpleARGB8 }
#define BLACK_COLOR { .argb = GColorBlackARGB8 }
#define WHITE_COLOR { .argb = GColorWhiteARGB8 }


static int c_traits[NUM_TRAITS] = {SPEED,MIGHT,SANITY,KNOWLEDGE};
typedef struct Character {
  char* name;
  int default_index[NUM_TRAITS];
  char* trait_array[NUM_TRAITS][TRACK_LENGTH] ;
  GColor background_color;
  GColor text_color;
} Character;

struct Character OX_BELLOWS =  {
  .name = "Ox Bellows",
  .default_index = {5,3,3,3},
  .trait_array =  {
    {"0","2","2","2","3","4","5","5","6"},
    {"0","4","5","5","6","6","7","8","8"},
    {"0","2","2","3","4","5","5","6","7"},
    {"0","2","2","3","3","5","5","6","6"}
  },
    .background_color = RED_CHAR_COLOR,
    .text_color = BLACK_COLOR
};

struct Character DARRIN_WILLIAMS =  {
  .name = "Darrin \"Flash\" Williams",
  .default_index = {5,3,3,3},
  .trait_array =  {
    {"0","4","4","4","5","6","7","7","8"},
    {"0","2","3","3","4","5","6","6","7"},
    {"0","1","2","3","4","5","5","5","7"},
    {"0","2","3","3","4","5","5","5","7"}
  },
    .background_color = RED_CHAR_COLOR,
    .text_color = BLACK_COLOR
};

struct Character MISSY_DUBOURDE =  {
  .name = "Missy Dubourde",
  .default_index = {3,4,3,4},
  .trait_array =  {
    {"0","3","4","5","6","6","6","7","7"},
    {"0","2","3","3","3","4","5","6","7"},
    {"0","1","2","3","4","5","5","6","7"},
    {"0","2","3","4","4","5","6","6","6"}
  },
    .background_color = YELLOW_CHAR_COLOR,
    .text_color = BLACK_COLOR
};

struct Character ZOE_INGSTROM =  {
  .name = "Zoe Ingstrom",
  .default_index = {4,4,3,3},
  .trait_array =  {
    {"0","4","4","4","4","5","6","8","8"},
    {"0","2","2","3","3","4","4","6","7"},
    {"0","3","4","5","5","6","6","7","8"},
    {"0","1","2","3","4","4","5","5","5"}
  },
    .background_color = YELLOW_CHAR_COLOR,
    .text_color = BLACK_COLOR
};

struct Character PETER_AKIMOTO =  {
  .name = "Peter Akimoto",
  .default_index = {4,3,4,3},
  .trait_array =  {
    {"0","3","3","3","4","6","6","7","7"},
    {"0","2","3","3","4","5","5","6","8"},
    {"0","3","4","4","4","5","6","6","7"},
    {"0","3","4","4","5","6","7","7","8"}
  },
    .background_color = GREEN_CHAR_COLOR,
    .text_color = BLACK_COLOR
};

struct Character BRANDON_JASPERS =  {
  .name = "Brandon Jaspers",
  .default_index = {3,4,4,3},
  .trait_array =  {
    {"0","3","4","4","4","5","6","7","8"},
    {"0","2","3","3","4","5","6","6","7"},
    {"0","3","3","3","4","5","6","7","8"},
    {"0","1","3","3","5","5","6","6","7"}
  },
    .background_color = GREEN_CHAR_COLOR,
    .text_color = BLACK_COLOR
};

struct Character FATHER_RHINEHARDT =  {
  .name = "Father Rhinehardt",
  .default_index = {3,3,5,4},
  .trait_array =  {
    {"0","2","3","3","4","5","6","7","7"},
    {"0","1","2","2","4","4","5","5","7"},
    {"0","3","4","5","5","6","7","7","8"},
    {"0","1","3","3","4","5","6","6","8"}
  },
    .background_color = WHITE_CHAR_COLOR,
    .text_color = BLACK_COLOR
};

struct Character PROFESSOR_LONGFELLOW =  {
  .name = "Professor Longfellow",
  .default_index = {4,3,3,5},
  .trait_array =  {
    {"0","2","2","4","4","5","5","6","6"},
    {"0","1","2","3","4","5","5","6","6"},
    {"0","1","3","3","4","5","5","6","7"},
    {"0","4","5","5","5","5","6","7","8"}
  },
    .background_color = WHITE_CHAR_COLOR,
    .text_color = BLACK_COLOR
};

struct Character VIVIAN_LOPEZ =  {
  .name = "Vivian Lopez",
  .default_index = {4,3,3,4},
  .trait_array =  {
    {"0","3","4","4","4","4","6","7","8"},
    {"0","2","2","2","4","4","5","6","6"},
    {"0","4","4","4","5","6","7","8","8"},
    {"0","4","5","5","5","5","6","6","7"}
  },
    .background_color = BLUE_CHAR_COLOR,
    .text_color = BLACK_COLOR
};

struct Character MADAME_ZOSTRA =  {
  .name = "Madame Zostra",
  .default_index = {3,4,3,4},
  .trait_array =  {
    {"0","2","3","3","5","5","6","6","7"},
    {"0","2","3","3","4","5","5","5","6"},
    {"0","4","4","4","5","6","7","8","8"},
    {"0","1","3","4","4","4","5","6","6"}
  },
    .background_color = BLUE_CHAR_COLOR,
    .text_color = BLACK_COLOR
};

struct Character JENNY_LECLERC =  {
  .name = "Jenny LeClerc",
  .default_index = {4,3,5,3},
  .trait_array =  {
    {"0","2","3","4","4","4","5","6","8"},
    {"0","3","4","4","4","4","5","6","8"},
    {"0","1","1","2","4","4","4","5","6"},
    {"0","2","3","3","4","4","5","6","8"}
  },
    .background_color = PURPLE_CHAR_COLOR,
    .text_color = BLACK_COLOR
};

struct Character HEATHER_GRANVILLE =  {
  .name = "Heather Granville",
  .default_index = {3,3,3,5},
  .trait_array =  {
    {"0","3","3","4","5","6","6","7","8"},
    {"0","3","3","3","4","5","6","7","8"},
    {"0","3","3","3","4","5","6","6","6"},
    {"0","2","3","3","4","5","6","7","8"}
  },
    .background_color = PURPLE_CHAR_COLOR,
    .text_color = BLACK_COLOR
};

Character *characters[NUM_CHARACTERS] = { &OX_BELLOWS,
                                          &DARRIN_WILLIAMS,
                                          &MISSY_DUBOURDE,
                                          &ZOE_INGSTROM,
                                          &PETER_AKIMOTO,
                                          &BRANDON_JASPERS,
                                          &FATHER_RHINEHARDT,
                                          &PROFESSOR_LONGFELLOW,
                                          &VIVIAN_LOPEZ,
                                          &MADAME_ZOSTRA,
                                          &JENNY_LECLERC,
                                          &HEATHER_GRANVILLE
                                        };
#endif